#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class BaseException : public exception
{
protected:
	string message = "Error";

public:
	virtual string GetExceptionMessage() const = 0;
};

class InputException : public BaseException
{
private:
	int errorCode;

public:
	InputException(string message, int errorCode)
	{
		this->message = message;
		this->errorCode = errorCode;
	}

	~InputException() { }

	string GetExceptionMessage() const override { return message; }

	int GetErrorCode() const { return errorCode; }
};

string GetCorrectString(istream& in, string whatInput);

template<typename T>
T GetCorrectNumber(istream& in, string whatInput)
{
	T number;
	int flag;

	do
	{
		cout << whatInput;

		try
		{
			flag = 0;

			in >> number;

			system("CLS");

			flag = cin.rdstate();

			if ((flag & ios::failbit) || cin.peek() != '\n')
			{
				string message = "There is not ";
				string typeName = typeid(number).name();
				throw InputException(message + typeName, 2);
			}
		}
		catch (InputException obj)
		{
			flag = 1;
			cout << obj.GetExceptionMessage() << ". Error code: " << obj.GetErrorCode() << endl;
			cin.clear(0);
			rewind(stdin);
		}
		catch (exception obj)
		{
			flag = 1;
			cout << obj.what() << endl;
			cin.clear(0);
			rewind(stdin);
		}
	} while (flag);

	return number;
}