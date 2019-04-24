#pragma once

#include <iostream>

#include "vector_t.hpp"
#include "matrix_t.hpp"
#include "dll_node_t.hpp"
#include "dll_t.hpp"
#include "pair_t.hpp"
#include "rational_t.hpp"

enum CONF
{
  COL_CONF,
  ROW_CONF
};

class sparse_matrix_t
{
private:
  int m_, n_;
  CONF conf_;
  vector_t<dll_t<pair_t<rational_t>>> matriz_;
  double eps_;

public:
  sparse_matrix_t(const matrix_t<rational_t> &mat, double eps, CONF op) : m_(mat.get_m()),
                                                                          n_(mat.get_n()),
                                                                          conf_(op),
                                                                          eps_(eps)
  {
    dll_node_t<pair_t<rational_t>> *aux;
    pair_t<rational_t> par;

    if (conf_ != COL_CONF)
    {
      matriz_.resize(n_);
      for (int i = m_; i > 0; --i)
        for (int j = n_; j > 0; --j)
          if (!mat(i, j).zero(eps_))
          {
            par.set(i, mat(i, j));
            aux = new dll_node_t<pair_t<rational_t>>;
            aux->set_data(par);
            matriz_[j - 1].insert_head(aux);
          }
    }
    else if (conf_ != ROW_CONF)
    {
      matriz_.resize(m_);
      for (int i = m_; i > 0; --i)
        for (int j = n_; j > 0; --j)
          if (!mat(i, j).zero(eps_))
          {
            par.set(j, mat(i, j));
            aux = new dll_node_t<pair_t<rational_t>>;
            aux->set_data(par);
            matriz_[i - 1].insert_head(aux);
          }
    }
  };
  ~sparse_matrix_t(){};

  ostream &write(ostream &os)
  {
    for (int i = 0; i < matriz_.size(); ++i)
    {
      os << i << ": ";
      matriz_[i].write(os);
      os << endl;
    }
    return os;
  }

  void mult(const matrix_t<rational_t> &mat, matrix_t<rational_t> &res)
  {
    assert(n_ == mat.get_m());

    res.resize(m_, mat.get_n());
    for (int i = 1; i <= matriz_.size(); i++)
    {
      for (int j = 1; j < mat.get_n(); j++)
      {
        dll_node_t<pair_t<rational_t>> *aux = matriz_[i-1].head();
        while (aux != NULL)
        {
          res(i, j) = res(i, j) + aux->get_data().get_val() * mat(aux->get_data().get_inx(), j);
          aux = aux->get_next();
        }
      }
    }
  }
};

ostream &operator<<(ostream &os, const pair_t<rational_t> &a)
{
  a.write(os);
  return os;
}
