#pragma once
#include <string>

using namespace std;

class Task {
	string taskid;
	string title;
	string description;
	string timestamp;
public:
	Task();
	Task(string taskid, string title, string description, string timestamp);
	string getTaskId();
	string getTaskTitle();
	string getTaskDescription();
	string getTaskTimeStamp();
};
