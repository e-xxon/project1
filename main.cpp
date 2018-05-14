#include <iostream>

using namespace std;

class matrix
{
private:
    long int n;
    long int m;
    long int** matr;
    void crmatr()
    {
        matr = new long int*[m];
        for (int i = 0; i < m; i++)
            matr[i] = new long int[n];
    }

public:
    friend ostream& operator<<(ostream& str, const matrix comp);
    friend istream& operator>>(istream& str, const matrix comp);
    // constructor
    matrix()
        : m(5)
        , n(5)
    {
        crmatr();
    }
    matrix(long int i)
        : m(i)
        , n(i)
    {
        crmatr();
    }
    matrix(long int i, long int j)
        : m(i)
        , n(j)
    {
        crmatr();
    }
    // destructor
    ~matrix()
    {
        for (int column = 0; column < m; column++)
            delete[] matr[column];
        delete[] matr;
    }
    void get()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matr[i][j];
    }
    matrix operator+(matrix comp)
    {
        matrix result(comp.n, comp.m);
        if (this->n == comp.n && this->m == comp.m)
        {
            for (int i = 0; i < comp.n; i++)
                for (int j = 0; j < comp.m; j++)
                    result.matr[i][j] = comp.matr[i][j] + this->matr[i][j];
        }
        else
            throw;
    }
    matrix operator+(int a)
    {
        matrix result(this->n, this->m);
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                result.matr[i][j] = this->matr[i][j] + a;
        return result;
    }

    matrix operator-(matrix comp)
    {
        matrix result(comp.n, comp.m);
        if (this->n == comp.n && this->m == comp.m)
        {
            for (int i = 0; i < comp.n; i++)
                for (int j = 0; j < comp.m; j++)
                    result.matr[i][j] = comp.matr[i][j] - this->matr[i][j];
        }
        throw;
    }
    matrix operator-(int a)
    {
        matrix result(this->n, this->m);
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                result.matr[i][j] = this->matr[i][j] - a;
        return result;
    }

    matrix operator*(int a)
    {
        matrix result(this->n, this->m);
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                result.matr[i][j] = this->matr[i][j] * a;
    }

    matrix& operator+=(int a)
    {
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                this->matr[i][j] = this->matr[i][j] + a;
        return *this;
    }
    matrix& operator-=(int a)
    {
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                this->matr[i][j] = this->matr[i][j] - a;
        return *this;
    }
    matrix& operator*=(int a)
    {
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                this->matr[i][j] = this->matr[i][j] * a;
        return *this;
    }

    matrix operator=(matrix comp)
    {
        matrix result(comp.n, comp.m);
        for (int i = 0; i < comp.n; i++)
            for (int j = 0; j < comp.m; j++)
                result.matr[i][j] = comp.matr[i][j];

        for (int i = 0; i < this->n; i++)
        {
            delete (this->matr[i]);
        }
        delete (this->matr);
        this->n = comp.n;
        this->m = comp.m;
        this->matr = result.matr;
        return *this;
    }

    int operator()(int a, int b)
    {
        if (a <= this->n && b <= this->m)
            return this->matr[a][b];
        else
            throw;
    }

    matrix trans()
    {
        matrix result(this->n, this->m);
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                result.matr[i][j] = this->matr[j][i];
        return result;
    }

    matrix atod(matrix comp)
    {
        matrix result(this->n, comp.m);
        if (this->m == comp.n)
        {
            for (int i = 0; i < this->n; i++)
                for (int j = 0; j < comp.m; j++)
                    for (int k = 0; k < comp.n; k++)
                    {
                        result.matr[i][j] += this->matr[i][k] * comp.matr[k][j];
                    }
            return result;
        }
        else
            throw;
    }
};

istream& operator>>(istream& is, matrix comp)
{
    for (int i = 0; i < comp.n; i++)
        for (int j = 0; j < comp.n; j++)
            is >> comp.matr[i][j];
}
ostream& operator<<(ostream& str, matrix comp)
{
    for (int i = 0; i < comp.n; i++)
    {
        for (int j = 0; j < comp.m; j++)
        {
            str << comp.matr[i][j] << " ";
        }
    }
    str << endl;
}

int main()
{
    return 0;
}
