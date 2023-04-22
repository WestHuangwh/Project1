#include<iostream>
#include"jinlilei.h"

jinli::jinli(int id, string name, int bianhao)
{
	this->m_id = id;
	this->m_name = name;
	this->m_bianhao=bianhao;


}

//显示个人信息
void jinli:: showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t职工岗位" << this->getDepName()
		<< "\t职责：完成老板的任务，下发给员工" << endl;
  }
//获取岗位名称
 string jinli:: getDepName()
{

	 return "经理";
}