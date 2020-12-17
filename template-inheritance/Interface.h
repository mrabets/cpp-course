#pragma once

#include "Laptop.h"
#include "Tablet.h"
#include "Monoblock.h"
#include "Ring.h"

template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void serviceMenu();
};

template <class T>
void Interface<T>::serviceMenu()
{
	Ring<T> object;

	while (true)
	{
		cout << "Choose operation:" << endl << endl
			<< "1. Add to begin" << endl
			<< "2. Add to end" << endl
			<< "3. Add by index" << endl << endl
			<< "4. Delete first" << endl
			<< "5. Delete last" << endl
			<< "6. Delete by index" << endl
			<< "7. Delete all" << endl << endl
			<< "8. Change data" << endl << endl
			<< "9. Display data" << endl << endl
			<< "10. Out number of nodes" << endl << endl
			<< "0. Exit" << endl;

		int choiceMenu;
		cin >> choiceMenu;

		system("CLS");
		
		T value;
		int index;

		switch (choiceMenu)
		{
		case 1:
			cin >> value;
			object.addToBegin(value);

			break;

		case 2:
			cin >> value;
			object.addToEnd(value);

			break;

		case 3:
			cout << "Enter the index: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Incorrectly index" << endl;
				break;
			}

			cin >> value;

			object.addByIndex(value, index);

			break;

		case 4:
			object.deleteFirst();
			break;

		case 5:
			object.deleteLast();
			break;

		case 6:
			cout << "Enter the index: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Incorrectly index" << endl;
				break;
			}

			object.deleteByIndex(index);

			break;

		case 7:
			object.clear();
			break;

		case 8:
			cout << "Enter the index: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Incorrectly index" << endl;
				break;
			}

			object.changeData(index);

			break;

		case 9:
			object.display();
			break;

		case 10:
			cout << "Count of nodes: " << object.getCountOfNodes() << endl;
			break;

		case 0:
			return;
		}

		cout << endl;
	}
}

void typeChoosing()
{
	while (true)
	{
		int choiceDevice;

		cout << "Choose one of device: " << endl << endl
			<< "1. Laptop" << endl
			<< "2. Tablet" << endl
			<< "3. Monoblock" << endl << endl
			<< "0. Exit" << endl;

		cin >> choiceDevice;

		system("CLS");

		switch (choiceDevice)
		{
		case 1:
		{
			Interface<Laptop> object;
			object.serviceMenu();
		}	
			break;

		case 2:
		{
			Interface<Tablet> object;
			object.serviceMenu();
		}
			break;

		case 3:
		{
			Interface<Monoblock> object;
			object.serviceMenu();
		}
			break;

		case 0:
			return;
		}
	}
}