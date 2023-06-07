#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>

using namespace std;

void delay(int di)
{
	clock_t start,end;
	start=clock();
	while (((end=clock())-start)<=((di*CLOCKS_PER_SEC)/1000));
}

void SetTeColor(WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}


void gotoxy(int x,int y){
	
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.X;
}

int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.Y;
}


char m=234,b=195;

 class cm
  {
  	public:
  		
    int xm;
    int ym;
 	
  };
  
  
  class cb
  {
  	public:	
  	int xb;
  	int yb;
  	friend class Player;
  	
  };
  
class Player 
{
	public:
	string NP;
	int SP;
   cm cmp[3];
   cb cbp[3]; 
   
		void launchmissile(Player P,int t){
			int j,x,y;
			do{
	  	      	    gotoxy(20,33);cout<<"Donner les coordonnees de missile "<<t+1;
	  	            gotoxy(20,34);cout<<"x:";cin>>this->cmp[t].xm; gotoxy(30,34);cout<<"y:";cin>>this->cmp[t].ym;
	  	            gotoxy(22,34);cout<<"   ";
					gotoxy(32,34);cout<<"   ";
				}while(this->cmp[t].xm<0 || this->cmp[t].xm>5 || this->cmp[t].ym<0 || this->cmp[t].ym>5);
	  	      srand(time(0));
				 for(j=32;j<=32+(this->cmp[t].xm*10);j++)
	             
	                { 
					   x=47;
	                   gotoxy(j,28);cout<<" |_(   )_|";
	                   delay(x);
	               }
				PlaySound("C:\\Users\\sa7toute\\Documents\\Computer Engineering Education\\3A IIR\\tie-fighter-explode.wav",NULL,SND_FILENAME|SND_ASYNC);	
	              for(int i=28;i>24-(this->cmp[t].ym*3);i--)
	             
	                { 
					  int y=47;
	                   gotoxy(j+3,i);cout<<m;
	                   delay(y);
	                   gotoxy(j+3,i);cout<<"  ";
	                }
	                
	               for(int i=0;i<3;i++)
					{
						if( ( wherex()<=P.cbp[i].xb+2 && wherex()>=P.cbp[i].xb-2 ) && ( wherey()<=P.cbp[i].yb+1 && wherey()>=P.cbp[i].yb-1) && P.cbp[i].xb!=0 && P.cbp[i].yb!=0 )
						{
						  (this->SP)++;
						  gotoxy(wherex()-2,wherey()-1);cout<<" X ";
						
						}
					}
		}
};
  
  
  
  int FlipTheCoin(){
  	
   int x=0;
  	char chp;
  	
   gotoxy(100,7);cout<<"   ______________________________________________________________________ ";
   gotoxy(100,8);cout<<"  |                                                                      |";
   gotoxy(100,9);cout<<"  |                                                                      |";
  gotoxy(100,10);cout<<"  |                                                                      |";
  gotoxy(100,11);cout<<"  |                                                                      |";
  gotoxy(100,12);cout<<"  |                                                                      |";
  gotoxy(100,13);cout<<"  |                                                                      |";
  gotoxy(100,14);cout<<"  |                                                                      |";
  gotoxy(100,15);cout<<"  |                                                                      |";
  gotoxy(100,16);cout<<"  |                                                                      |";
  gotoxy(100,17);cout<<"  |                                                                      |";
  gotoxy(100,18);cout<<"  |                                                                      |";
  gotoxy(100,19);cout<<"  |                                                                      |";
  gotoxy(100,20);cout<<"  |                                                                      |";
  gotoxy(100,21);cout<<"  |                                                                      |";
  gotoxy(100,22);cout<<"  |                                                                      |";
  gotoxy(100,23);cout<<"  |                                                                      |";
  gotoxy(100,24);cout<<"  |                                                                      |";
  gotoxy(100,25);cout<<"  |______________________________________________________________________|";

gotoxy(103,8);

srand(time(0));
  std::cout << "Player 1, enter your guess (H for heads, T for tails): ";
  char player1Guess;
  
  
  gotoxy(108,9);cout<<"HEAD";                           gotoxy(118,9);cout<<" TAILS ";                         
	gotoxy(110,10);cout<<" ___";                           gotoxy(120,10);cout<<" ___";
	gotoxy(110,11);cout<<"|   |";                          gotoxy(120,11);cout<<"|   |";
	gotoxy(110,12);cout<<"|   |";                          gotoxy(120,12);cout<<"|   |";
	gotoxy(110,13);cout<<"|___|";                          gotoxy(120,13);cout<<"|___|"; 
     	
     	
     	
		while(player1Guess !='H' && player1Guess !='T')
		{
		  gotoxy(x+112,12);
		  chp=getch();
		  switch(chp)
     	{
     		case 77: if(x<10)x+=10;break;
  			case 75: if(x>0)x-=10;break;
  			case 13: if(x==0) {
			                    player1Guess ='H';gotoxy(x+112,12);SetTeColor(2);cout<<"X";SetTeColor(7);break;
		                      }
  			         else {
  			         	x=0;
  			         	             player1Guess ='T';gotoxy(x+122,12);SetTeColor(2);cout<<"X";SetTeColor(7);break;
					     }
			default: break;		     
			        
		 } 
}
  gotoxy(103,15);std::cout << "Player 2, enter your guess (H for heads, T for tails): ";
  char player2Guess;
  x=0;
  
  gotoxy(110,16);cout<<"HEAD";                     gotoxy(120,16);cout<<" TAILS ";                         
	gotoxy(110,17);cout<<" ___";                           gotoxy(120,17);cout<<" ___";
	gotoxy(110,18);cout<<"|   |";                          gotoxy(120,18);cout<<"|   |";
	gotoxy(110,19);cout<<"|   |";                          gotoxy(120,19);cout<<"|   |";
	gotoxy(110,20);cout<<"|___|";                          gotoxy(120,20);cout<<"|___|"; 
     	
     	
     	
  	while(player2Guess !='H' && player2Guess !='T')
		{
		  gotoxy(x+112,19);
		  chp=getch();
		  switch(chp)
     	{
     		case 77: if(x<10)x+=10;break;
  			case 75: if(x>0)x-=10;break;
  			case 13: if(x==0) {
			                    player2Guess ='H';gotoxy(x+112,19);SetTeColor(2);cout<<"X";SetTeColor(7);break;
		                      }
  			         else {
  			         	x=0;
  			         	             player2Guess ='T';gotoxy(x+122,19);SetTeColor(2);cout<<"X";SetTeColor(7);break;
					     }
			default: break;			     
			       
		 } 
		 }


  
  int coin = rand() % 2;

  
  char outcome;
  if (coin == 0) {
    outcome = 'H';
  } else if (coin == 1) {
    outcome = 'T';
  }
  

  
  if (player1Guess == outcome && player2Guess != outcome) {
    gotoxy(103,22);std::cout << "Player 1 wins!" <<endl;
    return 1;
  } else if (player2Guess == outcome && player1Guess != outcome) {
    gotoxy(103,22);std::cout << "Player 2 wins!" <<endl;
    return 2;
  }
  
  else {
    gotoxy(103,22);std::cout << "It's a tie! => repeating the coin flip" <<endl;getch();
    
    gotoxy(103,8);cout << "                                                            ";
    gotoxy(103,15);cout << "                                                            ";
    gotoxy(103,22);cout << "                                                            ";
    
    gotoxy(x+112,19);cout << "  ";
    gotoxy(x+122,19);cout << "  ";
    gotoxy(x+112,12);cout << "  ";
    gotoxy(x+122,12);cout << "  ";
    
    return FlipTheCoin();
    
  }

  }
  
int main ()
{
  int grille[60][60];
  Player P1,P2;P1.SP=0;P2.SP=0;
  char pos,ch;
  int x,y,turn,c=0,i,j,t1,t2,replay=0,exit=0,flipcturn=0;
  //cm cmp1[3],cmp2[3];
  //cb cbp1[3],cbp2[3];
  
while(exit==0)
{

  gotoxy(10,2);cout<<"PLAYER 1: ";SetTeColor(4);cin>>P1.NP;SetTeColor(7);gotoxy(10,3);cout<<"Score: "<<P1.SP;
  gotoxy(100,2);SetTeColor(7);cout<<"PLAYER 2: ";SetTeColor(1);cin>>P2.NP;SetTeColor(7);gotoxy(100,3);cout<<"Score: "<<P2.SP;
  
 gotoxy(60,3);printf(" ___");
 gotoxy(60,4);printf("|   | ");
 gotoxy(60,5);printf("|   | ");
 gotoxy(60,6);printf("|___| ");
 
  
  
   gotoxy(30,7);cout<<"   ___________________________________________________________ ";
   gotoxy(30,8);cout<<"  |         |         |         |         |         |         |";
   gotoxy(30,9);cout<<"5 |         |         |         |         |         |         |";
  gotoxy(30,10);cout<<"  |_________|_________|_________|_________|_________|_________|";
  gotoxy(30,11);cout<<"  |         |         |         |         |         |         |";
  gotoxy(30,12);cout<<"4 |         |         |         |         |         |         |";
  gotoxy(30,13);cout<<"  |_________|_________|_________|_________|_________|_________|";
  gotoxy(30,14);cout<<"  |         |         |         |         |         |         |";
  gotoxy(30,15);cout<<"3 |         |         |         |         |         |         |";
  gotoxy(30,16);cout<<"  |_________|_________|_________|_________|_________|_________|";
  gotoxy(30,17);cout<<"  |         |         |         |         |         |         |";
  gotoxy(30,18);cout<<"2 |         |         |         |         |         |         |";
  gotoxy(30,19);cout<<"  |_________|_________|_________|_________|_________|_________|";
  gotoxy(30,20);cout<<"  |         |         |         |         |         |         |";
  gotoxy(30,21);cout<<"1 |         |         |         |         |         |         |";
  gotoxy(30,22);cout<<"  |_________|_________|_________|_________|_________|_________|";
  gotoxy(30,23);cout<<"  |         |         |         |         |         |         |";
  gotoxy(30,24);cout<<"0 |         |         |         |         |         |         |";
  gotoxy(30,25);cout<<"  |_________|_________|_________|_________|_________|_________|";
  gotoxy(30,26);cout<<"       0         1         2         3         4         5";
  
  for(i=0;i<60;i++)
    {
    	for(j=0;j<60;j++)
        grille[i][j]=0;  
	}
  x=0;y=0;
  turn=1;

  while(c<3)
  {
  	if(turn==1)
  	{
  		gotoxy(62,5);SetTeColor(4);cout<<"O";
  		gotoxy(x+36,y+9);
  		pos=getch();
  		switch (pos)
  		{
  			case 77: if(x<50)x+=10;break;
  			case 75: if(x>0)x-=10;break;
  			case 80: if(y<15)y+=3;break;
  			case 72: if(y>0)y-=3;break;
  			case 13 : if(grille[y][x]==0)
			         {
			            SetTeColor(4);cout<<"_"<<b<<"_";SetTeColor(7);
  			      	    for(i=c;i<=c;i++)
							{
							  P1.cbp[i].xb=wherex();
  			      	          P1.cbp[i].yb=wherey();
							}
  			      	    grille[y][x]=1;
  			      	    c++;
					    
			        } 
					 
  			default: break;
		  }
		  gotoxy(x+36,y+9);
		  if(c==3)
		  {
		    turn=2;
		    c=0; 
		  }
		  	  	  
	  }
	  
	  
	  else
	  {
	    gotoxy(62,5);SetTeColor(1);cout<<"O";
  		gotoxy(x+36,y+9);
  		pos=getch();
  		switch (pos)
  		{
  			case 77: if(x<50)x+=10;break;
  			case 75: if(x>0)x-=10;break;
  			case 80: if(y<15)y+=3;break;
  			case 72: if(y>0)y-=3;break;
  			case 13 : if(grille[y][x]==0)
			         {
			            SetTeColor(1);cout<<"_"<<b<<"_";SetTeColor(7);
  			      	    for(i=c;i<=c;i++)
							{
							  P2.cbp[i].xb=wherex();
  			      	          P2.cbp[i].yb=wherey();
							}
							
  			      	    grille[y][x]=1;
  			      	    c++;
			        } 
  			default: break;
		  }
		  gotoxy(x+36,y+9);
}}
		  if(c==3)
		  {
		  
	        
	      int cturn=0; 
		  t1=0;t2=0; 
	    do{
	        if(FlipTheCoin()==1)
	        {
	        	gotoxy(62,5);SetTeColor(4);cout<<"O";SetTeColor(7);
	            SetTeColor(4);gotoxy(17,30);cout<<"PLAYER 1:"<<endl;
	        	P1.launchmissile(P2,t1);SetTeColor(7);
	        	gotoxy(16,3);cout<<"  ";gotoxy(16,3);cout<<" "<<P1.SP;
	        	cturn++;
	        	t1++;
	        	gotoxy(17,30);cout<<"                                    ";
				gotoxy(20,33);cout<<"                                    ";
	        	gotoxy(20,34);cout<<"                                    ";
				gotoxy(30,26);cout<<"       0         1         2         3         4         5";
	        	
			}
			else if(FlipTheCoin()==2)
			{
				gotoxy(62,5);SetTeColor(1);cout<<"O";SetTeColor(7);	
	            SetTeColor(1);gotoxy(17,30);cout<<"PLAYER 2:"<<endl;
				P2.launchmissile(P1,t2);SetTeColor(7);
				gotoxy(106,3);cout<<"  ";gotoxy(106,3);cout<<" "<<P2.SP;
				cturn++;
				t2++;
				gotoxy(17,30);cout<<"                                    ";
				gotoxy(20,33);cout<<"                                    ";
				gotoxy(20,34);cout<<"                                    ";
				gotoxy(30,26);cout<<"       0         1         2         3         4         5";
			}
	    }while(cturn<3);
	        
	     }
	     

    
    if(P1.SP>P2.SP)
    {
  	   SetTeColor(4);gotoxy(31,48);
		 cout<<"Congratulations, "<<P1.NP<<" You are the champion with a score of: " << P1.SP <<endl;
		 
   gotoxy(41,50);cout << "     _______________    " <<endl;
  gotoxy(41,51);cout << "    '. _ = = = = _ .'     " <<endl;
  gotoxy(41,52);cout << "   .- \\ :   :     / -.    " <<endl;
  gotoxy(41,53);cout << "   |  (|:.     .:|)  |    " <<endl;
  gotoxy(41,54);cout << "    '-|:.       .:|-'     " <<endl;
  gotoxy(41,55);cout << "       \\ ::...:: /      " <<endl;
  gotoxy(41,56);cout << "        '::. .::'        " <<endl;
  gotoxy(41,57);cout << "           ) (          " <<endl;
  gotoxy(41,58);cout << "        _ .' '. _        " <<endl;
  gotoxy(41,59);cout << "       '---------'       " <<endl;SetTeColor(7);
	
	}
	else if(P2.SP>P1.SP)
	{
  	   SetTeColor(1);gotoxy(31,48);
  	   		 cout<<"Congratulations, "<<P2.NP<<" You are the champion with a score of: " << P2.SP <<endl;
		 
  gotoxy(41,50);cout << "     _______________    " <<endl;
  gotoxy(41,51);cout << "    '. _ = = = = _ .'     " <<endl;
  gotoxy(41,52);cout << "   .- \\ :   :     / -.    " <<endl;
  gotoxy(41,53);cout << "   |  (|:.     .:|)  |    " <<endl;
  gotoxy(41,54);cout << "    '-|:.       .:|-'     " <<endl;
  gotoxy(41,55);cout << "       \\ ::...:: /      " <<endl;
  gotoxy(41,56);cout << "        '::. .::'        " <<endl;
  gotoxy(41,57);cout << "           ) (          " <<endl;
  gotoxy(41,58);cout << "        _ .' '. _        " <<endl;
  gotoxy(41,59);cout << "       '---------'       " <<endl;SetTeColor(7);
  	   
	}
	else 
	{
  	   SetTeColor(7);gotoxy(50,50);cout<<"DRAW";SetTeColor(7);	
	}
	
	gotoxy(38,61);cout<<"PLAY AGAIN";                     gotoxy(60,61);cout<<" EXIT ";                         
	gotoxy(40,63);cout<<" ___";                           gotoxy(60,63);cout<<" ___";
	gotoxy(40,64);cout<<"|   |";                          gotoxy(60,64);cout<<"|   |";
	gotoxy(40,65);cout<<"|   |";                          gotoxy(60,65);cout<<"|   |";
	gotoxy(40,66);cout<<"|___|";                          gotoxy(60,66);cout<<"|___|"; 
     	
     	x=0;
     	gotoxy(x+42,65);
		while(replay==0 && exit==0)
		{
		  ch=getch();
		  switch(ch)
     	{
     		case 77: if(x<20)x+=20;break;
  			case 75: if(x>0)x-=20;break;
  			case 13: if(x==0) {
			                    replay=1;gotoxy(x+42,65);SetTeColor(2);cout<<"X";SetTeColor(7);
		                      }
  			         else {
  			         	             exit=1;gotoxy(x+42,65);SetTeColor(2);cout<<"X";SetTeColor(7);break;
					     }
			default: break;        
		 } 
		 gotoxy(x+42,65);
		 }
		 system("CLS");
		 replay=0;
		 P1.SP=0;P2.SP=0;c=0;
}
	gotoxy(90,60);SetTeColor(4);cout<<"E:";SetTeColor(7);cout<<"K/D/A/I ";
	
	return 0;
  		
 } 
