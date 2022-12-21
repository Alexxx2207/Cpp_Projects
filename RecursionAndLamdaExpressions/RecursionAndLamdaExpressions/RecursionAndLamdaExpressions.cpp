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
		return number == 0 ? 1 : factorial_non_tailed(number - 1) * number;
	};

	std::cout << factorial_tailed(0, 1) << std::endl;
	std::cout << factorial_tailed(1, 1) << std::endl;
	std::cout << factorial_tailed(4, 1) << std::endl;
	std::cout << factorial_tailed(5, 1) << std::endl;

	std::cout << std::endl;

	std::cout << factorial_non_tailed(0) << std::endl;
	std::cout << factorial_non_tailed(1) << std::endl;
	std::cout << factorial_non_tailed(4) << std::endl;
	std::cout << factorial_non_tailed(5) << std::endl;
}

void Fibonacci()
{
	std::function<int (int, int, int)> fibonacci_tailed = [&fibonacci_tailed](int n, int n1, int n2) -> int
	{
		return n == 0 ? n1 : n == 1 ? n2 : fibonacci_tailed(n - 1, n2, n1 + n2);
	};

	std::function<int(int)> fibonacci_non_tailed = [&fibonacci_non_tailed](int n) -> int
	{
		return n <= 1 ? n : fibonacci_non_tailed(n - 1) + fibonacci_non_tailed(n - 2);
	};

	std::cout << fibonacci_tailed(0, 0, 1) << std::endl;
	std::cout << fibonacci_tailed(1, 0, 1) << std::endl;
	std::cout << fibonacci_tailed(2, 0, 1) << std::endl;
	std::cout << fibonacci_tailed(3, 0, 1) << std::endl;
	std::cout << fibonacci_tailed(4, 0, 1) << std::endl;
	std::cout << fibonacci_tailed(5, 0, 1) << std::endl;

	std::cout << std::endl;

	std::cout << fibonacci_non_tailed(0) << std::endl;
	std::cout << fibonacci_non_tailed(1) << std::endl;
	std::cout << fibonacci_non_tailed(2) << std::endl;
	std::cout << fibonacci_non_tailed(3) << std::endl;
	std::cout << fibonacci_non_tailed(4) << std::endl;
	std::cout << fibonacci_non_tailed(5) << std::endl;
}
