#pragma once
#include <vector>
#include <functional>
/**
*	@file	Alias.h
*	@author	omelet
*	@date	2015/05/30
*	@brief	usingを使った型のエイリアスをまとめたヘッダ
*/

/**
*	@typedef std::vector < double >型のエイリアス
*/
using dvec = std::vector < double > ;
/**
*	@typedef コスト関数 std::function<double(dvec&)> のエイリアス
*/
using f_x = std::function < double(std::vector<double> &) > ;