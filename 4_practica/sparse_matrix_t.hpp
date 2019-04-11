#pragma once

#include "vector_t.hpp"
#include "matrix_t.hpp"
#include "dll_node_t.hpp"
#include "dll_t.hpp"
#include "pair_t.hpp"
#include "rational_t.hpp"

enum {COL_CONF, ROW_CONF};



ostream& operator<<(ostream& os, const pair_t<rational_t>& a)
{
	a.write(os);
	return os;
}
