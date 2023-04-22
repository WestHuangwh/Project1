#include<iostream>
#include"laoban.h"

laoban::laoban(int id, string name, int bianhao)
{
	this->m_id = id;
	this->m_name = name;
	this->m_bianhao=bianhao;
}

//显示个人信息
void laoban::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t职工岗位" << this->getDepName()
		<< "\t职责：给经理安排任务" << endl;
}
//获取岗位名称
string laoban::getDepName()
{
	return "老板";
}