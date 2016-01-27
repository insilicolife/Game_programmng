//----------------------------------------By: Nigatu Adossa------------------------------------------------------------------
//----------------------------------------Snake game programming----------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <fstream>
//#include <graphics.h>
#include <time.h>
//#include "SDL.h"
//#include <system.h>
#include <windows.h>


using namespace std;

void gotoxy(int x,int y)
{
    HANDLE hConsole;
    COORD cursorLoc;
    std::cout.flush();
    cursorLoc.X = x;
    cursorLoc.Y = y;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, cursorLoc);
}



class draw
{
private:

    int raw;
    int col;
    /*int score;
    int High_score;
    int speed;*/

public:
    draw(int c=75,int d=20);
    void draw_border();
    //void gotoxy(int x, int y);
    int randomvalue (int starting, int ending); // Return a random int value between end and starting parameters
    void put_food();


};
class snake: public draw
{
    //private:



public:

    int length;
    int head_x;
    int head_y;
    int tail_x;
    int tail_y;
    int tail_dir;
    int head_dir;
    int bend_x[1];
    int bend_y[1];
    int prev;
    int now;

    char snk[75][20];
    snake(int length, int head_x, int head_y, int tail_x, int tail_y, int head_dir, int tail_dir,int bend_x0,int bend_x1, int bend_y0,int bend_y1 );
    void make_snake();
    //void move_snake();
};
/*class play_game:public snake
{
    private:
    int score;
    int highscore;
    int start;
    int paouse;
    int speed;
    public:
    play_game(int score0,int highcore0,int start0,int paouse0);
    int give_score();
    int give_highscore;
    bool colision_ditacter();
};*/


draw::draw(int c,int d)
{
    raw=c;
    col=d;
}
void draw::draw_border()
{
    gotoxy(0,0);
    for (int j=0;j<raw;j++)
    {
        cout<<"x";
    }
    //gotoxy(1,col);
    for (int i=0;i<col;i++)
        cout<<"x"<<endl;
    //gotoxy(0,1);
    for (int k=0;k<raw;k++)
        cout<<"x";

    for (int z=0;z<col;z++)
    {
        gotoxy(raw,z+1);
        cout<<"x";
    }
    gotoxy(0,col+2);
    for (int a;a<80;a++)
    {
        cout<<'-';

    }
    cout<<endl<<"score=     "<<"High score=         "<<"speed=      "<<endl;
}
int draw::randomvalue(int starting, int ending) // Return a random int value between end and starting parameters

{
    static int previous = 0;
    int answer;
    if (previous <0) previous = 0;
    int difference = starting - ending;
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i <previous;i++) rand ();
    answer = (rand () % difference);
    previous++;
    return answer;
}
/*void draw::put_food()
{
static int foodcount = 0;//Keep Count of food
int futurex, futurey, futurepixel;
int i;
char scorestring [100];
if (foodcount < 500) //Adds a food if no food is present and upto maximum 500 food
{
int valid = 0;
int foodx;
int foody;
while (!valid)
{
foodx = randomvalue (15,1003);
foody = randomvalue (15,695);
if (getpixel (foodx,foody)!= 15)
{
putpixel (foodx,foody,2);
foodcount++;
valid = 1;
}
}
 }
}*/

void draw::put_food()
{
    for (int i=0;i<5;i++)
    {
        gotoxy(randomvalue(0,50),randomvalue(0,20));
        cout<<"�";
    }
}

snake::snake(int length0, int head_x0, int head_y0, int tail_x0, int tail_y0,int head_dir0,int tail_dir0,int bend_x0, int bend_x1,int bend_y0,int bend_y1)
{
    length=length0;
    head_x=head_x0;
    head_y=head_y0;
    tail_x=tail_x0;
    tail_y=tail_y0;
    head_dir=head_dir0;
    tail_dir=tail_dir0;
    bend_x[0]=bend_x0;
    bend_x[1]=bend_x1;
    bend_y[0]=bend_y0;
    bend_y[1]=bend_y1;



}
void snake::make_snake()
{

    for (int  i=0;i<length;i++)
    {
        gotoxy(head_x,head_y);
        snk[head_x][head_y]='~';
        cout<<snk[head_x][head_y];

        head_x++;

        //Sleep(1000);

    }
}

/*void snake::move_snake(snake a,int keypress)
    {   //head_dir=keypress;
        if(head_dir==6)
        head_x++;
        make_snake();
        Sleep(1000);
        if(head_dir==4)
        tail_x--;
        make_snake();
        Sleep(1000);

        if(head_dir==8)
        head_y++;
        make_snake();
        Sleep(1000);
        if(head_dir==2)
        head_dir--;
        make_snake();
        Sleep(1000);

    }*/

/*char snake0[5];
for(int  i=0;i<4;i++)
{
         gotoxy(35,10);
         int j=0;
         snake0[j]='~';
         cout<<snake0[j];
         j++;
}*/

void move(snake a)
{
    a.make_snake();
    a.tail_x=a.head_x-(a.length);
    a.tail_y=a.head_y;
//    putpixel(12,25,6);
    //int keypress;

    //if(kbhit());
    //a.head_dir=cin.get();
    for (int i=0;i<50;i++)
    {
        a.now=a.head_dir;
    if(kbhit())
    cin>>a.head_dir;
    a.prev=a.now;
    a.now=a.head_dir;
   //if(kbhit())

   //a.head_dir=getche();


         do{

           /* if(a.prev==2)
            {
            a.tail_x=a.head_x;
            a.tail_y=a.head_y-a.length;
            }
            else if(a.prev==8)
            {
            a.tail_x=a.head_x;
            a.tail_y=a.head_y+a.length;
            }
            else
            {
            a.tail_x=a.head_x-(a.length);
            a.tail_y=a.head_y;
            }*/



            ++a.head_x;
            a.snk[a.head_x][a.head_y]='~';
            gotoxy(a.head_x-1,a.head_y);
            cout<<a.snk[a.head_x][a.head_y];
            Sleep(100);

            gotoxy(a.tail_x,a.tail_y);
            a.snk[a.tail_x][a.tail_y]=' ';
            cout<<a.snk[a.tail_x][a.tail_y];
            //a.tail_x++;

            if(/*(a.prev==2) && (*/a.tail_y<a.head_y)
            {
                         a.tail_y++;}
            else if(a.tail_y>a.head_y)
            a.tail_y--;

            else{

                         a.tail_x++;}


          // if(/*(a.prev==8)&& (*/a.tail_y>a.head_y){
                        //   a.tail_y--;}
           // else {
                          // a.tail_x++;}

            Sleep(100);

            if(kbhit())

            cin>>a.head_dir;
            a.prev=a.now;
            a.now=a.head_dir;

            }while(a.head_dir==6);




        /*{
            //for(a.tail_x;a.tail_x<a.head_x;a.tail_x++)
            //{

            //int x=a.tail_x;
                   for(a.tail_x;a.tail_x<50;)
                    {

                int x=a.tail_x;
                a.snk[a.tail_x][a.tail_y]=' ';
                a.head_x++;
                a.tail_x++;

                a.snk[a.head_x][a.head_y]='~';
                //for(x;x<=a.head_x;x++)
                //cout<<a.snk[x][a.tail_y];

                 cout<<a.snk[x+1][a.tail_y];
                 Sleep(1000);

                  cout<<a.snk[x+2][a.tail_y];
                  Sleep(1000);
                   cout<<a.snk[x+3][a.tail_y];
                   Sleep(1000);
                 //cout<<a.snk[4][a.tail_y];
                cout<<a.snk[a.head_x][a.tail_y];
                //Sleep(1000);
                Sleep(1000);

                        /*for(a.tail_x-1;<a.tail_x(a.tail_x+5);a.tail_x++)
                        {
                            a.snk[a.tail_x]=' ';
                            a.tail_x++;
                            a.head_x++;
                            a.snk[a.head_x]='~';
                        cout<<a.snk[x];
                        Sleep(1000);
                        }
                        Sleep(1000);*/
        /*cout<<a.snk[a.tail_x+1];
        Sleep(1000);
        cout<<a.snk[a.tail_x+2];
        Sleep(1000);
        cout<<a.snk[a.tail_x+3];
        Sleep(1000);
        cout<<a.snk[a.tail_x+4];
        Sleep(1000);
        }*/
        //Sleep(1000);
        //}


        //if (a.head_dir==4)
        do{

            //a.head_x=a.tail_x;
            //a.tail_x=a.head_x;
            //a.head_x--;
            /*if(a.prev==2)
            {
            a.tail_x=a.head_x;
            a.tail_y=a.head_y-a.length;}
            if(a.prev==8)
            {
            a.tail_x=a.head_x;
            a.tail_y=a.head_y+a.length;
            }

            a.tail_x=a.head_x-(a.length);
            a.tail_y=a.tail_y;*/
            a.head_x--;

            a.snk[a.head_x][a.head_y]='~';
            gotoxy(a.head_x,a.head_y);
            cout<<a.snk[a.head_x][a.head_y];
            Sleep(100);

            a.snk[a.tail_x][a.tail_y]=' ';
            gotoxy(a.tail_x,a.tail_y);
            cout<<a.snk[a.tail_x][a.tail_y];
            if(a.tail_y>a.head_y)
            a.tail_y--;
            else if(a.tail_y<a.head_y)
            a.tail_y++;
            else
            a.tail_x--;

            Sleep(100);
            if(kbhit()){

            cin>>a.head_dir;
            a.prev=a.now;
            a.now=a.head_dir;}

        }while(a.head_dir==4);


        //if (a.head_dir==2)
        do{

            ++a.head_y;
            a.snk[a.head_x][a.head_y]='~';
            gotoxy(a.head_x,a.head_y-1);
            cout<<a.snk[a.head_x][a.head_y];
            Sleep(100);

            gotoxy(a.tail_x,a.tail_y);
            a.snk[a.tail_x][a.tail_y]=' ';
            cout<<a.snk[a.tail_x][a.tail_y];
            if (a.tail_x<a.head_x)
                ++a.tail_x;
                //++a.tail_y;}

            else
                ++a.tail_y;

            Sleep(100);

            if(kbhit()){

            cin>>a.head_dir;
            a.prev=a.now;
            a.now=a.head_dir;}
        }while(a.head_dir==2);
        //if (a.head_dir==8)
        do{
            --a.head_y;
            a.snk[a.head_x][a.head_y]='~';
            gotoxy(a.head_x,a.head_y);
            cout<<a.snk[a.head_x][a.head_y];
            Sleep(100);
            gotoxy(a.tail_x,a.tail_y);
            a.snk[a.tail_x][a.tail_y]=' ';
            cout<<a.snk[a.tail_x][a.tail_y];
            if (a.tail_x<a.head_x)
                ++a.tail_x;
            else
                --a.tail_y;
            Sleep(100);
        if(kbhit()){

            cin>>a.head_dir;
            a.prev=a.now;
            a.now=a.head_dir;}
        }while(a.head_dir==8);
        do
        {
        break;
        }while(a.head_dir==5);
        /*if(keypress==8)
            {



            }*/

        //}



    }
}

int main()
{

    //draw x;

    //x.put_food();

    //x.draw_border();
    snake y(4,15,5,11,5,6,6,0,0,0,0);
    y.draw_border();
    //y.make_snake();

    y.put_food();
     move(y);

    y.draw_border();
    //sleep(1000);
    system("PAUSE");
    return 0;
}

//-----------------------------------------------CopyRight Nigatu Adossa-----------------------------------------------------------
