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
unsigned long Fibonacci::iterativeNextInSequence(void)
{
    unsigned long result;

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

void Fibonacci::recursivePrintSequence(unsigned long mostRecentPreceding,
                                           unsigned long nextMostRecentPreceding,
                                           unsigned long sequenceMax)
{
    unsigned long result;

    if(sequenceMax > 0)
    {
        switch(mostRecentPreceding + nextMostRecentPreceding)
        {
        case 0:
            result = 0;
            mostRecentPreceding = 1;
            break;
        case 1:
            result = 1;
            if(1 == mostRecentPreceding)
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
        std::cout << result << '\n';
        this->recursivePrintSequence(mostRecentPreceding, nextMostRecentPreceding, sequenceMax - 1);
    }
}
