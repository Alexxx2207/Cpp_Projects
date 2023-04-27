#include <iostream>

int main()
{
    unsigned long long number = 67280421310721;

    for (unsigned long long i = 2; i < sqrt(number); i++)
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


