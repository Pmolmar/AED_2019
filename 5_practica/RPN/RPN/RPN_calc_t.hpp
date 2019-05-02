#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>


using namespace std;

namespace AED {

	template <class T>
	class RPN_calc_t{
	private:
		T stack_;

	public:
		RPN_calc_t() {}

		~RPN_calc_t() {}
	
		const int compute(istream& is)
		{

			int operando;
			char operador;

			while(!is.eof()){

				is >> ws;
				int c = is.peek();

				if (!is.eof()) {

					if (isdigit(c)){
						is >> operando;
						...
					}
					else {
						is >> operador;
						...
					}
				}
			}

			const int result = stack_.top();
			stack_.pop();

			return result;
		}

		private: 

			void operate(char operador){
				
				...
			}

       };

}

