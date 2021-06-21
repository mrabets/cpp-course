#pragma once
#pragma warning (disable:4786)

#include <set>

#include "Laptop.h"
#include "Tablet.h"
#include "Monoblock.h"
// #include "Ring.h"

template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void serviceMenu();
	void displayHeader();
	void addElement();
	void deleteFirst();
	void deleteLast();
	void deleteByIndex();
	void deleteAll();
	void deleteByValue();
	void deleteDublicates();
	void search();
	void display();
	void displayReverse();
	void displayCount();
	void writeToTxtFile();
	void readFromTxtFile();
	void writeToBinFile();
	void readFromBinFile();

	typedef typename multiset<T, less<T>> myMultiSet;
	typedef typename multiset<T, less<T>>::iterator myIterator;
	typedef typename multiset<T, less<T>>::reverse_iterator myReverseIterator;

private:
	myMultiSet obj;
	myIterator iter;
	myReverseIterator riter;
};

template <class T>
void Interface<T>::serviceMenu()
{
	while (true)
	{
		cout << "Choose operation:" << endl << endl
			<< "1. Add" << endl
			<< "2. Delete first" << endl
			<< "3. Delete last" << endl
			<< "4. Delete by index" << endl
			<< "5. Delete all" << endl
			<< "6. Delete by value" << endl
			<< "7. Delete by value (include dublicates)" << endl
			<< "8. Find" << endl
			<< "9. Display" << endl
			<< "10. Reverse display" << endl
			<< "11. Show count of records" << endl
			<< "12. Write to TXT file" << endl
			<< "13. Read from TXT file" << endl << endl
			<< "14. Write to BIN file" << endl
			<< "15. Read from BIN file" << endl << endl
			<< "0. Exit" << endl;
		
		int choiceMenu = GetCorrectNumber(cin, "", 0, 15);
		system("CLS");
		
		T value;
		int index;

		switch (choiceMenu)
		{
		case 1:
			addElement();
			break;

		case 2:
			deleteFirst();
			break;

		case 3:
			deleteLast();
			break;

		case 4:
			deleteByIndex();
			break;

		case 5:
			deleteAll();
			break;

		case 6:
			deleteByValue();
			break;

		case 7:
			deleteDublicates();
			break;

		case 8:
			search();
			break;

		case 9:
			display();
			break;

		case 10:
			displayReverse();
			break;

		case 11:
			displayCount();
			break;

		case 12:
			writeToTxtFile();
			break;
		
		case 13:
			readFromTxtFile();
			break;

		case 14:
			writeToBinFile();
			break;

		case 15:
			readFromBinFile();
			break;

		default:
			return;
		}

		cout << endl;
	}
}

template<class T>
inline void Interface<T>::addElement()
{
	T value;
	cin >> value;
	obj.insert(value);
}

template<class T>
inline void Interface<T>::deleteFirst()
{
	if (!obj.empty())
	{
		obj.erase(obj.begin());
		cout << "Data deleted successfully" << endl;
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::deleteLast()
{
	if (!obj.empty())
	{
		obj.erase(--obj.end());
		cout << "Data deleted successfully" << endl;
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::deleteByIndex()
{
	if (!obj.empty())
	{
		int index = GetCorrectNumber(cin, "Enter the index: ", 1, int(obj.size()));
		iter = obj.begin();
		advance(iter, index - 1);
		obj.erase(iter);
		cout << "Data deleted successfully" << endl;
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::deleteAll()
{
	if (!obj.empty())
	{
		obj.clear();
		cout << "Data deleted successfully" << endl;
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::deleteByValue()
{
	if (!obj.empty())
	{
		T value;
		cin >> value;
		iter = obj.find(value);

		if (iter != obj.end())
		{
			obj.erase(iter);
		}
		else
		{
			cout << "Item not found" << endl;
		}
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::deleteDublicates()
{
	if (!obj.empty())
	{
		T value;

		cin >> value;

		iter = obj.begin();

		if (iter != obj.end())
		{
			obj.erase(value);
		}
		else
		{
			cout << "Item not found" << endl;
		}
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::search()
{
	if (!obj.empty())
	{
		T temp;
		cin >> temp;

		displayHeader();

		int index = 1;
		auto range = obj.equal_range(temp);

		if (range.first != obj.end())
		{
			iter = range.first;

			while (iter != range.second)
			{
				cout << setw(3) << index++
					<< *iter++;
			}
		}
		else
		{
			cout << "Item not found" << endl;
		}
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::display()
{
	if (!obj.empty())
	{
		displayHeader();
		iter = obj.begin();

		int index = 1;
		while (iter != obj.end())
		{
			cout << setw(3) << index++
				<< (*iter++);
		}
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::displayReverse()
{
	if (!obj.empty())
	{
		displayHeader();
		riter = obj.rbegin();
		int index = int(obj.size());

		while (riter != obj.rend())
		{
			cout << setw(3) << index--
				<< (*riter++);
		}
	}
	else
	{
		cout << "Data is empty" << endl;
	}
}

template<class T>
inline void Interface<T>::displayCount()
{
	cout << "Count of records: " << obj.size() << endl;
}

template<class T>
inline void Interface<T>::writeToTxtFile()
{
	FileTxt<T> fl_txt(GetFileName<T>());
	fl_txt.OpenFileOut();

	if (!fl_txt.isOpened())
	{
		cout << "File open failed";
		return;
	}

	iter = obj.begin();

	while (iter != obj.end())
	{
		T obj = *iter;
		fl_txt.WriteToFile(obj);
		iter++;
	}

	cout << "Write succeed" << endl;
}

template<class T>
inline void Interface<T>::readFromTxtFile()
{
	FileTxt<T> fl_txt(GetFileName<T>());
	fl_txt.OpenFileIn();

	if (!fl_txt.isOpened())
	{
		cout << "File open failed";
		return;
	}

	T temp;

	while (true)
	{
		fl_txt.ReadFromFile(temp);

		if (fl_txt.isEnd())
		{
			break;
		}

		obj.insert(temp);
	}

	cout << "Read succeed" << endl;
}

template<class T>
inline void Interface<T>::writeToBinFile()
{
	FileBin<T> fl_bin(GetFileName<T>(true));
	fl_bin.OpenBinFileOut();

	if (!fl_bin.isOpenedOut())
	{
		cout << "File open failed";
		return;
	}

	iter = obj.begin();

	while (iter != obj.end())
	{
		T obj = *iter;
		fl_bin.WriteToBinFile(obj);
		iter++;
	}

	cout << "Write succeed" << endl;
}

template<class T>
inline void Interface<T>::readFromBinFile()
{
	FileBin<T> fl_bin(GetFileName<T>(true));
	fl_bin.OpenBinFileIn();

	if (!fl_bin.isOpenedIn())
	{
		cout << "File open failed";
		return;
	}

	T temp;

	while (true)
	{
		fl_bin.ReadFromBinFile(temp);

		if (fl_bin.isEnd())
		{
			break;
		}

		obj.insert(temp);
	}

	cout << "Read succeed" << endl;
}

template<>
void Interface<Laptop>::displayHeader()
{
	cout << setw(3) << "ID" << setw(10) << "MODEL" << setw(10) << "BATTERY" << setw(10) << "MATRIX" << endl;
}

template<>
void Interface<Tablet>::displayHeader()
{
	cout << setw(3) << "ID" << setw(10) << "MODEL" << setw(10) << "BATTERY" << setw(10) << "STYLUS" << endl;
}

template<>
void Interface<Monoblock>::displayHeader()
{
	cout << setw(3) << "ID" << setw(10) << "MODEL" << setw(10) << "POWER" << setw(10) << "COLOUR" << endl;
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