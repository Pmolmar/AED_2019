#include <cstdio>
#include <iostream>

#include "matrix_t.hpp"
#include "rational_t.hpp"
#include "sparse_matrix_t.hpp"

#define MAX_DIM 5

using namespace std;

/*
contar elementos no nulos de la ultima columna de la matriz.
*/

int main(void)
{
	matrix_t<rational_t> A(MAX_DIM, MAX_DIM);
	matrix_t<rational_t> B(MAX_DIM, MAX_DIM);

	for (int i = 1; i <= MAX_DIM; i++)
		A(i, i) = rational_t(1, i + 1);

	A(1, 2) = rational_t(5);
	A(3, 4) = rational_t(3, 2);

	A.write(cout);
	cout << endl;

	cout << "COL_CONF = 0, ROW_CONF > 0: ";
	bool fila;
	cin >> fila;

	int x;
	if (!fila)
	{
		cout << "COL_CONF:" << endl;
		sparse_matrix_t SA(A, 1E-2, COL_CONF);
		SA.write(cout);
		cout << endl;

		cout << "Introduzca col entre 1-"<<MAX_DIM-1<<": "<< endl;
		cin>>x;
		cout<<"Hay "<<SA.no_null(x)<<" elementos no nulos."<<endl<<endl;

		SA.mult(A, B);
		cout << "La multiplicacion es:" << endl;
		B.write(cout);
	}
	else
	{
		cout << "ROW_CONF:" << endl;
		sparse_matrix_t SA(A, 1E-2, ROW_CONF);
		SA.write(cout);
		cout << endl;

		cout << "Introduzca col entre 1-"<<MAX_DIM-1<<": "<< endl;
		cin>>x;
		cout<<"Hay "<<SA.no_null(x)<<" elementos no nulos."<<endl<<endl;

		SA.mult(A, B);
		cout << "La multiplicacion es:" << endl;
		B.write(cout);
	}

	return 0;
}
