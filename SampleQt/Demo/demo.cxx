#include <iostream>
#include "hello.hpp"

extern Hello hello;

int main()
{
  hello.Print();
  
  return 0;
}
