#include "StandardPSO.h"

PSO::StandardPSO::StandardPSO(CostFunction func,int itr, int pop) : BasePSO(func,itr, pop)
{
}

PSO::StandardPSO::~StandardPSO()
{
}

bool PSO::StandardPSO::update()
{
	bool is_update = false;
	for (int i = 0; i < _pop; i++)
	{
		for (int j = 0; j < _func.get_dim(); j++)
		{
			double r1 = uniform(), r2 = uniform();
			_particles[i].v[j] = w * _particles[i].v[j]
				+ c1 * r1 * (_particles[i].pbest_x[j] - _particles[i].x[j])
				+ c2 * r2 * (_gbest_x[j] - _particles[i].x[j]);
			set_domain(_particles[i].v[j], -_func.get_euclid() / 2.0, _func.get_euclid() / 2.0);
			_particles[i].x[j] += _particles[i].v[j];
			set_domain(_particles[i].x[j], _func.get_min(), _func.get_max());
		}
		_particles[i].f = _func.get_cost(_particles[i].x);
		if (_particles[i].evaluate())
		{
			if (evaluate(_particles[i])) { is_update; }
		}
	}
	return is_update;
}