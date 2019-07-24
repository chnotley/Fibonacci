#include "verylong.h"
#include <string.h>
#include <assert.h>

VeryLong::VeryLong()
{
    // Containing the 100th number in Fibonacci seqence requires 21 decimal characters
    num = new char[MAX_LENGTH];
    memset(num, '\0', sizeof(char) * MAX_LENGTH);
}

VeryLong::~VeryLong()
{
    delete[] num;
}

//
// Adds two VeryLong numbers
//
VeryLong VeryLong::operator+ (const VeryLong& addend) const
{
    int indexIterator;
    int intermediateValue;
    int carryValue = 0;
    VeryLong &result = *new VeryLong();

    // Convert each base 10 digit to an integer value and add
    // account for carry
    for(indexIterator = 0; indexIterator < MAX_LENGTH; indexIterator++)
    {
        intermediateValue = addend.num[indexIterator] - '0' +
            this->num[indexIterator] - '0' + carryValue;

        if(intermediateValue > 9)
        {
            carryValue = intermediateValue - 9;
        }
        else
        {
            carryValue = 0;
        }

        result.num[indexIterator] = (intermediateValue % 10) + '0';

        // Detect overflow
        if(indexIterator == MAX_LENGTH - 1)
        {
            assert(carryValue == 0);
        }
    }

    return result;
}
