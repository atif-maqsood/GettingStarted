// function template
#include <iostream>
using namespace std;

template <class T>
T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}
double sum (double a, int b,int c)
{
  return a+b+c;
}
int main () {
  int i=5, j=6, k;
  double f=2.0, g=0.5, h,normalResult;
  k=sum(i,j);
  h=sum(f,g);
  normalResult= sum(5.5,5,5);
  cout << k << '\n';
  cout << h << '\n';
  cout << normalResult<< '\n';
  return 0;
}