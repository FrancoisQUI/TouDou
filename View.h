#pragma once

#include <iostream>

#include "TaskList.h"

using namespace std;

class View
{
public:
	static void showText(string text);
	static string prompt(string question);
	static int showMainMenu();
	static void listTasks(TaskList* taskList);
	static void describeTask(Task* task);
	static void taskView(Task* task);
	static void addTaskView(TaskList* tasklist);
private:
	static void writeSeparation();
};

