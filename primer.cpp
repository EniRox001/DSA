#include "stdio.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <mutex>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

enum ECarTypes { Sedan, Hatchback, SUV, Wagon };

class Dog {
private:
  std::string name;
  int weight;

public:
  Dog();

  void setName(const std::string &dogName);
  void setWeight(int dogWeight);

  virtual void print() const;

  void bark() const { std::cout << name << " barks!\n"; }

  virtual ~Dog();
};

Dog::Dog() { std::cout << "A dog has been constructed\n"; }

void Dog::setName(const std::string &dogName) { name = dogName; }

void Dog::setWeight(int dogWeight) { weight = dogWeight; }

void Dog::print() const {
  std::cout << "Dog is " << name << " and weighs " << weight << " kg\n";
}

Dog::~Dog() { std::cout << "Goodbye " << name << '\n'; }

class OwnedDog : public Dog {
private:
  std::string owner;

public:
  void setOwner(const std::string &dogOwner);

  void print() const override;
};

void OwnedDog::setOwner(const std::string &dogOwner) { owner = dogOwner; }

void OwnedDog::print() const {
  Dog::print();
  std::cout << "Dog is owned by " << owner << "\n";
}

class Point {
public:
  double x = 0;
  double y = 0;

  Point() {};

  Point(double a, double b) : x(a), y(b) {}

  Point operator+(const Point &rhs) const;

  Point &operator+=(const Point &rhs);
};

Point Point::operator+(const Point &rhs) const {
  return Point(x + rhs.x, y + rhs.y);
}

Point &Point::operator+=(const Point &rhs) {
  x += rhs.x;
  y += rhs.y;

  return *this;
  ;
};

template <class T> class Box {
public:
  void insert(const T &) {}
};

int main() {
  // OwnedDog myDog;
  //
  // myDog.setName("Bingo");
  // myDog.setWeight(10);
  // myDog.setOwner("Enoch");
  // myDog.print();
  //

  // Point up(0, 1);
  // Point right(1, 0);
  //
  // Point result = up + right;
  //
  // std::cout << "result is upright (" << result.x << ',' << result.y << ")\n";
  //
  //

  // Box<int> intBox;
  //
  // intBox.insert(123);
  //
  // try {
  //   throw std::runtime_error("An error has occured");
  // } catch (...) {
  //   std::cout << "Unknown exception caught";
  //   throw;
  // }

  // Dog *ptr = new Dog();
  // ptr->bark();
  // delete ptr;
  //

  // std::string val;
  // std::vector<std::string> my_vector;
  //
  // std::cout << "Enter a value: " << "\n";
  // std::cin >> val;
  //
  // my_vector.push_back(val);
  // my_vector.push_back(val);
  //
  // for (int i = 0; i < my_vector.size(); i++) {
  //   std::cout
  //       << my_vector[i]
  //       << '\n'; // for accessing a vector's element we can use the operator
  //       []
  // }

  return 0;
}
