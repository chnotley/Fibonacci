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
    char *num;

 public:
VeryLong();
~VeryLong();
    VeryLong operator+(const VeryLong&) const;
};
