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
	fstream f_stream;
	ifstream if_stream;
	ofstream of_stream;
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
	f_stream << object;
}

template<class T>
inline void FileTxt<T>::ReadFromFile(T& object)
{
	if (!isEnd())
	{
		f_stream >> object;
	}
}

template<class T>
inline void FileTxt<T>::OpenFileOut()
{
	f_stream.open(fileName, ios::out | ios::trunc);
}

template<class T>
inline void FileTxt<T>::OpenFileIn()
{
	f_stream.open(fileName, ios::in);
}

template<class T>
inline bool FileTxt<T>::isOpened()
{
	return f_stream.is_open();
}

template<class T>
inline bool FileTxt<T>::isEnd()
{
	return f_stream.eof();
}

template<class T>
inline void FileTxt<T>::CloseFile()
{
	f_stream.close();
}

template <class T>
class FileBin : public FileBase
{
	
public:
	FileBin(string name)
	{
		this->fileName = name;
	};

	~FileBin()
	{
		if (isOpenedIn())
		{
			CloseFileIn();
		}
		else
		{
			CloseFileOut();
		}
	}

	void WriteToBinFile(T& object);
	void ReadFromBinFile(T& object);

	void OpenBinFileOut();
	void OpenBinFileIn();

	bool isOpenedIn();
	bool isOpenedOut();

	void CloseFileIn();
	void CloseFileOut();

	bool isEnd();
};

template<class T>
inline void FileBin<T>::WriteToBinFile(T& object)
{
	of_stream << object;
}

template<class T>
inline void FileBin<T>::ReadFromBinFile(T& object)
{
	if_stream >> object;
}

template<class T>
inline void FileBin<T>::OpenBinFileOut()
{
	of_stream.open(fileName, ios::binary);
}

template<class T>
inline void FileBin<T>::OpenBinFileIn()
{
	if_stream.open(fileName, ios::binary);
}

template<class T>
inline bool FileBin<T>::isOpenedIn()
{
	return if_stream.is_open();
}

template<class T>
inline bool FileBin<T>::isOpenedOut()
{
	return of_stream.is_open();
}

template<class T>
inline void FileBin<T>::CloseFileIn()
{
	if_stream.close();
}

template<class T>
inline void FileBin<T>::CloseFileOut()
{
	of_stream.close();
}

template<class T>
inline bool FileBin<T>::isEnd()
{
	return if_stream.eof();
}
