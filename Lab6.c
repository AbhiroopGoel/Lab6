#include <iostream>
#include <fstream>
#include <iomanip>

const int N = 3; 

// Function to read values from a file into a matrix
void readMatrixFromFile(int matrix[N][N], const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    int size;
    file >> size; // Read matrix size from the first line
    if (size != N) {
        std::cerr << "Invalid matrix size." << std::endl;
        return;
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> matrix[i][j];

    file.close();
}

// Function to print a matrix
void printMatrix(const int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and place the result in a third matrix
void addMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

// Function to multiply two matrices and place the result in a third matrix
void multiplyMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
}

// Function to subtract the second matrix from the first matrix and place the result in a third matrix
void subtractMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

// Function to update an element of the first matrix
void updateElement(int matrix[N][N], int row, int col, int newValue) {
    if (row >= 0 && row < N && col >= 0 && col < N)
        matrix[row][col] = newValue;
    else
        std::cerr << "Invalid row or column." << std::endl;
}

// Function to get the max value of the first matrix
int getMaxValue(const int matrix[N][N]) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (matrix[i][j] > maxVal)
                maxVal = matrix[i][j];
    return maxVal;
}

// Function to transpose the first matrix
void transposeMatrix(const int matrix[N][N], int transposed[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            transposed[j][i] = matrix[i][j];
}

int main() {
    int matrix1[N][N];
    int matrix2[N][N];
    int result[N][N];

    // Read matrices from file
    readMatrixFromFile(matrix1, "matrix_input.txt");
    readMatrixFromFile(matrix2, "matrix_input.txt");

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1);

    std::cout << "Matrix 2:" << std::endl;
    printMatrix(matrix2);

    // Perform operations
    addMatrices(matrix1, matrix2, result);
    std::cout << "Addition result:" << std::endl;
    printMatrix(result);

    multiplyMatrices(matrix1, matrix2, result);
    std::cout << "Multiplication result:" << std::endl;
    printMatrix(result);

    subtractMatrices(matrix1, matrix2, result);
    std::cout << "Subtraction result:" << std::endl;
    printMatrix(result);

    updateElement(matrix1, 1, 1, 99);
    std::cout << "Updated Matrix 1:" << std::endl;
    printMatrix(matrix1);

    std::cout << "Max value of Matrix 1: " << getMaxValue(matrix1) << std::endl;

    int transposed[N][N];
    transposeMatrix(matrix1, transposed);
    std::cout << "Transposed Matrix 1:" << std::endl;
    printMatrix(transposed);

    return 0;
}

