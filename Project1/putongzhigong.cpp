#include <iostream>
#include "putongzhigong.h"

//���캯��
Putongzhigong::Putongzhigong(int id,string name,int bianhao)
{
	this->m_id = id;
	this->m_name = name;
	this->m_bianhao = bianhao;
}

//��ʾ������Ϣ
void Putongzhigong::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\tְ����λ" << this->getDepName()
		<< "\tְ����ɾ������������" << endl;

}
//��ȡ��λ����
string Putongzhigong::getDepName() 
{
	return "Ա��";
 }