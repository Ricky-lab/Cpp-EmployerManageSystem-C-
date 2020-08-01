#include"boss.h"


Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}

void Boss::showInfo() {
	cout << "¡¾Employee ID£º " << this->m_Id
		<< "¡¿\t¡¾Employee Name£º" << this->m_Name
		<< "¡¿\t¡¾Position£º" << this->getDeptName()
		<< "¡¿\t¡¾Duty: to order the Manager¡¿"
		<< endl;
};

string Boss::getDeptName() {
	return string("BOSS");
};
