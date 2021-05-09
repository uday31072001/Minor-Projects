#include <bits/stdc++.h>
using namespace std;
void blankboard(char board[3][3]);
void display_board(char board[3][3]);
int update(char board[3][3],int pos,char a,int c);
int check(char b[3][3],int blank);
void rules();
void playpp();
void playvc(){
    int pos=0,_c=9;
    char board[3][3];
    blankboard(board);
    cout<<"\n||\tGAME Begins\t||\n"<<endl;
    for(int i=0;i<10;i++){
        int s=check(board,_c);
        switch(s){
            case 1:
                display_board(board);
                cout<<"\n||\tPlayer 1 WINS\t||\n"<<endl;
                return;
            case 2:
                display_board(board);        
                cout<<"||\tCOMPUTER WINS\t||"<<endl;
                return;
            case 3:
                display_board(board);
                cout<<"||\tDRAW\t||"<<endl;
                return;
        }
        display_board(board);
        if(i%2==0){
            //player 1
            cout<<"player 1 enter postion"<<endl;
            cin>>pos;
            if(!update(board,pos,'X',0))
                i--;
            else{   
                _c--;
            }
        }
        else{
            //comp
            cout<<"Computer Turn"<<endl;
            srand((unsigned) time(0));
            pos = (rand() % 9) + 1;
            while(!update(board,pos,'O',1))
                {
                    srand((unsigned) time(0));
                    pos = (rand() % 9) + 1;
                }   
                _c--;
        }
    }
}

int main()
{   
    int op=0;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout<<"WELCOME TO ~ CPP ~ TIC-TAC-TOE"<<endl;
    int x=1;
    while(x){
        cout<<"MAIN MENU\npress 1 -> play with computer \npress 2 -> play with friend\npress 3 -> rules\npress 4 -> Exit"<<endl;
        cout<<"\n"<<endl;
        cin>>op;
        switch (op){
            case 1:
                playvc();
                cout<<"Enter 1 for main menu 0 for exit"<<endl;
                cin>>x;
                break;
            case 2:
                playpp();
                cout<<"Enter 1 for main menu 0 for exit"<<endl;
                cin>>x;
                break;
            case 3:
                rules();
                cout<<"Enter 1 for main menu 0 for exit"<<endl;
                cin>>x;
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"ERROR : wrong option"<<endl;
                cout<<"Enter 1 for main menu 0 for exit"<<endl;
                cin>>x;
                
        }
    }
        
}
void playpp(){
    int pos=0,_c=9;
    char board[3][3];
    blankboard(board);
    cout<<"\n||\tGAME Begins\t||\n"<<endl;
    for(int i=0;i<10;i++){
        int s=check(board,_c);
        switch(s){
            case 1:
                display_board(board);
                cout<<"\n||\tPlayer 1 WINS\t||\n"<<endl;
                return;
            case 2:
                display_board(board);        
                cout<<"||\tPlayer 1 WINS\t||"<<endl;
                return;
            case 3:
                display_board(board);
                cout<<"||\tDRAW\t||"<<endl;
                return;
        }
        display_board(board);
        if(i%2==0){
            //player 1
            cout<<"player 1 enter postion"<<endl;
            cin>>pos;
            if(!update(board,pos,'X',0))
                i--;
            else{   
                _c--;
            }
        }
        else{
            //player 2
            cout<<"player 2 enter postion"<<endl;
            cin>>pos;
            if(!update(board,pos,'O',0))
                i--;
            else   
                _c--;
        }
    }
}

int check(char b[3][3],int blank){
    if
    ( 
        (b[0][0]=='X'&&b[0][1]=='X'&&b[0][2]=='X') || (b[1][0]=='X'&&b[1][1]=='X'&&b[1][2]=='X') || (b[2][0]=='X'&&b[2][1]=='X'&&b[2][2]=='X') || 
        (b[0][0]=='X'&&b[1][0]=='X'&&b[2][0]=='X') || (b[0][1]=='X'&&b[1][1]=='X'&&b[2][1]=='X') || (b[0][2]=='X'&&b[1][2]=='X'&&b[2][2]=='X') ||
        (b[0][0]=='X'&&b[1][1]=='X'&&b[2][2]=='X') || (b[0][2]=='X'&&b[1][1]=='X'&&b[2][0]=='X')
    )
        return 1;
    else if
    ( 
        (b[0][0]=='O'&&b[0][1]=='O'&&b[0][2]=='O') || (b[1][0]=='O'&&b[1][1]=='O'&&b[1][2]=='O') || (b[2][0]=='O'&&b[2][1]=='O'&&b[2][2]=='O') || 
        (b[0][0]=='O'&&b[1][0]=='O'&&b[2][0]=='O') || (b[0][1]=='O'&&b[1][1]=='O'&&b[2][1]=='O') || (b[0][2]=='O'&&b[1][2]=='O'&&b[2][2]=='O') ||
        (b[0][0]=='O'&&b[1][1]=='O'&&b[2][2]=='O') || (b[0][2]=='O'&&b[1][1]=='O'&&b[2][0]=='O')
    )
        return 2;
    else if(blank==0)
    {
        return 3;
        cout<<"ig draw hoga"<<endl;
    }
    else
        return 0;
}

void blankboard(char board[3][3]){
    int k=1;
    cout<<endl<<"BOARD LAYOUT"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++,k++){
            board[i][j]='_';
            if(j<2)
                cout<<k<<" | ";
            else
                cout<<k<<endl;
        }
        if(i<2)
            cout<<"----------"<<endl;
    }
}

void display_board(char board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j<2)
                cout<<board[i][j]<<" | ";
            else
                cout<<board[i][j]<<endl;
        }
        if(i<2)
            cout<<"----------"<<endl;
    }
}


int update(char board[3][3],int pos,char a,int c){
    switch(pos){
        case 1:
            if(board[0][0]=='_')
            board[0][0]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        case 2:
            if(board[0][1]=='_')
            board[0][1]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        case 3:
            if(board[0][2]=='_')
            board[0][2]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        case 4:
            if(board[1][0]=='_')
            board[1][0]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        case 5:
            if(board[1][1]=='_')
            board[1][1]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        case 6:
            if(board[1][2]=='_')
            board[1][2]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        case 7:
            if(board[2][0]=='_')
            board[2][0]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        case 8:
            if(board[2][1]=='_')
            board[2][1]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        case 9:
            if(board[2][2]=='_')
            board[2][2]=a;
            else if(c)
                return 0;
            else
            {
                cout<<"position occupied"<<endl;
                return 0;
            }
            break;
        default:
            cout<<"ERROR: pls choose a postion [1,9] "<<endl;
            return 0;
            break;
        return 1;                
    }
}
void rules(){
    cout<<"RULES LIST\n1. player 1 uses \"X\" and player 2 uses \"O\" \n2.player 1 plays first\n"<<endl; 
}
