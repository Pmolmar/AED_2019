#pragma once

#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

# define EPSILON 1e-6

using namespace std;

class rational_t
{
  int num_, den_;

public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}

  int get_num() const
  { return num_; }

  int get_den() const
  { return den_; }

  void set_num(const int n)
  { num_ = n; }

  void set_den(const int d)
  { assert(d != 0), den_ = d; }

  void add(const rational_t& a, const rational_t& b);
  void sub(const rational_t& a, const rational_t& b);
  void multiply(const rational_t&a, const rational_t& b);

  void write(ostream& os = cout) const;

  bool zero(const double precision) const
  {
    if(fabs(double(get_num())/double(get_den()))<precision)
      return true;
    return false;
  }

private:
    int gcd(int a, int b) const {
        return b == 0 ? a : gcd(b, a % b);
    }
};

rational_t::rational_t(const int num, const int den):
num_(num),
den_(den)
{ assert(den != 0);
}

void rational_t::add(const rational_t& a, const rational_t& b)
{
	if (a.get_den() == b.get_den()){
		den_ = a.get_den();
		num_ = a.get_num() + b.get_num();
	}
	else{
		den_ = a.get_den() * b.get_den();
		num_ = b.get_num() * a.get_den() + a.get_num() * b.get_den();
	}
}

void rational_t::sub(const rational_t& a, const rational_t& b)
{
	if (a.get_den() == b.get_den()){
		den_ = a.get_den();
		num_ = a.get_num() - b.get_num();
	}
	else{
		den_ = a.get_den() * b.get_den();
		num_ = b.get_num() * a.get_den() - a.get_num() * b.get_den();
	}
}


void rational_t::multiply(const rational_t&a, const rational_t& b)
{
	num_ = a.get_num() * b.get_num();
	den_ = a.get_den() * b.get_den();
}

void rational_t::write(ostream& os) const
{
    const int mcd = gcd (num_, den_);

    if(get_num()>get_den())
    {
      os<<get_num()/get_den();
      if((get_num()%get_den())>0)
      {
        os<<"+"<<(get_num()%get_den())/mcd<<"/"<<get_den()/mcd;
      }
    }
    else
      os<<get_num()/mcd<<"/"<<get_den()/mcd;
    os<<setw('\t');
}

ostream& operator<<(ostream& os, const rational_t& a)
{
    a.write(os);
    return os;
}

rational_t operator+(const rational_t& a, const rational_t& b)
{
    rational_t c;
    c.add(a,b);

    return c;
}

rational_t operator-(const rational_t& a, const rational_t& b)
{
    rational_t c;
    c.sub(a,b);

    return c;
}

rational_t operator*(const rational_t& a, const rational_t& b)
{
    rational_t c;
    c.multiply(a,b);

    return c;
}
