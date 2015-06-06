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
	*	@brief 通常のPSOクラス
	*	Baseクラスを継承
	*/
	class StandardPSO :
		public BasePSO
	{
	private:
		const double w = 0.792, c1 = 1.4955, c2 = 1.4955;
	protected:
		/**
		*	@brief PSOの更新
		*	粒子速度を，\f$v^{t+1} = wv^t + c_1r_1(pbest^t-x^t) + c_2r_2(gbest^t-x^t)\f$
		*	粒子位置を，\f$x^{t+1} = x^t + v^{t+1}\f$
		*	で更新する．
		*/
		bool update();
	public:
		StandardPSO(CostFunction func, int itr = 1, int pop = 1);
		~StandardPSO();
	};
}
