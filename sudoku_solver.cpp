#include <vector>
#include <iostream>

using namespace std;

bool isZero(int grid[9][9], int& row, int& col){
    for (row=0; row < 9; row++){
        for (col = 0; col < 9; col++){
            if (grid[row][col] == 0){
                return true;
            }
        }
    }return false;
}

bool colCheck(int grid[9][9], int col, int num){
    for (int row = 0; row < 9; row++){
        if (grid[row][col] == num){
            return true;
        }
    }return false;
}

bool rowCheck(int grid[9][9], int row, int num){
    for (int col = 0; col < 9; col++){
        if (grid[row][col] == num){
            return true;
        }
    }return false;
}

bool boxCheck(int grid[9][9], int xbox, int ybox, int num){
    for (int i = xbox*3; i < xbox*3+3; i++){
        for (int j = ybox*3; j < ybox*3+3; j++){
            if (grid[i][j] == num){
                return true;
            }
        }
    }return false;
}

bool isOk(int grid[9][9], int row, int col, int num){
    return grid[row][col] == 0
    && !boxCheck(grid, row/3, col/3, num)
    && !colCheck(grid, col, num)
    && !rowCheck(grid, row, num);
}

bool solver(int grid[9][9]){
    int row, col;
    if (!isZero(grid, row, col)){
        return true;
    }
    for (int num = 1; num <=9; num++){
        if (isOk(grid, row, col, num)){
            grid[row][col] = num;
            if (solver(grid)){
                return true;
            }grid[row][col] = 0;
        }
    }return false;
}


void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++) 
    {
        for (int col = 0; col < 9; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

// Driver Code
int main()
{
    // 0 means unassigned cells
    int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    if (solver(grid) == true)
        printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
