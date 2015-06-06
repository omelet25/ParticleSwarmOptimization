#pragma once
#include <vector>
#include <functional>

#include "Alias.h"

/**
*	@file	CostFunction.h
*	@author	omelet
*	@date	2015/05/30
*/

/**
*	@brief コスト関数クラス
*/
class CostFunction
{
	int _dim;	/*!< 目的関数の次元数*/
	double
		_min,	/*!< 下限 */
		_max;	/*!< 上限 */

	f_x 
		_f,	/*!< 目的関数 */
		_p;	/*!< ペナルティ関数*/
public:
	/**
	*	@brief コンストラクタ
	*	@param function	目的関数
	*	@param penalty	ペナルティ関数
	*	@param dim		関数の次元数
	*	@param min		定義域下限
	*	@param max		定義域上限
	*/
	CostFunction(f_x function,f_x penalty,int dim,double min = -1.,double max = 1.);
	~CostFunction();

	/**
	*	@brief コスト関数の値を得る
	*	return function(x) + penalty(x)
	*/
	double get_cost(dvec& x);

	/**
	*	@brief 定義域の下限を得る
	*	@return 下限
	*/
	inline double get_min() { return _min; };
	/**
	*	@brief 定義域の上限を得る
	*	@return 上限
	*/
	inline double get_max() { return _max; };
	/**
	*	@brief コスト関数の次元数を得る
	*	@return 次元数
	*/
	inline int get_dim() { return _dim; };
	/**
	*	@brief 定義域のユークリッド距離を得る
	*	@return \f$\sqrt{(max-min)^2}\f$
	*/
	inline double get_euclid() { return std::sqrt((_max - _min)*(_max - _min)); }

	/**
	*	@brief f(x) = 0の関数
	*/
	static inline double zero_cost(dvec &x) { return 0.0; };
};

