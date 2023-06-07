#include<stdio.h>
#include<windows.h>
#include<time.h>

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
  
   struct coordmissile
  {
  	int xm;
  	int ym;
  	
  };
  typedef struct coordmissile cm;
  
  struct coordnavire
  {
  	int xb;
  	int yb;
  	
  };
  typedef struct coordnavire cb;
  
void main ()
{
  int grille[60][60];
  char NP1[10],NP2[10],pos,ch;
  int SP1=0,SP2=0,x,y,turn,c=0,i,j,t,replay=0,exit=0;
  cm cmp1[3],cmp2[3];
  cb cbp1[3],cbp2[3];
  char m=234,b=195;
  
while(exit==0)
{

  gotoxy(10,2);printf("PLAYER 1: ");SetTeColor(4);fflush(stdin);gets(NP1);SetTeColor(7);gotoxy(10,3);printf("Score:%d",SP1);
  gotoxy(100,2);SetTeColor(7);printf("PLAYER 2: ");SetTeColor(1);fflush(stdin);gets(NP2);SetTeColor(7);gotoxy(100,3);printf("Score:%d",SP2);
  
 gotoxy(60,3);printf(" ___");
 gotoxy(60,4);printf("|   | ");
 gotoxy(60,5);printf("|   | ");
 gotoxy(60,6);printf("|___| ");
 
  
  
   gotoxy(30,7);printf("   ___________________________________________________________ ");
   gotoxy(30,8);printf("  |         |         |         |         |         |         |");
   gotoxy(30,9);printf("5 |         |         |         |         |         |         |");
  gotoxy(30,10);printf("  |_________|_________|_________|_________|_________|_________|");
  gotoxy(30,11);printf("  |         |         |         |         |         |         |");
  gotoxy(30,12);printf("4 |         |         |         |         |         |         |");
  gotoxy(30,13);printf("  |_________|_________|_________|_________|_________|_________|");
  gotoxy(30,14);printf("  |         |         |         |         |         |         |");
  gotoxy(30,15);printf("3 |         |         |         |         |         |         |");
  gotoxy(30,16);printf("  |_________|_________|_________|_________|_________|_________|");
  gotoxy(30,17);printf("  |         |         |         |         |         |         |");
  gotoxy(30,18);printf("2 |         |         |         |         |         |         |");
  gotoxy(30,19);printf("  |_________|_________|_________|_________|_________|_________|");
  gotoxy(30,20);printf("  |         |         |         |         |         |         |");
  gotoxy(30,21);printf("1 |         |         |         |         |         |         |");
  gotoxy(30,22);printf("  |_________|_________|_________|_________|_________|_________|");
  gotoxy(30,23);printf("  |         |         |         |         |         |         |");
  gotoxy(30,24);printf("0 |         |         |         |         |         |         |");
  gotoxy(30,25);printf("  |_________|_________|_________|_________|_________|_________|");
  gotoxy(30,26);printf("       0         1         2         3         4         5");
  
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
  		gotoxy(62,5);SetTeColor(4);printf("O");
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
			            SetTeColor(4);printf("_%c_",b);SetTeColor(7);
  			      	    for(i=c;i<=c;i++)
							{
							  cbp1[i].xb=wherex();
  			      	          cbp1[i].yb=wherey();
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
	    gotoxy(62,5);SetTeColor(1);printf("O");
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
			            SetTeColor(1);printf("_%c_",b);SetTeColor(7);
  			      	    for(i=c;i<=c;i++)
							{
							  cbp2[i].xb=wherex();
  			      	          cbp2[i].yb=wherey();
							}
							
  			      	    grille[y][x]=1;
  			      	    c++;
			        } 
  			default: break;
		  }
		  gotoxy(x+36,y+9);
		  if(c==3)
		  {
		  	turn=1;
		  	for(t=0;t<3;t++)
		  	{
			  if(turn==1)
	        {
	          gotoxy(62,5);SetTeColor(4);printf("O");SetTeColor(7);
	          SetTeColor(4);gotoxy(17,30);printf("PLAYER 1:\n");SetTeColor(7);	
	  	      do{
	  	      	    gotoxy(20,33);printf("Donner les coordonnees de missile %d: ",t+1);
	  	            gotoxy(20,34);printf("x:");scanf("%d",&cmp1[t].xm); gotoxy(30,34);printf("y:");scanf("%d",&cmp1[t].ym);
				}while(cmp1[t].xm<0 || cmp1[t].xm>5 || cmp1[t].ym<0 || cmp1[t].ym>5);
	  	      srand(time(0));
				 for(j=32;j<=32+(cmp1[t].xm*10);j++)
	             
	                { 
					   x=47;
	                   gotoxy(j,28);SetTeColor(4);printf(" |_(   )_|");SetTeColor(7);
	                   delay(x);
	               }
	               
	              for(i=28;i>24-(cmp1[t].ym*3);i--)
	             
	                { 
					   y=47;
	                   gotoxy(j+3,i);SetTeColor(4);printf(" %c",m);SetTeColor(7);
	                   delay(y);
	                   gotoxy(j+3,i);printf("  ");
	                }
	                
	               for(i=0;i<c;i++)
					{
						if( ( wherex()<=cbp2[i].xb+2 && wherex()>=cbp2[i].xb-2 ) && ( wherey()<=cbp2[i].yb+1 && wherey()>=cbp2[i].yb-1) && cbp2[i].xb!=0 && cbp2[i].yb!=0 )
						{
						  SP1++;
						  gotoxy(wherex()-2,wherey()-1);SetTeColor(4);printf(" X ");SetTeColor(7);
						  gotoxy(16,3);printf("%d",SP1);
						  cbp2[i].xb=0;
						  cbp2[i].yb=0;
						  
						}
					}
	               gotoxy(30,26);printf("       0         1         2         3         4         5");
	  	      }
	  	      turn=2;
	  	      
	  	      
	  	      if(turn==2)
	        {
	          gotoxy(62,5);SetTeColor(1);printf("O");SetTeColor(7);	
	          SetTeColor(1);gotoxy(17,36);printf("PLAYER 2:\n");SetTeColor(7);	
	  	      do{
	  	      	    gotoxy(20,39);
	  	      	    printf("Donner les coordonnees de missile %d: ",t+1);
				    gotoxy(20,40);printf("x:");scanf("%d",&cmp2[t].xm);gotoxy(30,40);printf("y:");scanf("%d",&cmp2[t].ym);
					}while(cmp2[t].xm<0 || cmp2[t].xm>5 || cmp2[t].ym<0 || cmp2[t].ym>5 );
	  	      
	  	        gotoxy(22,34);printf("  ");gotoxy(32,34);printf("  ");
	  	        gotoxy(22,40);printf("  ");gotoxy(32,40);printf("  ");
	  	      
				srand(time(0));
				 for(j=32;j<=32+(cmp2[t].xm*10);j++)
	             
	                { 
					   x=47;
	                   gotoxy(j,28);SetTeColor(1);printf(" |_(   )_|");SetTeColor(7);
	                   delay(x);
	               }
	               
	              for(i=28;i>24-(cmp2[t].ym*3);i--)
	             
	                { 
					   y=47;
	                   gotoxy(j+3,i);SetTeColor(1);printf(" %c",m);SetTeColor(7);
	                   delay(y);
	                   gotoxy(j+3,i);printf("  ");
	                }
	               for(i=0;i<c;i++)
					{
						if( ( wherex()<=cbp1[i].xb+2 && wherex()>=cbp1[i].xb-2 ) && ( wherey()<=cbp1[i].yb+1 && wherey()>=cbp1[i].yb-1 ) && cbp1[i].xb!=0 && cbp1[i].yb!=0 ) 
						{
						  SP2++;
						  gotoxy(wherex()-2,wherey()-1);SetTeColor(1);printf(" X ");SetTeColor(7);
						  gotoxy(106,3);printf("%d",SP2);
						  cbp1[i].xb=0;
						  cbp1[i].yb=0;
						}
					}
					
	               gotoxy(30,26);printf("       0         1         2         3         4         5");
	  	      }
	  	      turn=1;
	  	     
	  	
	        }
	        
	     }
		       
		}
		  	  
    }
    
    if(SP1>SP2)
    {
  	   SetTeColor(4);gotoxy(40,50);printf("PLAYER 1 is the winner ");SetTeColor(7);printf("with score:%d",SP1);	
	}
	else if(SP2>SP1)
	{
  	   SetTeColor(1);gotoxy(40,50);printf("PLAYER 2 is the winner ");SetTeColor(7);printf("with score:%d",SP2);	
	}
	else 
	{
  	   SetTeColor(7);gotoxy(50,50);printf("DRAW");SetTeColor(7);	
	}
	
	gotoxy(38,61);printf("PLAY AGAIN");                     gotoxy(60,61);printf(" EXIT ");                         
	gotoxy(40,63);printf(" ___");                           gotoxy(60,63);printf(" ___");
	gotoxy(40,64);printf("|   |");                          gotoxy(60,64);printf("|   |");
	gotoxy(40,65);printf("|   |");                          gotoxy(60,65);printf("|   |");
	gotoxy(40,66);printf("|___|");                          gotoxy(60,66);printf("|___|"); 
     	
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
			                    replay=1;gotoxy(x+42,65);SetTeColor(2);printf("X");SetTeColor(7);
		                      }
  			         else {
  			         	             exit=1;gotoxy(x+42,65);SetTeColor(2);printf("X");SetTeColor(7);break;
					     }
			default: break;        
		 } 
		 gotoxy(x+42,65);
		 }
		 system("CLS");
		 replay=0;
		 SP1=0;SP2=0;c=0;
}
	gotoxy(90,60);SetTeColor(4);printf("E:");SetTeColor(7);printf("K/Z/D ");
  		
 } 


