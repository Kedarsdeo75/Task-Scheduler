#pragma once
#include <deque>
#include "Task.h"
using namespace std;

class TaskManager {

	std::deque<Task*> taskList;
public:
	TaskManager();
	void addTask(Task*);
	void removeTask();
	std::deque<Task*> getTaskList();
};


