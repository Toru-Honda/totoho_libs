Nullable
===============================

nullable template class implementation like C#.

## Requirement.

C++ compiler supports c++11.

## Usage


Includes `nullable.hpp` and declares variable.
Initial value is set null. Uses `get_value()` to get value.

```cpp
#include "nullable.hpp"

using namespace std;
using namespace totoho;

nullable<int> ni1;
if(ni1) {
  cout << "ni1 is " << ni1.get_value() << endl;
} else {
  cout << "ni1 is null..." << endl;
}

// ni1 is null...
```

You can set initial value by constructor.

```cpp
nullable<double> nd1(0.5f);
if(nd1) {
  cout << "nd1 is " << nd1.get_value() << endl;
} else {
  cout << "nd1 is null..." << endl;
}
// nd1 is 0.5
```

If variable has any value, you can initialize it by setting `nullptr` 

```cpp
nullable<double> nd1(0.5);
nd1 = nullptr; 
if(nd1) { 
  cout << "nd1 is " << nd1.get_value() << endl;
} else {
  cout << "nd1 is null..." << endl;
}
// nd1 is null...
```

Cast is available.

```
nd1 = 2.1f;
if(nd1) {
  cout << "nd1 is " << (double)nd1 << endl;
}
// nd1 is 2.1
```

Throw runtime_error if value is null.

```cpp
nullable<double> nd2;
// cout << "nd2 is " << nd2.get_value() << endl; // runtime_error
```


