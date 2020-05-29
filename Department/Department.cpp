#include"Department.h"
#include <iostream>

using namespace std;

char* Worker::GetName()
{
	return name;
}



int Worker::GetStartYear()
{
	return startYear;
}

double Worker::GetSalary()
{
	return salary;
}

WorkerType Worker::GetType()
{
	return type;
}

void Worker::PrintShortInfo() const
{
	cout << "Name " << name << endl;
	cout << "Salary " << salary << endl;
}

void Worker::PrintFullInfo() const
{
	cout << "Name " << name << endl;
	cout << "from what year he started working " << startYear << endl;
	cout << "Salary " << salary << endl;
	cout << "Position " << type << endl;
}


void Department::AddWorker(const Worker& newWorker)
{
	Worker* tmp = new Worker[workersCount + 1];
	for (int i = 0; i < workersCount; i++) {
		tmp[i] = workers[i];
	}
	tmp[workersCount] = newWorker;
	delete[]workers;
	workers = tmp;
	++workersCount;
}

void Department::DeleteWorker(int numbPosition)
{
	if (numbPosition > 0 && numbPosition <= workersCount) {
		for (int i = numbPosition - 1; i < workersCount - 1; i++) {
			workers[i] = workers[i + 1];
		}
		workersCount--;
	}
}

void Department::ShowWorkers() const
{
	for (int i = 0; i < workersCount; i++) {
		cout << i + 1 << ") "; workers[i].PrintShortInfo();

	}
}

void Department::SerchWorkerByName(const char* name) const
{
	for (int i = 0; i < workersCount; i++) {
		if (strcmp(workers[i].GetName(), name) == 0) {
			workers[i].PrintFullInfo();
		}
	}
}

double Department::GetAverageSalary()
{
	double suma=0;
	for (int i = 0; i < workersCount; i++) {
		suma += workers[i].GetSalary();
	}

	return suma/ workersCount;
}

void Department::SerchByType(const WorkerType type) const
{
	for (int i = 0; i < workersCount; i++) {
		if (workers[i].GetType() == type) {
			cout << i + 1 << ")"; workers[i].PrintFullInfo();
		}
	}
}

void Department::SerchByExperience(const int exp) const
{
	for (int i = 0; i < workersCount; i++) {
		int currentYear = 2020;
		if ((currentYear - workers[i].GetStartYear()) > exp) {
			workers[i].PrintFullInfo();
		}
	}
}


