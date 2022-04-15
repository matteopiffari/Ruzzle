#include <iostream>
#include <map>
#include <winbgim.h>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

bool temposcaduto = false;

class Timer
{
public:
	Timer(size_t time, const std::function<void(void)> &f) : time{std::chrono::seconds{time}}, f{f} {}
	~Timer() { wait_thread.join(); }

private:
	void wait_then_call()
	{
		std::unique_lock<std::mutex> lck{mtx};
		for (int i = 120; i >= 0; i--)
		{
			setcolor(COLOR(255, 255, 255));
			setbkcolor(COLOR(45, 95, 167));
			settextstyle(10, 0, 1);
			settextjustify(1, 1);
			char *p = new char[4];
			itoa(i, p, 10);
			outtextxy(300, 50, p);
			cv.wait_for(lck, time / 10);
		}
		temposcaduto = true;
		f();
	}
	std::mutex mtx;
	std::condition_variable cv{};
	std::chrono::milliseconds time;
	std::function<void(void)> f;
	std::thread wait_thread{[this]()
							{ wait_then_call(); }};
};

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
	if (x >= 100 && x <= 235 && y >= 100 && y <= 235)
	{
		xreturn = 100;
		yreturn = 100;
		return 0;
	}
	// else if x is beetween 255 and 390 and y is between 100 and 235 return 1
	else if (x >= 255 && x <= 390 && y >= 100 && y <= 235)
	{
		xreturn = 255;
		yreturn = 100;
		return 1;
	}
	// else if x is between 410 and 545 and y is between 100 and 235 return 2
	else if (x >= 410 && x <= 545 && y >= 100 && y <= 235)
	{
		xreturn = 410;
		yreturn = 100;
		return 2;
	}
	// else if x is between 565 and 700 and y is between 100 and 235 return 3
	else if (x >= 565 && x <= 700 && y >= 100 && y <= 235)
	{
		xreturn = 565;
		yreturn = 100;
		return 3;
	}
	// if x is between 100 and 235 and y is between 255 and 390 return 4
	else if (x >= 100 && x <= 235 && y >= 255 && y <= 390)
	{
		xreturn = 100;
		yreturn = 255;
		return 4;
	}
	// else if x is between 255 and 390 and y is between 255 and 390 return 5
	else if (x >= 255 && x <= 390 && y >= 255 && y <= 390)
	{
		xreturn = 255;
		yreturn = 255;
		return 5;
	}
	// else if x is between 410 and 545 and y is between 255 and 390 return 6
	else if (x >= 410 && x <= 545 && y >= 255 && y <= 390)
	{
		xreturn = 410;
		yreturn = 255;
		return 6;
	}
	// else if x is between 565 and 700 and y is between 255 and 390 return 7
	else if (x >= 565 && x <= 700 && y >= 255 && y <= 390)
	{
		xreturn = 565;
		yreturn = 255;
		return 7;
	}
	// if x is between 100 and 235 and y is between 410 and 545 return 8
	else if (x >= 100 && x <= 235 && y >= 410 && y <= 545)
	{
		xreturn = 100;
		yreturn = 410;
		return 8;
	}
	// else if x is between 255 and 390 and y is between 410 and 545 return 9
	else if (x >= 255 && x <= 390 && y >= 410 && y <= 545)
	{
		xreturn = 255;
		yreturn = 410;
		return 9;
	}
	// else if x is between 410 and 545 and y is between 410 and 545 return 10
	else if (x >= 410 && x <= 545 && y >= 410 && y <= 545)
	{
		xreturn = 410;
		yreturn = 410;
		return 10;
	}
	// else if x is between 565 and 700 and y is between 410 and 545 return 11
	else if (x >= 565 && x <= 700 && y >= 410 && y <= 545)
	{
		xreturn = 565;
		yreturn = 410;
		return 11;
	}
	// if x is between 100 and 235 and y is between 565 and 700 return 12
	else if (x >= 100 && x <= 235 && y >= 565 && y <= 700)
	{
		xreturn = 100;
		yreturn = 565;
		return 12;
	}
	// else if x is between 255 and 390 and y is between 565 and 700 return 13
	else if (x >= 255 && x <= 390 && y >= 565 && y <= 700)
	{
		xreturn = 255;
		yreturn = 565;
		return 13;
	}
	// else if x is between 410 and 545 and y is between 565 and 700 return 14
	else if (x >= 410 && x <= 545 && y >= 565 && y <= 700)
	{
		xreturn = 410;
		yreturn = 565;
		return 14;
	}
	// else if x is between 565 and 700 and y is between 565 and 700 return 15
	else if (x >= 565 && x <= 700 && y >= 565 && y <= 700)
	{
		xreturn = 565;
		yreturn = 565;
		return 15;
	}
	// else return -1
	else
		return -1;
}

void print_l(char lettere[], int x_r = 100, int y_r = 100, int k = 4, int n = 0)
{
	if (k == 4)
	{
		setbkcolor(COLOR(255, 255, 255));
		setfillstyle(1, COLOR(255, 255, 255));
	}
	settextstyle(10, 0, 1);
	settextjustify(1, 1);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (k == 4)
			{
				setcolor(COLOR(255, 255, 255));
				rectangle(x_r, y_r, x_r + 135, y_r + 135);
				floodfill(x_r + 1, y_r + 1, COLOR(255, 255, 255));
			}
			setcolor(COLOR(0, 0, 0));
			char *rl = new char[2];
			rl[0] = lettere[n];
			rl[1] = '\0';
			outtextxy(x_r + 69, y_r + 75, rl);
			x_r += 155;
			n++;
			if (j == 3)
				x_r = 100;
		}
		y_r += 155;
	}
}

void random_l(char lettere[])
{
	for (int i = 0; i < 16; i++)
	{
		if (lettere[i] == '-')
		{
			int r, s;
			s = rand() % 100;
			if (s > 42)
			{
				do
				{
					r = rand() % 26 + 65;
				} while (r == 87 || r == 88 || r == 89 || r == 74 || r == 75 || r == 65 || r == 69 || r == 76 || r == 79 || r == 85);
			}
			else
			{
				s = rand() % 5;
				switch (s)
				{
				case 0:
					r = 65;
					break;
				case 1:
					r = 69;
					break;
				case 2:
					r = 73;
					break;
				case 3:
					r = 79;
					break;
				case 4:
					r = 85;
					break;
				}
			}
			lettere[i] = (char)r;
		}
	}
}

void color_clicked(char lettere[], int x, int y)
{
	setbkcolor(COLOR(254, 154, 0));
	setfillstyle(1, COLOR(254, 154, 0));
	settextstyle(10, 0, 1);
	settextjustify(1, 1);
	int x_r, y_r;
	int pos = click(x, y, x_r, y_r);
	setcolor(COLOR(254, 154, 0));
	rectangle(x_r, y_r, x_r + 135, y_r + 135);
	floodfill(x_r + 1, y_r + 1, COLOR(254, 154, 0));
	setcolor(COLOR(0, 0, 0));
	print_l(lettere, x_r, y_r, 1, pos);
	cout << endl
		 << endl
		 << x_r << " " << y_r << endl
		 << endl;
}

void print_points(int points)
{
	setcolor(COLOR(255, 255, 255));
	setbkcolor(COLOR(45, 95, 167));
	settextstyle(10, 0, 1);
	settextjustify(1, 1);
	char *p = new char[5];
	itoa(points, p, 10);
	outtextxy(500, 50, p);
}

int mod()
{
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(20);
	}
	while (ismouseclick(WM_LBUTTONDOWN))
	{
		if (mousex() >= 100 && mousex() <= 700 && mousey() >= 130 && mousey() <= 270)
			return 1;
		else if (mousex() >= 100 && mousex() <= 700 && mousey() >= 470 && mousey() <= 620)
			return 2;
	}
}

int main()
{
	srand(time(NULL));
	map<string, bool> dizionario = {};
	inizializza("Dizionario.txt", dizionario);
	initwindow(800, 800);
	bool finito = false;
	do
	{
		temposcaduto = false;
		finito = false;
		char lettere[16] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'};
		random_l(lettere);
		cleardevice();
		setfillstyle(1, COLOR(61, 132, 187));
		floodfill(0, 0, COLOR(61, 132, 187));

		setcolor(COLOR(255, 255, 255));
		setbkcolor(COLOR(255, 255, 255));
		setfillstyle(1, COLOR(255, 255, 255));
		rectangle(100, 130, 700, 270);
		floodfill(251, 251, COLOR(255, 255, 255));
		rectangle(100, 470, 700, 620);
		floodfill(251, 571, COLOR(255, 255, 255));

		setcolor(COLOR(0, 0, 0));
		settextstyle(10, 0, 1);
		settextjustify(1, 1);
		outtextxy(400, 200, "STATICO");
		outtextxy(400, 540, "DINAMICO");
		int modalita = mod();
		delay(400);
		cleardevice();

		setfillstyle(1, COLOR(61, 132, 187));
		floodfill(0, 0, COLOR(61, 132, 187));
		setcolor(COLOR(45, 95, 167));
		line(170, 80, 630, 80);
		line(170, 80, 120, 0);
		line(630, 80, 680, 0);
		setfillstyle(1, COLOR(45, 95, 167));
		floodfill(200, 50, COLOR(45, 95, 167));

		print_l(lettere);

		int points = 0, ppcount = 0;
		string parole[200];

		print_points(points);
		auto f = []()
		{ std::cout << "---------------- Tempo scaduto! ----------------\n"; };
		Timer t1{10, f};
		while (temposcaduto == false)
		{
			string word = "";
			int oldpos = -1, counter = 0;
			int saved_pos[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
			while (!ismouseclick(WM_LBUTTONDOWN) && temposcaduto == false)
			{
				delay(20);
			}
			while (ismouseclick(WM_LBUTTONDOWN) && temposcaduto == false)
			{
				int xidk, yidk;
				int pos = click(mousex(), mousey(), xidk, yidk);
				if (pos != oldpos && pos != -1)
				{
					word += tolower(lettere[pos]);
					oldpos = pos;
					color_clicked(lettere, mousex(), mousey());
					saved_pos[counter] = pos;
					counter++;
				}
				delay(10);
				if (ismouseclick(WM_LBUTTONUP))
				{
					clearmouseclick(WM_LBUTTONDOWN);
					clearmouseclick(WM_LBUTTONUP);
				}
			}
			if (esiste(word, dizionario) && word.length() > 1)
			{
				bool trovata = false;
				for (int t = 0; t < ppcount && trovata == false; t++)
				{
					if (parole[t] == word)
						trovata = true;
				}
				if (trovata == false)
				{
					parole[ppcount] = word;
					ppcount++;
					cout << word << " Esiste!\n";
					if (modalita == 2)
					{
						for (int i = 0; i < counter; i++)
						{
							lettere[saved_pos[i]] = '-';
						}
						random_l(lettere);
					}
					points += counter * 20;
					print_points(points);
				}
			}
			else
			{
				cout << word << " No\n";
			}
			print_l(lettere);
			counter = 0;
		}

		setfillstyle(1, COLOR(61, 132, 187));
		floodfill(0, 0, COLOR(61, 132, 188));

		setcolor(COLOR(255, 255, 255));
		settextstyle(10, 0, 1);
		setbkcolor(COLOR(61, 132, 187));
		settextjustify(1, 1);
		outtextxy(400, 250, "Tempo scaduto!");
		char *p = new char[5];
		char text[] = "Hai totalizzato un punteggio di ";
		itoa(points, p, 10);
		outtextxy(400, 300, strcat(text, p));

		outtextxy(400, 350, "Vuoi rigiocare?");
		setcolor(COLOR(255, 255, 255));
		rectangle(200, 400, 350, 550);
		rectangle(450, 400, 600, 550);
		setfillstyle(1, COLOR(255, 255, 255));
		floodfill(201, 401, COLOR(255, 255, 255));
		floodfill(451, 401, COLOR(255, 255, 255));
		setcolor(COLOR(0, 0, 0));
		setbkcolor(COLOR(255, 255, 255));
		outtextxy(275, 475, "Si");
		outtextxy(525, 475, "No");
		delay(200);
		clearmouseclick(WM_LBUTTONDOWN);
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(20);
		}
		while (ismouseclick(WM_LBUTTONDOWN))
		{
			if (mousex() >= 200 && mousex() <= 350 && mousey() >= 400 && mousey() <= 550)
				finito = false;
			else if (mousex() >= 450 && mousex() <= 600 && mousey() >= 400 && mousey() <= 550)
				finito = true;
			clearmouseclick(WM_LBUTTONDOWN);
		}
	} while (finito == false);
	closegraph();
	return 0;
}