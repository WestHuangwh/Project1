#pragma once//��ͨԱ���ļ�
#include<iostream>
#include"Worker.h"
using namespace std;

class Putongzhigong :public Worker
{
public:
	//���캯��
	Putongzhigong(int id , string name , int bianhao);

	//��ʾ������Ϣ
	virtual  void showInfo();
	//��ȡ��λ����
	virtual string getDepName();

};