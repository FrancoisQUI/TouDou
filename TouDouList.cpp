// TouDouList.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Task.h"
#include "TaskList.h"
#include "View.h"
#include "TouDouList.h"


void makeAction(int action, TaskList* taskList);

int main()
{
    TaskList* tasklist = TaskList::getInstance();
    tasklist->addTask("Titre", "Une Description");
    tasklist->addTask("Une Seconde tache", "Une Autre Description");

    bool next = true;
    // Boucle principale
    while (next)
    {
        int action = View::showMainMenu();
		if (action == 3)
			next = false;
		else if (action == 1)
			View::listTasks(tasklist);
		else if (action == 2)
			View::addTaskView(tasklist);
		else
			View::showText("Action non reconnue");
	}
}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
