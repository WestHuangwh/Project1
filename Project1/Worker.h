#pragma once
#include <iostream>
#include <string>
using namespace std;



class Worker//������Ա
{
public:

	//��ʾ������Ϣ
	virtual  void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDepName() = 0;

	int m_id;
	string m_name;
	int m_bianhao;
};