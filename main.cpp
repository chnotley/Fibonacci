#include <iostream>
#include "fibonacci.h"
#define FIBONACCI_SEQUENCE_LIMIT 100

//
// Program to display first 50 numbers is the Fibonacci sequence
// using an iterative approach followed by a recursive approach
//
int main()
{
    int sequenceIterator;
    Fibonacci obj;
    VeryLong arg1;
    VeryLong arg2;

    std::cout << "\nUsing iterative method to disply the first " \
              << FIBONACCI_SEQUENCE_LIMIT \
              << " numbers of the Fibonacci Sequence\n\n";

    for(sequenceIterator = 0; sequenceIterator <  FIBONACCI_SEQUENCE_LIMIT; sequenceIterator++)
    {
        std::cout << obj.iterativeNextInSequence() << '\n';
    }

    std::cout << "\nUsing recursive method to disply the first "\
              << FIBONACCI_SEQUENCE_LIMIT \
              << " numbers of the Fibonacci Sequence\n\n";

    obj.recursivePrintSequence(arg1, arg2, FIBONACCI_SEQUENCE_LIMIT);

    return 0;
}
