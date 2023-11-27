#include <iostream>
#include <random>

void inicialization(int** matrix, int rows, int cols);
void filling(int** matrix, int rows, int cols);
void print(int** matrix, int rows, int cols);
void max_in_row(int** matrix, int rows ,int cols, int row_number);
int min_in_col(int** matrix, int rows, int cols, int col_number);
void min_in_row(int** matrix, int rows, int cols, int row_number);
int max_in_col(int** matrix, int rows, int cols, int col_number);
void find_sandle_point(int** matrix, int rows, int cols);
void clear_memory(int** matrix, int rows);

int main()
{
    srand(time(NULL));
    int n,m;
    std::cin >> n >> m;
    int** matrix = new int* [n];
    inicialization(matrix, n, m);
    filling(matrix, n, m);
    print(matrix, n,m);
    find_sandle_point(matrix, n, m);
    clear_memory(matrix, n);
}

void inicialization(int** matrix , int rows,int cols) {
    for (int i = 0; i < rows;i++) {
        matrix[i] = new int[cols];
    }
}

void filling(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand()%100;
        }
    }
}

void print(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void max_in_row(int** matrix, int rows, int cols, int row_number) {
    int col = 0;
    int max = matrix[row_number][0];
    for (int i = 0; i < cols; i++) {
        if (max < matrix[row_number][i]) {
            max = matrix[row_number][i];
            col = i;
        }
    }
    if (max == min_in_col(matrix, rows, cols, col)) {
        std::cout << row_number << " " << col<<std::endl;
    }
}

int min_in_col(int** matrix, int rows, int cols, int col_number) {
    int min = matrix[0][col_number];
    for (int i = 0; i < rows; i++) {
        if (min > matrix[i][col_number]) {
            min = matrix[i][col_number];
        }
    }
    return min;
}

void min_in_row(int** matrix, int rows, int cols, int row_number) {
    int col = 0;
    int min = matrix[row_number][0];
    for (int i = 0; i < cols; i++) {
        if (min > matrix[row_number][i]) {
            min = matrix[row_number][i];
            col = i;
        }
    }
    if (min == max_in_col(matrix, rows, cols, col)) {
        std::cout << row_number << " " << col << std::endl;
    } 
}
int max_in_col(int** matrix, int rows, int cols, int col_number) {
    int max = matrix[0][col_number];
    for (int i = 0; i < rows; i++) {
        if (max < matrix[i][col_number]) {
            max = matrix[i][col_number];
        }
    }
    return max;
}

void find_sandle_point(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        max_in_row(matrix, rows, cols, i);
        min_in_row(matrix, rows, cols, i);
    }
}

void clear_memory(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
}