#include "CostFunction.h"

CostFunction::CostFunction(f_x function, f_x penalty, int dim, double min, double max)
	:_f(function),_p(penalty) ,_dim(dim), _min(min), _max(max)
{
}

CostFunction::~CostFunction()
{
}

double CostFunction::get_cost(dvec& x)
{
	return _f(x) + _p(x);
}