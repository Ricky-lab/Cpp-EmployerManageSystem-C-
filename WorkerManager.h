#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"



class WorkerManager {
public:
	WorkerManager();

	//show
	void Show_Manu();

	//exit
	void ExitSystem();

	//
	int m_EmpNum;

	//add
	void Add_Emp();

	//save file
	void save();

	//File isEmpty
	bool m_FileIsEmpty;

	//count up the person in file
	int m_getEmpNum();

	//after reading from file, initialize the emp in to RAM
	void init_Emp();

	//show emp
	void Show_Emp();

	//delete emp
	void del_Emp();

	//check if emp is exist
	int IsExist(int id);

	//edit the emp
	void Mod_Emp();

	//find emp
	void find_Emp();

	//Sort emp
	void sort_Emp();

	//clean file
	void Clean_File();


	Worker** m_EmpArray;
	

	~WorkerManager();
};