#include <iostream>
#include <array>
#include "matrix.hh"

int main() {
    // Example usage with std::array
    std::array<std::array<int, 2>, 3> container = {{{1, 2}, {3, 4}, {5, 6}}};
    Matrix<int, 3, 2> matrixA(container);

    // Print original matrix
    std::cout << "Original Matrix A:" << std::endl;
    matrixA.print();

    // Modify an element
    matrixA.get(1, 1) = 10;

    // Print modified matrix
    std::cout << "Modified Matrix A:" << std::endl;
    matrixA.print();

    // Transpose matrix
    Matrix<int, 2, 3> matrixB = matrixA.transpose();

    // Print transposed matrix
    std::cout << "Transpose of Matrix A (Matrix B):" << std::endl;
    matrixB.print();

    // Add two matrices
    Matrix<int, 3, 2> matrixC = matrixA.add(matrixB.transpose());

    // Print result of addition
    std::cout << "Result of Matrix A + Transpose of Matrix A:" << std::endl;
    matrixC.print();

    // Subtract two matrices
    Matrix<int, 3, 2> matrixD = matrixA.subtract(matrixB.transpose());

    // Print result of subtraction
    std::cout << "Result of Matrix A - Transpose of Matrix A:" << std::endl;
    matrixD.print();

    // Multiply matrices
    Matrix<int, 3, 3> productAB = matrixA.multiply(matrixB);

    // Print result of multiplication
    std::cout << "Product of Matrix A and Transpose of Matrix A:" << std::endl;
    productAB.print();

    return 0;
}

