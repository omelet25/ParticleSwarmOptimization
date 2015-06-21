#pragma once
#include "BasePSO.h"
#include "QuantumPotential.h"

namespace PSO
{
	/**
	*	@brief	QPSOクラス
	*	
	*/
	template<class PotentialType = QuantumPotential>
	class QuantumPSO : public BasePSO
	{
	public:
		QuantumPSO(CostFunction func, int itr = 1, int pop = 1);
		~QuantumPSO();
	protected:
		void update();
	private:
		const double _beta = 0.8;
		PotentialType _pt;
	};
}

template<class PotentialType = QuantumPotential>
PSO::QuantumPSO<PotentialType>::QuantumPSO(CostFunction func, int itr, int pop) 
	: BasePSO(func, itr, pop)
{
}

template<class PotentialType = QuantumPotential>
PSO::QuantumPSO<PotentialType>::~QuantumPSO()
{
}

template<class PotentialType = QuantumPotential>
void PSO::QuantumPSO<PotentialType>::update()
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
			double phi = uniform();
			// 位置更新
			double potential = _beta * _pt.Potential(mbest[j], _particles[i].x[j], uniform());
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
