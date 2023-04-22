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
		cin >> xuanzhesu;//输入选择功能
			switch (xuanzhesu)
		{
			case 0://执行推出功能
				mw.ExitSystem();
				break;
			case 1://添加职工
				mw.Add_Emp();
				break;
			case 2://显示职工
				mw.Show_Emp();
				break;
			case 3://删除职工
				mw.Del_Emp();
				break;
			case 4://修改职工
				mw.Mod_Emp();
				break;
			case 5://查找职工
				mw.Find_Emp();
				break;
			case 6://给职工按编号排序
				mw.Sort_Emp();
				break;
			case 7://清空文件
				mw.Clean_Find();
				break;
			default:
				system("cls");//清屏
				break;
		}

			
			
	}

	system("pause");
		return 0;
}