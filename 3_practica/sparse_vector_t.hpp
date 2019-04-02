#pragma once

#include "list_pair_t.hpp"
#include "vector_t.hpp"
#include <cmath>

#include <iostream>
#include <iomanip>

using namespace std;

namespace AED {

class sparse_vector_t{
private:
	list_pair_t   v_;
	int           sz_;

public:
	sparse_vector_t(const vector_t<double>& v, double eps):
		v_(),
		sz_(v.size())
	{
		node_pair_t *nodo;

		for(int i=sz_-1; i>=0; --i)
		{
			spair_t par(i,v[i]);
			nodo=new node_pair_t;
			nodo->set_data(par);

			if(is_not_zero(v[i],eps))
				v_.insert_head(nodo);
		}
	}

	~sparse_vector_t(void){}

	ostream& write(ostream& os) const{

		os << "[ " << setw(7) << sz_ << " ";
		v_.write(os);
		os << " ]";

		return os;
	}

//fase III
	//metodo extra para tamaño original
	int get_tam(void)const
	{
		return sz_;
	}

	double scal_prod(const vector_t<double>& b) const
	{
		assert(sz_==b.size());
		double producto=0.0;
		node_pair_t *aux=v_.head();

		for(int j=0; j<v_.get_sz(); ++j)
		{
			for(int i=0; i<b.size();++i)
			{
				if(aux->get_data().get_inx()==i)
					producto+=b[i]*aux->get_data().get_val();
			}
			aux=aux->get_next();
		}
		return producto;
	}

//fase IV
  //metodo extra para elegir el nodo de v_
	node_pair_t* get_node(int pos)const
	{
		node_pair_t* node=v_.head();

		for(int i=0; i<pos&&i<v_.get_sz(); ++i)
		{
			node=node->get_next();
		}

		return node;
	}

	double scal_prod(const sparse_vector_t& b) const
	{
		assert(sz_==b.get_tam());
		double producto=0.0;
		node_pair_t *aux=v_.head();
		node_pair_t *auxb=b.get_node(0);

		for(int j=0; j<v_.get_sz(); ++j)
		{
			auxb=b.get_node(0);
			for(int i=0; auxb!=NULL; ++i)
			{
				if(aux->get_data().get_inx()==auxb->get_data().get_inx())
					producto+=auxb->get_data().get_val()*aux->get_data().get_val();
				auxb=auxb->get_next();
			}
			aux=aux->get_next();
		}
		return producto;
	}

private:
	bool is_not_zero(double val, double eps){ return fabs(val) > eps;}

};

}
