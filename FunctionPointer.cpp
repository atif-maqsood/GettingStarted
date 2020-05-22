#include <iostream>

void PrintMessage( int num)
{
  std::cout << "Hello World" << " value is = " << num << std::endl;
}

int main() {
//  auto function = &PrintMessage;

  void(* function)(int) = &PrintMessage;
  function(8);
  function(10);
  
 // std::cout << "Hello World!\n";
}
