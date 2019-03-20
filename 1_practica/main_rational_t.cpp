//Practica Pablo Molina Martinez
//modificacion, comprobar si el racional es la unidad
#include <iostream>
#include <cmath>
#include <stdio.h>

#include "rational_t.hpp"

using namespace std;

// FASE III: función de búsqueda
bool search(const rational_t* v, const int n, const rational_t& x)
{
  for (int i = 0; i < n; i++)
  {
      if(x.equal(v[i]))
        return true;
  }
  return false;
}

int main()
{
  system("clear");

  rational_t a(1,2), b(1,3), c;
  int n=0,op=0;
  rational_t *v = new rational_t[n];

do
{
  cout<<endl<<"Menu: "<<endl
  <<"1.Introducir A y B."<<endl
  <<"2.Introducir vector de valores."<<endl
  <<"3.Sumar,restar,multiplicar y dividir A y B."<<endl
  <<"4.Comparar,opuesto,inverso e unidad A y B."<<endl
  <<"5.Buscar en el vector de valores."<<endl
  <<"6.Borrar vector de valores."<<endl
  <<"0.Salir."<<endl
  <<endl<<"Op: ";

  cin >> op;
  if(op==2)
  {
    cout<<"Introduzca tamaño del vector: ";
    cin>>n;
  }

  system("clear");

  switch (op) {
    case 0:
      cout<<"Adios!!!"<<endl;
    break;

    case 1:
      a.read();
      cout<<"a: ";
      a.write();
      b.read();
      cout<<"b: ";
      b.write();
    break;

    case 2:
      for (int i = 0; i < n; i++) {
        v[i].read();
        cout<<i<<": ";
        v[i].write();
      }
    break;

    case 3:
      cout << "a + b: ";
      a.add(b).write();

      cout << "b - a: ";
      b.substract(a).write();

      cout << "a * b: ";
      a.multiply(b).write();

      cout << "a / b: ";
      a.divide(b).write();
    break;

    case 4:
      if(a.equal(b))
        cout<<"Iguales"<< '\n';
      else if(a.greater(b))
        cout<<"A mayor que B."<<endl;
      else if(a.less(b))
        cout<<"A menor que B."<<endl;

        if(a.zero())
          cout<<"A es igual a 0."<<endl;
        if(a.unidad())
          cout<<"A es la unidad."<<endl;
        if(b.zero())
          cout<<"B es igual a 0."<<endl;
        if(b.unidad())
          cout<<"B es la unidad."<<endl;

        cout << "Opuesto de a: ";
        a.opposite().write();
        cout << "Recíproco de a: ";
        a.reciprocal().write();

        cout << "Opuesto de b: ";
        b.opposite().write();
        cout << "Recíproco de b: ";
        b.reciprocal().write();

    break;

    case 5:
      cout<<"Introduzca numero a buscar"<<endl;
      c.read();
      cout<<"Numero: ";
      c.write();
      if(search(v,n,c))
        cout<<"Numero encontrado."<<endl;
      else
        cout<<"Numero NO encontrado."<<endl;
    break;

    case 6:
      cout<<"Borrando vector..."<<endl;
      delete[] v;
    break;

    default:
      cout<<"Opcion no conocida intentelo de nuevo."<<endl;
    break;
  }
}while(op!=0);
  return 0;
  // cout << "a.value()= " << a.value() << endl;
  // cout << "b.value()= " << b.value() << endl;
  // cout << "c.value()= " << c.value() << endl;
  //
  // cout << "a: ";
  // a.write();
  // cout << "b: ";
  // b.write();
  //
  // c.read();
  // cout << "c: ";
  // c.write();
  //
  // cout << "Opuesto de a: ";
  // a.opposite().write();
  // cout << "Recíproco de b: ";
  // b.reciprocal().write();
  // if(a.equal(b))
  //   cout<<"Iguales"<< '\n';
  // else if(a.greater(b))
  //   cout<<"A mayor que B."<<endl;
  // else if(a.less(b))
  //   cout<<"A menor que B."<<endl;



  // FASE III: ejemplo
  // int n;
  // cout << "Introduce n: ";
  // cin >> n;
  // rational_t *v = new rational_t[n];
  // if (v != NULL) {
  //   for (int i = 0; i < n; i++) {
  //     v[i] = rational_t(1, pow(2, i));
  //     v[i].write();
  //   }

  //   rational_t x(1, pow(2, 3));
  //   bool b = search(v, n, x);
  //   cout << "Valor " << x.value() << (b ? "" : "no") << " encontrado" << endl;

  //   delete[] v;
  // }
  // else {
  //   cerr << "ERROR: no se ha podido reservar memoria dinámica" << endl;
  //   return 1;
  // }

  // FASE IV
  // cout << "a + b: ";
  // a.add(b).write();
  //
  // cout << "b - a: ";
  // b.substract(a).write();
  //
  // cout << "a * b: ";
  // a.multiply(b).write();
  //
  // cout << "a / b: ";
  // a.divide(b).write();
  //
  // return 0;
}
