#include"boss.h"


Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}

void Boss::showInfo() {
	cout << "��Employee ID�� " << this->m_Id
		<< "��\t��Employee Name��" << this->m_Name
		<< "��\t��Position��" << this->getDeptName()
		<< "��\t��Duty: to order the Manager��"
		<< endl;
};

string Boss::getDeptName() {
	return string("BOSS");
};
