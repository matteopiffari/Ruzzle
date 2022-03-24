#include <iostream>
#include <map>
#include <winbgim.h>
#include <fstream>

using namespace std;

template<typename Map>
bool esiste(string s,Map& map1){
	auto p=map1.find(s);
	if (p!= map1.end()) return true;
    else return false;
}


template<typename Map>
void PrintMap(Map& m)
{
    cout << "[ ";
    for (auto &item : m) {
        cout << item.first << ":" << item.second << " ";
    }
    cout << "]\n";
}

template<typename Map>
void inizializza(const char filename[],Map& map1){
	ifstream dizionario(filename);
	string line;
    
	while (getline(dizionario, line)){
    	map1.insert ( pair<string,bool>(line,true) );
	}
	
}

int main() {

    map<string,bool> dizionario = {};
    inizializza("Dizionario.txt",dizionario);
	
	char *lettere[16]={"0","1","2","3","4","5","6","7","8","9","0","1","2","3","4","5"};
	
	/*string s;
	do{
		cin>>s;
		if (esiste(s,dizionario)) cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;
	}while(s!="NO");*/
    
    initwindow(800,800);
    
    int x_r=100,y_r=100,n=0;
    setbkcolor(COLOR(0,255,0));
    setfillstyle(1,COLOR(0,255,0));
    settextstyle(10,0,1);
    settextjustify(1,1);
	for(int i=0;i<4;i++){
    	x_r=100;
    	for(int j=0;j<4;j++){
    		setcolor(COLOR(0,255,0));
    		rectangle(x_r,y_r,x_r+135,y_r+135);
    		floodfill(x_r+1,y_r+1,COLOR(0,255,0));
    		setcolor(COLOR(255,255,255));
			outtextxy(x_r+69,y_r+75,lettere[n]);
			x_r+=155;
			n++;
		}
		y_r+=155;
	}
    
    bool finito=false;
    while(finito==false){
    	while(!ismouseclick(WM_LBUTTONDOWN)){
    		delay(20);
		}
		while(ismouseclick(WM_LBUTTONDOWN)){
    		cout<<mousex()<<" "<<mousey()<<endl;
    		delay(40);
    		if(ismouseclick(WM_LBUTTONUP)){
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_LBUTTONUP);
			}
		}
	}
    
    getch();
    return 0;
}
