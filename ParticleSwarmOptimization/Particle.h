#pragma once
#include <vector>
#include <limits>
#include <iostream>

#include "Alias.h"

/**
*	@file	Particle.h
*	@author	omelet
*	@date	2015/05/23
*/

namespace PSO
{
/**
*	@brief 粒子クラス．
*/
	class Particle
	{
	public:
		/**
		*	@brief コンストラクタ．
		*	\sa x, pbest_x, v を次元数で初期化．
		*	f, pbest_f を std::numeric_limits<double>::max()で初期化．
		*	@param dim 探索空間の次元数．デフォルトは1次元
		*/
		Particle(int dim = 1);
		/**
		*	@brief デストラクタ
		*/
		~Particle();
		/**
		*	@brief コピーコンストラクタ．
		*	@param that コピー元
		*/
		Particle(const Particle &that);

		/**
		*	@brief 粒子の評価．
		*	粒子を評価し，pbest_x, pbest_f を更新．
		*	@return 現在の評価値 f が pbest_f より小さかったら ture．
		*/
		bool evaluate();

		std::vector < double >
			x,			/*!< 現在の粒子位置 */
			pbest_x,	/*!< 過去に探索した最適な粒子位置 */
			v;			/*!< 粒子速度 */
		double
			f,			/*!< 粒子の評価値 */
			pbest_f;	/*!< 過去に探索した最適な粒子の評価値 */

		/**
		*	@brief 粒子情報出力．
		*	x		x1	x2	...	xn	f	現在の粒子位置と評価値
		*	pbest	px1	px2	...	pxn	pf	最適な粒子位置と評価値
		*/
		friend std::ostream& operator << (std::ostream& os, const Particle& p);
	};
}