#pragma once
#include <iostream>
using namespace std;
#include"Worker.h"
#include"putongzhigong.h"
#include"jinlilei.h"
#include"laoban.h"
#define FILENAME "empfile.txt"
#include<fstream>


class WorkerManager//����
{
	public:

		WorkerManager();//������һ�����캯��

		void show_Menu();//����ְ������ϵͳ���溯��

		void ExitSystem();//�˳�ѡ��0

		void Add_Emp();	//���ְ��	1		

		void save();//�����ļ�

		bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

		int get_Empnum();//ͳ�Ƽ�������

		void init_Emp();//��ʼ��Ա�� _

		void Show_Emp();//��ʾְ��

		void Del_Emp();//ɾ��ְ��

		void Mod_Emp();//�޸�ְ��

		void Find_Emp();//����ְ��

		void Sort_Emp();//���������

		void Clean_Find();//����ļ�

		int InExist(int id);//�ж�Ա���Ƿ����

		~WorkerManager();//����һ����������

		//��¼�ļ�������
		int m_EmpNum ;
		//Ա�������ָ��
		Worker ** m_EmpArray ;
};


	
