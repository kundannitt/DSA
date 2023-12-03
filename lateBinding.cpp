/*
!!!!! Runtime polymorphism is achieved only through a pointer (or reference) of the base class type !!!!!
// C++ program to illustrate
// working of Virtual Functions
#include <iostream>
using namespace std;
 
class base {
public:
    void fun_1() { cout << "base-1\n"; }
    virtual void fun_2() { cout << "base-2\n"; }
    virtual void fun_3() { cout << "base-3\n"; }
    virtual void fun_4() { cout << "base-4\n"; }
};
 
class derived : public base {
public:
    void fun_1() { cout << "derived-1\n"; }
    void fun_2() { cout << "derived-2\n"; }
    void fun_4(int x) { cout << "derived-4\n"; }
};
 
int main()
{
    base* p;
    derived obj1;
    p = &obj1;
 
    // Early binding because fun1() is non-virtual
    // in base
    p->fun_1();
 
    // Late binding (RTP)
    p->fun_2();
 
    // Late binding (RTP)
    p->fun_3();
 
    // Late binding (RTP)
    p->fun_4();
 
    // Early binding but this function call is
    // illegal (produces error) because pointer
    // is of base type and function is of
    // derived class
    // p->fun_4(5);
 
    return 0;
}
output: - 
base-1
derived-2
base-3
base-4

*/

#include <bits/stdc++.h>
using namespace std;

class base{
  public:
  virtual void fun(){
    cout<<"parent is called"<<endl;
  }
  void fun2(){
    cout<<"fun2 is called from parent"<<endl;
  }
};

class child : public base{
  public:
  void fun(){
    cout<<"child is called"<<endl;
  }
  void fun2(){
    cout<<"fun2 is called from child"<<endl;
  }
};

int main(){
  base *obj;
  child ch;
  obj = &ch;
  obj->fun(); // late binding => child fun will be called.
  obj->fun2(); // early binding => since fun2 is not virtual and obj is a pointer to base class(which is pointing to child class) but still it is pointer of base class.
  return 0;
}