#include "StandardPSO.h"

PSO::StandardPSO::StandardPSO(CostFunction func,int itr, int pop) : BasePSO(func,itr, pop)
{
}

PSO::StandardPSO::~StandardPSO()
{
}

void PSO::StandardPSO::update()
{
	for (int i = 0; i < _pop; i++)
	{
		for (int j = 0; j < _func.get_dim(); j++)
		{
			double r1 = uniform(), r2 = uniform();
			// ���x�X�V
			_particles[i].v[j] = w * _particles[i].v[j]
				+ c1 * r1 * (_particles[i].pbest_x[j] - _particles[i].x[j])
				+ c2 * r2 * (_gbest_x[j] - _particles[i].x[j]);
			// ���x����
			set_domain(_particles[i].v[j], -_func.get_euclid() / 2.0, _func.get_euclid() / 2.0);
			// �ʒu�X�V
			_particles[i].x[j] += _particles[i].v[j];
			// �ʒu����
			set_domain(_particles[i].x[j], _func.get_min(), _func.get_max());
		}
		// �]���l�v�Z
		_particles[i].f = _func.get_cost(_particles[i].x);
	}
}