#include <functional>
#include <iostream>
#include <string>

using namespace std;

class Commander
{
private:
    static string command;
    static Commander currentObject;
    void commandError();

public:
    Commander();
    ~Commander();
    static Commander& get(string instruction);
    void address(string route, function<void()> callable);
};

string Commander::command;
Commander Commander::currentObject;

Commander::Commander() {
    Commander::command = "";
    Commander::currentObject = *this;
}

Commander::~Commander() {
}

Commander& Commander::get(string instruction) {
    Commander::command = instruction;
    return Commander::currentObject;
}

void Commander::address(string route, function<void()> callable) {
    if (route.compare(Commander::command) == 0) callable();
    return;
}
