#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;


class  laoban:public Worker
{
public:
	//构造函数
	laoban(int id, string name, int bianhao);

	//显示个人信息
	virtual  void showInfo() ;
	//获取岗位名称
	virtual string getDepName();

};