#include "employee.h";

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}


void Employee::showInfo() {
	cout << "��Employee ID�� " << this->m_Id
		<< "��\t��Employee Name��" << this->m_Name
		<< "��\t\t��Position��" << this->getDeptName()
		<< "��\t��Duyt: serve to manager��"
		<< endl;
}
string Employee::getDeptName() {
	return string("STAFF");
 }