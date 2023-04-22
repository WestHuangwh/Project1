#include "workerManager.h"
#include"putongzhigong.h"
#include"jinlilei.h"
#include"laoban.h"

WorkerManager::WorkerManager()//构造函数
{   //初始化
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	if (!ifs.is_open())//判断文件是否存在
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	char ch; //判断文件是否为空
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}
	
	int num = this->get_Empnum();//文件存在，记录数据
	//cout << "职工数量为" << num << "人" << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];//开辟空间
	this->init_Emp();

	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "职工号" << this->m_EmpArray[i]->m_id
			<< "职工姓名" << this->m_EmpArray[i]->m_name
			<< "部门编号" << this->m_EmpArray[i]->m_bianhao << endl;

	}*/

}

void WorkerManager::show_Menu()//界面
{
	cout << "************************************************************" << endl;
	cout << "*****************欢迎使用职工管理系统***********************" << endl;
	cout << "*****************  0.退出职工管理系统 ***********************" << endl;
	cout << "*****************  1.增加职工系统    ***********************" << endl;
	cout << "*****************  2.显示职工信息   ***********************" << endl;
	cout << "*****************  3.删除职工信息   ***********************" << endl;
	cout << "*****************  4.修改职工信息   ***********************" << endl;
	cout << "*****************  5. 查找职工信息  ***********************" << endl;
	cout << "*****************  6.按照编号排序   ***********************" << endl;
	cout << "*****************  7.清空所有文档  *************************" << endl;
	cout << "*************************************************************" << endl;

}

void WorkerManager::ExitSystem()//退出选项
{
	cout<< "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);


	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "  "
			<< this->m_EmpArray[i]->m_name << "  "
			<< this->m_EmpArray[i]->m_bianhao << endl;

	}
	ofs.close();

}


void WorkerManager::Add_Emp()
{
	cout << "输入添加职工数量" << endl;
	int addNum = 0;//保存用户输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL)//将原来信息存储于newSpace中
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];

			}

		}
		for (int i = 0; i < addNum; i++)//进行写入新职工
		{
			int id;
			string name;
			int xiang;
			cout << "请输入第" << i + 1 << "职工的职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "职工的名字" << endl;
			cin >> name;
			cout << "请选择岗位1为普通员工" << endl;
			cout << "请选择岗位2为经理" << endl;
			cout << "请选择岗位3为老板" << endl;
			cin >> xiang;
			Worker* worker = NULL;
			switch (xiang)
			{
			case 1:
				worker = new Putongzhigong(id ,name,1);
				break;
			case 2:
				worker = new jinli(id, name, 2);
				break;
			case 3:
				worker = new laoban(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		cout << "添加成功" << endl;
		
		this->save();
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "添加有误" << endl;
	}
	system("pause");
	system("cls");

}

int WorkerManager::get_Empnum()//计算职工人数
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int bianhao;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> bianhao)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp()//初始化人员
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int bianhao;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> bianhao)
	{
		Worker* worker = NULL;

		if (bianhao == 1)
		{
			worker = new Putongzhigong(id, name, bianhao);
		}

		else if (bianhao == 2)
		{
			worker = new jinli(id, name, bianhao);
		}

		else (bianhao == 3);
		{
			worker = new laoban(id, name, bianhao);
		}
		this->m_EmpArray[index] = worker;//存入数组
		index++;


	}
	ifs.close();
}

void WorkerManager::Show_Emp()//显示职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();

		}

	}
	system("pause");
	system("cls");
}

int WorkerManager::InExist(int id)//判断员工是否存在
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			
			break;
		}

	}
	return index;
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{

		cout << "文件为空" << endl;

	}
	else 
	{
		cout << "输入你要删除的职工号" << endl;
		int id = 0;
		cin >> id;

		int index = this->InExist(id);//判断职工是或存在

		if (index != -1)
		{
			for (int i = index; i < m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			
			}
			this->m_EmpNum--;
			this->save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "未找到该职工" << endl;
		}

	}

	system("pause");
	system("cls");


}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请输入你要更改的职工号" << endl;
		int id = 0;
		cin >> id;
			

		int ret = this->InExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = " ";
			int newbianhao = 0;

			cout << "查到" << id <<"号职工，请输入新职工号" << endl;
			cin >> newid;

			cout << "输入新姓名" << endl;
			cin >> newname;

			cout << "请输入岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newbianhao;
			Worker* worker = NULL;
			switch (newbianhao)
			{
			case 1:
				worker = new Putongzhigong(newid, newname, 1);
				break;
			case 2:
				worker = new jinli(newid, newname, 2);
				break;
			case 3:
				worker = new laoban(newid, newname, 3);
				break;
			default:
				break;

			}
			this->m_EmpArray[ret] = worker;
			cout << "删除成功" << this->m_EmpArray[ret]->m_bianhao << endl;
			this->save();

		}
		else
		{
			cout << "查无此人" << endl;
		}
	}


	system("pause");
	system("cls");
}


void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;

	}
	else
	{
		cout << "请输入你要查找的姓名" << endl;
		string name = "";
		cin >> name;

		bool falg = false;//查找到的标志
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i]->m_name == name)
			{
				cout << "查找成功，该人编号为："
					<< m_EmpArray[i]->m_id
					<< "号信息如下:" << endl;
				falg = true;

				this->m_EmpArray[i]->showInfo(); 

			}
		}
		if (falg == false)
		{
			cout << "查无此人" << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;

		system("pause");
		system("cls");

	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.从小到大排序" << endl;
		cout << "2.从大到小排序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)//利用选择排序
		{
			int miOrMax = 0;//通过比较大小交换下标

			for (int j = 0; j < m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[miOrMax]->m_id > m_EmpArray[j]->m_id)
					{
						miOrMax = j;

					}

				}
				else
				{
					if (this->m_EmpArray[miOrMax]->m_id < m_EmpArray[j]->m_id)//降序
					{
						miOrMax = j;

					}

				}
			}
			
			if (i != miOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[miOrMax];
				m_EmpArray[miOrMax] = temp;
			}

		}
		cout << "排序成功" << endl;
		this->save();
		this->Show_Emp();
	}

}

void WorkerManager::Clean_Find()
{
	cout << "确认是否清空" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式ios：：trunc如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			//删除堆区数组指针
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()//析构函数
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] = NULL) 
			{
				delete[]this->m_EmpArray;
			}
			
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}

}