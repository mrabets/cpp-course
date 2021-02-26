#include "BaseException.h"

string GetCorrectString(istream& in, string whatInput)
{
	string str;

	int flag;
	do
	{
		cout << whatInput;

		try
		{
			flag = 0;
			in.clear();
			in >> str;

			system("CLS");

			if (str.length() > 20)
			{
				throw InputException("The length of the word is longer than 20", 1);
			}

			if (str.length() < 2)
			{
				throw InputException("The length of the word is shorter than 2", 1);
			}

			for (int i = 0; i < str.length(); i++)
			{
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
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
		catch (exception obj)
		{
			cout << obj.what() << endl;
			flag = 1;
		}
	} while (flag);

	return str;
}
