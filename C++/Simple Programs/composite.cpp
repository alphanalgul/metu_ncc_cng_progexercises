
#include <iostream> 
using namespace std; 
 
class Component{ 
 private: 
  int value; 
 public: 
  Component(int value): value(value){} 
  void set(int value){ this->value = value; } 
  int get(){ return value; } 
}; 
 
class Composite{ 
 private: 
  Component *owned1, *owned2; 
 public: 
  Composite(int one, int two) { 
      owned1 = new Component(one); 
      owned2 = new Component(two); 
  } 
  void show_components(){ 
   cout << owned1->get() << " | " << owned2->get(); 
  } 
  ~Composite(){ 
      delete owned1; 
      delete owned2; 
  } 
}; 
 
int main(){ 
 Composite example(3, 5); 
 example.show_components(); 
 return 0; 
} 
