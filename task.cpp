#include <string>
#include "Task.h"
using namespace std;

Task::Task() {
}
Task::Task(string taskid, string title, string description, string timestamp)
{
	this->taskid = taskid;
	this->title = title;
	this->description = description;
	this->timestamp = timestamp;
}

string Task::getTaskId() {
	return taskid;
}
string Task::getTaskTitle() {
	return title;
}
string Task::getTaskDescription() {
	return description;
}
string Task::getTaskTimeStamp() {
	return timestamp;
}
