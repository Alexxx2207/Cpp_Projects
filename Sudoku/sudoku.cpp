#include <iostream>

/// @brief Converts the chars to integers from plane and loads them in sudoku matrix
/// @param sudoku Integer matrix for the sudoku game
/// @param plane Input sudoku as characters 
void loadSudoku(int sudoku[9][9], char plane[]);

/// @brief Prints sudoku matrix
/// @param sudoku Integer matrix for the sudoku game
void printSudoku(int sudoku[9][9]);

/// @brief Facade function for recursive backtracking solve function
/// @param sudoku Integer matrix for the sudoku game
bool solve(int sudoku[9][9]);

/// @brief Facade function for recursive backtracking solve function
/// @param sudoku Integer matrix for the sudoku game
/// @param cell_index Cell index from 0 to 81
bool actual_solve(int sudoku[9][9], int cell_index);

/// @brief Facade function for recursive backtracking solve function
/// @param sudoku Integer matrix for the sudoku game
/// @param x Row index
/// @param y Row index
/// @param value Value tried to be inserted
bool canBeInserted(int sudoku[9][9], int x, int y, int value);


int main() {
    int sudoku[9][9];

    char plane[81];

    // Example input from here: https://norvig.com/top95.txt
    std::cout << "Enter 81 character plane on one line: " << std::endl;
    std::cin >> plane;

    loadSudoku(sudoku, plane);

    if(solve(sudoku))
        printSudoku(sudoku);
    else
        std::cout << std::endl << "Unsolvable" << std::endl;
   
    return 0;
}

void loadSudoku(int sudoku[9][9], char plane[]) {
    for(int i = 0; i < 81; i++) {
        sudoku[i / 9][i % 9] = plane[i] == '.' ? 0 : plane[i] - '0';
    }
}

void printSudoku(int sudoku[9][9]) {
    for(int y = 0; y < 10; y++) {
        std::cout << "---"; 
    }
    for(int x = 0; x < 9; x++) {
        if(x != 0 && x % 3 == 0) {
            for(int y = 0; y < 10; y++) {
                std::cout << "---"; 
            }
        }
        std::cout << std::endl;
        for(int y = 0; y < 9; y++) {
            if(y % 3 == 0) {
                std::cout << "|";
            }
            std::cout << " " << sudoku[x][y] << " "; 
        }
        std::cout << "|" << std::endl;
    }
    for(int y = 0; y < 10; y++) {
        std::cout << "---"; 
    }
}

bool solve(int sudoku[9][9]) {
    int cell_index = 0;
    return actual_solve(sudoku, cell_index);
}

bool actual_solve(int sudoku[9][9], int cell_index) {
    if(cell_index == 81) return true;

    if(sudoku[cell_index / 9][cell_index % 9] != 0) 
        return actual_solve(sudoku, cell_index + 1);

    for (int i = 1; i <= 9; i++) {
        if(canBeInserted(sudoku, cell_index / 9, cell_index % 9, i)) {
            sudoku[cell_index / 9][cell_index % 9] = i;

            if(actual_solve(sudoku, cell_index + 1)) return true;
            sudoku[cell_index / 9][cell_index % 9] = 0;
        }
    }

    return false;
}

bool canBeInserted(int sudoku[9][9], int x, int y, int value) {
    for (int i = 0; i < 9; i++)
        if(sudoku[x][i] == value || sudoku[i][y] == value) return false;

    int box_row_index = x / 3, box_col_index = y / 3;

    for (int box_row = 3*box_row_index; box_row < 3*box_row_index + 3; box_row++)
        for (int box_col = 3*box_col_index; box_col < 3*box_col_index + 3; box_col++) 
            if(sudoku[box_row][box_col] == value) {
                
             
                return false;
            }
    
    return true;
}
