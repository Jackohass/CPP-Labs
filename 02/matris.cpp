// constructors
template<class T>
Matris<T>::Matris() : Matris(0) {}
template<class T>
Matris<T>::Matris(size_t size) : Matris(size, size) {}
template<class T>
Matris<T>::Matris(size_t cols, size_t rows)
{
    is_Move_Constructible_And_Assignable();
    m_rows = rows;
    m_cols = cols;
    m_capacity = m_rows*m_cols;
    m_vec = new T[m_capacity]();
}

template<class T>
Matris<T>::Matris(const Matris<T>& copyM)
{
    m_rows = copyM.m_rows;
    m_cols = copyM.m_cols;
    m_capacity = m_rows*m_cols;
    m_vec = new T[m_capacity];
    for (size_t i = 0; i < m_capacity; i++)
    {
        m_vec[i] = copyM.m_vec[i];
    }
    
}

template<class T>
Matris<T>::Matris(Matris<T>&& moveM)
    :m_rows{moveM.m_rows}, m_cols{moveM.m_cols}, m_capacity{moveM.m_capacity}, m_vec{moveM.m_vec}
{ 
    moveM.m_rows = 0;
    moveM.m_cols = 0;
    moveM.m_capacity = 0;
    moveM.m_vec = nullptr;
}

template<class T>
Matris<T>::Matris(initializer_list<T> list)
{
    size_t numElems = sqrt(list.size());
    if(numElems%2 != 0) throw out_of_range("The lists size is not an even square root");
    
    m_rows = numElems;
    m_cols = numElems;
    m_capacity = m_rows*m_cols;
    m_vec = new T[m_capacity];
    for (size_t i = 0; i < list.size(); i++)
    {
        m_vec[i] = list.begin()[i];
    }
}

// deconstructor
template<class T>
Matris<T>::~Matris()
{
    delete[] m_vec;
}

// operators
template<class T>
void Matris<T>::operator=(const Matris<T>& copyM)
{
    if(this == &copyM) return;

    T* tmp = new T[copyM.m_capacity];
    for (size_t i = 0; i < copyM.m_capacity; i++)
    {
        tmp[i] = copyM.m_vec[i];
    }
    delete[] m_vec;
    m_vec = tmp;
    m_rows = copyM.m_rows;
    m_cols = copyM.m_cols;
    m_capacity = m_rows*m_cols;
}

template<class T>
void Matris<T>::operator=(Matris<T>&& moveM)
{
    if(this == &moveM) return;

    m_rows = moveM.m_rows;
    m_cols = moveM.m_cols;
    m_capacity = moveM.m_capacity;
    delete[] m_vec;
    m_vec = moveM.m_vec;

    moveM.m_rows = 0;
    moveM.m_cols = 0;
    moveM.m_capacity = 0;
    moveM.m_vec = nullptr;
}

template<class T>
void Matris<T>::operator+=(size_t scalar)
{
    for (size_t i = 0; i < m_capacity; i++)
    {
        m_vec[i] += scalar;
    }
}

template<class T>
void Matris<T>::operator+=(const Matris<T>& m)
{
    isSameDim(m);
    for (size_t i = 0; i < m_capacity; i++)
    {
        m_vec[i] += m.m_vec[i];
    }
}

template<class T>
void Matris<T>::operator-=(size_t scalar)
{
    for (size_t i = 0; i < m_capacity; i++)
    {
        m_vec[i] -= scalar;
    }
}

template<class T>
void Matris<T>::operator-=(const Matris<T>& m)
{
    isSameDim(m);
    for (size_t i = 0; i < m_capacity; i++)
    {
        m_vec[i] -= m.m_vec[i];
    }
}

template<class T>
void Matris<T>::operator*=(size_t scalar)
{
    for (size_t i = 0; i < m_capacity; i++)
    {
        m_vec[i] *= scalar;
    }
}

template<class T>
void Matris<T>::operator*=(const Matris<T>& m)
{
    isMatrixMul(m);
    int tmpCap = m_rows*m.m_cols;
    T* tmp = new T[tmpCap];
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m.m_cols; j++)
        {
            size_t sum = 0;
            for (size_t k = 0; k < m_cols; k++)
            {
                sum += (*this)(k,i) * m(j,k);
            }
            tmp[j+i*m.m_cols] = sum;
        }
    }
    m_rows = m_rows;
    m_cols = m.m_cols;
    m_capacity = tmpCap;
    delete[] m_vec;
    m_vec = tmp;
}

template<class T>
Matris<T> Matris<T>::operator-(size_t scalar) const {return operator+(-scalar);}
template<class T>
Matris<T> Matris<T>::operator+(size_t scalar) const
{
    Matris<T> ret(m_cols, m_rows);
    for (size_t i = 0; i < m_capacity; i++)
    {
        ret.m_vec[i] = m_vec[i] + scalar;
    }
    return move(ret);
}

template<class T>
Matris<T> Matris<T>::operator+(const Matris<T>& m) const
{
    isSameDim(m);
    Matris<T> ret(m_cols, m_rows);
    for (size_t i = 0; i < m_capacity; i++)
    {
        ret.m_vec[i] = m_vec[i] + m.m_vec[i];
    }
    return move(ret);
}

template<class T>
Matris<T> Matris<T>::operator-(const Matris<T>& m) const
{
    isSameDim(m);
    Matris<T> ret(m_cols, m_rows);
    for (size_t i = 0; i < m_capacity; i++)
    {
        ret.m_vec[i] = m_vec[i] - m.m_vec[i];
    }
    return move(ret);
}

template<class T>
Matris<T> Matris<T>::operator*(size_t scalar) const
{
    Matris<T> ret(m_cols, m_rows);
    for (size_t i = 0; i < m_capacity; i++)
    {
        ret.m_vec[i] = m_vec[i] * scalar;
    }
    return move(ret);
}

template<class T>
Matris<T> Matris<T>::operator*(const Matris<T>& m) const
{
    isMatrixMul(m);
    Matris<T> tmp(m.m_cols, m_rows);
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m.m_cols; j++)
        {
            size_t sum = 0;
            for (size_t k = 0; k < m_cols; k++)
            {
                sum += (*this)(k,i) * m(j,k);
            }
            tmp(j,i) = sum;
        }
    }
    return move(tmp);
}

// 0 indexed
template<class T>
T& Matris<T>::operator()(size_t x, size_t y)
{
    if(x > m_cols-1 || y > m_rows-1) throw out_of_range("x or y position is out of the range.");
    return m_vec[x+y*m_cols];
}
// 0 indexed
template<class T>
T& Matris<T>::operator()(size_t x, size_t y) const
{
    if(x > m_cols-1 || y > m_rows-1) throw out_of_range("x or y position is out of the range.");
    return m_vec[x+y*m_cols];
}

template<class T>
bool Matris<T>::operator!=(const Matris<T>& m) const {return !(*this == m);}
template<class T>
bool Matris<T>::operator==(const Matris<T>& m) const
{
    if(m_cols != m.m_cols) return false;
    if(m_rows != m.m_rows) return false;
    for (size_t i = 0; i < m_capacity; i++)
    {
        if(m_vec[i] != m.m_vec[i]) return false;
    }
    return true;
}

// methods
template<class T>
size_t Matris<T>::rows() const {return m_rows;}
template<class T>
size_t Matris<T>::cols() const {return m_cols;}

template<class T>
void Matris<T>::reset()
{
    for (size_t i = 0; i < m_capacity; i++)
    {
        m_vec[i] = T();
    }
}

template<class T>
Matris<bool> Matris<T>::identity(unsigned int size) const
{
    Matris<bool> ret(size);
    for (unsigned int i = 0; i < size; i++)
    {
        ret(i,i) = 1;
    }
    return move(ret);
}

// 0 indexed.
template<class T>
void Matris<T>::insert_row(int rowNumber)
{
    canInsert(rowNumber, m_rows);
    size_t new_rows = m_rows + 1;
    size_t new_capacity = m_cols*new_rows;
    T* newV = new T[new_capacity]();
    
    size_t newI = 0, oldI = 0;
    for (; oldI < (rowNumber-1)*m_cols;)
    {
        newV[oldI] = m_vec[oldI];
        oldI++;
        newI++;
    }
    newI += m_cols;
    for (; oldI < m_capacity;)
    {
        newV[newI] = m_vec[oldI];
        oldI++;
        newI++;
    }
    delete[] m_vec;
    m_vec = newV;
    m_rows = new_rows;
    m_capacity = new_capacity;
}

template<class T>
void Matris<T>::append_row(int rowNumber)
{
    canAppend(rowNumber, m_rows);
    size_t new_rows = m_rows + 1;
    size_t new_capacity = m_cols*new_rows;
    T* newV = new T[new_capacity]();
    
    size_t newI = 0, oldI = 0;
    for (; oldI < (rowNumber+1)*m_cols;)
    {
        newV[oldI] = m_vec[oldI];
        oldI++;
        newI++;
    }
    newI += m_cols;
    for (; oldI < m_capacity;)
    {
        newV[newI] = m_vec[oldI];
        oldI++;
        newI++;
    }
    delete[] m_vec;
    m_vec = newV;
    m_rows = new_rows;
    m_capacity = new_capacity;
}

template<class T>
void Matris<T>::remove_row(size_t rowNumber)
{
    canRemove(rowNumber, m_rows);
    size_t new_rows = m_rows - 1;
    size_t new_capacity = m_cols*new_rows;
    T* newV = new T[new_capacity]();
    
    size_t newI = 0, oldI = 0;
    for (; oldI < rowNumber*m_cols;)
    {
        newV[oldI] = m_vec[oldI];
        oldI++;
        newI++;
    }
    oldI += m_cols;
    for (; oldI < m_capacity;)
    {
        newV[newI] = m_vec[oldI];
        oldI++;
        newI++;
    }
    delete[] m_vec;
    m_vec = newV;
    m_rows = new_rows;
    m_capacity = new_capacity;
}

template<class T>
void Matris<T>::insert_column(size_t columnNumber)
{
    canInsert(columnNumber, m_cols);
    size_t new_cols = m_cols + 1;
    size_t new_capacity = new_cols*m_rows;
    T* newV = new T[new_capacity]();

    size_t newI = 0, oldI = 0;
    for (; oldI < m_capacity;)
    {
        if(newI%(new_cols) == columnNumber-1)
        {
            newI++;
        }
        else
        {
            newV[newI] = m_vec[oldI];
            newI++;
            oldI++;
        }
    }
    delete[] m_vec;
    m_vec = newV;
    m_cols = new_cols;
    m_capacity = new_capacity;
}

template<class T>
void Matris<T>::append_column(size_t columnNumber)
{
    canAppend(columnNumber, m_cols);
    size_t new_cols = m_cols + 1;
    size_t new_capacity = new_cols*m_rows;
    T* newV = new T[new_capacity]();

    size_t newI = 0, oldI = 0;
    for (; oldI < m_capacity;)
    {
        if(newI%(new_cols) == columnNumber+1)
        {
            newI++;
        }
        else
        {
            newV[newI] = m_vec[oldI];
            newI++;
            oldI++;
        }
    }
    delete[] m_vec;
    m_vec = newV;
    m_cols = new_cols;
    m_capacity = new_capacity;
}

template<class T>
void Matris<T>::remove_column(size_t columnNumber)
{
    canRemove(columnNumber, m_cols);
    size_t new_cols = m_cols - 1;
    size_t new_capacity = new_cols*m_rows;
    T* newV = new T[new_capacity]();

    size_t newI = 0, oldI = 0;
    for (; oldI < m_capacity;)
    {
        if(oldI%(m_cols) == columnNumber)
        {
            oldI++;
        }
        else
        {
            newV[newI] = m_vec[oldI];
            newI++;
            oldI++;
        }
    }
    delete[] m_vec;
    m_vec = newV;
    m_cols = new_cols;
    m_capacity = new_capacity;
}

template<class T>
typename Matris<T>::iterator Matris<T>::begin() const { return m_vec;}
template<class T>
typename Matris<T>::iterator Matris<T>::end() const { return m_vec+m_capacity-1;}

template<class T>
void Matris<T>::is_Move_Constructible_And_Assignable()
{
    static_assert(is_move_constructible<T>::value, "The type must be move constructible\n");
    static_assert(is_move_assignable<T>::value, "The type must be move assignable\n");
}

template<class T>
void Matris<T>::isSameDim(const Matris<T>& m) const
{
    if(m_cols != m.m_cols || m_rows != m.m_rows) throw out_of_range("The dimensions must be the same.");
}

template<class T>
void Matris<T>::isMatrixMul(const Matris<T>& m) const
{
    if(m_cols != m.m_rows) throw out_of_range("Left matrix number of coloumns must the same as right matrix number of rows.");
}

template<class T>
void Matris<T>::canInsert(int index, size_t size) const
{
    if(index < 1 || index > size+1) throw out_of_range("Can't insert on that number");
}
template<class T>
void Matris<T>::canRemove(int index, size_t size) const
{
    if(index < 0 || index > size-1) throw out_of_range("Can't remove that number");
}
template<class T>
void Matris<T>::canAppend(int index, int size) const
{
    if(index < -1 || index > size-1) throw out_of_range("Can't append on that number");
}

template <class T>
ostream& operator<<(ostream& os, const Matris<T>& m)
{
    os << m.cols() << " " << m.rows() << endl;
    for (size_t i = 0; i < m.rows(); i++)
    {
        for (size_t j = 0; j < m.cols(); j++)
        {
            os << m(j,i) << " ";
        }
        os << "\n";
    }
    return os;
};

template <class T>
istream& operator>>(istream& is, Matris<T>& m)
{
    size_t cols, rows;
    is >> cols >> rows;
    Matris<T> ret(cols, rows);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            T elem;
            is >> elem;
            ret(j,i) = elem;
        }
    }
    m = move(ret);
    return is;
};
