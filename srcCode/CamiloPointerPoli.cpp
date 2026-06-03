/**
 * @file main.cpp
 * @brief Punto de entrada del programa.
 * @date 2026/06/01
 */

#include <iostream>

#include "MatrixOp.h"
double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}
int main() {

    //First Part
    /*
    MatrixOp A(2, 2);
    MatrixOp B(2, 2);

    MatrixOp C(2, 2);

    A.set(0, 0, 1.5);
    A.set(0, 1, 2.5);
    A.set(1, 0, 3.5);
    A.set(1, 1, 4.5);

    B.set(0, 0, 1.5);
    B.set(0, 1, 2.5);
    B.set(1, 0, 3.5);
    B.set(1, 1, 4.5);

    std::cout << A.get(0, 0) << std::endl;
    std::cout << A.get(1, 1) << std::endl;

    A.add(&B, &C);

    std::cout << "C[0,0] = " << C.get(0, 0) << std::endl;
    */

    //Second Part
    MatrixOp A(2, 2);
    MatrixOp B(2, 2);


    A.set(0, 0, 1.5);
    A.set(0, 1, 2.5);
    A.set(1, 0, 3.5);
    A.set(1, 1, 4.5);

    B.set(0, 0, 1.5);
    B.set(0, 1, 2.5);
    B.set(1, 0, 3.5);
    B.set(1, 1, 4.5);

    // Inicializa A y B con valores

    MatrixOp C = A + B;
    MatrixOp D = A - B;

    std::cout << "C[0,0] = " << C.get(0, 0) << "\n";
    std::cout << "D[1,1] = " << D.get(1, 1) << "\n";

    double maxElem = maxValue<double>(A.data(), A.size());
    std::cout << "Máximo elemento de A: " << maxElem << "\n";

    MatrixOp M(2, 2);
    M.set(0, 0, 1);
    M.set(0, 1, 2);
    M.set(1, 0, 3);
    M.set(1, 1, 4);

    IMatrix* mat = &M;
    std::cout << "Determinante: " << mat->determinant() << "\n";

   

}
