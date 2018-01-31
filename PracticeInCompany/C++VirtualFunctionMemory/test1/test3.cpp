/*************************************************************************
	> File Name: test1.cpp
	> Author: wk
	> compiler: gcc4.3.2
	> platform: linux
	> Created Time: Mon 06 Mar 2017 01:44:41 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;
 
class A
{
public:
  void printA()
  {
    cout<<"this is A class\n";
  }
    
  char ca;

};

class B
{
public:
 virtual  void printB()
  {
    cout<<"this is B class\n";
  }
    
  char cb;
};
int main()
{
   
  A *a = new A;
  B *b = (B*)a;
  b->printB();
  delete a;
  a=NULL;
  return 0;
}


