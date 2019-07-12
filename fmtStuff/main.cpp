#include <iostream>
#include <fmt/core.h>


using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    fmt::print("The answer is {}.\n", 42);
    fmt::print("The binary presentation is: {0:b}.\n", 42);
    return 0;
}
