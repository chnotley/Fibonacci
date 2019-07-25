#pragma once
#include <iostream>
#include <string>

#define MAX_LENGTH 22
//
// Implements as base 10 unsigned integer
//
class VeryLong
{
private:
    std::string num;

public:
    VeryLong();
    VeryLong operator+(const VeryLong&) const;
    VeryLong operator=(const VeryLong&);
    VeryLong operator=(const unsigned&);
    int convertLeastSignificantDigitToInt(void);
    friend std::ostream& operator<<(std::ostream&, const VeryLong);
};
