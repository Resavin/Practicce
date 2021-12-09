#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include "funcs.cpp"

using namespace std;

// enum {
// 	NAME_SIZE = 19,
// 	SIZE = 1,
// 	GROUP_SIZE = 14
// };

enum {
	INPUT = 1,
	INPUT_FROM_TXT,
	INPUT_FROM_BIN,
	OUTPUT,
	OUTPUT_TO_TXT,
	REQUEST,
	// OUTPUT_TO_TXT,
	TXT_TO_BIN,
	ADD,
	EDIT,
	DEL,
	SORT,
	EXIT = 0
};

// struct  student
// {
// 	char name[NAME_SIZE]{""};
// 	char group[GROUP_SIZE]{"Иук4-12б"};
// 	char year[5]{"2000"};
// 	char mark[5]{"1234"};
// 	float avgMark{};
// };


int inp{};
student list[SIZE];
int minI{}, minMark{};
char edit[]{};
bool flag = true;

int main(){
	int srt{};
	system("chcp 65001");
	do{
		cout << endl <<  "--------------МЕНЮ--------------" << endl;
		cout << INPUT  << ".  Ввод данных с клавиатуры" << endl;
		cout << INPUT_FROM_TXT << ".  Ввод данных из текстового файла" << endl;
		cout << INPUT_FROM_BIN << ".  Ввод данных из бинарного файла" << endl;
		cout << OUTPUT << ".  Вывод данных на экран" << endl;
		cout << OUTPUT_TO_TXT << ".  Вывод данных в файл" << endl;
		cout << REQUEST << ".  Выполнение запроса" << endl;
		cout << OUTPUT_TO_TXT << ".  Перевод в текстовый файл" << endl;
		cout << TXT_TO_BIN << ".  Перевод текстового файла в бинарный" << endl;
		cout << ADD << ".  Добавление записи" << endl;
		cout << EDIT << ".  Изменение записи" << endl;
		cout << DEL << ". Удаление записи" << endl;
		cout << SORT << ". Cортировка" << endl;
		cout << EXIT << ".  Выход" << endl;
		cin >> inp;
		switch(inp){
			case INPUT:
				cout <<  endl << "//////// ВВОД СТУДЕНТОВ ////////";
				for(int i=0; i < SIZE; i++){
					list[i] = input(i, list);
				}
				break;
				
			


			case OUTPUT:
				cout << endl << "────────────────┐";
				cout << endl << "Список студентов|" << endl;
					// cout << " w|" << setw(19) << "Имя|" << setw(13) << "Группа|" << setw(5) << "Год|" << setw(18) << "Оценки|"<< endl;
					cout << "─#┐─────────────┘──Имя┐───Группа┐──Год┐──Оценки┐"<< endl;
				for(int i{}; i<SIZE;i++){
					cout << setw(2) << i+1 << '|' << setw(maxName) <<list[i].name << '|' << setw(13) << list[i].group << '|' << setw(5) << list[i].year << '|';
					for(int j{};j<4;j++)
						cout << setw(2) << list[i].mark[j];
					cout << '|' << endl;
					// cout << "──┘───────────────────┘─────────┘─────┘────────" << endl;
				}
				// cout << "──┘───────────────────┘─────────┘─────┘────────" << endl;
				break;
			


			case REQUEST:
				cout << endl << "//////////// ЗАПРОС ////////////";
				cout << endl << "Студент с минимальным средним баллом: ";
				for(int i{};i<SIZE;i++){
					if(list[i].avgMark < minMark){
						minMark = list[i].avgMark;
						minI = i;
					}
				}
				cout << list[minI].name << endl;
				break;
			




			case SORT:
				char test[6];
				cin >> test;
				cout << endl << "Введите способ сортировки:\n";
				cout << "1) Сортировать по имени\n";
				cout << "2) Сортировать по группе\n";
				cout << "3) Сортировать по году поступления\n";
				cout << "4) Сортировать по общим оценкам\n";
				cout << "5) Сортировать по средней оценке\n";
				cin >> srt;
				switch(srt){
					case 1:
						cout << "Выполняется сортировка по имени.." << endl;
						// bubble_char(&test, 5);
						break;
					case 2:
						cout << "Выполняется сортировка по группе.." << endl;
						// bubble_char(&list[SIZE].name, SIZE);
						break;
					case 3:
						cout << "Выполняется сортировка по году поступления.." << endl;
						// bubble_char(&list[SIZE].name, SIZE);
						break;
					case 4:
						cout << "Выполняется сортировка по общим оценкам.." << endl;
						// bubble_int(list[SIZE].mark, SIZE);

						break;
					default:
						cout << "Ошибка: введено неверное значение. Переход в главное меню..";
						break;
				}

			case EDIT:
				cout << "\tВыбрано редактирование записи" << endl;
				do{
					cout << "Выберите номер записи для редактирования (1-" << SIZE << "): ";
					cin >> edit;
					int iedit = charToInt(edit);
					if(iedit >= SIZE or iedit <= 0){
						cout << "Ошибка, номер записи для редактирования должен быть числом в отрезке [1;" << SIZE << ']';
						flag = true;
					}
					else
						flag = false;
				}while(flag == true);


			




			case EXIT:
				cout << "Выход из программы... " << endl;
				break;
			default:
				cout << "Ошибка: вы ввели неверное значение" << endl;
				break;
			} 
		} while(inp);
	return 0;
}