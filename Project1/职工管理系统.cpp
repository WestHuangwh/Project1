#include <iostream>
#include "workerManager.h"
using namespace std;
#include "Worker.h"
#include"putongzhigong.h"
#include"laoban.h"
#include"jinlilei.h"

int main()
{
	int xuanzhesu = 0;
	WorkerManager mw;
	mw.init_Emp();
	while (1)
	{
		mw.show_Menu();
		cin >> xuanzhesu;//����ѡ����
			switch (xuanzhesu)
		{
			case 0://ִ���Ƴ�����
				mw.ExitSystem();
				break;
			case 1://���ְ��
				mw.Add_Emp();
				break;
			case 2://��ʾְ��
				mw.Show_Emp();
				break;
			case 3://ɾ��ְ��
				mw.Del_Emp();
				break;
			case 4://�޸�ְ��
				mw.Mod_Emp();
				break;
			case 5://����ְ��
				mw.Find_Emp();
				break;
			case 6://��ְ�����������
				mw.Sort_Emp();
				break;
			case 7://����ļ�
				mw.Clean_Find();
				break;
			default:
				system("cls");//����
				break;
		}

			
			
	}

	system("pause");
		return 0;
}