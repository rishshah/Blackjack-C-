#include<iostream>
using namespace std;
struct id{
	int cardno;
    int suit;
    double posx;
    double posy;
	const string noarr[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    const string suitarr[4]={"Clubs","Diamonds","Hearts","Spades"};
	
	id(int n=13, int s=0, double x=0, double y=0);
    void operator=(id i);
};

class card{
public:
    int cardval[14]={11,2,3,4,5,6,7,8,9,10,10,10,10,0};
    id player[6]={id(),id(),id(),id(),id(),id()};
    id split[6]={id(),id(),id(),id(),id(),id()};
    id dealer[6]={id(),id(),id(),id(),id(),id()};
    void display(id c);
	void print(id v[]);
    int calculate(int &l,id val[]);
    int length(id p[]);
    void destroycard(); 
};

class Deck{
	public:
	bool d[52]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int countval[13]={-1,1,1,1,1,1,0,0,0,-1,-1,-1,-1};
	id  shuffle();
    int count();
	void print();
	};
