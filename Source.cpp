#include <iostream>
#include "TaskManager.h"
#include "Task.h"
#include <chrono>
#include <ctime>  
#include <string>

using namespace std;

class TaskSchedularClient {
	TaskManager* taskManager;

	char* getTimeStamp() {

		auto end = std::chrono::system_clock::now();
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		return std::ctime(&end_time);
	}

public:
	TaskSchedularClient() {
		taskManager = new TaskManager();
	}

	void displayCLI() {
		int option;
		string taskid;
		string title;
		string description;
		string timestamp;
		std::deque<Task*> list;

		while (true) {
			cout << "1. New Task" << endl;
			cout << "2. Remove Task" << endl;
			cout << "3. List Task" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter options [1..4]: ";
			cin >> option;

			switch (option) {

			case 1: cout << "Enter Task details..." << endl;
				cout << "Enter Task ID:";
				cin >> taskid;
				cout << "Enter Task Title:";
				cin >> title;
				cout << "Enter Description :";
				cin >> description;
				timestamp = getTimeStamp();
				taskManager->addTask(new Task(taskid, title, description, timestamp));
				break;

			case 2: cout << "Remove task from queue" << endl;
				taskManager->removeTask();

				break;
			case 3:
				cout << "display all task..." << endl;
				list = taskManager->getTaskList();
				for (auto itr = list.begin(); itr != list.end(); itr++)
					cout << "Task Title : " << (*itr)->getTaskTitle().c_str() << endl;

				break;
			case 4:
				return;
				break;

			default: cout << "Invalid Option selected... try again..." << endl;

			}
		}
	}
};

int main() {

	TaskSchedularClient* client = new TaskSchedularClient();
	client->displayCLI();


	/*
	TaskManager *taskManager = new TaskManager();

	taskManager->addTask(new Task("001", "T1", "do t1", "00:00:00"));
	taskManager->addTask(new Task("002", "T2", "do t2", "00:00:00"));
	taskManager->addTask(new Task("003", "T3", "do t3", "00:00:00"));
	taskManager->addTask(new Task("004", "T4", "do t4", "00:00:00"));

	auto taskList = taskManager->getTaskList();

	for (auto itr = taskList.begin(); itr != taskList.end(); itr++)
	{
		cout << "Task Title : " << (*itr)->getTaskTitle().c_str() << endl;
	}

	taskManager->removeTask();
	taskManager->removeTask();

	taskList = taskManager->getTaskList();

	cout << "After removing t1 & t2" << endl;

	for (auto itr = taskList.begin(); itr != taskList.end(); itr++)
	{
		cout << "Task Title : " << (*itr)->getTaskTitle().c_str() << endl;
	}

	*/
	return 0;
}

