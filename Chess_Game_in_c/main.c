
//----------------------------------------Nigatu Adossa--------------------------------------------------------
//----------------------------------------Chess Game programming in C------------------------------------------
//-------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BORDSIZE 64
#define INVALID_RANK 10
#define INVALID_FILE 9
#define KILLED 100
#define HORIZONTAL_LENGTH 8
#define RIGHT_MOVE 2
#define WRONG_MOVE 1
#define WHITE 0
#define BLACK 1
#define UNDEFINED -1
#define STOP 0
#define KEYVORD_INPUT 10

//--------------------------global variable declaration-----------------------------------------------------------------
typedef struct chess_pieces// data type to store chess piece information
{
    int rank;
    char file;
    char piece_name;
    char color;
}
chess_piece;

chess_piece setup[BORDSIZE];//a structure that holde the ongoing movments of the peices

chess_piece bourder[BORDSIZE]= //initial peice setup information
{
    {
        1,'a','r','w'
    },
    {
        1,'b','n','w'
    },
    {
        1,'c','b','w'
    },
    {
        1,'d','q','w'
    },
    {
        1,'e','k','w'
    },
    {
        1,'f','b','w'
    },
    {
        1,'g','n','w'
    },
    {
        1,'h','r','w'
    },

    {
        2,'a','p','w'
    },
    {
        2,'b','p','w'
    },
    {
        2,'c','p','w'
    },
    {
        2,'d','p','w'
    },
    {
        2,'e','p','w'
    },
    {
        2,'f','p','w'
    },
    {
        2,'g','p','w'
    },
    {
        2,'h','p','w'
    },

    {
        3,'a',' ',' '
    },
    {
        3,'b',' ',' '
    },
    {
        3,'c',' ',' '
    },
    {
        3,'d',' ',' '
    },
    {
        3,'e',' ',' '
    },
    {
        3,'f',' ',' '
    },
    {
        3,'g',' ',' '
    },
    {
        3,'h',' ',' '
    },

    {
        4,'a',' ',' '
    },
    {
        4,'b',' ',' '
    },
    {
        4,'c',' ',' '
    },
    {
        4,'d',' ',' '
    },
    {
        4,'e',' ',' '
    },
    {
        4,'f',' ',' '
    },
    {
        4,'g',' ',' '
    },
    {
        4,'h',' ',' '
    },

    {
        5,'a',' ',' '
    },
    {
        5,'b',' ',' '
    },
    {
        5,'c',' ',' '
    },
    {
        5,'d',' ',' '
    },
    {
        5,'e',' ',' '
    },
    {
        5,'f',' ',' '
    },
    {
        5,'g',' ',' '
    },
    {
        5,'h',' ',' '
    },

    {
        6,'a',' ',' '
    },
    {
        6,'b',' ',' '
    },
    {
        6,'c',' ',' '
    },
    {
        6,'d',' ',' '
    },
    {
        6,'e',' ',' '
    },
    {
        6,'f',' ',' '
    },
    {
        6,'g',' ',' '
    },
    {
        6,'h',' ',' '
    },

    {
        7,'a','p','b'
    },
    {
        7,'b','p','b'
    },
    {
        7,'c','p','b'
    },
    {
        7,'d','p','b'
    },
    {
        7,'e','p','b'
    },
    {
        7,'f','p','b'
    },
    {
        7,'g','p','b'
    },
    {
        7,'h','p','b'
    },

    {
        8,'a','r','b'
    },
    {
        8,'b','n','b'
    },
    {
        8,'c','b','b'
    },
    {
        8,'d','q','b'
    },
    {
        8,'e','k','b'
    },
    {
        8,'f','b','b'
    },
    {
        8,'g','n','b'
    },
    {
        8,'h','r','b'
    },
};

//---------------------------------------game logic functions--------------------------------------------------------------

//--------------------------------finding rank cordinate in the chass board-------------------------------------------
int rankf_axis(int c)
{
    switch(c)

    {
    case 0:
        return 8;
        break;
    case 1:
        return 7;
        break;
    case 2:
        return 6;
        break;
    case 3:
        return 5;
        break;
    case 4:
        return 4;
        break;
    case 5:
        return 3;
        break;
    case 6:
        return 2;
        break;
    case 7:
        return 1;
        break;
    case 8:
        return 0;
        break;
    default:
        return INVALID_RANK;
        break;
    }
}


//-------------------------------------printing the status of chass board to the screen----------------------------------
void print_setup()
{
    int x,y;
    char files='a';

    for(y=0; y<HORIZONTAL_LENGTH; y++)
    {

        printf("\n\n\n\n            %d",rankf_axis(y));

        for(x=0; x<HORIZONTAL_LENGTH; x++)
        {
            printf(" %3c",setup[HORIZONTAL_LENGTH*y+x].color);
            printf("%c ",setup[HORIZONTAL_LENGTH*y+x].piece_name);


        }
    }
    printf("\n\n            %c",' ');
    for(y=0; y<HORIZONTAL_LENGTH; y++)
    {
        printf("%4c  ",files);
        files++;
    }

}
//------------------------------------printing the initial chess board-----------------------------------------------
void draw_setup()
{
    int i;
    for(i=0; i<BORDSIZE; i++)
    {

        setup[i]=bourder[i];

    }
    print_setup();
}

//----------------------------------finding the file coortdinate in the chass board------------------------------------
int filecodnat(char z)
{
    switch(z)
    {
    case 'a':
        return 0;
        break;
    case 'b':
        return 1;
        break;
    case 'c':
        return 2;
        break;
    case 'd':
        return 3;
        break;
    case 'e':
        return 4;
        break;
    case 'f':
        return 5;
        break;
    case 'g':
        return 6;
        break;
    case 'h':
        return 7;
        break;
    default:
        return INVALID_FILE;
        break;
    }
}
//-----------------------------function that saves the game state to the disc--------------------------------------
int save_game_status()
{

    FILE* save_to_disc;
    save_to_disc=fopen("write_to_file.dat","wb");//open write_to_file.dat file to write game state
    if(save_to_disc==NULL)
    {
        printf("error!! \n");//return error massage if the file does not exist
        return 1;
    }
    else

        fwrite(setup,1,sizeof(setup),save_to_disc);//write array of structure to the disck

    fclose(save_to_disc);//close the file

    return 0;
}

// ------------------------------------moving chass peices in the board----------------------------------------------

int move(char filefrom,int rankfrom,char fileto,int rankto)
{

    if((rankfrom==INVALID_RANK)||((filecodnat(filefrom))==INVALID_FILE))// if original piece is not in the chass board cordinate
    {
        printf("the peice you want to move does not exist! \n");
        return WRONG_MOVE;

    }
    else if(((rankto)==INVALID_RANK)||((filecodnat(fileto))==INVALID_FILE))//the destination coordenate is not in the chass board
    {
        printf("moving to out of bourder! \n");

        return WRONG_MOVE;

    }

    //else if(setup[filecodnat(filefrom)][rankfrom]==" ") //tring to move empity pieces
    else if(setup[filecodnat(filefrom)+rankfrom*HORIZONTAL_LENGTH].piece_name==' ') //tring to move empity pieces
    {
        printf("there is no peices in original position\n");

        return WRONG_MOVE;
    }
    else if(setup[filecodnat(filefrom)+rankfrom*HORIZONTAL_LENGTH].rank==KILLED) //Trying to move killed peice
    {
        //In the case of this program there would not be a case that this will apear
        printf("This peice is moved out of the game\n");
        return WRONG_MOVE;
    }

    else
    {

        printf("right move! \n");

        if(setup[filecodnat(fileto)+rankto*HORIZONTAL_LENGTH].piece_name==' ')
        {
            setup[filecodnat(fileto)+rankto*HORIZONTAL_LENGTH]=setup[filecodnat(filefrom)+rankfrom*HORIZONTAL_LENGTH];
        }
        else
        {

            printf("%c%c is killed",setup[filecodnat(fileto)+rankto*HORIZONTAL_LENGTH].color,setup[filecodnat(fileto)+rankto*HORIZONTAL_LENGTH].piece_name);//eats the existing peices

            setup[filecodnat(fileto)+rankto*HORIZONTAL_LENGTH]=setup[filecodnat(filefrom)+rankfrom*HORIZONTAL_LENGTH];
        }
        //The peices is moved out of the game
        setup[filecodnat(filefrom)+rankfrom*HORIZONTAL_LENGTH].piece_name=' ';
        setup[filecodnat(filefrom)+rankfrom*HORIZONTAL_LENGTH].file='z';
        setup[filecodnat(filefrom)+rankfrom*HORIZONTAL_LENGTH].rank=100;
        setup[filecodnat(filefrom)+rankfrom*HORIZONTAL_LENGTH].color=' ';


        print_setup();//prints the game statuse to the computer screen

    }
    save_game_status();//saves Game State when there is a move

    return RIGHT_MOVE;
}

//---------------------------function to read game state from disk--------------------------------------------------
void read_game_state_from_disk()
{
    FILE *disk;
    int i;
    int count;
    chess_piece setup_disk[BORDSIZE];

    disk=fopen("write_to_file.dat","rb");//open a file to read a game state

    if(disk!=NULL)

        count=fread(setup_disk, sizeof(chess_piece),BORDSIZE, disk);//

    if(count==BORDSIZE)//if the structure read from the disk is the size of the BORDSIZE, then file reading is successful
    {

        for(i=0; i<BORDSIZE; i++)
        {
            setup[i]=setup_disk[i];//copy structure from disck to global struct variable one by one
        }

        fclose(disk);//close the file
        print_setup();//print the game status to the computer screen
    }
}
//------------------------------checks the color of the peice-------------------------------------------------------
int give_turnf(char x)
{

    if(x=='w')
        return BLACK;
    else if(x=='b')
        return WHITE;
    else
        return UNDEFINED;
}
//--------------------------------Main function-------------------------------------------------------------------
int main(void)
{

    int i=2;
    int a;
    char str[KEYVORD_INPUT];
    int give_turn;
    int check;
    char z;
    printf("                   Nigatu Adossa\n");
    printf("                   \n");
    printf("                   programming a chess Game in c\n\n ");



    int  originalrank,destinationrank;
    char originfile,destinationfile;

    printf("\n 'n' to start new game \n 'p' to resume previous game \n");
    scanf("%c",&z);

    if(z=='p')//reading game status from the disk
    {
        printf(" Here is previous game status");
        read_game_state_from_disk();
    }
    else
    {


        printf("\n new gmae\n  game rule:it will only checks weather the peice movment is valid\n           chess game rules  will be applied in the next phase of this project.\n  \n");
        printf(" key:  \n bp black pawn  \n bk black king  \n bn black knight  \n bb black bishop  \n br black rook  \n bq black queen  \n wp white pawn  \n wk white king  \n wn white knight  \n wb white bishop  \n wr white rook  \n wq white queen  \n" );
        draw_setup();//draw initial game status
    }

    printf("\n\n");

    while(a)
    {
        do
        {
            printf("\ngive coordinates in the form of a1c4, press any key if you want to save & stop!\n al- a-original file peice coordinate 1-original rank peice coordinate\n c4- c-destination file coordinate 4-destination rank coordinate\n");

            do
            {
                give_turn=(i%2);
                if(give_turn==BLACK)//to keep giving a chance to white and black peices
                    printf("\n now it is black's piece's turn!\n");
                else
                    printf("\n now it is white's piece's turn!\n");


                scanf("%s",&str);

                check=sscanf(str,"%c%d%c%d",&originfile,&originalrank,&destinationfile,&destinationrank);

                if(check==1 || (int)str[0]==STOP)//if the user wants to quit
                {
                    save_game_status();//save the game status to the disck
                    return STOP;
                }

            }
            while(give_turn==give_turnf(setup[filecodnat(originfile)+rankf_axis(originalrank)*HORIZONTAL_LENGTH].color)); //checks if the player is playing in his/her turn

            i++;//increment the value of i to give turns to other player
        }
        while( move(originfile,rankf_axis(originalrank),destinationfile,rankf_axis(destinationrank))!=RIGHT_MOVE);//give chance to player until it plays correctlly

    }

    return 0;
}
//-----------------------------------------------CopyRight Nigatu Adossa-----------------------------------------------------------

