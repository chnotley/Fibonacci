#include "fibonacci.h"
#include <iostream>

Fibonacci::Fibonacci(void)
{
    sequenceNumber = 0;
    nextMostRecentPreceding = 1;
    mostRecentPreceding = 1;
}

//
// Calculates the next number in a Fibonacci sequence.
//
unsigned long Fibonacci::getNextInFibonacciSequence(void)
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
