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
*	@brief ���q�N���X�D
*/
	class Particle
	{
	public:
		/**
		*	@brief �R���X�g���N�^�D
		*	\sa x, pbest_x, v ���������ŏ������D
		*	f, pbest_f �� std::numeric_limits<double>::max()�ŏ������D
		*	@param dim �T����Ԃ̎������D�f�t�H���g��1����
		*/
		Particle(int dim = 1);
		/**
		*	@brief �f�X�g���N�^
		*/
		~Particle();
		/**
		*	@brief �R�s�[�R���X�g���N�^�D
		*	@param that �R�s�[��
		*/
		Particle(const Particle &that);

		/**
		*	@brief ���q�̕]���D
		*	���q��]�����Cpbest_x, pbest_f ���X�V�D
		*	@return ���݂̕]���l f �� pbest_f ��菬���������� ture�D
		*/
		bool evaluate();

		std::vector < double >
			x,			/*!< ���݂̗��q�ʒu */
			pbest_x,	/*!< �ߋ��ɒT�������œK�ȗ��q�ʒu */
			v;			/*!< ���q���x */
		double
			f,			/*!< ���q�̕]���l */
			pbest_f;	/*!< �ߋ��ɒT�������œK�ȗ��q�̕]���l */

		/**
		*	@brief ���q���o�́D
		*	x		x1	x2	...	xn	f	���݂̗��q�ʒu�ƕ]���l
		*	pbest	px1	px2	...	pxn	pf	�œK�ȗ��q�ʒu�ƕ]���l
		*/
		friend std::ostream& operator << (std::ostream& os, const Particle& p);
	};
}