#include <iostream>

using namespace std;

class MyClass {
public:
    void* operator new (size_t sz, void* v) {
        cout << "Placement new invoked" << endl;
        return v;
    }

    ~MyClass() {
        //cleanup
    }
};

int main() {
    int buffer[16];
    cout << "Starting address of my buffer = " << &buffer << endl;

    MyClass* obj = new (buffer) MyClass();
    cout << "Location of my object = " << obj << endl;

    obj->~MyClass();
}
