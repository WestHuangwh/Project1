#pragma once
#include <iostream>
using namespace std;
#include"Worker.h"
#include"putongzhigong.h"
#include"jinlilei.h"
#include"laoban.h"
#define FILENAME "empfile.txt"
#include<fstream>


class WorkerManager//界面
{
	public:

		WorkerManager();//这是在一个构造函数

		void show_Menu();//这是职工管理系统界面函数

		void ExitSystem();//退出选项0

		void Add_Emp();	//添加职工	1		

		void save();//保存文件

		bool m_FileIsEmpty;//判断文件是否为空

		int get_Empnum();//统计计算人数

		void init_Emp();//初始化员工 _

		void Show_Emp();//显示职工

		void Del_Emp();//删除职工

		void Mod_Emp();//修改职工

		void Find_Emp();//查找职工

		void Sort_Emp();//按编号排序

		void Clean_Find();//清空文件

		int InExist(int id);//判断员工是否存在

		~WorkerManager();//这是一个析构函数

		//记录文件中人数
		int m_EmpNum ;
		//员工数组的指针
		Worker ** m_EmpArray ;
};


	
