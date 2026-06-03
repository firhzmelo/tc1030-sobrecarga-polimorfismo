#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

/**
 * @file MatrixOp.h
 * @brief Definición de MatrixOp.h.
 * @date 2026/06/01
 * @author Javier Lopez
 */

#pragma once

#include <iostream>
#include <string>


class IMatrix {
public:
    virtual ~IMatrix() = default;
    virtual double determinant() const = 0;
};

class MatrixOp : public IMatrix {
private:
    int rows_;
    int cols_;
    double* data_;

public:
    MatrixOp(int, int);
    ~MatrixOp();

    MatrixOp operator+(const MatrixOp& other) const;
    MatrixOp operator-(const MatrixOp& other) const;


    //Abstract
    double determinant() const override;







    void doSomething() const;

    void set(int, int, double);
    double get(int, int) const;

    void add(const MatrixOp*, MatrixOp*) const;

    void forEachDiagonal(void (MatrixOp::* fn)(int i, int j)) const;
    void printAt(int i, int j) const;

    using OpFunc = double(*)(double, double);



    void apply(const MatrixOp* A,
        const MatrixOp* B,
        MatrixOp* out,
        OpFunc op) const;

    void print() const;

    const double* data() const {
        return data_;
    }

    int size() const {
        return rows_ * cols_;
    }
};
/*template<typename T>
T maxValue(const T* arr, int n);
*/
template <typename T>
T maxValue(const T* arr, int n) {

    if (arr == nullptr) {
        throw std::invalid_argument("El arreglo es nullptr");
    }


    if (n <= 0) {
        throw std::invalid_argument("El tamaño debe ser mayor que 0");
    }


    T max = arr[0];


    for (int i = 1; i < n; i++) {

        if (arr[i] > max) {
            max = arr[i];
        }
    }


    return max;
}



#endif  // TEMPLATECLASS_H
