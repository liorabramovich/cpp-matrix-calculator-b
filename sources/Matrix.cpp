#include <iostream>
#include <stdexcept>
#include "vector"
#include "Matrix.hpp"

using namespace std;
using namespace zich;

Matrix::Matrix(int rows, int cols)
{
    this->MyMatrix.resize((unsigned)rows);
    for (unsigned int i = 0; i < rows; i++)
    {
        this->MyMatrix[i].resize((unsigned)cols);
    }
}

Matrix::Matrix(vector<double> mymat, int rows, int cols)
{
    if(rows < 1 or cols <1){
        throw std::invalid_argument("rows and cols must be greater then zero");
    }
    if(rows*cols!=mymat.size()){
        throw std::invalid_argument("invalide argument");
    }

    this->MyMatrix.resize((unsigned)rows);
    for (unsigned int i = 0; i < rows; i++)
    {
        this->MyMatrix[i].resize((unsigned)cols);
    }
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            this->MyMatrix[i][j] = mymat[(double)j + i * (unsigned)cols];
        }
    }
}

Matrix Matrix::operator+()
{

    Matrix OnaryMatrix(this->MyMatrix.size(), this->MyMatrix[0].size());
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[0].size(); j++)
        {
            OnaryMatrix.MyMatrix[i][j] = (this->MyMatrix[i][j]);
        }
    }
    return OnaryMatrix;
}

Matrix& Matrix::operator++()
{
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[0].size(); j++)
        {
            this->MyMatrix[i][j]++;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix t= *this;
    ++*this;
    return t;

}

Matrix Matrix::operator+=(const Matrix &mat)
{
    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[0].size(); j++)
        {
            this->MyMatrix[i][j] += mat.MyMatrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &mat)
{

    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    Matrix OperatorPlus(this->MyMatrix.size(), this->MyMatrix[0].size());
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[i].size(); j++)
        {
            OperatorPlus.MyMatrix[i][j] = (this->MyMatrix[i][j] + mat.MyMatrix[i][j]);
        }
    }
    return OperatorPlus;
}

Matrix Matrix::operator-()
{

    std::vector<double> OnaryVector;
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[i].size(); j++)
        {
            OnaryVector.push_back(-this->MyMatrix[i][j]);
        }
    }
    return Matrix(OnaryVector, this->MyMatrix.size(), this->MyMatrix[0].size());
}

Matrix Matrix::operator-=(const Matrix &mat)
{
    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[0].size(); j++)
        {
            this->MyMatrix[i][j] -= mat.MyMatrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &mat)
{

    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    std::vector<double> PlusMatrix;
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[0].size(); j++)
        {
            PlusMatrix.push_back(this->MyMatrix[i][j] - mat.MyMatrix[i][j]);
        }
    }
    return Matrix(PlusMatrix, this->MyMatrix.size(), this->MyMatrix[0].size());
}

Matrix& Matrix::operator--()
{
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[0].size(); j++)
        {
            this->MyMatrix[i][j]--;
        }
    }
    return *this;
}

Matrix Matrix::operator--(int)
{
    Matrix t = *this;
    --*this;
    return t;
}
bool Matrix::operator==(const Matrix &mat)
{
    if (this->MyMatrix.empty() and mat.MyMatrix.empty())
    {
        return true;
    }
    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < mat.MyMatrix[0].size(); j++)
        {
            if (this->MyMatrix[i][j] != mat.MyMatrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &mat)
{
    return !(this->operator==(mat));
}

bool Matrix::operator>=(const Matrix &mat)
{
    if (this->MyMatrix.empty() and mat.MyMatrix.empty())
    {
        return true;
    }
    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    unsigned int sum = 0;
    unsigned int otherSum = 0;
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[i].size(); j++)
        {
            sum += this->MyMatrix[i][j];
        }
    }
    for (unsigned int i = 0; i < mat.MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < mat.MyMatrix[i].size(); j++)
        {
            otherSum += mat.MyMatrix[i][j];
        }
    }
    return sum >= otherSum;
}

bool Matrix::operator<=(const Matrix &mat)
{
    if (this->MyMatrix.empty() and mat.MyMatrix.empty())
    {
        return true;
    }
    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    unsigned int sum = 0;
    unsigned int otherSum = 0;
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[i].size(); j++)
        {
            sum += this->MyMatrix[i][j];
        }
    }
    for (unsigned int i = 0; i < mat.MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < mat.MyMatrix[i].size(); j++)
        {
            otherSum += mat.MyMatrix[i][j];
        }
    }
    return sum <= otherSum;
}

bool Matrix::operator>(const Matrix &mat)
{
    if (this->MyMatrix.empty() and mat.MyMatrix.empty())
    {
        return true;
    }
    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    unsigned int sum = 0;
    unsigned int otherSum = 0;
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[i].size(); j++)
        {
            sum += this->MyMatrix[i][j];
        }
    }
    for (unsigned int i = 0; i < mat.MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < mat.MyMatrix[i].size(); j++)
        {
            otherSum += mat.MyMatrix[i][j];
        }
    }
    return sum > otherSum;
}

bool Matrix::operator<(const Matrix &mat)
{
    if (this->MyMatrix.empty() and mat.MyMatrix.empty())
    {
        return true;
    }
    if (this->MyMatrix.size() != mat.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (this->MyMatrix[0].size() != mat.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    unsigned int sum = 0;
    unsigned int otherSum = 0;
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[i].size(); j++)
        {
            sum += this->MyMatrix[i][j];
        }
    }
    for (unsigned int i = 0; i < mat.MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < mat.MyMatrix[i].size(); j++)
        {
            otherSum += mat.MyMatrix[i][j];
        }
    }
    return sum < otherSum;
}


Matrix Matrix::operator*(const Matrix &toMult)
{
    // check for valid size for multiplication
    if (MyMatrix[0].size() != toMult.MyMatrix.size())
    {
        throw("undefined matrix multiplication\n");
    }

    // actual multiplication
    Matrix result(this->MyMatrix.size(), toMult.MyMatrix[0].size());
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < toMult.MyMatrix[0].size(); j++)
        {
            for (unsigned int k = 0; k < toMult.MyMatrix.size(); k++)
            {
                result.MyMatrix[i][j] += this->MyMatrix[i][k] * toMult.MyMatrix[k][j];
            }
        }
    }

    return result;
}

Matrix Matrix::operator*=(double num)
{
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < this->MyMatrix[i].size(); j++)
        {
            this->MyMatrix[i][j] *= num;
        }
    }
    return *this;
}

Matrix Matrix::operator*=(const Matrix &toMult)
{
    // check for valid size for multiplication
    if (this->MyMatrix[0].size() != toMult.MyMatrix.size())
    {
        throw logic_error("undefined matrix multiplication\n");
    }

    // actual multiplication
    Matrix result(this->MyMatrix.size(), toMult.MyMatrix[0].size());
    for (unsigned int i = 0; i < this->MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < toMult.MyMatrix[0].size(); j++)
        {
            for (unsigned int k = 0; k < this->MyMatrix[0].size(); k++)
            {
                result.MyMatrix[i][j] += this->MyMatrix[i][k] * toMult.MyMatrix[k][j];
            }
        }
    }

    this->MyMatrix=result.MyMatrix;
    return *this;
}
namespace zich
{

    bool operator==(const Matrix &matrix1 , const Matrix &matrix2){
            if (matrix1.MyMatrix.empty() and matrix2.MyMatrix.empty())
    {
        return true;
    }
    if (matrix1.MyMatrix.size() != matrix2.MyMatrix.size())
    {
        throw("cant compare matrices with different row size");
    }
    if (matrix1.MyMatrix[0].size() != matrix2.MyMatrix[0].size())
    {
        throw("cant compare matrices with different col size");
    }
    for (unsigned int i = 0; i < matrix1.MyMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < matrix1.MyMatrix[0].size(); j++)
        {
            if (matrix1.MyMatrix[i][j] != matrix2.MyMatrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
    }

    ostream &operator<<(ostream &o, const Matrix &mat)
    {
        std::string toString;
        for(unsigned int i = 0 ; i < mat.MyMatrix.size();i++){
            toString+='[';
            for(unsigned int j = 0 ; j < mat.MyMatrix[i].size();j++){

                if((int)mat.MyMatrix[i][j]==mat.MyMatrix[i][j]){
                    toString+=std::to_string((int)mat.MyMatrix[i][j]);
                }
                else{
                    toString+=std::to_string(mat.MyMatrix[i][j]);
                }
                if (j!=mat.MyMatrix[i].size()-1){
                    toString+=" ";
                }
            }
            toString+=']';
            if(i!=mat.MyMatrix.size()-1){
                toString+='\n';
            }

        }
        return o << toString;
    }

    pair<unsigned int, unsigned int> check_cin(string st) {
        if (st[0] != '[' or st[st.size()-1] != ']') {
            throw("incorrect syntax");
        }
        unsigned int comas = 0;
        unsigned int open_parentheses = 0;
        unsigned int close_parentheses = 0;
        for (int i = 0; i < st.size(); i++) {
            if (st[(unsigned int)i] == '[') {
                open_parentheses++;
                if (i + 1 < st.size() and isdigit(st[(unsigned int)i+1]) == 0 and st[(unsigned int)i] != '-') {
                    throw("incorrect syntax1");
                }
                if (i - 1 > 0 and st[(unsigned int)i-1] != ' ') {
                    throw("incorrect syntax2");
                }
                if (i - 2 > 0 and st[(unsigned int)i-2] != ',') {
                    throw("incorrect syntax3");
                }
                if (i - 3 > 0 and st[(unsigned int)i-3] != ']') {
                    throw("incorrect syntax4");
                }
            }
            if (st[(unsigned int)i] == ']') {
                close_parentheses++;
                if (i - 1 > 0 and isdigit(st[(unsigned int)i-1]) == 0) {
                    throw("incorrect syntax5");
                }
                if (i + 1 < st.size() and st[(unsigned int)i+1] != ',') {
                    throw("incorrect syntax6");
                }
                if (i + 2 < st.size() and st[(unsigned int)i+2] != ' ') {
                    throw("incorrect syntax7");
                }
                if (i + 3 < st.size() and st[(unsigned int)i+3] != '[') {
                    throw("incorrect syntax8");
                }
            }
            if (st[(unsigned int)i] == ',') {
                comas++;
                if (i - 2 > 0 and isdigit(st[(unsigned int)i-2]) == 0) {
                    throw("incorrect syntax9");
                }
                if (i - 1 > 0 and st[(unsigned int)i-1] != ']') {
                    throw("incorrect syntax10");
                }
                if (i + 1 < st.size() and st[(unsigned int)i+1] != ' ') {
                    throw("incorrect syntax11");
                }
                if (i + 2 < st.size() and st[(unsigned int)i+2] != '[') {
                    throw("incorrect syntax12");
                }
            }
        }
        if (open_parentheses != close_parentheses) {
            throw("invalid syntax");
        }
        if (open_parentheses != comas + 1) {
            throw("invalid syntax");
        }
        std::pair p(open_parentheses, comas+1);
        return p;
    }

    istream &operator>>(istream &i, Matrix &mat)
    {
        string st;
        std::getline(i, st);
        pair p = check_cin(st);
        vector<double> vec;
        unsigned int rows = p.first;
        unsigned int cols = p.second;
        string current_num_as_str;
        for (unsigned int i = 0; i < st.size(); i++) {
            if (st[i] == '.' or st[i] == '-') {
                current_num_as_str += '.';
                continue;
            }
            if (isdigit(st[i]) != 0) {
                current_num_as_str += st[i];
            } else if (!current_num_as_str.empty()){
                double current_num = stod(current_num_as_str);
                vec.push_back(current_num);
                current_num_as_str.resize(0);
            }
        }
        if (mat.MyMatrix.size() != rows) {
            mat.MyMatrix.resize(rows);
        }
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < cols; j++) {
                mat.MyMatrix[i][j] = vec[i*cols + j];
            }
        }
        return i;
    }

    Matrix operator*(double sc, const Matrix &mat1)
    {
        Matrix Multi(mat1.MyMatrix.size(), mat1.MyMatrix[0].size());
        for (unsigned int i = 0; i < mat1.MyMatrix.size(); i++)
        {
            for (unsigned int j = 0; j < mat1.MyMatrix[0].size(); j++)
            {
                Multi.MyMatrix[i][j] = sc * mat1.MyMatrix[i][j];
            }
        }

        return Multi;
    }

    Matrix operator*(const Matrix &mat1 , double sc){
        return sc * mat1;

    }

}