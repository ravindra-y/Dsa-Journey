#include <iostream>
using namespace std;

class Car {
public:
  string brand;
};

int main() {
  Car c1; // object
  c1.brand = "BMW";
  cout << c1.brand;
}