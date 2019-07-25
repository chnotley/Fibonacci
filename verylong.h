#pragma once
#include <iostream>
#include <string>

#define MAX_LENGTH 22
#define TWENTY_TWO_ZEROS "0000000000000000000000"
#define TWENTY_ONE_ZEROS_AND_A_ONE "0000000000000000000001"

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
    void initialValueSetter(const std::string);
    int convertLeastSignificantDigitToInt(void);
    friend std::ostream& operator<<(std::ostream&, const VeryLong);
};
