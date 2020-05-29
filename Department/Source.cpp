#include <iostream>
#include"Department.h"
using namespace std;



int main() {
	Department p1;
	p1.AddWorker(Worker ("Vova", 7.45, 2015, PROGRAMMER));
	p1.ShowWorkers();


	system("pause");
	return 0;
}