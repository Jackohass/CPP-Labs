//#pragma once

#include<type_traits>
#include<initializer_list>
#include<cmath>
#include<iostream>

/*TODO:
* Answer questions
*/

using namespace std;

template <class T>
class Matris {
public:
    // constructors
    Matris();
    explicit Matris(size_t size);
    explicit Matris(size_t cols, size_t rows);

    Matris(const Matris<T>& copyM);

    Matris(Matris<T>&& moveM);

    Matris(initializer_list<T> list);

    // deconstructor
    ~Matris();

    // operators
    void operator=(const Matris<T>& copyM);

    void operator=(Matris<T>&& moveM);

    void operator+=(size_t scalar);

    void operator+=(const Matris<T>& m);

    void operator-=(size_t scalar);

    void operator-=(const Matris<T>& m);

    void operator*=(size_t scalar);

    void operator*=(const Matris<T>& m);

    //Skapa en kopia
    Matris<T> operator-(size_t scalar) const;
    Matris<T> operator+(size_t scalar) const;

    Matris<T> operator+(const Matris<T>& m) const;

    Matris<T> operator-(const Matris<T>& m) const;

    Matris<T> operator*(size_t scalar) const;

    Matris<T> operator*(const Matris<T>& m) const;

    // 0 indexed
    T& operator()(size_t x, size_t y);
    // 0 indexed
    T& operator()(size_t x, size_t y) const;

    bool operator!=(const Matris<T>& m) const;
    bool operator==(const Matris<T>& m) const;

    // methods
    size_t rows() const;
    size_t cols() const;

    void reset();

    Matris<bool> identity(unsigned int size) const;

    // 0 indexed.
    void insert_row(int rowNumber);

    void append_row(int rowNumber);

    void remove_row(size_t rowNumber);

    void insert_column(size_t columnNumber);

    void append_column(size_t columnNumber);

    void remove_column(size_t columnNumber);

    typedef T* iterator;
    iterator begin() const;
    iterator end() const;

private:
    size_t m_rows;
    size_t m_cols;
    size_t m_capacity;
    T* m_vec;
    
    void is_Move_Constructible_And_Assignable();

    void isSameDim(const Matris<T>& m) const;

    void isMatrixMul(const Matris<T>& m) const;

    void canInsert(int index, size_t size) const;
    void canRemove(int index, size_t size) const;
    void canAppend(int index, int size) const;
};

#include"matris.cpp"
