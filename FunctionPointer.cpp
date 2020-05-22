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
/*
#include <iostream>
#include <vector>
void PrintValue(int value)
{
 std::cout << " value is = " << value << std::endl;
}

void ForEach( const std::vector<int>& values, void(*func)(int))
{
  for(int value : values)
       func(value);
 
}

int main() {
std::vector<int> values = {1,2,3,4,5};
ForEach(values,PrintValue);
}
*/
/*
// using Lambda function (unnammed func)
#include <iostream>
#include <vector>



void ForEach( const std::vector<int>& values, void(*func)(int))
{
  for(int value : values)
       func(value);
 
}

int main() {
std::vector<int> values = {1,2,3,4,5};
ForEach(values,[](int value){std::cout << " value is = " << value << std::endl;});
}
*/
