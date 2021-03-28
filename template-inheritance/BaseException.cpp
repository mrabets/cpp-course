#include "BaseException.h"

string GetCorrectString(istream& in, string whatInput, int maxLength)
{
	string str;

	int flag;
	do
	{
		cout << whatInput;

		try
		{
			flag = 0;
			in.clear(0);
			rewind(stdin);
			getline(in, str);

			system("CLS");

			if (str.length() > maxLength)
			{
				throw InputException("The length of the word is longer than 20", 1);
			}

			if (str.length() < 2)
			{
				throw InputException("The length of the word is shorter than 2", 1);
			}

			for (int i = 0; i < str.length(); i++)
			{
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && str[i] != ' ')
				{
					throw InputException("The word isn't in English!", 2);
				}
			}
		}
		catch (InputException obj)
		{
			cout << obj.GetExceptionMessage() << " Error code: " << obj.GetErrorCode() << endl;
			flag = 1;
		}
		catch (...)
		{
			cout << "Error in block catch (...)." << endl;
			flag = 1;
		}
	} while (flag);

	RemoveSpaces(str);

	return str;
}

void RemoveSpaces(string& str)
{
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		string::iterator begin = it;

		while (it != str.end() && ::isspace(*it))
		{
			it++;
		}

		if (it - begin > 1)
		{
			it = str.erase(begin + 1, it) - 1;
		}
	}

	if (str.length() > 0 && str[0] == ' ')
	{
		str.erase(0, 1);
	}

	if (str[str.length() - 1] == ' ')
	{
		str.erase(str.length() - 1, 1);
	}
}
