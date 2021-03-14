#pragma once

using namespace std;

template<class T>
class Ring
{
private:
	template<class T>
	class Node
	{
	public:
		Node* next;
		T data;

		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;

			countOfNodes++;
		}
	};
	int size;
	Node<T>* head;

	static int countOfNodes;
	void displayBase();
	

public:
	Ring();
	~Ring();

	int getSize();

	void addToEmpty(T data);
	void addToBegin(T data);
	void addToEnd(T data);
	void addByIndex(T value, int index);

	void fileService();

	void deleteFirst();
	void deleteLast();
	void deleteByIndex(int index);
	void clear();

	void changeData(int index);
	void display();

	static int getCountOfNodes();

	void fileServiceBase(string fileName);
};

template<class T>
void Ring<T>::fileServiceBase(string fileName)
{
	fstream fs;

	while (true)
	{
		cout << "Choose operation for work with file system: " << endl << endl
			<< "1. Write data" << endl
			<< "2. Overwrite data" << endl
			<< "3. Read data" << endl
			<< "4. Print data to screen" << endl
			<< "5. Delete data" << endl << endl
			<< "0. Back" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		string info;
		switch (choice)
		{
		case 1:
		{
			FileTxt<T> fileObject(fileName, ios::out | ios::app);

			if (!fileObject.isOpened())
			{
				cout << "Cannot open file" << endl << endl;
			}
			else
			{
				if (head == nullptr)
				{
					cout << "The table is empty" << endl;
					break;
				}

				Node<T>* current = head;

				while (current->next != head)
				{
					fileObject.WriteToFile(current->data);
					//fs << current->data;
					current = current->next;
				}

				fileObject.WriteToFile(current->data);

				cout << "Succesfully writed" << endl << endl;
			}

			break;
		}
		case 2:
		{
			fs.open(fileName, fstream::out | fstream::trunc);

			if (!fs.is_open())
			{
				cout << "Ошибка открытия файла" << endl;
			}
			else
			{
				if (head == nullptr)
				{
					cout << "Таблица пуста" << endl;
					break;
				}

				Node<T>* current = head;
				while (current->next != head)
				{
					fs << current->data;
					current = current->next;
				}

				fs << current->data;

				cout << "Данные успешно перезаписаны в базу данных" << endl << endl;
			}

			fs.close();
			break;
		}

		case 3:
		{
			FileTxt<T> fileObject(fileName, ios::in);

			if (!fileObject.isOpened())
			{
				cout << "Cannot read file" << endl;
			}
			else
			{
				while (true)
				{
					T object;
					fileObject.ReadFromFile(object);

					if (fileObject.isEnd())
					{
						break;
					}

					addToEnd(object);
				}

				cout << "Succesfully read" << endl << endl;
			}

			break;
		}

		case 4:
		{
			fs.open(fileName, fstream::in);

			if (!fs.is_open())
			{
				cout << "Cannot open file" << endl;
			}
			else
			{
				while (true)
				{
					T object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					cout << object;
				}
			}

			fs.close();
			break;
		}

		case 5:
		{
			fs.open(fileName, fstream::out | fstream::trunc);
			fs.close();
			break;
		}

		case 0:
			return;
		}
	}
}
 
template<class T>
void Ring<T>::fileService()
{
	fileServiceBase("NewFile.txt");
}

template<class T>
int Ring<T>::countOfNodes = 0;

template<class T>
Ring<T>::Ring()
{
	size = 0;
	head = nullptr;
}

template<class T>
Ring<T>::~Ring()
{
	clear();
}

template<class T>
void Ring<T>::addToEnd(T data)
{
	if (head == nullptr)
	{
		addToEmpty(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->next != head)
		{
			current = current->next;
		}

		current->next = new Node<T>(data, head);

		size++;
	}
}

template<class T>
void Ring<T>::addToEmpty(T data)
{
	head = new Node<T>(data);
	head->next = head;

	size++;
}

template<class T>
void Ring<T>::addToBegin(T data)
{
	if (head == nullptr)
	{
		addToEmpty(data);
	}
	else
	{
		Node<T>* current = head;

		while (current->next != head)
		{
			current = current->next;
		}

		head = new Node<T>(data, head);
		current->next = head;

		size++;
	}
}

template<class T>
void Ring<T>::addByIndex(T value, int index)
{
	if (index == 0)
	{
		addToBegin(value);
		return;
	}

	if (index == size - 1)
	{
		addToEnd(value);
		return;
	}

	Node<T>* previous = head;

	for (int i = 0; i < index - 1; i++)
	{
		previous = previous->next;
	}

	Node<T>* newNode = new Node<T>(value, previous->next);
	previous->next = newNode;

	size++;
}

template<class T>
void Ring<T>::deleteByIndex(int index)
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
		return;
	}

	if (index == 0)
	{
		deleteFirst();
		return;
	}

	Node<T>* previous = head;

	if (previous->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node<T>* temp = previous->next;

		previous->next = temp->next;
		delete temp;
	}

	size--;
}

template<class T>
void Ring<T>::deleteFirst()
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
		return;
	}

	Node<T>* current = head;

	if (current->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		while (current->next != head)
		{
			current = current->next;
		}

		Node<T>* temp = head;

		head = head->next;
		current->next = head;

		delete temp;
	}

	size--;
}

template<class T>
void Ring<T>::deleteLast()
{
	deleteByIndex(size - 1);
}

template<class T>
void Ring<T>::clear()
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
		return;
	}

	while (size)
	{
		deleteFirst();
	}

	cout << "Successful deletion" << endl;
}

template<class T>
void Ring<T>::displayBase()
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
		return;
	}

	Node<T>* current = head;
	while (current->next != head)
	{
		cout << current->data;
		current = current->next;
	}

	cout << current->data;
}

template<class T>
void Ring<T>::display()
{
	displayBase();
}

template<class T>
int Ring<T>::getCountOfNodes()
{
	return countOfNodes;
}

template<>
void Ring<Laptop>::display()
{
	cout << setw(10) << "MODEL" << setw(10) << "BATTERY" << setw(10) << "MATRIX" << endl;
	displayBase();
}

template<>
void Ring<Tablet>::display()
{
	cout << setw(10) << "MODEL" << setw(10) << "BATTERY" << setw(10) << "STYLUS" << endl;
	displayBase();
}

template<>
void Ring<Monoblock>::display()
{
	cout << setw(10) << "MODEL" << setw(10) << "POWER" << setw(10) << "COLOUR" << endl;
	displayBase();
}

template <class T>
void Ring<T>::changeData(int index)
{
	Node<T>* current = head;

	if (current->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		T data;

		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		cin >> data;
		current->data = data;
	}
}

template<>
void Ring<Laptop>::changeData(int index)
{
	Node<Laptop>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		int whatChange;
		cout << "Choose what change:" << endl
			<< "1. Model" << endl
			<< "2. Battery" << endl
			<< "3. Matrix" << endl;

		cin >> whatChange;

		system("CLS");

		string newModel;
		int newBattery;
		string newMatrix;

		switch (whatChange)
		{
		case 1:
			cout << "Enter new model: ";
			cin >> newModel;
			current->data.setModel(newModel);
			return;

		case 2:
			cout << "Enter new battery: ";
			cin >> newBattery;
			current->data.setBattery(newBattery);
			return;

		case 3:
			cout << "Enter new matrix: ";
			cin >> newMatrix;
			current->data.setMatrix(newMatrix);
			return;

		default:
			break;
		}
	}
}

template<>
void Ring<Tablet>::changeData(int index)
{
	Node<Tablet>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		int whatChange;
		cout << "Choose what change:" << endl
			<< "1. Model" << endl
			<< "2. Battery" << endl
			<< "3. Stylus" << endl;

		cin >> whatChange;

		system("CLS");

		string newModel;
		int newBattery;
		bool newIsStylus;

		switch (whatChange)
		{
		case 1:
			cout << "Enter new model: ";
			cin >> newModel;
			current->data.setModel(newModel);
			return;

		case 2:
			cout << "Enter new battery: ";
			cin >> newBattery;
			current->data.setBattery(newBattery);
			return;

		case 3:
			cout << "Enter new stylus presense: ";
			cin >> newIsStylus;
			current->data.setStylus(newIsStylus);
			return;

		default:
			break;
		}
	}
}

template<>
void Ring<Monoblock>::changeData(int index)
{
	Node<Monoblock>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		int whatChange;
		cout << "Choose what change:" << endl
			<< "1. Model" << endl
			<< "2. Power supply" << endl
			<< "3. Stand colour" << endl;

		cin >> whatChange;

		system("CLS");

		string newModel;
		int newPowerSupply;
		string newStandColour;

		switch (whatChange)
		{
		case 1:
			cout << "Enter new model: ";
			cin >> newModel;
			current->data.setModel(newModel);
			return;

		case 2:
			cout << "Enter new power supply: ";
			cin >> newPowerSupply;
			current->data.setPowerSupply(newPowerSupply);
			return;

		case 3:
			cout << "Enter new stand colour: ";
			cin >> newStandColour;
			current->data.setStandColour(newStandColour);
			return;

		default:
			break;
		}
	}
}

template<class T>
int Ring<T>::getSize()
{
	return size;
}
