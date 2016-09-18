#include<simplecpp>
#include<cstdlib>
#include <ctime>
#include"id.h"
#include"Buttons.h"
void neww(int &split_again ,bool &stand_again,Deck &deck,card &c, bool &hit_again);
id Deck:: shuffle(){
			int cardno;
			bool c=false;
			for(int i=0;i<52;i++){
					if(this->d[i])c =true;
				}
			if(!c) for(int i=0;i<52;i++) this->d[i]=true;
			do {
				cardno=rand()%52; 
				}
			while(!d[cardno]);
			d[cardno]=false;
			id i;
			i.posx=0;
			i.posy=0;
			i.cardno=cardno%13;
			i.suit=cardno/13;
			return i;
		}
int Deck::count(){
        int sum=0;
        for(int i=0;i<52;i++){
            if(!d[i]) sum+=countval[i%13];
            }
        return sum;
        }
void Deck:: print(){
        for(int i=0;i<52;i++) cout<<d[i]<<" ";
        cout<<endl;
        }

Buttons:: Buttons(string s,float positionX,float positionY,bool l){
        pos[0]=positionX;
        pos[1]=positionY;
        if (l) disp1(s);
        }
void Buttons:: disp1( string s){
            Rectangle r(pos[0],pos[1],SIZE[0],SIZE[1]);
            r.imprint();
            Text t(pos[0],pos[1],s);
            t.imprint();
        }
bool Buttons:: is_click(float x,float y){
        if  ((pos[1]-SIZE[1]/2<=y) and (y<=pos[1]+SIZE[1]/2)and(pos[0]-SIZE[0]/2<=x) and (x<=pos[0]+SIZE[0]/2)) return true;
        else return false;
        }
  
  
  
  
