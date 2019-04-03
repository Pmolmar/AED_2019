#include "vector_t.hpp"
#include "sparse_vector_t.hpp"

#include <iostream>
using namespace std;
using namespace AED;

#define V_SZ 10000
#define EPS  1E-3

/*
Modificacion:
Crear funcion void insert_pos(sll_node_t& nodo, int pos)
*/

int main(void)
{
	vector_t<double> v1(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v1[i] = 0.0;

	v1[0]    = 1.0;
	v1[1000] = 1.0;
	v1[2000] = 1.0;
	v1[3000] = 1.0;
	v1[4000] = 1.0;
	v1[5000] = 1.0;
	v1[9000] = 1.0;

	sparse_vector_t sv1(v1, EPS);

	sv1.write(cout);
	cout << endl;

	vector_t<double> v2(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v2[i] = 0.0;

	v2[0]    = 1.0;
	v2[100]  = 1.0;
	v2[1000] = 1.0;
	v2[3000] = 1.0;
	v2[5000] = 1.0;

	sparse_vector_t sv2(v2, EPS);

	sv2.write(cout);
	cout << endl;

	const double prod1 = sv1.scal_prod(v2);
	const double prod2 = sv1.scal_prod(sv2);

	cout << prod1 << endl;
	cout << prod2 << endl;

	double val=0.0;
	int pos=0;
	cout<<"Introduzca valor: ";
	cin>>val;
	cout<<"Introduzca posicion: ";
	cin>>pos;
	spair_t par(pos,val);
	node_pair_t *nodo;
	nodo = new node_pair_t;
	nodo->set_data(par);

	sv1.insert_pos(nodo,pos);

	sv1.write(cout);
}
