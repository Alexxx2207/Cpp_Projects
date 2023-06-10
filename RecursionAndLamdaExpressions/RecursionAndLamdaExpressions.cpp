#include <iostream>
#include <functional>

void Factorial();
void Fibonacci();

int main()
{
	Factorial();

	std::cout << std::endl;

	Fibonacci();
}


void Factorial()
{
	std::function<int(int, int)> factorial_tailed = [&factorial_tailed](int number, int product) -> int
	{
		return number == 0 ? 1 : number == 1 ? product : factorial_tailed(number - 1, product * number);
	};

	std::function<int(int)> factorial_non_tailed = [&factorial_non_tailed](int number) -> int
	{
		return number <= 1 ? 1 : factorial_non_tailed(number - 1) * number;
	};

	for (int i = 0; i <= 5; i++)
	{
		std::cout << factorial_tailed(i, 1) << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i <= 5; i++)
	{
		std::cout << factorial_non_tailed(i) << std::endl;
	}
}

void Fibonacci()
{
	std::function<int(int, int, int)> fibonacci_tailed = [&fibonacci_tailed](int n, int n1, int n2) -> int
	{
		return n == 0 ? n1 : n == 1 ? n2 : fibonacci_tailed(n - 1, n2, n1 + n2);
	};

	std::function<int(int)> fibonacci_non_tailed = [&fibonacci_non_tailed](int n) -> int
	{
		return n <= 1 ? n : fibonacci_non_tailed(n - 1) + fibonacci_non_tailed(n - 2);
	};

	for (int i = 0; i <= 5; i++)
	{
		std::cout << fibonacci_tailed(i, 0, 1) << std::endl;
	}
	
	std::cout << std::endl;

	for (int i = 0; i <= 5; i++)
	{
		std::cout << fibonacci_non_tailed(i) << std::endl;
	}
}