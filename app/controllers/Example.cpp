#include <iostream>
#include <string>

using namespace std;

class Example
{
private:
    static int data;
    static Example curr;

public:
    Example();

    static void process ();
    void asd();

    ~Example();
};

int Example::data;
Example Example::curr;

Example::Example() {
    Example::data = 312;
}

void Example::asd() {
    Example::data = 123;
}

void Example::process() {
    Example::data = 312;
    Example::curr.asd();
    cout << Example::data << endl;
}

Example::~Example() {}
