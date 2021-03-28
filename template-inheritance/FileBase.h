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
		CloseFile();
	}

	void WriteToBinFile(T& object);
	void ReadFromBinFile(T& object);

	void OpenBinFileOut();
	void OpenBinFileIn();

	bool isOpened();
	void CloseFile();

	bool isEnd();
};

template<class T>
inline void FileBin<T>::WriteToBinFile(T& object)
{
	//fs << object;
	fs.write(reinterpret_cast<char*>(&object), sizeof(object));
}

template<class T>
inline void FileBin<T>::ReadFromBinFile(T& object)
{
	//fs >> object;
	fs.read(reinterpret_cast<char*>(&object), sizeof(object));
}

template<class T>
inline void FileBin<T>::OpenBinFileOut()
{
	fs.open(fileName, ios::out | ios::binary | ios::trunc);
}

template<class T>
inline void FileBin<T>::OpenBinFileIn()
{
	fs.open(fileName, ios::in | ios::binary);
}

template<class T>
inline bool FileBin<T>::isOpened()
{
	return fs.is_open();
}

template<class T>
inline void FileBin<T>::CloseFile()
{
	fs.close();
}

template<class T>
inline bool FileBin<T>::isEnd()
{
	return fs.eof();
}
