#include<string>
class Buttons{
	const int SIZE[2]={200,40};
   	char text[20];
    float pos[2];
	public:
	Buttons(string s,float positionX,float positionY,bool l);
    void disp1( string s);
    bool is_click(float x,float y);
	};    
class Money{
    public:
    int money=200;
    int betmoney=0;
    int hwon=0;
    int hlost=0;
    int htied=0;
	void keyevent();
    void clickevent(bool &l,Buttons ng,bool h,bool s,bool sp);
    void Bet(Buttons ng,int &split_again ,bool &stand_again,Deck &d,card &c, bool &hit_again);
    void dispmon(int m);
    void disptally();  
	};
