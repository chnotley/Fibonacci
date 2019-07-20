// Eight byte unsigned long long will hold any value in the first 50 numbers
// of the Fibonacci sequence, but nine bytes are required to hold values in the
// first 100 numbers of the Fibonacci sequence.
// @todo create class with nine byte unsigned long long and overloaded + and =
// operators

#pragma once

class Fibonacci
{
 private:
    int sequenceNumber;
    unsigned long mostRecentPreceding;
    unsigned long nextMostRecentPreceding;

 public:
    Fibonacci();
    unsigned long getNextInFibonacciSequence(void);
};
