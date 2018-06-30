
#include <iostream>
#include "nullable.hpp"


int main() {
  using namespace std;
  using namespace totoho;
  nullable<int> ni1;
  if(ni1) {
    cout << "ni1 is " << ni1.get_value() << endl;
  } else {
    cout << "ni1 is null..." << endl;
  }

  nullable<double> nd1(0.5f);
  if(nd1) {
    cout << "nd1 is " << nd1.get_value() << endl;
  } else {
    cout << "nd1 is null..." << endl;
  }

  nd1 = nullptr;
  if(nd1) { 
    cout << "nd1 is " << nd1.get_value() << endl;
  } else {
    cout << "nd1 is null..." << endl;
  }

  nd1 = 2.1f;
  if(nd1) {
    double d1 = (double)nd1;
    cout << "d1 is " << d1 << endl;
  }
}