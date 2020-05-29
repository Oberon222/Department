#pragma once
#include <iostream>
using namespace std;

enum WorkerType
{
	NONE,
	DIRECTOR,
	ADMIN,
	PROGRAMMER,
	DESIGNER
};

class Worker
{
	char name[50];
	int startYear;
	double salary;
	WorkerType type; 

public:
	Worker()
	{
		strcpy_s(name, "No name");
		startYear = 0;
		salary = 0;
		type = NONE;
	}

	Worker(const char* name, double salary, int startYear,WorkerType type)
		: salary(salary), startYear(startYear), type(type)
	{
		strcpy_s(this->name, name);
	}

	char* GetName();
	
	int GetStartYear();
	

	double GetSalary();
	

	WorkerType GetType();
	


	void PrintShortInfo()const;
	void PrintFullInfo()const;
};

class Department
{
	Worker* workers;
	int workersCount;

public:
	Department()
	{
		workers = nullptr;
		workersCount = 0;
	}

	Department(const Department& other) // конструкотор копіювання
	{
		this->workersCount = other.workersCount;
		this->workers = new Worker[other.workersCount];
		for (int i = 0; i < other.workersCount; i++) {
			this->workers[i] = other.workers[i];
		}
	}
	

	~Department()
	{
		delete[]workers;
	}


	void AddWorker(const Worker& newWorker);

	void DeleteWorker(int numbPosition);

	void ShowWorkers()const;

	void SerchWorkerByName(const char* name) const;

	double GetAverageSalary();

	void SerchByType(const WorkerType type) const;

	void SerchByExperience(const int exp) const;
};