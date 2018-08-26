#include <stdexcept>
#include <iostream>
#include "nullable.hpp"

#include "nullable.hpp" // check include guard

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

  nd1 = 1;
  nd1 = nullopt;
  if(nd1) {
    cout << "nd1 is " << nd1.get_value() << endl;
  }else{
    cout << "nd1 is null..." << endl;
  }

  nd1 = 2.1f;
  if(nd1) {
    double d1 = (double)nd1;
    cout << "d1 is " << d1 << endl;
  }

  nd1.set_value(nullopt);
  if(nd1) {
    cout << "nd1 is " << nd1.get_value() << endl;
  }else{
    cout << "nd1 is null..." << endl;
  }

  try{
    nd1 = nullptr;
    nd1.get_value();
  }catch(std::runtime_error& e){
    cout << "caught runtime_error: " << e.what() << endl;
  }
}
