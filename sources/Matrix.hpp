#include <iostream>
#include "vector"
namespace zich
{

    class Matrix
    {
    private:


    public:
        std::vector<std::vector<double>> MyMatrix;
        Matrix(int , int);
        Matrix();
        Matrix(std::vector<double>, int rows, int cols);

        Matrix operator+();
        Matrix operator+=(const Matrix &);
        Matrix operator+(const Matrix &);
        Matrix& operator++();
        Matrix operator++(int);

        Matrix operator-();
        Matrix operator-=(const Matrix &);
        Matrix operator-(const Matrix &);
        Matrix& operator--();
        Matrix operator--(int);

        bool operator==(const Matrix &);
        bool operator!=(const Matrix &);
        bool operator<=(const Matrix &);
        bool operator>=(const Matrix &);
        bool operator>(const Matrix &);
        bool operator<(const Matrix &);

        Matrix operator*(const Matrix &);
        Matrix operator*=(double);
        Matrix operator*=(const Matrix &);

        friend bool operator==(const Matrix & , const Matrix&);
        friend Matrix operator*(double, const Matrix &);
        friend Matrix operator*(const Matrix &, double);
        friend std::ostream &operator<<(std::ostream &o, const Matrix &);
        friend std::istream &operator>>(std::istream &i,  Matrix &);
    };

}