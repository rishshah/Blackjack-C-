#include<simplecpp>
#include<cstdlib>
#include <ctime>
#include"id.h"
#include"Buttons.h"

void neww(int &split_again ,bool &stand_again,Deck &deck,card &c, bool &hit_again);
void Stand(bool &stand_again,Deck &d,card &c,bool &hit_again,int &split_again, Money &m);
void busted( bool &l,bool b, card &c,Deck &d1,bool &hit_again ,int &split_again, Money &m);

void hint(bool stand_again,Deck d,card c, bool hit_again,int split_again){
    if(!hit_again) return;
    Rectangle r(400,350,300,300);
    r.setColor(COLOR(255,255,0));
    r.setFill();
    Rectangle r1(400,350,300,300);
    int ace1=0;
    int val = c.calculate(ace1,c.player);
    string message;
    int dealer=c.cardval[c.dealer[1].cardno];
	int count=d.count()-d.countval[c.dealer[0].cardno];
	
	if(val<12) message="HIT is now the best move";

    if (ace1==10 and val<=17) message="HIT is now the best move";
    else if (val>=12){
    
		if(val>=12 and val<14){
			if(count>1 and dealer<5) message="STAND is now the best move";
			else if(count>1 and dealer>8){
				message="BET(SURRENDER) is now the best move";
				//if(ace1==1) message="HIT is now the best move.";
			}
			else if (count>1 and dealer<=8)message="HIT is now the best move.";
			
			
			
			if(count==1 and dealer>7)message="STAND is now the best move";
			else if(count==1 and dealer<=4){
				message="BET(SURRENDER) is now the best move";
				//if (ace1==1) message="HIT is now the best move.";
			}
			else if(count==1 and dealer<=6)message="HIT is now the best move.";
			
			
			
			if(count==0 and dealer>7)message="STAND is now the best move";
			else if(count==0 and dealer<=4){
				message="BET(SURRENDER) is now the best move";
				//if(ace1==1)message="HIT is now the best move.";
			}
			else if(count==0 and dealer<=7)	message="HIT is now the best move";
			
			
			
			if(count<=-1)message="HIT is now the best move";
		}

		else if(val<16){
			if(count>1 and  dealer<=6) message="STAND is now the best move";
			else if (count>1 and dealer>8){
				message="BET(SURRENDER) is now the best move";
				//if(ace1==1)message="HIT is now the best move.";
			}
			else if(count>1 and dealer<=8) message="HIT is now the best move";
			
			
			
			if((count==1 or count==0) and dealer>6)message="STAND is now the best move";
			else if((count==1 or count==0 )and dealer<=4){
				message="BET(SURRENDER) is now the best move";
				//if(ace1==1)message="HIT is now the best move.";
			}
			else if((count==1 or count==0 )and dealer<=6)message="HIT is now the best move";

			
			
			if(count==-1  and dealer>=8)message="STAND is now the best move";
			else if(count==-1 and dealer<6){
				message="BET(SURRENDER) is now the best move";
				//if(ace1==1)message="HIT is now the best move.";
			}
			else if(count==-1  and dealer>=6)message="HIT is now the best move";

			
			
			if(count<=-2) message="HIT is now the best move";
		}

		else if(val>17) message="STAND is now the best move";


		else{
			
			if(count>1 and  dealer<=6) message="STAND is now the best move";
			else if (count>1 and dealer>7){
				message="BET(SURRENDER) is now the best move";
				//if(ace1==1) message="HIT is now the best move.";
			}
			else if (count>1 and dealer<=7)message="HIT is now the best move.";
			
			
			
			if(count==1  and dealer>6)message="STAND is now the best move";
			else if(count==1  and dealer<=4){
				message="BET(SURRENDER) is now the best move";
				//if(ace1==1) message="HIT is now the best move.";
			}
			else if(count==1  and dealer<=6)message="HIT is now the best move.";

			
			
			if( ( count==0 or count==-1) and dealer>7) message="STAND is now the best move";
			else if( (count==0 or count==-1) and dealer<=5){
				message="BET(SURRENDER) is now the best move";
				//if(ace1==1)message="HIT is now the best move.";
			}
			else if( ( count==0 or count==-1) and dealer<=7) message="HIT is now the best move.";

			
			
			if(count<-1)message="HIT is now the best move";
			
		}
	}	
	int p=c.cardval[c.player[0].cardno];
	if(c.cardval[c.player[0].cardno]==c.cardval[c.player[1].cardno] and c.length(c.player)==2 and split_again==1){
		if( p==8 or p==7 or p==6 or p==11) message="SPLITTING is the best move";
		else if(p==9 or p==10){ 
			Text t5(400,360,"Do not SPLIT");
			wait(2);
		}		
		else{
			Text t4(400,360,"You may try SPLITTING");
			wait(2);
		}
	}

    if(message!="HIT is now the best move" and message!= "SPLITTING is the best move" and ace1==10)
    {
        message+="Or you may even HIT.";
        }
    Text t2(400,344,message);
    Text t3(400,400,"Click anywhere to continue");
    getClick();
    }

void deal(int &split_again ,Deck &d,card &p){
    id p1 = d.shuffle();
    p1.posx=57.5;
    p1.posy=262;
    p.display(p1);
    p.player[0]=p1;

	id p2 = d.shuffle();
    p2.posx=152.5;
    p2.posy=262;
    p.display(p2);
    p.player[1]=p2;

	id d1 = d.shuffle();
    d1.posx=57.5;
    d1.posy=106;
    p.dealer[0]=d1;

    Rectangle r(57.5,106,75,100);
    r.setColor(COLOR(64,0,0));
    r.setFill();
    r.imprint();
    Rectangle r1(57.5,106,75,100);
    r1.imprint();

    id d2 = d.shuffle();
    d2.posx=152.5;
    d2.posy=106;
    p.display(d2);
    p.dealer[1]=d2;
    if (p.cardval[p1.cardno]==p.cardval[p2.cardno] ){
		split_again=1;
		}
}

void busted(bool &stand_again,bool b,card &c,Deck &d1,bool &hit_again, int &split_again, Money &m){
	//cout<<"split"<<split_again<<endl;
    bool win=false;
    bool tie=false;
    bool loss=false;
    stand_again=true;
    int ace1=0;
    int p = c.calculate(ace1,c.player);
    int d= c.calculate(ace1,c.dealer);
    string s= " ";
    if (p>21)
    {
        p=c.calculate(ace1,c.player);
        if (p>21)
        {
            s="Player Busted.";
            m.hlost++;
            //cout<<"Player Busted"<<endl;
            stand_again=false;
            hit_again=false;
            loss=true;
        }
    }
    if (d>21)
    {
        s="Dealer Busted.";
        m.hwon++;
        win=true;
        //cout<<"Dealer Busted"<<endl;
        stand_again=false;
        hit_again=false;
    }
    if (b and d>=17 and d<=21)
    {
        if(p>d or p==21 )
        {
            s="You win.";
            m.hwon++;
            win=true;
            //cout<<"You win"<<endl;
            stand_again=false;
            hit_again=false;

        }
        if(d>p or d==21)
        {
            s="You lose.";
            m.hlost++;
            //cout<<"You lose"<<endl;
            stand_again=false;
            hit_again=false;
            loss=true;
        }
        if(p==d)
        {
            s="Its a tie.";
            m.htied++;
            //cout<<"Its a tie."<<endl;
            stand_again=false;
            hit_again=false;
            tie=true;
        }
    }
    if (!stand_again){
        Text t(600,377,s);
        wait(3);
        
  		if(win){ 	
			if(split_again==2){
				m.dispmon(m.money+2*m.betmoney);
				wait(0.5);
				m.money+=m.betmoney;
			}	
			else m.money+=(2*m.betmoney);

			if(p==21 and c.length(c.player)==2){
				m.money+=(m.betmoney/2);
			}
		}
		if(tie){
			if(split_again!=2){
				m.money+=(m.betmoney);
			}
			else{
				m.dispmon(m.money+m.betmoney);
				wait(0.5);
			}
		}
		if(loss){
			if(split_again==2){
				m.dispmon(m.money);
				wait(0.5);
				m.money-=m.betmoney;
			}	
		}
		
		if(split_again!=2){
			m.betmoney=0;
		}
        if(split_again==2){
            c.destroycard();
            for(int i=0;i<6;i++){
                c.player[i]=id();
                c.dealer[i]=id();
                }
			id p1=c.split[0];
			p1.posx=57.5;
			p1.posy=262;
			c.display(p1);
			c.player[0]=p1;
			c.split[0]=id();

			Rectangle r(57.5,106,75,100);
            r.setColor(COLOR(64,0,0));
            r.setFill();
            r.imprint();
            Rectangle r1(57.5,106,75,100);
            r1.imprint();

			id p2 = d1.shuffle();
			p2.posx=152.5;
			p2.posy=262;
			c.display(p2);
			c.player[1]=p2;

			id d3= d1.shuffle();
			d3.posx=57.5;
			d3.posy=106;
			c.dealer[0]=d3;

			id d2 = d1.shuffle();
			d2.posx=152.5;
			d2.posy=106;
			c.display(d2);
			c.dealer[1]=d2;
			hit_again=true;
			
			//if (c.cardval[p1.cardno]==c.cardval[p2.cardno] ){
				//split_again=1;
			//}
		    }
	}
	if (!stand_again and (split_again==3)){
		split_again=0;
		hit_again=false; stand_again=false;
	}
    if (!stand_again and (split_again==2)){
		split_again=3;
		if (d>=17) stand_again=false;
		else stand_again=true;
		hit_again=true;
	//	cout<<hit_again<<"after split"<<endl;
	}
    
    if(!b and d>=17){
        stand_again=false;
      //  cout<<hit_again<<endl;
        }
    if (b and d<17){
        Stand(stand_again,d1,c,hit_again,split_again,m);
    }
    Rectangle rb(400,377,800,16);
    rb.setColor(COLOR(255,255,255));
    rb.setFill();
    rb.imprint();

    m.disptally();
    m.dispmon(m.money);
   // cout<<hit_again<<"after bust"<<endl;
    return;
}

void Hit(bool &stand_again,Deck &d,card &c,bool &hit_again ,int &split_again, Money &m){
     if (!hit_again) {
		 return;
	 }
    stand_again=false;
    int ace1=0;
    id i=d.shuffle();
    i.posy=262;
    int l=c.length(c.player);
    i.posx=57.5+(l)*95;
    c.display(i);
    c.player[l]=i;
    //Text t(600,28,c.calculate(ace1,c.dealer));
    Text t2(600,184,c.calculate(ace1,c.player));
    wait(1);
    busted(stand_again,false,c,d,hit_again,split_again,m);
    }
void Stand(bool &stand_again,Deck &d,card &c,bool &hit_again,int &split_again, Money &m){
    c.display(c.dealer[0]);
    int ace1=0;
    if (!stand_again or c.calculate(ace1,c.dealer)>=17 ){
		//Text t(600,28,c.calculate(ace1,c.dealer));
		Text t2(600,184,c.calculate(ace1,c.player));
		if(hit_again){
			busted(stand_again,true,c,d,hit_again,split_again,m);
        }
        return;
        }
    id i=d.shuffle();
    i.posy=106;
    int l=c.length(c.dealer);
    i.posx=57.5+(l)*95;

    c.display(i);
    c.dealer[l]=i;
    //Text t(600,28,c.calculate(ace1,c.dealer));
    Text t2(600,184,c.calculate(ace1,c.player));
    wait(1);
    //cout<<hit_again<<"stand before bust"<<endl;
    busted(stand_again,true,c,d,hit_again,split_again,m);
    //cout<<hit_again<<"stand after bust"<<endl;
    }
void Newgame(Buttons ng,int &split_again ,bool &stand_again,Deck &deck,card &c, bool &hit_again,Money &m){
    for(int i=0;i<52;i++) deck.d[i]=1;
    m.money=200;
    m.betmoney=0;
    m.hwon=0;
    m.hlost=0;
    m.htied=0;
    hit_again=false;
    m.Bet(ng,split_again ,stand_again,deck,c,hit_again);
    }

void neww(int &split_again ,bool &stand_again,Deck &deck,card &c, bool &hit_again){
    for(int i=0;i<6;i++){
        c.player[i]=id();
        c.dealer[i]=id();
        }
        split_again=0;
        stand_again=true;
        hit_again=true;
        c.destroycard();
        deal(split_again,deck,c);
        return;
        }

void Ins(){
    Rectangle box(400,350,750,600);
    box.setColor(COLOR(255,255,0));
    box.setFill();
    Text title(400,128,"INSTRUCTIONS");
    string s="1. Before every hand you are expected to bet money. Choose appropriate amount to bet.";
    Text l1 (90+(textWidth(s)/2),128+20+8+(0*26),s);

    s="2. The objective of the game is to gain more points than the dealer.";
    Text l2(90+(textWidth(s)/2),128+20+8+(1*26),s);

    s="   Number cards have the face value. Face cards have value 10.";
    Text l3(90+(textWidth(s)/2),128+20+8+(2*26),s);

    s="   Aces have value 1 or 11 to the advantage of the user (AND DEALER TOO) ";
    Text l4(90+(textWidth(s)/2),128+20+8+(3*26),s);

    s= " 3. Click on bet to bet money and start game/hand.";
    Text l5(90+(textWidth(s)/2),128+20+8+(4*26),s);

    s= " 4. Click on hit to get a card dealt to you.";
    Text l6(90+(textWidth(s)/2),128+20+8+(5*26),s);

    s= " 5. Click on hint to get a free hint to win the hand.";
    Text l7(90+(textWidth(s)/2),128+20+8+(6*26),s);

    s= " 6. Click on stand to compare your score with the dealer.";
    Text l8(90+(textWidth(s)/2),128+20+8+(7*26),s);

    s= " 7. Click on new game to start a new game.";
    Text l9(90+(textWidth(s)/2),128+20+8+(8*26),s);

    s= " 8. Click on split to split your hand into two only if you have TWO EQUAL SCORING (NOT EQUAL FACE VALUE) cards.";
    Text l10(90+(textWidth(s)/2),128+20+8+(9*26),s);

	s= "    Two separated hands are played one after other.No multiple splitting is permitted.";
    Text l11(90+(textWidth(s)/2),128+20+8+(10*26),s);
    
    s= " 9. To win a bet you need to score less than 21 but more than the dealer.";
    Text l12(90+(textWidth(s)/2),128+20+8+(11*26),s);

    s= " 10. If the dealer has score less than 17 he WILL (MUST IN ALL CASES) automatically deal himself a new card.";
    Text l13(90+(textWidth(s)/2),128+20+8+(12*26),s);

    s= " 11. If either of you exceed 21 the opposite player automatically wins.";
    Text l14(90+(textWidth(s)/2),128+20+8+(13*26),s);

    s= " 12.Click anywhere to continue";
    Text l15(90+(textWidth(s)/2),128+20+8+(14*26),s);
    
    s= " 13.In case of blackjack,u get 250% of bet back else in normal win you get 200% ";
    Text l16(90+(textWidth(s)/2),128+20+8+(15*26),s);
    
    s= " 14.In case of surrender(BET) u get 50% bet back and in lost cases u lose entire bet";
    Text l17(90+(textWidth(s)/2),128+20+8+(16*26),s);
    
    getClick();
    }
void Split(Deck &d,card &c,int &split_again,Money m){
    if(split_again==0 or split_again==2 or split_again==3 ) return;
    split_again=2;
    c.split[0]=c.player[1];
    id p2 = d.shuffle();
    p2.posx=152.5;
    p2.posy=262;
    c.display(p2);
    c.player[1]=p2;
    }

main_program{
	srand((unsigned)time(0));
	initCanvas("BlackJack",800,700);
	Rectangle r(400,10-0.5,800,20-1);
	r.setColor(COLOR(0,91,0));
	r.setFill();
	r.imprint();
	r.moveTo(400,46);
	r.imprint();
	r.moveTo(400,166);
	r.imprint();
	r.moveTo(400,202);
	r.imprint();
	Rectangle bg(400,502,800,236);
	bg.setColor(COLOR(0,91,0));
	bg.setFill();
	bg.imprint();
	Rectangle v(10,184,20,256);
	v.setColor(COLOR(0,91,0));
	v.setFill();
	v.imprint();
	r.moveTo(400,322);
	r.imprint();
	r.moveTo(400,358);
	r.imprint();
	int i=1;
	repeat(9)
	{
        v.moveTo(10+(i*95),184);
        v.imprint();
        i++;
    }
	Rectangle ps(400,184,800,16);
	ps.setColor(COLOR("white"));
	ps.setFill();
	ps.imprint();
	Rectangle p(400,28,800,16);
	p.setColor(COLOR("white"));
	p.setFill();
	p.imprint();
	Text dt(50,28,"Dealer's Hand");
	Text pt(50,184,"Player's Hand");
	r.moveTo(500,28);
	r.imprint();
	r.moveTo(500,28+156);
	r.imprint();
    Text handswon(20+((textWidth("Hands Won")+10)/2),340+0.5,"Hands Won");
    Text handslost(20+(textWidth("Hands Won")+10)+20+((textWidth("Hands Lost")+10)/2),340+0.5,"Hands Lost");
    Text handstied(20+(textWidth("Hands Won")+10)+20+((textWidth("Hands Lost")+10))+20+((textWidth("Hands Tied")+10)/2),340+0.5,"Hands Tied");
    Text moneyleft(20+(textWidth("Hands Won")+10)+20+((textWidth("Hands Lost")+10))+20+((textWidth("Hands Tied")+10))+20+((textWidth("Money Left")+10)/2),340+0.5,"Money Left");
	bool stand_again=false, hit_again=false,l=true;
	int split_again=0;
    float Y1=680 ,Y2=640;
	float Xh=100 ,Xs=300,Xng=500,Xb=700;
    Buttons hit("HIT",Xh,Y2,l),stand("STAND",Xs,Y2,l),split("SPLIT",Xng,Y2,l),h("HINT",Xb,Y2,l);
    Buttons ins("INSTRUCTIONS",Xh,Y1,l),ng("NEW GAME",Xs,Y1,l),bet("BET",Xng,Y1,l),exit("EXIT",Xb,Y1,l);
	Deck d;
	card c;
	Money m;
	m.dispmon(m.money);
	Ins();
    m.Bet(ng,split_again ,stand_again,d,c,hit_again);
    while(true){
        int center=getClick();
        float cx=center/65536 ,  cy=center%65536;
        if(hit.is_click(cx,cy)) Hit(stand_again,d,c,hit_again,split_again,m);
        else if (stand.is_click(cx,cy)) Stand(stand_again,d,c,hit_again,split_again,m);
        else if (split.is_click(cx,cy)) Split(d,c,split_again,m);
        else if (exit.is_click(cx,cy)) break;
        else if (ins.is_click(cx,cy)) Ins();
        else if (ng.is_click(cx,cy)) Newgame(ng,split_again ,stand_again,d,c,hit_again,m);
        else if (bet.is_click(cx,cy)) m.Bet(ng,split_again ,stand_again,d,c,hit_again);
        else if (h.is_click(cx,cy)) hint(stand_again,d,c,hit_again,split_again);
    }
    
}


