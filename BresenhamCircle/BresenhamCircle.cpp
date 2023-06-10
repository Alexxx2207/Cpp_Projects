#include <iostream>
#include <cmath>

const char fill = '#';
const char empty = ' ';
const short int fieldSize = 51 ;
const short int center = fieldSize / 2;
const short int radius = ceil((fieldSize - 4) / 2);

void bresenham(char field[fieldSize][fieldSize])
{
    short int x = 0;
    short int y = radius;
    short int d = 3 - 2 * radius;

    field[center - radius][center] = empty;
    field[center + radius][center] = empty;
    field[center][center - radius] = empty;
    field[center][center + radius] = empty;

    while (x < y)
    {
        if (d >= 0)
        {
            x++;
            y--;
            d += 4 * (x - y) + 10;
        }
        else
        {
            x++;
            d += 4 * x + 6;
        }

        field[center - y][center + x] = fill;
        field[center - y][center - x] = fill;
        field[center + y][center - x] = fill;
        field[center + y][center + x] = fill;

        field[center - x][center + y] = fill;
        field[center + x][center + y] = fill;
        field[center + x][center - y] = fill;
        field[center - x][center - y] = fill;
    }
}

int main()
{
    char field[fieldSize][fieldSize];
    for (int row = 0; row < fieldSize; row++)
    {
        for (int col = 0; col < fieldSize; col++)
        {
            if (row == col && row == center)
            {
                field[row][col] = 'O';
            }
            else if (round(sqrt(pow(row - center, 2) + pow(col - center, 2))) < radius)
            {
                field[row][col] = empty;
            }
            else
            {
                field[row][col] = fill;
            }
        }
    }

    bresenham(field);

    for (int row = 0; row < fieldSize; row++)
    {
        for (int col = 0; col < fieldSize; col++)
        {
            std::cout << field[row][col] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
