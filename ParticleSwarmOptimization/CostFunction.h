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
*	@brief �R�X�g�֐��N���X
*/
class CostFunction
{
	int _dim;	/*!< �ړI�֐��̎�����*/
	double
		_min,	/*!< ���� */
		_max;	/*!< ��� */

	f_x 
		_f,	/*!< �ړI�֐� */
		_p;	/*!< �y�i���e�B�֐�*/
public:
	/**
	*	@brief �R���X�g���N�^
	*	@param function	�ړI�֐�
	*	@param penalty	�y�i���e�B�֐�
	*	@param dim		�֐��̎�����
	*	@param min		��`�扺��
	*	@param max		��`����
	*/
	CostFunction(f_x function,f_x penalty,int dim,double min = -1.,double max = 1.);
	~CostFunction();

	/**
	*	@brief �R�X�g�֐��̒l�𓾂�
	*	return function(x) + penalty(x)
	*/
	double get_cost(dvec& x);

	/**
	*	@brief ��`��̉����𓾂�
	*	@return ����
	*/
	inline double get_min() { return _min; };
	/**
	*	@brief ��`��̏���𓾂�
	*	@return ���
	*/
	inline double get_max() { return _max; };
	/**
	*	@brief �R�X�g�֐��̎������𓾂�
	*	@return ������
	*/
	inline int get_dim() { return _dim; };
	/**
	*	@brief ��`��̃��[�N���b�h�����𓾂�
	*	@return \f$\sqrt{(max-min)^2}\f$
	*/
	inline double get_euclid() { return std::sqrt((_max - _min)*(_max - _min)); }

	/**
	*	@brief f(x) = 0�̊֐�
	*/
	static inline double zero_cost(dvec &x) { return 0.0; };
};

