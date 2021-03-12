#pragma once

#include "FileBase.h"

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

string GetCorrectString(istream& in, string whatInput, int maxLength);

template<typename T>
T GetCorrectNumber(istream& in, string whatInput, const T minNumber, const T maxNumber)
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
			
			flag = cin.rdstate(); // ios::good() ios::bad() ios::eof() ios::fail()

			if ((flag & ios::failbit) || cin.peek() != '\n')
			{
				string message = "There is not ";
				string typeName = typeid(number).name();
				throw InputException(message + typeName, 1);
			}

			if (number < minNumber)
			{
				string message = "Value must be more than ";
				throw underflow_error(message + to_string(minNumber));

				//throw InputException("Value must be positive", 2);
			}

			if (number > maxNumber)
			{
				string message = "Value must be less than ";
				throw overflow_error(message + to_string(maxNumber));
				
				//throw InputException(message + to_string(maxNumber), 2);
			}
		}
		catch (InputException obj)
		{
			flag = 1;
			cout << obj.GetExceptionMessage() << ". Error code: " << obj.GetErrorCode() << endl;
			cin.clear(0);
			rewind(stdin);
		}
		catch (underflow_error obj)
		{
			flag = 1;
			cout << obj.what() << endl;
			cin.clear(0);
			rewind(stdin);
		}
		catch (overflow_error obj)
		{
			flag = 1;
			cout << obj.what() << endl;
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