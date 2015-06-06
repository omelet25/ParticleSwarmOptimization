#pragma once
#include "BasePSO.h"

/**
*	@file	StandardPSO.h
*	@author	omelet
*	@date	2015/05/30
*/
namespace PSO
{
	/**
	*	@brief �ʏ��PSO�N���X
	*	Base�N���X���p��
	*/
	class StandardPSO :
		public BasePSO
	{
	private:
		const double w = 0.792, c1 = 1.4955, c2 = 1.4955;
	protected:
		/**
		*	@brief PSO�̍X�V
		*	���q���x���C\f$v^{t+1} = wv^t + c_1r_1(pbest^t-x^t) + c_2r_2(gbest^t-x^t)\f$
		*	���q�ʒu���C\f$x^{t+1} = x^t + v^{t+1}\f$
		*	�ōX�V����D
		*/
		bool update();
	public:
		StandardPSO(CostFunction func, int itr = 1, int pop = 1);
		~StandardPSO();
	};
}
