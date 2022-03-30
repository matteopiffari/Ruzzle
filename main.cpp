#include <iostream>
#include <map>
#include <winbgim.h>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <string.h>
#include <ctype.h>

using namespace std;

template <typename Map>
bool esiste(string s, Map &map1)
{
	auto p = map1.find(s);
	if (p != map1.end())
		return true;
	else
		return false;
}

template <typename Map>
void PrintMap(Map &m)
{
	cout << "[ ";
	for (auto &item : m)
	{
		cout << item.first << ":" << item.second << " ";
	}
	cout << "]\n";
}

template <typename Map>
void inizializza(const char filename[], Map &map1)
{
	ifstream dizionario(filename);
	string line;

	while (getline(dizionario, line))
	{
		map1.insert(pair<string, bool>(line, true));
	}
}

int click(int x, int y)
{
	// if x is between 100 and 235 and y is between 100 and 235 return 0
	if (x >= 100 && x <= 235 && y >= 100 && y <= 235)
		return 0;
	// else if x is beetween 255 and 390 and y is between 100 and 235 return 1
	else if (x >= 255 && x <= 390 && y >= 100 && y <= 235)
		return 1;
	// else if x is between 415 and 550 and y is between 100 and 235 return 2
	else if (x >= 415 && x <= 550 && y >= 100 && y <= 235)
		return 2;
	// else if x is between 575 and 710 and y is between 100 and 235 return 3
	else if (x >= 575 && x <= 710 && y >= 100 && y <= 235)
		return 3;
	// if x is between 100 and 235 and y is between 255 and 390 return 4
	else if (x >= 100 && x <= 235 && y >= 255 && y <= 390)
		return 4;
	// else if x is between 255 and 390 and y is between 255 and 390 return 5
	else if (x >= 255 && x <= 390 && y >= 255 && y <= 390)
		return 5;
	// else if x is between 415 and 550 and y is between 255 and 390 return 6
	else if (x >= 415 && x <= 550 && y >= 255 && y <= 390)
		return 6;
	// else if x is between 575 and 710 and y is between 255 and 390 return 7
	else if (x >= 575 && x <= 710 && y >= 255 && y <= 390)
		return 7;
	// if x is between 100 and 235 and y is between 415 and 550 return 8
	else if (x >= 100 && x <= 235 && y >= 415 && y <= 550)
		return 8;
	// else if x is between 255 and 390 and y is between 415 and 550 return 9
	else if (x >= 255 && x <= 390 && y >= 415 && y <= 550)
		return 9;
	// else if x is between 415 and 550 and y is between 415 and 550 return 10
	else if (x >= 415 && x <= 550 && y >= 415 && y <= 550)
		return 10;
	// else if x is between 575 and 710 and y is between 415 and 550 return 11
	else if (x >= 575 && x <= 710 && y >= 415 && y <= 550)
		return 11;
	// if x is between 100 and 235 and y is between 575 and 710 return 12
	else if (x >= 100 && x <= 235 && y >= 575 && y <= 710)
		return 12;
	// else if x is between 255 and 390 and y is between 575 and 710 return 13
	else if (x >= 255 && x <= 390 && y >= 575 && y <= 710)
		return 13;
	// else if x is between 415 and 550 and y is between 575 and 710 return 14
	else if (x >= 415 && x <= 550 && y >= 575 && y <= 710)
		return 14;
	// else if x is between 575 and 710 and y is between 575 and 710 return 15
	else if (x >= 575 && x <= 710 && y >= 575 && y <= 710)
		return 15;
	// else return -1
	else
		return -1;
}

int main()
{
	srand(time(NULL));
	map<string, bool> dizionario = {};
	inizializza("Dizionario.txt", dizionario);

	char lettere[16];
	for (int i = 0; i < 16; i++)
	{
		int r;
		do
		{
			r = rand() % 26 + 65;
		} while (r == 87 || r == 88 || r == 89 || r == 74 || r == 75);
		lettere[i] = (char)r;
	}
	initwindow(800, 800);

	int x_r = 100, y_r = 100, n = 0;
	setbkcolor(COLOR(0, 255, 0));
	setfillstyle(1, COLOR(0, 255, 0));
	settextstyle(10, 0, 1);
	settextjustify(1, 1);
	for (int i = 0; i < 4; i++)
	{
		x_r = 100;
		for (int j = 0; j < 4; j++)
		{
			setcolor(COLOR(0, 255, 0));
			rectangle(x_r, y_r, x_r + 135, y_r + 135);
			floodfill(x_r + 1, y_r + 1, COLOR(0, 255, 0));
			setcolor(COLOR(255, 255, 255));
			char *rl = new char[2];
			rl[0] = lettere[n];
			rl[1] = '\0';
			outtextxy(x_r + 69, y_r + 75, rl);
			x_r += 155;
			n++;
		}
		y_r += 155;
	}

	bool finito = false;
	while (finito == false)
	{
		string word = "";
		int oldpos;
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(20);
		}
		while (ismouseclick(WM_LBUTTONDOWN))
		{
			// cout << mousex() << " " << mousey() << endl;
			int pos = click(mousex(), mousey());
			if (pos != oldpos && pos != -1)
			{
				word += tolower(lettere[pos]);
				oldpos = pos;
			}
			delay(40);
			if (ismouseclick(WM_LBUTTONUP))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_LBUTTONUP);
			}
		}
		if (esiste(word, dizionario) && word.length() > 1)
			cout << word << " Esiste!\n";
		else
			cout << word << " No\n";
	}

	getch();
	return 0;
}

/*string s;
do{
	cin>>s;
	if (esiste(s,dizionario)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}while(s!="NO");*/