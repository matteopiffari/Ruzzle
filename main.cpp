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

int click(int x, int y, int &xreturn, int &yreturn)
{
	// if x is between 100 and 235 and y is between 100 and 235 return 0
	if (x >= 100 && x <= 235 && y >= 100 && y <= 235){
		xreturn=100;
		yreturn=100;
		return 0;
	}
	// else if x is beetween 255 and 390 and y is between 100 and 235 return 1
	else if (x >= 255 && x <= 390 && y >= 100 && y <= 235){
	    xreturn=255;
		yreturn=100;
		return 1;
	}
	// else if x is between 410 and 545 and y is between 100 and 235 return 2
	else if (x >= 410 && x <= 545 && y >= 100 && y <= 235){
		xreturn=410;
		yreturn=100;
		return 2;
	}
	// else if x is between 565 and 700 and y is between 100 and 235 return 3
	else if (x >= 565 && x <= 700 && y >= 100 && y <= 235){
	    xreturn=565;
		yreturn=100;
		return 3;
	}
	// if x is between 100 and 235 and y is between 255 and 390 return 4
	else if (x >= 100 && x <= 235 && y >= 255 && y <= 390){
		xreturn=100;
		yreturn=255;
		return 4;
	}
	// else if x is between 255 and 390 and y is between 255 and 390 return 5
	else if (x >= 255 && x <= 390 && y >= 255 && y <= 390){
		xreturn=255;
		yreturn=255;
		return 5;
	}
	// else if x is between 410 and 545 and y is between 255 and 390 return 6
	else if (x >= 410 && x <= 545 && y >= 255 && y <= 390){
		xreturn=410;
		yreturn=255;
		return 6;
	}
	// else if x is between 565 and 700 and y is between 255 and 390 return 7
	else if (x >= 565 && x <= 700 && y >= 255 && y <= 390){
		xreturn=565;
		yreturn=255;
		return 7;
	}
	// if x is between 100 and 235 and y is between 410 and 545 return 8
	else if (x >= 100 && x <= 235 && y >= 410 && y <= 545){
		xreturn=100;
		yreturn=410;
		return 8;
	}
	// else if x is between 255 and 390 and y is between 410 and 545 return 9
	else if (x >= 255 && x <= 390 && y >= 410 && y <= 545){
		xreturn=255;
		yreturn=410;
		return 9;
	}
	// else if x is between 410 and 545 and y is between 410 and 545 return 10
	else if (x >= 410 && x <= 545 && y >= 410 && y <= 545){
		xreturn=410;
		yreturn=410;
		return 10;
	}
	// else if x is between 565 and 700 and y is between 410 and 545 return 11
	else if (x >= 565 && x <= 700 && y >= 410 && y <= 545){
		xreturn=565;
		yreturn=410;
		return 11;
	}
	// if x is between 100 and 235 and y is between 565 and 700 return 12
	else if (x >= 100 && x <= 235 && y >= 565 && y <= 700){
		xreturn=100;
		yreturn=565;
		return 12;
	}
	// else if x is between 255 and 390 and y is between 565 and 700 return 13
	else if (x >= 255 && x <= 390 && y >= 565 && y <= 700){
		xreturn=255;
		yreturn=565;
		return 13;
	}
	// else if x is between 410 and 545 and y is between 565 and 700 return 14
	else if (x >= 410 && x <= 545 && y >= 565 && y <= 700){
		xreturn=410;
		yreturn=565;
		return 14;
	}
	// else if x is between 565 and 700 and y is between 565 and 700 return 15
	else if (x >= 565 && x <= 700 && y >= 565 && y <= 700){
		xreturn=565;
		yreturn=565;
		return 15;
	}
	// else return -1
	else
		return -1;
}

void print_l(char lettere[],int x_r = 100,int y_r = 100,int k = 4,int n = 0){
	if(k==4){
		setbkcolor(COLOR(0, 255, 0));
		setfillstyle(1, COLOR(0, 255, 0));
	}
	settextstyle(10, 0, 1);
	settextjustify(1, 1);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if(k==4){
				setcolor(COLOR(0, 255, 0));
				rectangle(x_r, y_r, x_r + 135, y_r + 135);
				floodfill(x_r + 1, y_r + 1, COLOR(0, 255, 0));
			}
			setcolor(COLOR(255, 255, 255));
			char *rl = new char[2];
			rl[0] = lettere[n];
			rl[1] = '\0';
			outtextxy(x_r + 69, y_r + 75, rl);
			x_r += 155;
			n++;
			if(j==3)
				x_r = 100;
		}
		y_r += 155;
	}
}

void random_l(char lettere[]){
	for (int i = 0; i < 16; i++)
	{
		if(lettere[i]=='-'){
			int r;
			do
			{
				r = rand() % 26 + 65;
			} while (r == 87 || r == 88 || r == 89 || r == 74 || r == 75);
			lettere[i] = (char)r;
			cout<<endl<<endl<<lettere[i]<<endl<<endl;
		}
	}
}

void color_clicked(char lettere[], int x,int y){
	setbkcolor(COLOR(255, 0, 0));
	setfillstyle(1, COLOR(255, 0, 0));
	settextstyle(10, 0, 1);
	settextjustify(1, 1);
	int x_r,y_r;
	int pos=click(x,y,x_r,y_r);
	setcolor(COLOR(255, 0, 0));
	rectangle(x_r, y_r, x_r + 135, y_r + 135);
	floodfill(x_r + 1, y_r + 1, COLOR(255, 0, 0));
	setcolor(COLOR(255, 255, 255));
	print_l(lettere,x_r,y_r,1,pos);
	cout<<endl<<endl<<x_r<<" "<<y_r<<endl<<endl;
	
}

int main()
{
	srand(time(NULL));
	map<string, bool> dizionario = {};
	inizializza("Dizionario.txt", dizionario);

	char lettere[16]={'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'};
	random_l(lettere);
	initwindow(800, 800);

	print_l(lettere);

	bool finito = false;
	while (finito == false)
	{
		string word = "";
		int oldpos,counter=0;
		int saved_pos[16]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(20);
		}
		while (ismouseclick(WM_LBUTTONDOWN))
		{
			// cout << mousex() << " " << mousey() << endl;
			int xidk,yidk;
			int pos = click(mousex(), mousey(),xidk,yidk);
			if (pos != oldpos && pos != -1)
			{
				word += tolower(lettere[pos]);
				oldpos = pos;
				color_clicked(lettere,mousex(),mousey());
				saved_pos[counter]=pos;
				counter++;
			}
			delay(10);
			if (ismouseclick(WM_LBUTTONUP))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_LBUTTONUP);
			}
		}
		if (esiste(word, dizionario) && word.length() > 1){
			cout << word << " Esiste!\n";
			for(int i=0;i<counter;i++){
				lettere[saved_pos[i]]='-';
			}
			random_l(lettere);
		}
		else{
			cout << word << " No\n";
		}
		print_l(lettere);
		counter=0;
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
