#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;


class  laoban:public Worker
{
public:
	//���캯��
	laoban(int id, string name, int bianhao);

	//��ʾ������Ϣ
	virtual  void showInfo() ;
	//��ȡ��λ����
	virtual string getDepName();

};