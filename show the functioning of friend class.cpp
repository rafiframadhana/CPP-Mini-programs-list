// C++ program to demonstrate the working of friend class

#include <iostream>
using namespace std;

// forward declaration
class ClassB;

class ClassA {
    private:
        int numA;
        friend class ClassB;

    public:
        ClassA() : numA(34) {}
};

class ClassB {
    private:
        int numB;

    public:
        ClassB() : numB(14) {}

    int add() {
        ClassA objA;
        return objA.numA + numB;
    }
};

int main() {
    ClassB objB;
    cout << "Sum: " << objB.add();
    return 0;
}