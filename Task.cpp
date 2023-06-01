#include "Task.h"

int NextId = 0;

Task::Task(string name, string description)
{
	setName(name);
	setDescription(description);
	generateId();
}

Task::~Task()
{

}

void Task::setName(string name)
{
	this->m_name = name;
}

void Task::setDescription(string description)
{
	this->m_description = description;
}


string Task::getName()
{
	return string(this->m_name);
}

string Task::getDescription()
{
	return string(this->m_description);
}

int Task::getId()
{
	return this->m_id;
}

void Task::generateId()
{
	this->m_id = NextId;
	NextId++;
}
