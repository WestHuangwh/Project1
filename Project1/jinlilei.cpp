#include<iostream>
#include"jinlilei.h"

jinli::jinli(int id, string name, int bianhao)
{
	this->m_id = id;
	this->m_name = name;
	this->m_bianhao=bianhao;


}

//��ʾ������Ϣ
void jinli:: showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\tְ����λ" << this->getDepName()
		<< "\tְ������ϰ�������·���Ա��" << endl;
  }
//��ȡ��λ����
 string jinli:: getDepName()
{

	 return "����";
}