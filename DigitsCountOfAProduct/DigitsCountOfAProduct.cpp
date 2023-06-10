#include <iostream>
#include <cmath>

int main()
{
    unsigned long numbersForMultiplication[] = { 5432, 5309, 4234, 536,
        3141247, 863157, 23, 435891, 6791, 3123641, 647391, 739, 8391 };
    int arraySize = sizeof(numbersForMultiplication) / sizeof(numbersForMultiplication[0]);
    int digits = 1;

    for (int i = 0; i < arraySize; i++)
    {
        digits += log10(numbersForMultiplication[i]);
    }

    std::cout << "Digits of the product: " << digits << std::endl;
}

