#include"manager.h"


Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}

void Manager::showInfo() {
	cout << "��Employee ID�� " << this->m_Id
		<< "��\t��Employee Name��" << this->m_Name
		<< "��\t��Position��" << this->getDeptName()
		<< "��\t��Duyt: serve BOSS and order STAFF��"
		<< endl;
};

string Manager::getDeptName() {
	return string("MANAGER");
};
