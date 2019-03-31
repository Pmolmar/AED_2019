#include <iostream>

#include "rational_matrix_t.hpp"

using namespace std;

/*
Modificacion:
crear funcion que devuelva un rational_t llamada mod que se encarga de sumar
todos los elementos que tiene, pero cuando el numero de filas sea par sumamos
si es impar restamos
*/


int main(void)
{
    rational_matrix_t A(3, 2);

    A( 1, 1) = rational_t( 8, 5);
    A( 1, 2) = rational_t( 4, 2);
    A( 2, 1) = rational_t( 1, 2);
    A( 2, 2) = rational_t( 6, 3);
    A( 3, 1) = rational_t( 4, 3);
    A( 3, 2) = rational_t( 3, 2);

    cout << A << endl;

    rational_matrix_t B(2, 4);

    B( 1, 1) = rational_t( 8, 3);
    B( 1, 2) = rational_t( 5, 2);
    B( 1, 3) = rational_t( 1, 3);
    B( 1, 4) = rational_t( 7, 3);
    B( 2, 1) = rational_t( 4, 2);
    B( 2, 2) = rational_t( 5, 2);
    B( 2, 3) = rational_t( 4, 3);
    B( 2, 4) = rational_t( 3, 2);

    cout << "*" << endl << endl;
    cout << B << endl;

    rational_matrix_t C;

    C = A * B;

    cout << "=" << endl << endl;
    cout << C << endl;
    cout << C.mod()<<endl;

    return 0;
}
