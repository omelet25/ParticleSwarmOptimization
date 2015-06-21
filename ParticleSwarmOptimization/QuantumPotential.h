#pragma once
#include <cmath>

namespace PSO
{
	/**
	*	@brief	�ʎq�|�e���V�����x�[�X�N���X
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
	*	@brief	�f���^��ˌ^�|�e���V����
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
	*	@brief	���a�U���q�|�e���V����
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