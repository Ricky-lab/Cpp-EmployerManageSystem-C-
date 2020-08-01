#include"manager.h"


Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}

void Manager::showInfo() {
	cout << "¡¾Employee ID£º " << this->m_Id
		<< "¡¿\t¡¾Employee Name£º" << this->m_Name
		<< "¡¿\t¡¾Position£º" << this->getDeptName()
		<< "¡¿\t¡¾Duyt: serve BOSS and order STAFF¡¿"
		<< endl;
};

string Manager::getDeptName() {
	return string("MANAGER");
};
