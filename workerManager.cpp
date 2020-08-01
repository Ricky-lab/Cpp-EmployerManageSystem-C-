#include "WorkerManager.h"

WorkerManager::WorkerManager() {
	//初始化属性
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;

	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "File not exist" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，但内容为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "File is empty inside!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//when the file exist and the data is not empty
	int num = this->m_getEmpNum();
	cout << "now the number of emp is " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "【emp ID: " << this->m_EmpArray[i]->m_Id
			<< "】\t【emp Name: " << this->m_EmpArray[i]->m_Name
			<< "】\t【emp dId: " << this->m_EmpArray[i]->m_DeptId << "】" << endl;

	}
}

void WorkerManager::Show_Manu() {

	cout << "***********************************" << endl;
	cout << "Welcome to use EmployeeManageSystem！" << endl;
	cout << "********0.      Exit       ********" << endl;
	cout << "********1.  Add Employee   ********" << endl;
	cout << "********2. Show Employee   ********" << endl;
	cout << "********3. remove Employee ********" << endl;
	cout << "********4.  Edit Employee  ********" << endl;
	cout << "********5.  Find Employee  ********" << endl;
	cout << "********6.   Sort in Id    ********" << endl;
	cout << "********7. Clean the Data  ********" << endl;
	cout << "***********************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem() {
	cout << "Hope to serve you next time!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() {

	cout << "Please enter the number you want to add： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//add

		//calculate
		int newSize = this->m_EmpNum + addNum;

		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArray != NULL)//copy old array into new array
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)//start to add new member
		{
			int id;
			string name;
			int dSelect;

			cout << "Please enter the " << i + 1 << " (th) EMPLOYEE Id：" << endl;
			cin >> id;

			cout << "Please enter the " << i + 1 << " (th) EMPLOYEE's Name：" << endl;
			cin >> name;

			cout << "Please select the position of the EMPLOYEE：" << endl;
			cout << "1、STAFF：" << endl;
			cout << "2、MANAGER：" << endl;
			cout << "3、BOSS：" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;

			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[]this->m_EmpArray;

		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;
		cout << "We have been successfully added " << addNum << " STUFF(s)" << endl;

		this->m_FileIsEmpty = false;// file now is not empty.

		this->save();//save data to file
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Incorrect input. Please retype" << endl;
		system("pause");
		system("cls");
	}

}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

int WorkerManager::m_getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	return num;
}

//after reading from file, initialize the emp in to RAM
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;


	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;

		if (dId == 1)//STAFF{
		{
			worker = new Employee(id, name, dId);

		}
		else if (dId == 2)//MANAGER
		{
			worker = new Manager(id, name, dId);

		}
		else//BOSS
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index++] = worker;

	}

};

//show emp
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file is not exist or no emp in file" << endl;
		system("pause");
		system("cls");

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

//check if emp is exist
int WorkerManager::IsExist(int idd)
{
	int index = -1;


	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == idd)
		{
			index = i;
			break;

		}
	}
	return index;
};

//delete emp
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file is not exist or no emp in file" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "please enter the ID you want to delete" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; //update the num
			this->save();
			cout << "deletion complete!" << endl;
		}
		else
		{
			cout << "this emp can not be found in file" << endl;
			cout << "deletion failed" << endl;
		}
		system("pause");
		system("cls");
	}
};

//edit the emp
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file is not exist or no emp in file" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int res = 0;
		cout << "please enter the ID you want to edit: " << endl;
		cin >> res;
		if (this->IsExist(res) != -1)
		{
			cout << "searching success!" << endl;
			//delete m_EmpArray[res]; Exception thrown

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "ID: " << res << " , please enter an new ID: " << endl;
			cin >> newId;

			cout << "Please enter an new Name: " << endl;
			cin >> newName;

			cout << "Please select a new department: " << endl;
			cout << "1. STAFF" << endl;
			cout << "2. MANAGER" << endl;
			cout << "3. BOSS" << endl;

			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;

			default:
				break;
			}
			this->m_EmpArray[res] = worker;
			cout << "modification complete!!" << endl;

			this->save();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "modification failed, emp doesn't exist!" << endl;
			system("pause");
			system("cls");
		}
	}

}

//find emp
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout<<"file is not exist or no emp in file" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Please select the way to find emp" << endl;
		cout << "1. Find emp by Id" << endl;
		cout << "2. Find emp by Name" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "Please enter the Id: " << endl;
			cin >> id;
			
			int ret = IsExist(id);

			if (ret!= -1)
			{
				cout << "Finding success!! Id: " << id << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "Sorry! This Id is not exist!!" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "Please enter the target Name" << endl;
			string Name;
			cin >> Name;

			bool flag = false;


			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == Name)
				{
					flag = true;

					cout << "Finding success!! Name: " << Name << endl;
					this->m_EmpArray[i]->showInfo();
				}
			}
		}
		else
		{
			cout << "Enter wrong selection! " << endl;
		}
	}

	system("pause");
	system("cls");

}

//Sort emp
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file is not exist or no emp in file" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Please select the way to Sort emp" << endl;
		cout << "1. Sort emp by Ascending" << endl;
		cout << "2. Find emp by Descending" << endl;

		int select;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}

			}
			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}

		}

		cout << "Sorting success!!" << endl;
		this->save();
		this->Show_Emp();
	}
}

//clean file
void WorkerManager::Clean_File()
{
	cout << "Are you sure to clean all data" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;

	int select;
	cin >> select;

	if (select ==1 )
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]!=NULL)
				{
					delete this->m_EmpArray[i];
				}
				this->m_EmpNum = 0;
				delete[]this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;
			}
			cout << "Cleaning success!!" << endl;
		}
		system("pause");
		system("cls");
	}
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]!=NULL)
			{
				delete this->m_EmpArray[i];

			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

