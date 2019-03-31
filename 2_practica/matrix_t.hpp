#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include "vector_t.hpp"

using namespace std;

template <class T>
class matrix_t
{
private:
        int m_;
        int n_;

        vector_t<T> v_;

public:
        matrix_t(void):
        m_(0),
        n_(0),
        v_() {}

        matrix_t(int m, int n):
        m_(m),
        n_(n),
        v_(m * n) {}

        ~matrix_t(void)
        {}

        void resize(int m, int n)
        {
            v_.resize(m * n);
            m_ = m; n_ = n;
        }

        T& at (int i, int j)
        {
            return v_.at(pos(i,j));
        }

        const T& at (int i, int j) const
        {
            return v_.at(pos(i,j));
        }

        T& operator()(int i, int j)
        {
            return at(i,j);
        }

        const T& operator()(int i, int j) const
        {
            return at(i,j);
        }

        int get_m(void) const
        {
            return m_;
        }

        int get_n(void) const
        {
            return n_;
        }

        void write(ostream& os) const
        {

             for(int i = 1; i <= m_; i++){
                 for(int j = 1; j <= n_; j++)
                          os << at(i, j) << "  ";

                os << endl;
             }
        }

        void multiply(const matrix_t& A, const matrix_t& B)
        {
          if(A.get_n()==B.get_m())
          {
            resize(A.get_m(),B.get_n());

            for (int i = 1; i <= A.get_m(); i++)
              for (int j = 1; j <= B.get_n(); j++) {
                at(i,j) = 0;
                for (int k = 1; k <= A.get_n(); k++)
                  at(i,j) = at(i,j) + A(i,k) * B(k,j);
              }
          }
        }

//Modificacion
  T mod(void)
  {
    T aux;
    for (int i = 1; i <= get_m(); i++)
    {
      for (int j = 1; j <= get_n(); j++)
      {
        if(i%2==0)
          aux=aux+at(i,j);
        else
          aux=aux-at(i,j);
      }
    }
    return aux;
  }

private:

        int pos(int i, int j) const
        {
            return (i -1)* n_ + j - 1;
        }
};
