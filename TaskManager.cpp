#include "task.h"
#include "TaskManager.h"

TaskManager::TaskManager() {
}

void TaskManager::addTask(Task* task) {
	taskList.push_back(task);
}

void TaskManager::removeTask() {

	if (taskList.empty())
		throw "Task List empty Exception";

	taskList.pop_front();
}

std::deque<Task*> TaskManager::getTaskList() {
	return taskList;
}