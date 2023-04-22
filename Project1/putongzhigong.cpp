#include <iostream>
#include "putongzhigong.h"

//构造函数
Putongzhigong::Putongzhigong(int id,string name,int bianhao)
{
	this->m_id = id;
	this->m_name = name;
	this->m_bianhao = bianhao;
}

//显示个人信息
void Putongzhigong::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t职工岗位" << this->getDepName()
		<< "\t职责：完成经理交给你的任务" << endl;

}
//获取岗位名称
string Putongzhigong::getDepName() 
{
	return "员工";
 }