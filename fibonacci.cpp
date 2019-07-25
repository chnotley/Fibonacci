#include "fibonacci.h"
#include <iostream>

//
// Default constructor
//
Fibonacci::Fibonacci(void)
{
    sequenceNumber = 0;
    nextMostRecentPreceding = 1;
    mostRecentPreceding = 1;
}

//
// Calculates the next number in a Fibonacci sequence.
//
VeryLong Fibonacci::iterativeNextInSequence(void)
{
    VeryLong result;

    switch(this->sequenceNumber++)
    {
    case 0:
        result = 0;
        break;
    case 1:
    case 2:
        result = 1;
        break;
    default:
        result = this->mostRecentPreceding + this->nextMostRecentPreceding;
        this->nextMostRecentPreceding = this->mostRecentPreceding;
        this->mostRecentPreceding = result;
        break;
    }

    return result;
}

void Fibonacci::recursivePrintSequence(VeryLong mostRecentPreceding,
                                           VeryLong nextMostRecentPreceding,
                                           unsigned sequenceMax)
{
    VeryLong result;
    int mrp;
    int nmrp;

    if(sequenceMax > 0)
    {
        mrp = mostRecentPreceding.convertLeastSignificantDigitToInt();
        nmrp = nextMostRecentPreceding.convertLeastSignificantDigitToInt();
        switch(mrp + nmrp)
        {
        case 0:
            result = 0;
            mostRecentPreceding = 1;
            break;
        case 1:
            result = 1;
            if(1 == mrp)
            {
                mostRecentPreceding = 0;
                nextMostRecentPreceding = 1;
            }
            else
            {
                mostRecentPreceding = 1;
            }
            break;
        default:
            result = mostRecentPreceding + nextMostRecentPreceding;
            nextMostRecentPreceding = mostRecentPreceding;
            mostRecentPreceding = result;
            break;
        }
        std::cout << result << std::endl;
        this->recursivePrintSequence(mostRecentPreceding, nextMostRecentPreceding, sequenceMax - 1);
    }
}

std::ostream& operator<<(std::ostream& os, const VeryLong val)
{
    std::string num = val.num;
    
    os << num.erase(0, std::min(num.find_first_not_of('0'), num.size()-1));
  
    return os;
}
