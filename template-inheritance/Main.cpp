#include "Interface.h"

int main()
{
	typeChoosing();

	return 0;
}






















//class Exp
//{
//protected:
//	int errorNumber;
//};
//
//class Exp_Vvod : Exp
//{
//public:
//	Exp_Vvod(int flag, string message)
//	{
//		this->errorNumber = flag;
//		this->message = message;
//	}
//
//private:
//	string message;
//};

//string StringChecker() {
//	char str[80];
//	int flag; // проверка на правильность строки
//		do {
//			try {
//				flag = 0;
//				cin.getline(str, 80);
//				for (int i = 0; str[i]; i++)
//					if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'z' || str[i] > 'z'))
//						throw Exp_Vvod(100, "No English");
//			}
//			catch (Exp_Vvod &obj)
//			{
//				flag = 1;
//			}
//		}
//		while (flag);
//
//		return str;
//}

// Обработка исключений

// Добавить в класс перегрузка ввода / вывода
// Класс Exception (int код ошибки) -> Exception_Vvod (string расшифровка ошибки)
// Функция проверки строки в перегрузках ввода (строк) ... 
// char* Checker(istream...) {
// char str[80];
// int flag - проверка на правильность строки
// do {
// try {
// flag = 0;
// cin.getline(str, 80);
// for (int i = 0; ss[i]; i++)
// if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'z' || str[i] > 'z'))
// throw Exception_Vvod(100, "No English");
// }
// catch (Exceptiom_Vvod obj)
// {
// flag = 1;
// }
// }
// while (flag);
// return str;