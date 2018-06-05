#include <fstream>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <iterator>
#include <stack>
#include <map>
using namespace std;
#include "IO.h"
#include "Date.h"
#include "Names.h"
#include "Plans.h"
#include "Money.h"
#include "Result.h"
#include "Person.h"
//#include "Stack.h"
ifstream::pos_type filesize(const char* filename)
{
	ifstream in(filename, ifstream::ate | ifstream::binary);
	return in.tellg();
}

void ToVector(char* from, vector<Names>& names)
{
	char ch;
	string s = "", id, name;
	int i = 1;
	fstream myfile;
	float perc = 0;
	float size = filesize(from);
	myfile.open(from, ios::in);
	myfile.get(ch);
	while (myfile)
	{
		s = "";
		do {
			perc += 1;
			s += ch;
			myfile.get(ch);
		} while (ch != ';'&& ch != '\n');
		perc += 1;
		myfile.get(ch);
		i++;
		if (i % 2 == 0)
		{
			id = s;
		}
		else
		{
			name = s;
			Names addName;
			addName.setFields(atoi(id.c_str()), name);
			names.insert(names.end(), addName);
		}
		if (myfile.eof())
			break;
	}
	myfile.close();
	cout << "Файл " << from << " загружен" << endl;
}
void ToVector(char* from, vector<Money>& money)
{
	char ch;
	string s = "";
	int i = 0;
	fstream myfile;
	float perc = 0;
	float size = filesize(from);
	myfile.open(from, ios::in);
	myfile.get(ch);
	while (myfile)
	{
		Money addMoney;
		while (true)
		{
			s = "";
			do {
				s += ch;
				myfile.get(ch);
			} while (ch != ';'&& ch != '\n');
			myfile.get(ch);


			for (int j = 0; j < 17; j++)
			{
				if (i % 18 == j)
				{
					addMoney.setFields(j, s);
				}
			}

			if (i % 18 == 17)
			{
				addMoney.setFields(17, s);
				money.insert(money.end(), addMoney);
				i++;
				break;
			}
			i++;
		}
		if (myfile.eof())
			break;
	}
	myfile.close();
	cout << "Файл " << from << " загружен" << endl;
}
void ToVector(char* from, vector<Plans>& plan)
{
	char ch;
	string s = "";
	int i = 0;
	fstream myfile;
	float perc = 0;
	float size = filesize(from);
	myfile.open(from, ios::in);
	myfile.get(ch);
	while (myfile)
	{
		Plans addPlan;
		int fields = addPlan.getNumberOfFields();
		while (true)
		{
			s = "";
			do {
				s += ch;
				myfile.get(ch);
			} while (ch != ';'&& ch != '\n');
			myfile.get(ch);
			for (int j = 0; j < fields - 1; j++)
			{
				if (i % fields == j)
				{
					addPlan.setFields(j, s);
				}
			}
			if (i % fields == (fields - 1))
			{
				addPlan.setFields(fields - 1, s);
				plan.insert(plan.end(), addPlan);
				i++;
				break;
			}

			i++;
		}
		if (myfile.eof())
			break;
	}
	myfile.close();
	cout << "Файл " << from << " загружен" << endl;
} 
deque<Result> search_money(deque<Money> mon, int n1, int n2)
{
	deque<Result> vec;
	for each (Money el in mon)
	{
		if (atoi(el.getValue(0).c_str()) == n1 && atoi(el.getValue(2).c_str()) == n2)
		{
			Result a(n1, n2, el.getValue(16).substr(0, 10), el.getValue(15));
			vec.push_back(a);
			//el.printData();
		}
	}
	return vec;
}

void toFile(vector<Names> from, string path)
{
	fstream f;
	f.open(path, ios::out);
	if (f)
	{
		cout << endl << from.size() << endl;
		for (int i = 0; i < from.size(); i++)
		{
			f << from.at(i).getId() << ";" << from.at(i).getName() << endl;
		}
		f.close();
	}
	else
		cout << "Error opening file for writing!" << endl;
	cin.get();
}
void toFile(vector<Result> from, string path)
{
	fstream f;
	f.open(path, ios::out);
	if (f)
	{
		cout << endl << from.size() << endl;
		for (int i = 0; i < from.size(); i++)
		{
			//getline(cin, from.at(i).toString());
			f << from.at(i).toString() << endl;
		}
		f.close();
	}
	else
		cout << "Error opening file for writing!" << endl;
	cin.get();
}

void second();

//Course work
//AM&CS 4
//Eugene Buyvolov



void third()
{
	system("cls");
	int numbers;
	cout << "Введите количество вариантов: ";
	cin >> numbers;
	map<Person, int> display;
	IO<Person> group("files\\group.txt");
	display = group.toRandomMap(numbers);
	group.mapToDeque(display);
	group.toFile("files\\groupvar.txt");
}
//sort function for Names class objects
bool sort_function(Names i, Names j)
{
	return (i>j);
}
void second()
{
	system("cls");
	cout << "Инициализация..." << endl;
	IO<Names> names("files\\NAMES.txt");
	deque<Names> toSort = names.getDeque();
	std::sort(toSort.begin(), toSort.end(), sort_function);
	names.setDeque(toSort);
	names.toFile("files\\NAMES_sort.txt");
}
//We need to understand stream iterators to do this task
//Just rewrite our methods
void first()
{
	system("cls");
	string fl1 = "files\\NAMES.txt";
	string fl2 = "files\\101F.txt";
	string fl3 = "files\\PLAN.txt";
	int number, number2;
	cout << "Инициализация..." << endl;
	IO<Names> inputName(fl1);
	IO<Money> inputMoney(fl2);
	IO<Plans> inputPlan(fl3);
	IO<Result> outputResult;
	
	bool found=false;
	while (!found)
	{
		cout << "Введите регистрационный номер: ";
		cin >> number;
			for each (Names name in inputName.getDeque())
			{
				if (name.getId() == number)
				{
					name.printData();
					found = true;
					break;
				}
			}
			if (found == false)
			{
				cout << "Данного номера банка нет в базе, пожалуйста, укажите другой номер." << endl;
			}
		
	}
	found = false;
	while (!found)
	{
		cout << "Введите номер счета: ";
		cin >> number2;
		for each (Plans p in inputPlan.getDeque())
		{
			if (atoi(p.getValue(1).c_str()) == number2)
			{
				p.printData();
				found = true;
				break;
			}
		}
		if (found == false)
		{
			cout << "Данного номера счета нет в базе, пожалуйста, укажите другой номер." << endl;
		}
	}
	cout << "\tДата\t\tСумма, тыс.руб" << endl << endl;
	outputResult.setDeque(search_money(inputMoney.getDeque(), number, number2));
	outputResult.toScreen("\t");
	outputResult.resultToFile("files\\output.txt");
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	while (true)
	{
		system("cls");
		cout << "1. Задание один\n2. Задание два\n3. Задание три\n4. Exit"<<endl<<endl<<"Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			first();
			break;
		case 2:
			second();
			break;
		case 3:
			third();
			break;
		case 4:
			return 0;
		default:
			break;
		}
		system("pause");
	}
	return 0;
}