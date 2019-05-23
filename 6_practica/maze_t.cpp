#include "maze_t.hpp"

bool maze_t::solve()
{
  return solve(i_start_, j_start_);
}

istream &maze_t::read(istream &is)
{
  int m, n;
  is >> m >> n;
  assert(m != 0 && n != 0);

  matrix_.resize(m, n);
  visited_.resize(m, n);

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      short s;
      is >> s;
      if (s == START_ID)
      {
        i_start_ = i, j_start_ = j;
      }
      else if (s == END_ID)
      {
        i_end_ = i, j_end_ = j;
      }
      matrix_(i, j) = s;
    }
  }
  assert(i_start_ != -1 && j_start_ != -1 && i_end_ != -1 && j_end_ != -1);
  return is;
}

ostream &maze_t::write(ostream &os) const
{
  os << matrix_.get_m() << "x" << matrix_.get_n() << endl;
  for (int i = 1; i <= matrix_.get_m(); i++)
  {
    for (int j = 1; j <= matrix_.get_n(); j++)
      switch (matrix_(i, j))
      {
      case START_ID:
        os << START_CHR;
        break;
      case END_ID:
        os << END_CHR;
        break;
      case WALL_ID:
        os << WALL_CHR;
        break;
      case PASS_ID:
        os << PASS_CHR;
        break;
      case PATH_ID:
        os << PATH_CHR;
        break;
      }
    os << endl;
  }
  return os;
}

bool maze_t::isOK(int i, int j)
{
  return (i >= 1 &&
          i <= matrix_.get_m()) &&
         (j >= 1 && j <= matrix_.get_n()) &&
         matrix_(i, j) != WALL_ID &&
         !visited_(i, j);
}

bool maze_t::solve(int i, int j)
{
  // CASO BASE:
  // retornar 'true' si 'i' y 'j' han llegado a la salida
  if (matrix_(i, j) == END_ID)
    return true;

  // marcamos la celda como visitada
  visited_(i, j) = true;

  // CASO GENERAL:
  // para cada una de las 4 posibles direcciones (N, E, S, W) ver si es posible
  // el desplazamiento (isOK), y en ese caso, intentar resolver el laberinto
  // llamando recursivamente a 'solve'. Si la llamada devuelve 'true',
  // propagarla retornando también 'true'
  for (int k = N; k <= SE; ++k)
  {
    if (isOK(i + i_d[k], j + j_d[k]))
    {
      if (solve(i + i_d[k], j + j_d[k]))
      {
        matrix_(i, j) = PATH_ID;
        return true;
      }
    }
  }

  // desmarcamos la celda como visitada (denominado "backtracking") y
  // retornamos 'false'
  visited_(i, j) = false;
  return false;
}

istream &operator>>(istream &is, maze_t &M)
{
  return M.read(is);
}

ostream &operator<<(ostream &os, const maze_t &M)
{
  return M.write(os);
}
