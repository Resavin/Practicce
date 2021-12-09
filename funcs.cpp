#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

enum {
	NAME_SIZE = 29,
	SIZE = 1,
	GROUP_SIZE = 14
};

struct  student
{
	char name[NAME_SIZE]{"ЯРослав Малов"};
	char group[GROUP_SIZE]{"Иук4-12б"};
	char year[5]{"2000"};
	char mark[5]{"1234"};
	float avgMark{};
};


int charToInt(char a[]){
	int len = strlen(a), ia{};
	while(len>0){
		ia += ((int)a[strlen(a)-len]-'0')*pow(10, len-1);
		len--;
	}
	return ia;
}

void bSort(char *arr, int n) {	
	for (int i = 0; i<n; i++) {
		for (int j =i+1; j < n; j++)
			if (arr[i] > arr[j])
				std::swap(arr[i], arr[j]);
	}
}

void swap_int(int &a, int &b){
	int tmp{};
	tmp = a;
	a = b;
	b = tmp;
}

void swap_char(char &a, char &b){
	char tmp;
	tmp = a;
	a = b;
	b = tmp;
}

// void bubble_int(int arr[], int size){
// 	int flag{};
// 	cout << "Выберите сортировать по возрастанию или убыванию \n \
// 	(1=по возрастанию, 2=по убыванию): ";
// 	cin >> flag;
// 	if(flag == 1){
// 		for(int i = 0; i < size; i++){
// 			for(int j = 0; j < size; j++){
// 				if(arr[j] > arr[j+1])
// 					swap_int(arr[j], arr[j+1]);
// 			}
// 		}
// 		cout << "Сортировка была выполнена" << endl;
// 	}
// 	else if(flag == 2){
// 		for(int i = 0; i < size; i++){
// 			for(int j = 0; j < size; j++){
// 				if(arr[j] < arr[j+1])
// 					swap_int(arr[j], arr[j+1]);
// 			}
// 		}
// 		cout << "Сортировка была выполнена" << endl;
// 	}
// 	else{
// 		cout << "Ошибка, выбрано неверное значение сортировки \n \
// 		(1=по возрастанию, 2=по убыванию, 0=выход)";
// 	}
// }


void bubble_char(char arr[], int size){
	int flag{};
	cout << "Выберите сортировать по возрастанию или убыванию \n \
	(1=по возрастанию, 2=по убыванию)";
	cin >> flag;
	if(flag == 1){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(arr[j] > arr[j+1])
					swap(arr[j], arr[j+1]);
			}
		}
		cout << "Сортировка была выполнена" << endl;
	}
	else if(flag == 2){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(arr[j] < arr[j+1])
					swap(arr[j], arr[j+1]);
			}
		}
		cout << "Сортировка была выполнена" << endl;
	}
	else{
		cout << "Ошибка, выбрано неверное значение сортировки \n \
		(1=сортировка по возрастанию, 2=сортировка по убыванию)";
	}
}




int maxName= 19, maxGroup = 13;
student input(int i, student flist[]){
	bool flag = true, check = true;
	
	//ИМЯ
	do{
		cout << endl <<  "Введите имя: ";
		cin.ignore();
		cin.getline(flist[i].name, NAME_SIZE);
		if(strlen(flist[i].name) > NAME_SIZE){
			cout << "Ошибка: имя не может содержать больше " << NAME_SIZE << " символов" << endl;
			flag = true;
		}
		else{
			if(strlen(flist[i].name) > maxName)
				maxName = strlen(flist[i].name);
			flag = false;
		}
	} while(flag == true);

	//ГРУППА
	do{
		cout <<  "Введите группу: ";
		cin.ignore();
		cin >> flist[i].group;
		if(strlen(flist[i].group) > GROUP_SIZE){
			cout << "Ошибка: название группы не может содержать больше " << GROUP_SIZE << " символов" << endl;
			flag = true;
		}
		else 
			flag = false;
	} while(flag == true);		

	//ГОД
	do{
		cout << "Введите год поступления: ";
		cin.ignore();
		cin >> flist[i].year;
		int iyear = charToInt(flist[i].year);
		if( (strlen(flist[i].year)) != 4){
			cout << "Ошибка год поступления должен быть числом в отрезке [1755;2021]" << endl;
			flag=true;	
		}
		else if( (iyear < 1755) or (iyear > 2021)){
			cout << "Ошибка год поступления должен быть числом в отрезке [1755;2021]" << endl;
			flag=true;
		}
		else
			flag = false;
	}while(flag == true);
	

	//ОЦЕНКИ
	do{
			cout << "Введите 4 оценки через пробел: ";
			// cin.clear();
			cin.ignore();
			cin >> flist[i].mark;
				for(int j=0; j < 4; j++){
					if( (((int)flist[i].mark[j]-'0') > 5) or (((int)flist[i].mark[j]-'0') < 1))
						check = false;
				}
			if( (strlen(flist[i].mark) != 4) or (check == false) ) {
				cout << "Ошибка: оценки должны вводиться без пробелов и быть числами на отрезке [1;5]" << endl;
				flag = true;
			}
			else{
				flag = false;
			}
		}while(flag == true);
	flist[i].avgMark = ((int)flist[i].mark[0]-'0'+(int)flist[i].mark[1]-'0'+(int)flist[i].mark[2]-'0'+(int)flist[i].mark[3]-'0')/4.0;
	return flist[i];
}

// int main(){
// 	student list[2];
// 	system("chcp 65001");
// 	for(int i = 0; i < 3; i++)
// 		list[i] = input(i, list);
// 	cout << list[0].name << endl;
// }
