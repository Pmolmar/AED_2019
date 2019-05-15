#include <cstdio>
#include <iostream>


#include "stack/stack_v_t.hpp"
#include "stack/stack_l_t.hpp"
#include <stack>

#include "RPN/RPN_calc_t.hpp"

using namespace std;
using namespace AED;

typedef stack_v_t<int> stack_vector;
typedef stack_l_t<int> stack_lista;  
typedef stack<int>     stack_stl;


/*
modificacion:
	crear un nuevo operador 'n' que multiplica por -1 el valor
*/

int main(void)
{
	{
		RPN_calc_t<stack_vector> calculadora_vector;
		const int result_vector = calculadora_vector.compute(cin);
		cout << "Calculadora vector: " << result_vector << endl;
	}
	
	cin.clear();             // OMG!
	cin.seekg(0, ios::beg);

	{
		RPN_calc_t<stack_lista> calculadora_lista;
		const int result_lista = calculadora_lista.compute(cin);
		cout << "Calculadora lista:  " << result_lista << endl;
	}

	cin.clear();
	cin.seekg(0, ios::beg);

	{
		RPN_calc_t<stack_stl> calculadora_stl;
		const int result_stl = calculadora_stl.compute(cin);
		cout << "Calculadora stl:    " << result_stl << endl;
	}

	return 0;
}
