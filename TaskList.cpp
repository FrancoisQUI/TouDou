#include "TaskList.h"

TaskList::TaskList()
{
}

TaskList* TaskList::instance = nullptr;

TaskList* TaskList::getInstance()
{
	if (instance == nullptr)
		instance = new TaskList();
	return instance;
}

bool TaskList::addTask(string name, string description)
{
	Task task = Task(name, description);
	m_tasks.push_back(task);
	return true;
}

bool TaskList::addTask(Task task)
{
	m_tasks.push_back(task);
	return true;
}

bool TaskList::removeTask(Task* task)
{
	for (int i = 0; i < m_tasks.size(); i++)
	{
		if (m_tasks[i].getId() == task->getId())
		{
			m_tasks.erase(m_tasks.begin() + i);
			return true;
		}
	}
	return false;
}

vector<Task> TaskList::getTasks()
{
	return m_tasks;
}

Task* TaskList::getTheTask(int index)
{
	Task* taskPtr = &m_tasks[index];
	return taskPtr;
}
