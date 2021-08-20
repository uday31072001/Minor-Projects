#include<bits/stdc++.h>
#include <windows.h>
#define l 10 //1 space border all sides;
using namespace std;
char board[l][l];
int coins;
int li,lj;
void display_board(){
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
    cout<<"\n\n";
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(i==li && j== lj){
                SetConsoleTextAttribute(h,15);
                cout<<"#";
                SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
            }
            else if(board[i][j]=='0')
            {
                SetConsoleTextAttribute(h,6);//turn text yellow
                cout<<board[i][j];
                SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
            }
            else if(board[i][j]=='O')
            {
                SetConsoleTextAttribute(h,FOREGROUND_GREEN);//turn text green
                cout<<board[i][j];
                SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
            }
            else if(board[i][j]=='+')
            {
                SetConsoleTextAttribute(h,FOREGROUND_RED );//turn text red
                cout<<board[i][j];
                SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
            }
            else
                cout<<board[i][j];
            cout<<" ";
        }
        cout<<endl;    
    }
    SetConsoleTextAttribute(h,15);//white
}
void display_menu(){
    cout<<"+--------------------+"<<endl;
    cout<<"|   OTHELLO - GAME   |"<<endl;
    cout<<"+--------------------+"<<endl;
    cout<<"|                    |"<<endl;
    cout<<"|  1 . START         |"<<endl;
    cout<<"|  2 . INSTRUCTION   |"<<endl;
    cout<<"|  3 . EXIT          |"<<endl;
    cout<<"|                    |"<<endl;
    cout<<"+--------------------+"<<endl;
}
void help(){
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(h,15);//white
    cout<<"BOTH player coins\n"<<endl;
    cout<<"player 1 = ";
    SetConsoleTextAttribute(h,6 );//turn text yellow
    cout<<"0";
    SetConsoleTextAttribute(h,15);//white
    cout<<" coins"<<endl;
    cout<<"player 2 = ";
    SetConsoleTextAttribute(h,FOREGROUND_GREEN );//turn text red
    cout<<"O";
    SetConsoleTextAttribute(h,15);//turn text white
    cout<<" coins"<<endl;
    cout<<"___________________"<<endl<<endl;
    cout<<" : player moves : \n__________________\n\nw : move up\ns : move down\na : move left\nd : move right\n";
    cout<<"x : put coin\nf :decide winner\n"<<endl;
    
    int op;
    cout<<"enter 1> MAIN MENU : ";
    cin>>op;
    if(op==1){
        system("cls");
        return;
    }
    else
        exit(0);
}
bool checkLegal(char coin){
    //lXl(10 x 10) === x X y(8x8) board mapping
    //if you put the coin at [li][lj] is it legal or not;
    //if it will result in zero flips illegal or else legal
    if(board[li][lj]!= '-')
        return false;
    int countflips=0;
    int flips;
    //direction ->
    int y=lj+1;
    flips=0;
    while(y<l-1){
        if(board[li][y]=='-' ||board[li][y]==coin )
            break;
        flips++;
        y++;
    }
    if(board[li][y]==coin && flips>0)
        return true;
    //end
    //direction <-
    y=lj-1;
    flips=0;
    while(y>0){
        if(board[li][y]=='-' ||board[li][y]==coin )
            break;
        flips++;
        y--;
    }
    if(board[li][y]==coin && flips>0)
        return true;
    //end
    //direction down
    int x=li+1;
    flips=0;
    while(x<l-1){
        if(board[x][lj]=='-' ||board[x][lj]==coin )
            break;
        flips++;
        x++;
    }
    if(board[x][lj]==coin && flips>0)
        return true;
    //end
    //direction up
    x=li-1;
    flips=0;
    while(x>0){
        if(board[x][lj]=='-' ||board[x][lj]==coin )
            break;
        flips++;
        x--;
    }
    if(board[x][lj]==coin && flips>0)
        return true;
    //end
    //direction /up
    x=li-1;
    y=lj+1;
    flips=0;
    while(x>0 && y<l-1){
        if(board[x][y]=='-' ||board[x][y]==coin )
            break;
        flips++;
        x--;
        y++;
    }
    if(board[x][y]==coin && flips>0)
        return true;
    //end
    //direction /down
    x=li+1;
    y=lj-1;
    flips=0;
    while(x<l-1 && y>0){
        if(board[x][y]=='-' ||board[x][y]==coin )
            break;
        flips++;
        x++;
        y--;
    }
    if(board[x][y]==coin && flips>0)
        return true;
    //end
    //direction \up
    x=li-1;
    y=lj-1;
    flips=0;
    while(x>0 && y>0){
        if(board[x][y]=='-' ||board[x][y]==coin )
            break;
        flips++;
        x--;
        y--;
    }
    if(board[x][y]==coin && flips>0)
        return true;
    //end
    //direction \down
    x=li+1;
    y=lj+1;
    flips=0;
    while(x<l-1 && y<l-1){
        if(board[x][y]=='-' ||board[x][y]==coin )
            break;
        flips++;
        x++;
        y++;
    }
    if(board[x][y]==coin && flips>0)
        return true;
    //end
    return false;
}
void place(char coin){
    //lXl(10 x 10) === x X y(8x8) board mapping
    //if you put the coin at [li][lj] is it legal or not;
    //if it will result in zero flips illegal or else legal
    int flips,ptr;
    //direction ->
    int y=lj+1;
    flips=0;
    while(y<l-1){
        if(board[li][y]=='-' ||board[li][y]==coin )
            break;
        flips++;
        y++;
    }
    if(board[li][y]==coin && flips>0)
        for(ptr=lj;ptr<=y;ptr++)
            board[li][ptr]=coin;
    //end
    //direction <-
    y=lj-1;
    flips=0;
    while(y>0){
        if(board[li][y]=='-' ||board[li][y]==coin )
            break;
        flips++;
        y--;
    }
    if(board[li][y]==coin && flips>0)
        for(ptr=lj;ptr>=y;ptr--)
            board[li][ptr]=coin;
    //end
    //direction down
    int x=li+1;
    flips=0;
    while(x<l-1){
        if(board[x][lj]=='-' ||board[x][lj]==coin )
            break;
        flips++;
        x++;
    }
    if(board[x][lj]==coin && flips>0)
          for(ptr=li;ptr<=x;ptr++)
            board[ptr][lj]=coin;
    //end
    //direction up
    x=li-1;
    flips=0;
    while(x>0){
        if(board[x][lj]=='-' ||board[x][lj]==coin )
            break;
        flips++;
        x--;
    }
    if(board[x][lj]==coin && flips>0)
        for(ptr=li;ptr>=x;ptr--)
            board[ptr][lj]=coin;
    //end
    int ptrx,ptry;
    //direction /up
    x=li-1;
    y=lj+1;
    flips=0;
    while(x>0 && y<l-1){
        if(board[x][y]=='-' ||board[x][y]==coin )
            break;
        flips++;
        x--;
        y++;
    }
    if(board[x][y]==coin && flips>0)
        for(ptrx=li,ptry=lj;ptrx>=x && ptry<=y;ptrx--,ptry++)
            board[ptrx][ptry]=coin;
    //end
    //direction /down
    x=li+1;
    y=lj-1;
    flips=0;
    while(x<l-1 && y>0){
        if(board[x][y]=='-' ||board[x][y]==coin )
            break;
        flips++;
        x++;
        y--;
    }
    if(board[x][y]==coin && flips>0)
        for(ptrx=li,ptry=lj;ptrx<=x && ptry>=y;ptrx++,ptry--)
            board[ptrx][ptry]=coin;
    //end
    //direction \up
    x=li-1;
    y=lj-1;
    flips=0;
    while(x>0 && y>0){
        if(board[x][y]=='-' ||board[x][y]==coin )
            break;
        flips++;
        x--;
        y--;
    }
    if(board[x][y]==coin && flips>0)
        for(ptrx=li,ptry=lj;ptrx>=x && ptry>=y;ptrx--,ptry--)
            board[ptrx][ptry]=coin;
    //end
    //direction \down
    x=li+1;
    y=lj+1;
    flips=0;
    while(x<l-1 && y<l-1){
        if(board[x][y]=='-' ||board[x][y]==coin )
            break;
        flips++;
        x++;
        y++;
    }
    if(board[x][y]==coin && flips>0)
        for(ptrx=li,ptry=lj;ptrx<=x && ptry<=y;ptrx++,ptry++)
            board[ptrx][ptry]=coin;
    //end
}
int player_move(char key,int turn){
    char coin='0';
    if(turn)
        coin='O';
    switch(key){
        case 'w':
            if(board[li-1][lj] == '-' || board[li-1][lj] == '+')
                li=li-1;
            break;
        case 's':
            if(board[li+1][lj] == '-' || board[li+1][lj] == '+')
                li=li+1;
            break;
        case 'a':
            if(board[li][lj-1] == '-' || board[li][lj-1] == '+')
                lj=lj-1;
            break;
        case 'd':
            if(board[li][lj+1] == '-' || board[li][lj+1] == '+')
                lj=lj+1;
            break;
        case 'x':
            if(checkLegal(coin)){
                place(coin);
                return 1;
            }
            else
                return -1;
            break;
        default:
            cout<<"ENTER MOVE : w,s,a,d,x"<<endl;
            break;
    }
    return 0;
}
void set_board(){
    coins=64;
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(i==0 || i==l-1)
                board[i][j]='+';
            else if(j==0 || j==l-1)
                    board[i][j]='+';   
            else 
                board[i][j]='-';
        }    
    }
    board[l/2-1][l/2-1]='0';
    board[l/2-1][l/2]='O';
    board[l/2][l/2-1]='O';
    board[l/2][l/2]='0';
    coins-=4;
}
string winner(){
    int pl1=0,pl2=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(board[i][j]=='0')
                pl1++;
            else if(board[i][j]=='O')
                pl2++;
        }    
    }
    if(pl1>pl2)
        return "player 1 (coins 0) WINS";
    else if(pl2>pl1)
        return "player 2 (coins O) WINS";
    else
        return "DRAW";
}
void start(){
    set_board();
    display_board();
    int turn=0;
    li=0,lj=0;
    while(1){
        cout<<"  player "<<(turn+1);
        if(turn) 
            cout<<" ( coin O ) ";
        else
            cout<<" ( coin 0 ) ";
        cout<<" ENTER MOVE : ";
        char input;
        cin>>input;
        system("cls");
        if(isdigit(input)){
            cout<<"ENTER MOVE : w,s,a,d,x,f"<<endl;
            continue;    
        }
        if(input == 'f'){
            cout<<"Counting coins ....\n";
            break;
        }
        //status 0 turn not over, 1 turn over with legal move , -1 illegal move
        int status=player_move(input,turn); 
        if( status == 0 ){
            //do nothing
        }
        else if( status == 1 ){
            turn=!turn;
            li=0,lj=0;
            coins--;
        }
        else if( status == -1 ){
            cout<<"illegal move\n";
            turn=!turn;
            li=0,lj=0;
        }
        if(coins==0)
            break;
        display_board();
    }
    display_board();
    cout<<"\n GAME OVER \n"<<endl;
    cout<<" RESULT : "<<winner()<<endl;
}
int main(){
    while(1){
        display_menu();
        int op;
        cin>>op;
        switch(op){
            case 1:
                system("cls");
                start();
                break;
            case 2:
                system("cls");
                help();
                break;
            case 3:
                exit(0);
        }
    }
}