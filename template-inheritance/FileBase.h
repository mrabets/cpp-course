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
	fstream fs;
};

template <class T>
class FileTxt : public FileBase
{
public:
	FileTxt(string name)
	{ 
		this->fileName = name;
	};

	~FileTxt()
	{
		CloseFile();
	}

	void WriteToFile(T& object);
	void ReadFromFile(T& object);

	void OpenFileOut();
	void OpenFileIn();

	bool isOpened();
	void CloseFile();

	bool isEnd();
};

template<class T>
inline void FileTxt<T>::WriteToFile(T& object)
{	
	fs << object;
}

template<class T>
inline void FileTxt<T>::ReadFromFile(T& object)
{
	if (!isEnd())
	{
		fs >> object;
	}
}

template<class T>
inline void FileTxt<T>::OpenFileOut()
{
	fs.open(fileName, ios::out | ios::trunc);
}

template<class T>
inline void FileTxt<T>::OpenFileIn()
{
	fs.open(fileName, ios::in);
}

template<class T>
inline bool FileTxt<T>::isOpened()
{
	return fs.is_open();
}

template<class T>
inline bool FileTxt<T>::isEnd()
{
	return fs.eof();
}

template<class T>
inline void FileTxt<T>::CloseFile()
{
	fs.close();
}

