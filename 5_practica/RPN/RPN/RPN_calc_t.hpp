#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

namespace AED
{

template <class T>
class RPN_calc_t
{
private:
	T stack_;

public:
	RPN_calc_t() {}

	~RPN_calc_t() {}

	const int compute(istream &is)
	{

		int operando;
		char operador;

		while (!is.eof())
		{

			is >> ws;
			int c = is.peek();

			if (!is.eof())
			{

				if (isdigit(c))
				{
					is >> operando;
					stack_.push(operando);
				}
				else
				{
					is >> operador;
					operate(operador);
				}
			}
		}

		const int result = stack_.top();
		stack_.pop();

		return result;
	}

private:
	void operate(char operador)
	{
		int a, b;

		a = stack_.top();
		stack_.pop();

		if (operador == '+' | operador == '-' | operador == '*' | operador == '/' | operador == '^')
		{
			b = stack_.top();
			stack_.pop();
		}

		switch (operador)
		{
		case '+':
			stack_.push(b + a);
			break;

		case '-':
			stack_.push(b - a);
			break;

		case '*':
			stack_.push(b * a);
			break;

		case '/':
			stack_.push(b / a);
			break;

		case '^':
			stack_.push(pow(b, a));
			break;

		case 'r':
			stack_.push(sqrt(a));
			break;

		case 'l':
			stack_.push(log2(a));
			break;

		case 'c':
			stack_.push(pow(a, 2));
			break;

		//modificacion
		case 'n':
			stack_.push(a * (-1));
			break;

		default:
			break;
		}
	}
};

} // namespace AED
