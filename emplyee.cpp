#include "employee.h";

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}


void Employee::showInfo() {
	cout << "¡¾Employee ID£º " << this->m_Id
		<< "¡¿\t¡¾Employee Name£º" << this->m_Name
		<< "¡¿\t\t¡¾Position£º" << this->getDeptName()
		<< "¡¿\t¡¾Duyt: serve to manager¡¿"
		<< endl;
}
string Employee::getDeptName() {
	return string("STAFF");
 }