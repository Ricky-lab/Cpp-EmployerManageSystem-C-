#pragma once
#include <iostream>
#include<string>
using namespace std;

class Worker
{
public:


	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;

	int m_Id;//employee ID
	string m_Name;// emplyee Name
	int m_DeptId;//Department of emplyee

private:

};

