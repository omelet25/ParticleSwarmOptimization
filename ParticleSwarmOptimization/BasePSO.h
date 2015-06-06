#pragma once
#include <vector>
#include <limits>
#include <random>

#include "Alias.h"

#include "Particle.h"
#include "CostFunction.h"

/**
*	@file	BasePSO.h
*	@author	omelet
*	@date	2015/05/23
*/

namespace PSO
{
	/**
	*	@brief PSOのベースクラス．
	*/
	class BasePSO
	{
		/** 乱数生成器 */
		std::mt19937 _mt;
		std::uniform_real_distribution<> _urd;
	protected:
		/**
		*	@struct 結果格納構造体
		*/
		typedef struct
		{
			int t;			/*!< 更新回数 */
			dvec gbest_x;	/*!< 粒子群最適位置 */
			double gbest_f;	/*!< 最適な評価値 */
		} result;

		int
			_itr,	/*!< 最大更新回数 */
			_pop;	/*!< 粒子数 */
		std::vector<Particle> _particles;	/*!< 粒子群 */
		dvec _gbest_x;		/*!< 粒子群が探索した最適な位置 */
		double _gbest_f;	/*!< 粒子群が探索した最適な評価値 */
		CostFunction _func;	/*!< コスト関数クラス */

		/**
		*	@brief PSOの初期化．
		*	粒子群を乱数を用いて初期化する
		*/
		virtual void initialize();
		/**
		*	@brief PSOの更新（仮想関数）
		*	PSOの種類によってサブクラスでオーバーライドする．
		*/
		virtual bool update() = 0;
		/**
		*	@brief 粒子の評価
		*	粒子の評価を行い，gbestを求める．
		*/
		virtual bool evaluate(Particle& p);

		/**
		*	@brief 一様乱数[min,max)の生成
		*	@param min 下限
		*	@param max 上限
		*	@return [min,max)の一様乱数
		*/
		double uniform(double min = 0., double max = 1.);

		/**
		*	@brief targetを[min,max]内に制限
		*	@param val 値
		*	@param min 下限
		*	@param max 上限
		*/
		double set_domain(double val, double min, double max);
	public:
		std::vector<result> results;

		/**
		*	@brief コンストラクタ
		*	@param itr 最大更新回数
		*	@param pop 粒子数
		*	@param dim 次元数
		*/
		BasePSO(CostFunction func,int itr, int pop);
		/**
		*	@brief デストラクタ
		*/
		~BasePSO();

		/**
		*	@brief PSO処理スタート．
		*	PSOの処理を開始する．
		*/
		void Start();
		///**
		//*	@brief PSO処理スタート．
		//*	PSOの処理を開始する．
		//*	@param epoch_callback 各更新ごとに呼び出されるコールバック
		//*/
		//void Start(std::function<void()> epoch_callback);
	};

}
