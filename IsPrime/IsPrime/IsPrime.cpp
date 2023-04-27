#include <iostream>

int main()
{
    unsigned long long number = 0;

    std::cout << "Number=";
    std::cin >> number;

    for (unsigned long i = 2; i < sqrt(number); i++)
    {
        if (number % i == 0)
        {
            number = -1;
            break;
        }
    }

    std::cout << (number == -1 ? "Not Prime" : "Prime") << std::endl;
    return 0;
}


