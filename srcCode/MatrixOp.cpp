/**
 * @file MatrixOp.cpp
 * @brief Implementación de MatrixOp.h.
 * @date 2026/06/01
 */

#include "MatrixOp.h"

#include <iostream>

MatrixOp::MatrixOp(int rows, int colums) {
    rows_ = rows;
    cols_ = colums;

    data_ = (new double[rows_ * cols_]);
}

MatrixOp::~MatrixOp() {
    delete[] data_;
    data_ = nullptr;
}


MatrixOp MatrixOp::operator+(const MatrixOp& other) const {

    MatrixOp copy(rows_,cols_);

    

    for (int i = 0;i < rows_ * cols_;i++) {

        copy.data_[i] = this->data_[i] + other.data_[i];


    }


    return  copy;


}
MatrixOp MatrixOp::operator-(const MatrixOp& other) const {

    MatrixOp copy(rows_, cols_);



    for (int i = 0;i < rows_ * cols_;i++) {

        copy.data_[i] = this->data_[i] - other.data_[i];


    }


    return  copy;


    
}
void MatrixOp::printAt(int i, int j) const {

    std::cout << data_[i * cols_ + j];

}

void MatrixOp::forEachDiagonal(void (MatrixOp::* fn)(int i, int j)) const {

    for (int i = 0;i++;i < (std::min(rows_, cols_))) {

        printAt(i, i);

    }



}





void MatrixOp::doSomething() const {
    std::cout << "Doing something, data_=" << data_ << std::endl;
}

void MatrixOp::set(int i, int j, double num) {
    if ((i < 0 or i >= cols_) or (j < 0 or j >= rows_)) {
        throw std::out_of_range("Índice fuera de rango");
    }
    else {
        data_[i * cols_ + j] = num;
    }

    /*  [1 2 3 4]
        [4 5 6 2]
        [7 8 9 6]
    */
}
double MatrixOp::get(int i, int j) const { return data_[i * cols_ + j]; }

void MatrixOp::add(const MatrixOp* other, MatrixOp* result) const {

    if ((other == nullptr) or (result == nullptr)) { throw std::invalid_argument("Puntero nulo recibido"); }
    if ((this->rows_ != other->rows_) or (this->cols_ != other->cols_)) { throw std::invalid_argument("Dimensiones incompatibles"); }

    for (int i = 0;i < rows_ * cols_;i++) {

        result->data_[i] = this->data_[i] + other->data_[i];


    }

}



void MatrixOp::apply(const MatrixOp* A,
    const MatrixOp* B,
    MatrixOp* out,
    OpFunc op) const {
    if (A == nullptr || B == nullptr || out == nullptr) {
        throw std::invalid_argument("Puntero nulo recibido");
    }

    if (A->rows_ != B->rows_ || A->cols_ != B->cols_) {
        throw std::invalid_argument("Dimensiones incompatibles");
    }

    if (out->rows_ != A->rows_ || out->cols_ != A->cols_) {
        throw std::invalid_argument("Out y A tienen diferentes dimensiones");
    }


    for (int i = 0;i < rows_ * cols_;i++) {
        out->data_[i] = op(A->data_[i], B->data_[i]);

    }


}

void MatrixOp::print() const {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            std::cout << data_[i * cols_ + j] << " ";
        }
        std::cout << std::endl;
    }
}


double MatrixOp::determinant() const {

    if (rows_ != cols_) {
        throw std::invalid_argument("Matrix must be square");
    }

   
    if (rows_ == 2) {
        return data_[0] * data_[3]
            - data_[1] * data_[2];
    }

   
    if (rows_ == 3) {
        return
            data_[0] * (data_[4] * data_[8] - data_[5] * data_[7])
            - data_[1] * (data_[3] * data_[8] - data_[5] * data_[6])
            + data_[2] * (data_[3] * data_[7] - data_[4] * data_[6]);
    }

    throw std::invalid_argument("Determinant only implemented for 2x2 and 3x3");
}