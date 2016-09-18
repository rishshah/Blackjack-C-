#include"id.h"
#include"Buttons.h"
#include<simplecpp>
void neww(int &split_again ,bool &stand_again,Deck &deck,card &c, bool &hit_again);
id::id(int n, int s, double x, double y)
    {
        cardno= n;
        suit= s;
        posx=x;
        posy=y;
    }    
void id:: operator=(id i)
	{
		cardno= i.cardno;
        suit= i.suit;
        posx=i.posx;
        posy=i.posy;
	}


	void card:: display(id c)
    {
        Rectangle r(c.posx,c.posy,75,100);
        r.setColor(COLOR("white"));
        r.setFill();
        r.imprint();
        Rectangle r1(c.posx,c.posy,75,100);
        r1.imprint();
        Text num(c.posx-28,c.posy-40.5,c.noarr[c.cardno]);
        num.imprint();
        Text suit(c.posx,c.posy,c.suitarr[c.suit]);
        suit.imprint();
    }

	void card::print(id v[])
	{
		for(int i=0;i<6;i++) cout << v[i].cardno<<endl;
	}

    int card::calculate(int &ace1,id val[])
    {
        int score=0;
        ace1=0;
        for(int i=0; i<6;i++)
        {
            score = score + cardval[val[i].cardno];
            if(cardval[val[i].cardno]==11){
				ace1++;
				}
        }
        if(score>21 and ace1>=1){
			score-=10;
			if(score>21 and ace1>=2){
				score-=10;
				if(score>21 and ace1>=3){
					score-=10;
				}
				else if(ace1==3){
					ace1=10;
				}
			}
			else if(ace1==2){
				ace1=10;	
			}
		}
		else if (ace1==1){
			ace1=10;
		}
        return score;
    }

    int card::length(id p[])
    {
		int l=0;
		while(p[l].cardno!=13) 
		{
			l++;
		}
		return l;
	}

    void card::destroycard()
    {
        for(int i=0;i<6;i++)
        {
            Rectangle r (57.5+(i*95),262,75,100);
            r.setColor(COLOR("white"));
            r.setFill();
            r.imprint();
        }
        for(int i=0;i<6;i++)
        {
            Rectangle r (57.5+(i*95),106,75,100);
            r.setColor(COLOR("white"));
            r.setFill();
            r.imprint();

        }
    }  


/*void Money:: keyevent(){
        XEvent event;
        nextEvent(event);
        if(keyPressEvent){
            switch(charFromEvent(event)){
                case 'a': {
                        betmoney+=20;
                        money-=20;
                        break;
                        }
                case 'b': {
                        betmoney+=50;
                        money-=50;
                        break;
                        }
                case 'c': {
                        betmoney=money;
                        money=0;
                        break;
                        }
                default:{
                        keyevent();
                        }
                }
             }
        if (money<0)
        {
           closeCanvas();
        }
        }
*/
void Money:: clickevent(bool &l,Buttons ng,bool hit_again ,bool stand_again, bool split_again){
		if(hit_again){
			Text t(400,400,"ARE U SURE U WANT TO SURRENDER??");
			Text t2(400,420,"CLICK ON RIGHT SIDE OF PAGE TO PROCEED.");
			int center=getClick();
			float cx=center/65536;
			if(cx>=400){
				if (split_again==2 or split_again==3){
					l=true;
					return;
				}
				money+=betmoney/2;
				betmoney=0;
				hlost++;
			}
			else{
				l=true;
				return;
			}
		}
		Rectangle b(450,400,400,200);
		b.setColor(COLOR("white"));
        b.setFill();
        Rectangle b1(450,400,400,200);
        Text t(450,380,"PLEASE SELECT APPROPRIATE BET");
        Text tT(450,400,"AND PRESS CONTINUE");
		const int SIZE[2]={200,40};
		float Y1=480,Y2=440;
		float X20=350,X50=550;
		Buttons b20("BET $20 MORE",X20,Y2,l),b50("BET $50 MORE",X50,Y2,l);
		Buttons ai("ALL IN",X20,Y1,l),con("CONTINUE",X50,Y1,l);	
		Rectangle r1(X20,Y2,SIZE[0],SIZE[1]);
        Text t1(X20,Y2,"BET $20 MORE");
        Rectangle r2(X50,Y2,SIZE[0],SIZE[1]);
        Text t2(X50,Y2,"BET $50 MORE");
        Rectangle r3(X20,Y1,SIZE[0],SIZE[1]);
        Text t3(X20,Y1,"ALL IN");
        Rectangle r4(X50,Y1,SIZE[0],SIZE[1]);
        Text t4(X50,Y1,"CONTINUE");
		while(true){
			int center=getClick();
			float cx=center/65536 ,  cy=center%65536;
			if(b20.is_click(cx,cy))	betmoney+=20;
			else if (b50.is_click(cx,cy)) betmoney+=50;
			else if (ai.is_click(cx,cy)){ 		
				betmoney=money;
			}
			else if (con.is_click(cx,cy)) {
				if (betmoney==0){
					continue;
				}
				break;
			}
			else if (ng.is_click(cx,cy)){
				l=true;
				return;
			}
			if (betmoney>=money){
				if (money==0){
					Text t1(450,360,"Try  double clicking on NEWGAMME to play another round");
					betmoney=0;
					wait(2);
					continue;
				}
				betmoney=money;
				money=0;
				Text t(450,340,"WARNING: Thats all u can bet in this round.!!!");
				Text t1(450,360,"Try double clicking on NEWGAMME to play another round");
				wait(2);
				return;
			}
				
			dispmon(money-betmoney);
		}
		money-=betmoney;
		dispmon(money);
	}

void Money::Bet(Buttons ng,int &split_again ,bool &stand_again,Deck &d,card &c, bool &hit_again){
        /*Rectangle r(400,350,250,250) ;
        r.setColor(COLOR(255,255,0));
        r.setFill();
        Rectangle r1(400,350,250,250);
        Text t1(400,318,"PRESS 'a' TO BET 20$");
        Text t2(400,344,"PRESS 'b' TO BET 50$");
        Text t3(400,370,"PRESS 'c' TO BET ALL THAT U HAVE!! ");
        keyevent();
        */
        bool l=false;
        clickevent(l,ng,hit_again,stand_again,split_again);
        if(l) return;
        Rectangle rb(400,377,800,16);
        rb.setColor(COLOR(255,255,255));
        rb.setFill();
        rb.imprint();
        dispmon(money);
        disptally();
        neww(split_again ,stand_again,d,c,hit_again);
        return;
        }

void Money::dispmon(int m)
    {

       Text moneyleft(20+(textWidth("Hands Won")+10)+20+((textWidth("Hands Lost")+10))+20+((textWidth("Hands Tied")+10))+20+((textWidth("Money Left")+10)/2),376+1,m);
       wait(0.5);
       moneyleft.imprint();
    }
void Money::disptally()
    {
        Text wins(20+((textWidth("Hands Won")+10)/2),376+1,hwon);
        wins.imprint();
        Text lose(20+(textWidth("Hands Won")+10)+20+((textWidth("Hands Lost")+10)/2),376+1,hlost);
        lose.imprint();
        Text tied(20+(textWidth("Hands Won")+10)+20+((textWidth("Hands Lost")+10))+20+((textWidth("Hands Tied")+10)/2),376+1,htied);
        tied.imprint();
    }
