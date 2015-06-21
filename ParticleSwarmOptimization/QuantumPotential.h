#pragma once
#include <cmath>

namespace PSO
{
	/**
	*	@brief	量子ポテンシャルベースクラス
	**/
	class QuantumPotential
	{
	public:
		QuantumPotential() {};
		~QuantumPotential() {};
		virtual inline double Potential(double mbest, double x, double rand) = 0;
	private:

	};

	/**
	*	@brief	デルタ井戸型ポテンシャル
	*/
	class DeltaWell : public QuantumPotential
	{
	public:
		DeltaWell() {};
		~DeltaWell() {};
		inline double Potential(double mbest, double x, double rand)
		{
			return abs(mbest - x) * log(1.0 / (1.0 - rand));
		}
	private:

	};

	/**
	*	@brief	調和振動子ポテンシャル
	*/
	class HarmonicOscillator : public QuantumPotential
	{
	public:
		HarmonicOscillator() {};
		~HarmonicOscillator() {};
		inline double Potential(double mbest, double x, double rand)
		{
			return abs(mbest - x) * sqrt(log(1.0 / (1.0 - rand)));
		}
	private:

	};
}