#include "verylong.h"
#include <string.h>
#include <assert.h>

VeryLong::VeryLong(void)
{
    // Need at most 22 base 10 digits to represent the 100th number in the Fibonacci sequence
    num = "0000000000000000000000";
}

//
// Convert the least significant digit of a base 10 VeryLong to an integer.
// return -1 if the VeryLong's value exceeds 9
//
int VeryLong::convertLeastSignificantDigitToInt(void)
{
    std::string::reverse_iterator reverseIterator = this->num.rbegin();

    for(; reverseIterator != this->num.rend(); reverseIterator++)
    {
        // Check if any digit above the first digit is non-zero
        if(0 != (*reverseIterator - '0') && this->num.rbegin() != reverseIterator)
        {
            return -1;
        }
    }

    return (int)(*(this->num.rbegin()) - '0');
}

//
// Adds two VeryLong numbers
//
VeryLong VeryLong::operator+ (const VeryLong& addend) const
{
    VeryLong &result = *new VeryLong();
    std::string::const_reverse_iterator firstAddendIterator = this->num.rbegin();
    std::string::const_reverse_iterator secondAddendIterator = addend.num.rbegin();
    std::string::reverse_iterator resultIterator = result.num.rbegin();
    int intermediateResult;
    int carryValue = 0;

    // Convert each digit in a string to a base 10 integer and add them, accounting for carry
    for( ; firstAddendIterator != this->num.rend(); firstAddendIterator++, secondAddendIterator++, resultIterator++)
    {
        intermediateResult = (*firstAddendIterator - '0') + (*secondAddendIterator - '0') + carryValue;

        carryValue = intermediateResult / 10;
        *resultIterator = static_cast<char>((intermediateResult % 10) + '0');
    }

    // Detect overflow
    assert(carryValue == 0);

    return result;
}

//
// Assigns an unsigned value to a ReallyLong
//
VeryLong VeryLong::operator=(const unsigned& value)
{
    std::string::reverse_iterator reverseIterator = this->num.rbegin();
    unsigned temp = value;

    while(temp && reverseIterator != this->num.rend())
    {
        *reverseIterator = static_cast<char>((temp % 10) + '0');
        temp /= 10;
    }
    return *this;
}

//
// Assigns a VeryLong to a VeryLong
//
VeryLong VeryLong::operator=(const VeryLong& value)
{
    this->num = value.num;

    return *this;
}
