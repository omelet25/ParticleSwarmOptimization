#pragma once
#include <vector>
#include <functional>
/**
*	@file	Alias.h
*	@author	omelet
*	@date	2015/05/30
*	@brief	using���g�����^�̃G�C���A�X���܂Ƃ߂��w�b�_
*/

/**
*	@typedef std::vector < double >�^�̃G�C���A�X
*/
using dvec = std::vector < double > ;
/**
*	@typedef �R�X�g�֐� std::function<double(dvec&)> �̃G�C���A�X
*/
using f_x = std::function < double(std::vector<double> &) > ;