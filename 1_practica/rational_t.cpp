#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

double rational_t::value() const
{
  return double(get_num()) / get_den();
}

rational_t rational_t::opposite() const
{
  return rational_t((-1)*get_num(), get_den());
}

rational_t rational_t::reciprocal() const
{
  return rational_t(get_den(), get_num());
}

//Fase 3
bool rational_t::equal(const rational_t& r, const double precision) const
{
  if(fabs(value()-r.value())<precision)
      return true;
  return false;
}

bool rational_t::greater(const rational_t& r, const double precision) const
{
  if((value()-r.value())>precision)
      return true;
  return false;
}

bool rational_t::less(const rational_t& r, const double precision) const
{
  if((value()-r.value())<-precision)
      return true;
  return false;
}

bool rational_t::zero(const double precision) const
{
  if(fabs(value())<precision)
    return true;
  return false;
}

//Fase IV
rational_t rational_t::add(const rational_t& r)
{
  int mcd=0,num=0;
  mcd=r.get_den()*get_den();
  num=r.get_den()*get_num()+get_den()*r.get_num();
  rational_t suma(num,mcd);
  return suma;
}

rational_t rational_t::substract(const rational_t& r)
{
  int mcd=0,num=0;
  mcd=r.get_den()*get_den();
  num=r.get_den()*get_num()-get_den()*r.get_num();
  rational_t resta(num,mcd);
  return resta;
}

rational_t rational_t::multiply(const rational_t& r)
{
  int num=0,den=0;
  num=get_num()*r.get_num();
  den=get_den()*r.get_den();
  rational_t mult(num,den);
  return mult;
}

rational_t rational_t::divide(const rational_t& r)
{
  int num=0,den=0;
  num=get_num()*r.get_den();
  den=get_den()*r.get_num();
  rational_t div(num,den);
  return div;
}

void rational_t::write(ostream& os) const
{ os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream& is)
{ cout << "Numerador: ";
  is >> num_;
  cout << "Denominador: ";
  is >> den_;
  assert(den_ != 0);
}

//modificacion
bool rational_t::unidad()
{
  if(get_den()==get_num())
    return true;
  return false;
}
