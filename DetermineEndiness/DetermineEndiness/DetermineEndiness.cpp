#include <iostream>
#include <functional>

using namespace std;

int main()
{
    auto endiness = [](auto variable) -> string
    {
        return (*(char*)&variable) ? "little endian" : "big endian";
    };

    cout << endiness(5) << endl;
    cout << endiness(5.0) << endl;
}
