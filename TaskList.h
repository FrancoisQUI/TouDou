#pragma once

#include <iostream>
#include <vector>

#include "Task.h"

using namespace std;

class TaskList
{
protected :

public :
	static TaskList *getInstance();
	bool addTask(string name,string description);
	bool addTask(Task task);
	static bool removeTask(Task* task);
	vector<Task> getTasks();
	Task* getTheTask(int index);

private :
	TaskList();
	static TaskList* instance;
	vector<Task> m_tasks;
};

