#include <iostream>
#include <cstdio>
#include <cmath>

void drawTriangle(int length)
{
	for (int i = 0; i < length; i++)
	{
		printf(" ");
	}
	printf("*");
	printf("\n");

	for (int i = 0; i < length - 2; i++)
	{
		for (int j = 0; j < length - i-1; j++)
		{
			printf(" ");
		}
		printf("*");
		for (int j = 0; j < (i*2)+1; j++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	printf(" ");
	for (int i = 0; i < length; i++)
	{
		printf("*");
		printf(" ");
	}
}

void drawTrapezoid(int length)
{
	for (int i = 0; i < length; i++)
	{
		printf(" ");
	}
	for (int i = 0; i < length; i++)
	{
		printf("* ");
	}

	printf("\n");

	for (int i = 0; i < length - 2; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			printf(" ");
		}

		printf("*");

		for (int j = 0; j < 2 * length + i * 2 - 1; j++)
		{
			printf(" ");
		}

		printf("*");

		printf("\n");
	}
	for (int i = 0; i < length * 2 - 1; i++)
	{
		printf(" *");
	}
}

void squaredCircle(int r)
{
	int arr_size = r*2+1;
	char arr[100][100];

	for (int x = 0; x < arr_size; x++)
	{
		for (int y = 0; y < arr_size; y++)
		{
			arr[x][y] = '.';
		}
	}

	for (int x = 0; x < arr_size; x++)
	{
		for (int y = 0; y < arr_size; y++)
		{
			if (pow((r - x), 2) + pow((r - y), 2) > (r * r) - r / 2)
			{
				printf("# ");
			}
			else {
				printf("%c ", arr[x][y]);
			}
		}
		printf("\n");
	}
}


void circle(int r)
{
	float console_ratio = 2;
	float a = console_ratio * r;
	float b = r;

	for (int y = -r; y <= r; y++)
	{
		for (int x = -console_ratio * r; x <= console_ratio * r; x++)
		{
			float d = sqrt((x / a) * (x / a) + (y / b) * (y / b));
			if (d > 0.90 && d < 1.1)
			{
				printf("X");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main()
{
	drawTriangle(10);
	printf("\n\n");
	drawTrapezoid(10);
	printf("\n\n");
	circle(5);
	printf("\n\n");
	squaredCircle(10);
}
