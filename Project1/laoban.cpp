#include<iostream>
#include"laoban.h"

laoban::laoban(int id, string name, int bianhao)
{
	this->m_id = id;
	this->m_name = name;
	this->m_bianhao=bianhao;
}

//��ʾ������Ϣ
void laoban::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\tְ����λ" << this->getDepName()
		<< "\tְ�𣺸�����������" << endl;
}
//��ȡ��λ����
string laoban::getDepName()
{
	return "�ϰ�";
}