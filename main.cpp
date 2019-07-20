#include <iostream>
#include "fibonacci.h"

int main()
{
    unsigned int count = 0;

    std::cout << "Program displays the first n numbers in the Fibonacci Sequence.\n";
    std::cout << "Enter number of Fibonaccci numbers to display (50 maximum):\n";
    std::cin >> count;
  
    if(count > 50)
    {
        std::cout << count << " is too large.  Maximum number of Fibonacci numbers is 50.\n";
    }
    else
    {
        std::cout << count << '\n';
    }

    return 0;
}
