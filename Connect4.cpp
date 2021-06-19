#include <bits/stdc++.h>
#include <windows.h>
#define l 19
#define b 8
char Board[b][l];
using namespace std;
void setboard(){
    for(int i=0;i<b;i++){
        for(int j=0;j<l;j++){
            if(j%2==0)
                Board[i][j]='_';
            else
                Board[i][j]='|';
        }    
    }
}
void display_board(){
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
    cout<<"\n\n";
    for(int i=0;i<b;i++){
        for(int j=0;j<l;j++){
            if(Board[i][j]=='0')
            {
                SetConsoleTextAttribute(h,6 );//turn text yellow
                cout<<Board[i][j];
                SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
            }
            else if(Board[i][j]=='O')
            {
                SetConsoleTextAttribute(h,FOREGROUND_RED );//turn text red
                cout<<Board[i][j];
                SetConsoleTextAttribute(h,FOREGROUND_BLUE);//turn text BLUE
            }
            else
                cout<<Board[i][j];
        }
        cout<<endl;    
    }
}
void display_menu(){
    cout<<"+--------------------+"<<endl;
    cout<<"|   CONNECT_4 GAME   |"<<endl;
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
    cout<<"GAME OBJECTIVE : CONNECT 4 TO win\n"<<endl;
    cout<<"player 1 = ";
    SetConsoleTextAttribute(h,6 );//turn text yellow
    cout<<"0";
    SetConsoleTextAttribute(h,15);//white
    cout<<" coins"<<endl;
    cout<<"player 2 = ";
    SetConsoleTextAttribute(h,FOREGROUND_RED );//turn text red
    cout<<"O";
    SetConsoleTextAttribute(h,15);//turn text white
    cout<<" coins"<<endl;
    cout<<"___________________"<<endl<<endl;
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
int enter(int pno,int c){
    c=(c*2)-2;
    char coin;
    if(pno==1)
        coin='0';
    else 
        coin='O';
    for(int j=b-1;j>=0;j--){
        if(Board[j][c]=='_'){
            Board[j][c]=coin;
            //vertical win
            if( j<=(b-4) && Board[j][c]==coin && Board[j+1][c]==coin && Board[j+2][c]==coin &&Board[j+3][c]==coin){
                system("cls");
                display_board();
                cout<<"\n\n PLAYER "<<pno<<" WINS VERTICALLY"<<endl;
                return 1;
            }
            //horizontal win
            int l1=c,l2=c+2,l3=c+4,l4=c+6;
            for(int type=0;type<4;type++){
                if(l1>=0 && l4<=18 && Board[j][l1]==coin && Board[j][l2]==coin && Board[j][l3]==coin &&Board[j][l4]==coin){
                    system("cls");
                    display_board();
                    cout<<"\n\nPLAYER "<<pno<<" WINS HORIZONTALY"<<endl;
                    return 1;
                }
                l1-=2;
                l2-=2;
                l3-=2;
                l4-=2;
            }
            //"\"diagonal win
            int x1=c,x2=c+2,x3=c+4,x4=c+6;
            int y1=j,y2=j+1,y3=j+2,y4=j+3;
            for(int y=0;y<4;y++){
                if(( x1>=0 && y1>=0 )&& ( x4<=18 && y4>=7 ) && Board[y1][x1]==coin && Board[y2][x2]==coin && Board[y3][x3]==coin && Board[y4][x4]==coin){
                    system("cls");
                    display_board();
                    cout<<"\n\n PLAYER "<<pno<<" WINS fwdlash DIAGONALLY"<<endl;
                    return 1;
                }
                y1-=1;
                y2-=1;
                y3-=1;
                y4-=1;
                x1-=2;
                x2-=2;
                x3-=2;
                x4-=2;
            }
            //"/"diagonal win
            x1=c,x2=c+2,x3=c+4,x4=c+6;
            y1=j,y2=j-1,y3=j-2,y4=j-3;
            for(int y=0;y<4;y++){
                if(( x1>=0 && y1<b )&& ( x4<=18 && y4>=0 ) && Board[y1][x1]==coin && Board[y2][x2]==coin && Board[y3][x3]==coin && Board[y4][x4]==coin){
                    system("cls");
                    display_board();
                    cout<<"\n\n PLAYER "<<pno<<" WINS backslash DIAGONALLY"<<endl;
                    return 1;
                }
                y1+=1;
                y2+=1;
                y3+=1;
                y4+=1;
                x1-=2;
                x2-=2;
                x3-=2;
                x4-=2;
            }
            break;
        }
    }
    return 0;
}
void start(){
    setboard();
    int player=1;
    while(1){
        system("cls");
        display_board();
        int c;
        cout<<"\nPLAYER "<<player<<" enter cloumn";
        cin>>c;
        if(Board[0][(c*2)-2]!='_'){
            continue;
        }
        if(enter(player,c))
            return;
        if(player==1)
            player=2;
        else
            player=1;
    }


}

int main() {
    
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(h,FOREGROUND_BLUE );//turn text blue
    cout<<"CONNECT ";
    SetConsoleTextAttribute(h,FOREGROUND_RED );//turn text red 
    cout<<"4"<<endl;//turn text red 
    SetConsoleTextAttribute(h,15);//white
    
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
   
   return 0;
}
