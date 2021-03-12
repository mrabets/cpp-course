#pragma once

#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
#include <iomanip>

using namespace std;

class FileBase
{
protected:
	string fileName;
	ofstream out;
	ifstream in;
};

template <class T>
class FileTxt : public FileBase
{
public:
	FileTxt() { }
	FileTxt(string name);

	void Remove();

	void WriteToFile(T& object);

	void ReadFromFile(T& object);
};

class BinFile : public FileBase
{
};

template<class T>
inline FileTxt<T>::FileTxt(string name)
{
	fileName = name;
}

template<class T>
inline void FileTxt<T>::WriteToFile(T& object)
{
	out.open(fileName);

	if (!out.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
	}
	else
	{
		out << object << endl;
	}

	out.close();
}

template<class T>
inline void FileTxt<T>::ReadFromFile(T& object)
{
	in.open(fileName);

	if (!in.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
	}
	else
	{
		in >> object << endl;
	}

	out.close();
}

