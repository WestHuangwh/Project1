#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class jinli :public Worker
{
public:
	//���캯��
	jinli(int id, string name, int bianhao);

	//��ʾ������Ϣ
	virtual  void showInfo() ;
	//��ȡ��λ����
	virtual string getDepName() ;

};