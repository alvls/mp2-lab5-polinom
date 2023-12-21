#include <ctime>
#include <random>
#include "Queue_task.cpp"
class TaskGenerator {
	int Max_time = 15;
	int Max_nodes = 15;
	double p;
	Queue_task Tasks;
public:
	TaskGenerator(double _p) { p = _p; }
	Queue_task createTask(Queue_task tas) {
		Tasks = tas;
		srand(time(0));
		double chanse;
		Task tmp;
		for (int i = 0; i < 10; i++) {
			chanse = rand() % 100;
			if (chanse < p * 100) {
				tmp.time = rand() % Max_time;
				tmp.number_of_nodes = rand() % Max_nodes;
				Tasks.Push(tmp);
			}
		}
		return Tasks;
	}

	Queue_task GetTasks() { return Tasks; }
	void ChangeP(double _p) { p = _p; }
	double GetP() { return p; }
	int getSize(){ return Tasks.GetSize(); }
};