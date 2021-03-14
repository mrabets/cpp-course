#pragma once

#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
#include <iomanip>

using namespace std;

class FileBase
{
public:
	FileBase() { }
	FileBase(string fileName, long int mode)
	{ 
		this->fileName = fileName;
		this->mode = mode;
	}
protected:
	string fileName;
	fstream fs;
	long int mode;
};

template <class T>
class FileTxt : public FileBase
{
public:
	FileTxt() { }
	FileTxt(string name, long int mode) : FileBase(name, mode)
	{ 
		OpenFile();
	};

	~FileTxt()
	{
		CloseFile();
	}

	void WriteToFile(T& object);
	void ReadFromFile(T& object);
	void Remove();
	void OpenFile();
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
inline void FileTxt<T>::OpenFile()
{
	fs.open(fileName, ios::openmode(mode));
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

