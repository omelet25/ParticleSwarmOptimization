#pragma once
#include "BasePSO.h"

namespace PSO
{
	class QuantumPSO :
	public BasePSO
	{
	private:
		const double beta = 0.8;
	protected:
		void update();
	public:
		QuantumPSO(CostFunction func, int itr = 1, int pop = 1);
		~QuantumPSO();
	};

}

