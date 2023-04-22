#include "workerManager.h"
#include"putongzhigong.h"
#include"jinlilei.h"
#include"laoban.h"

WorkerManager::WorkerManager()//���캯��
{   //��ʼ��
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	if (!ifs.is_open())//�ж��ļ��Ƿ����
	{
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	char ch; //�ж��ļ��Ƿ�Ϊ��
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}
	
	int num = this->get_Empnum();//�ļ����ڣ���¼����
	//cout << "ְ������Ϊ" << num << "��" << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];//���ٿռ�
	this->init_Emp();

	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "ְ����" << this->m_EmpArray[i]->m_id
			<< "ְ������" << this->m_EmpArray[i]->m_name
			<< "���ű��" << this->m_EmpArray[i]->m_bianhao << endl;

	}*/

}

void WorkerManager::show_Menu()//����
{
	cout << "************************************************************" << endl;
	cout << "*****************��ӭʹ��ְ������ϵͳ***********************" << endl;
	cout << "*****************  0.�˳�ְ������ϵͳ ***********************" << endl;
	cout << "*****************  1.����ְ��ϵͳ    ***********************" << endl;
	cout << "*****************  2.��ʾְ����Ϣ   ***********************" << endl;
	cout << "*****************  3.ɾ��ְ����Ϣ   ***********************" << endl;
	cout << "*****************  4.�޸�ְ����Ϣ   ***********************" << endl;
	cout << "*****************  5. ����ְ����Ϣ  ***********************" << endl;
	cout << "*****************  6.���ձ������   ***********************" << endl;
	cout << "*****************  7.��������ĵ�  *************************" << endl;
	cout << "*************************************************************" << endl;

}

void WorkerManager::ExitSystem()//�˳�ѡ��
{
	cout<< "��ӭ�´�ʹ��" << endl;
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
	cout << "�������ְ������" << endl;
	int addNum = 0;//�����û���������
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL)//��ԭ����Ϣ�洢��newSpace��
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];

			}

		}
		for (int i = 0; i < addNum; i++)//����д����ְ��
		{
			int id;
			string name;
			int xiang;
			cout << "�������" << i + 1 << "ְ����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���λ1Ϊ��ͨԱ��" << endl;
			cout << "��ѡ���λ2Ϊ����" << endl;
			cout << "��ѡ���λ3Ϊ�ϰ�" << endl;
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
		cout << "��ӳɹ�" << endl;
		
		this->save();
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");

}

int WorkerManager::get_Empnum()//����ְ������
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

void WorkerManager::init_Emp()//��ʼ����Ա
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
		this->m_EmpArray[index] = worker;//��������
		index++;


	}
	ifs.close();
}

void WorkerManager::Show_Emp()//��ʾְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ��" << endl;
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

int WorkerManager::InExist(int id)//�ж�Ա���Ƿ����
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

		cout << "�ļ�Ϊ��" << endl;

	}
	else 
	{
		cout << "������Ҫɾ����ְ����" << endl;
		int id = 0;
		cin >> id;

		int index = this->InExist(id);//�ж�ְ���ǻ����

		if (index != -1)
		{
			for (int i = index; i < m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			
			}
			this->m_EmpNum--;
			this->save();

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
		}

	}

	system("pause");
	system("cls");


}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ���ĵ�ְ����" << endl;
		int id = 0;
		cin >> id;
			

		int ret = this->InExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = " ";
			int newbianhao = 0;

			cout << "�鵽" << id <<"��ְ������������ְ����" << endl;
			cin >> newid;

			cout << "����������" << endl;
			cin >> newname;

			cout << "�������λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			cout << "ɾ���ɹ�" << this->m_EmpArray[ret]->m_bianhao << endl;
			this->save();

		}
		else
		{
			cout << "���޴���" << endl;
		}
	}


	system("pause");
	system("cls");
}


void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;

	}
	else
	{
		cout << "��������Ҫ���ҵ�����" << endl;
		string name = "";
		cin >> name;

		bool falg = false;//���ҵ��ı�־
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i]->m_name == name)
			{
				cout << "���ҳɹ������˱��Ϊ��"
					<< m_EmpArray[i]->m_id
					<< "����Ϣ����:" << endl;
				falg = true;

				this->m_EmpArray[i]->showInfo(); 

			}
		}
		if (falg == false)
		{
			cout << "���޴���" << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;

		system("pause");
		system("cls");

	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.��С��������" << endl;
		cout << "2.�Ӵ�С����" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)//����ѡ������
		{
			int miOrMax = 0;//ͨ���Ƚϴ�С�����±�

			for (int j = 0; j < m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[miOrMax]->m_id > m_EmpArray[j]->m_id)
					{
						miOrMax = j;

					}

				}
				else
				{
					if (this->m_EmpArray[miOrMax]->m_id < m_EmpArray[j]->m_id)//����
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
		cout << "����ɹ�" << endl;
		this->save();
		this->Show_Emp();
	}

}

void WorkerManager::Clean_Find()
{
	cout << "ȷ���Ƿ����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽios����trunc�������ɾ���ļ������´���
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
			//ɾ����������ָ��
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()//��������
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