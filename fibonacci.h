// Eight byte unsigned long long will hold any value in the first 50 numbers
// of the Fibonacci sequence, but nine bytes are required to hold values in the
// first 100 numbers of the Fibonacci sequence.
// @todo create class with nine byte unsigned long long and overloaded + and =
// operators

#pragma once
#include "verylong.h"

class Fibonacci
{
 private:
    int sequenceNumber;
    VeryLong mostRecentPreceding;
    VeryLong nextMostRecentPreceding;

 public:
    Fibonacci();
    VeryLong iterativeNextInSequence(void);
    void recursivePrintSequence(VeryLong, VeryLong, unsigned);
};
