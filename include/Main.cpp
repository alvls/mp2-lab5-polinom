#include <iostream>
#include "TaskGenerator.cpp"
#include "Queue_task.cpp"
#include "Claster.cpp"
using namespace std;
void main() {
	char c;
	double p;
	Queue_task tasks;
	Claster Cl;
	int Max_takt;
	cout << "Enter p ";
	cin >> p;
	TaskGenerator TG(p);
	cout << "Enter max Takt ";
	cin >> Max_takt;
	for (int i = 0; i < Max_takt; i++) {
		cout << "1 - Next takt \n";
		cout << "2 - End and watch statistic\n";
		cout << "3 - change p\n";
		cin >> c;
		switch (c)
		{
		case'1':
			TG.createTask();
			tasks = TG.GetTasks();
			tasks = Cl.SetTask(tasks);
			Cl.maketakt();
			break;
		case '2':
			cout << "Number of takts:      " << i << endl;
			cout << "Number of make tasks: " << Cl.GetMakeTask() << endl;

		default:
			break;
		}

	}
}

