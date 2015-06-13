#include "QuantumPSO.h"

PSO::QuantumPSO::QuantumPSO(CostFunction func, int itr, int pop) : BasePSO(func, itr, pop)
{
}


PSO::QuantumPSO::~QuantumPSO()
{
}

void PSO::QuantumPSO::update()
{
	// mbest計算
	dvec mbest(_func.get_dim(), 0);
	for (int i = 0; i < _func.get_dim(); i++)
	{
		for (int j = 0; j < _pop; j++)
		{
			mbest[i] += _particles[j].pbest_x[i];
		}
		mbest[i] /= _pop;
	}

	for (int i = 0; i < _pop; i++)
	{
		for (int j = 0; j < _func.get_dim(); j++)
		{
			double u = 1.0 - uniform();
			double phi = uniform();
			// 位置更新
			double potential = beta * abs(mbest[j] - _particles[i].x[j]) * log(1.0 / u);
			double local = phi * _particles[i].pbest_x[j] + (1.0 - phi) * _gbest_x[j];
			if (uniform() < 0.5)
			{
				_particles[i].x[j] = local + potential;
			}
			else
			{
				_particles[i].x[j] = local - potential;
			}
			// 位置制限
			set_domain(_particles[i].x[j], _func.get_min(), _func.get_max());
		}
		// 評価値計算
		_particles[i].f = _func.get_cost(_particles[i].x);
	}
}
