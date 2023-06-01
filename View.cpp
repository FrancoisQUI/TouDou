#include "View.h"
#include <String>

void View::showText(string text)
{
	cout << text << endl;
	writeSeparation();
}

string View::prompt(string question)
{
	string response;	
	cout << question << endl;
	cin.ignore();
	getline(cin, response);
	writeSeparation();
	return string(response);	
}

int View::showMainMenu()
{
	string response;
	
	cout << "Bienvenue dans le gestionnaire de tâche" << endl;
	cout << "1 : Lister les taches" << endl;
	cout << "2 : Ajouter une tache" << endl;
	cout << "3 : Quitter" << endl;

	cin >> response;
	return stoi(response);
}

void View::writeSeparation()
{
	cout << "------------------------" << endl;
}


void View::listTasks(TaskList* taskList)
{
	int n = 0;
	for (Task task : taskList->getTasks())
	{
		cout << "Tache no " << n << " : " << task.getName() << endl;
		n++;
		writeSeparation();
	}
	cout << "Choisir une tache" << endl;
	cin.ignore();
	cin >> n;
	writeSeparation();
	if (n < 0 || n >= taskList->getTasks().size())
	{
		cout << "Tache non existante" << endl;
		writeSeparation();
		return;
	} else {		
		taskView(taskList->getTheTask(n));
	}

}


void View::describeTask(Task* task)
{
	writeSeparation();
	cout << "Titre : " << task->getName() << endl;
	cout << "Description : " << task->getDescription() << endl;
	writeSeparation();
}

void View::taskView(Task* task)
{
	writeSeparation();
	cout << "Titre : " << task->getName() << endl;
	cout << "Description : " << task->getDescription() << endl;
	cout << "1 : Modifier le titre" << endl;
	cout << "2 : Modifier la description" << endl;
	cout << "3 : Supprimer la tache" << endl;
	cout << "4 : Retour" << endl;
	writeSeparation();

	string response;
	cin >> response;

	switch (stoi(response))
	{
		case 1:
		task->setName(prompt("Donner un nouveau titre"));
		case 2:
		task->setDescription(prompt("Donner une nouvelle description"));
		case 3:
		TaskList::removeTask(task);
		break;
	}
}

void View::addTaskView(TaskList* tasklist)
{
	string name;
	string description;
	writeSeparation();
	cout << "Ajouter une tache" << endl;
	cout << "Donner un titre" << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Decrire la tache" << endl;
	cin.ignore();
	getline(cin, description);
	Task task = Task(name, description);
	tasklist->addTask(task);
	writeSeparation();
	cin.ignore();
}

