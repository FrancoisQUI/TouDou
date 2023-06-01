#pragma once

#include <iostream>

using namespace std;


class Task
{
public:
	Task(string name,string description);
	~Task();
	void setName(string name);
	void setDescription(string description);
	string getName();
	string getDescription();
	int getId();

private:
	int m_id;
	string m_name;
	string m_description;

	void generateId();
};

