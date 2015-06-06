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
	*	@brief PSO�̃x�[�X�N���X�D
	*/
	class BasePSO
	{
		/** ���������� */
		std::mt19937 _mt;
		std::uniform_real_distribution<> _urd;
	protected:
		/**
		*	@struct ���ʊi�[�\����
		*/
		typedef struct
		{
			int t;			/*!< �X�V�� */
			dvec gbest_x;	/*!< ���q�Q�œK�ʒu */
			double gbest_f;	/*!< �œK�ȕ]���l */
		} result;

		int
			_itr,	/*!< �ő�X�V�� */
			_pop;	/*!< ���q�� */
		std::vector<Particle> _particles;	/*!< ���q�Q */
		dvec _gbest_x;		/*!< ���q�Q���T�������œK�Ȉʒu */
		double _gbest_f;	/*!< ���q�Q���T�������œK�ȕ]���l */
		CostFunction _func;	/*!< �R�X�g�֐��N���X */

		/**
		*	@brief PSO�̏������D
		*	���q�Q�𗐐���p���ď���������
		*/
		virtual void initialize();
		/**
		*	@brief PSO�̍X�V�i���z�֐��j
		*	PSO�̎�ނɂ���ăT�u�N���X�ŃI�[�o�[���C�h����D
		*/
		virtual bool update() = 0;
		/**
		*	@brief ���q�̕]��
		*	���q�̕]�����s���Cgbest�����߂�D
		*/
		virtual bool evaluate(Particle& p);

		/**
		*	@brief ��l����[min,max)�̐���
		*	@param min ����
		*	@param max ���
		*	@return [min,max)�̈�l����
		*/
		double uniform(double min = 0., double max = 1.);

		/**
		*	@brief target��[min,max]���ɐ���
		*	@param val �l
		*	@param min ����
		*	@param max ���
		*/
		double set_domain(double val, double min, double max);
	public:
		std::vector<result> results;

		/**
		*	@brief �R���X�g���N�^
		*	@param itr �ő�X�V��
		*	@param pop ���q��
		*	@param dim ������
		*/
		BasePSO(CostFunction func,int itr, int pop);
		/**
		*	@brief �f�X�g���N�^
		*/
		~BasePSO();

		/**
		*	@brief PSO�����X�^�[�g�D
		*	PSO�̏������J�n����D
		*/
		void Start();
		///**
		//*	@brief PSO�����X�^�[�g�D
		//*	PSO�̏������J�n����D
		//*	@param epoch_callback �e�X�V���ƂɌĂяo�����R�[���o�b�N
		//*/
		//void Start(std::function<void()> epoch_callback);
	};

}
