#ifndef _LAZY_INITIALIZATION_H_
#define _LAZY_INITIALIZATION_H_

#include <iostream>

namespace lazy_initialization {
using namespace std;

class Fruit {
  public:
    static Fruit* getFruit(const string& type);
    static void printCurrentTypes();

  private:
    static map<string, Fruit*> types;
    string type;
    // note: constructor private forcing one to use static getFruit()
    Fruit(const string& t)
        : type(t) {
    }
};

//definition needed for using any static member variable
map<string, Fruit*> Fruit::types;
/*
 * Lazy Factory method, gets the Fruit instance associated with a
 * certain type. Instantiates new ones as needed.
 * precondition: type. Any string that describes a fruit type, e.g. "apple"
 * postcondition: The Fruit instance associated with that type.
 */
Fruit* Fruit::getFruit(const string& type) {
  Fruit *f = types[type]; // try to find a pre-existing instance, or std::map'll create one if not found

  if (!f) { // if it was created by map automatically, it'll be pointing to NULL
    // couldn't find one, so make a new instance
    f = new Fruit(type); // lazy initialization part
    types[type] = f; // Registering the newly created Fruit in the types' map for later use.
  }
  return f;
}

/*
 * For example purposes to see pattern in action
 */
void Fruit::printCurrentTypes() {
  if (!types.empty()) {
    cout << "Number of instances made = " << types.size() << endl;
    for (map<string, Fruit*>::iterator iter = types.begin();
        iter != types.end(); ++iter) {
      cout << (*iter).first << endl;
    }
    cout << endl;
  }
}

int test() {
  std::cout << "Test: Lazy initialization  pattern example --->" << std::endl;
  Fruit::getFruit("Banana");
  Fruit::printCurrentTypes();

  Fruit::getFruit("Apple");
  Fruit::printCurrentTypes();

  // returns pre-existing instance from first
  // time Fruit with "Banana" was created
  Fruit::getFruit("Banana");
  Fruit::printCurrentTypes();
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace lazy_initialization

#endif // _LAZY_INITIALIZATION_H_
