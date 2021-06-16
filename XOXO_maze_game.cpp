#include<bits/stdc++.h>
#define l 18
#define b 9
using namespace std;
int li,lj;
char matrix[b][l]={
    {'+','-','+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+'},
    {' ',' ','|','X',' ',' ',' ','+','-','-','-','-','-','-','-','-','-','|'},
    {'+',' ','|','-','-','+',' ',' ','+',' ',' ',' ',' ','+','-',' ',' ','|'},
    {'|',' ','|',' ',' ','|',' ',' ',' ',' ','+','-',' ',' ','-','+',' ','|'},
    {'|',' ','|',' ',' ','+','-','-','+',' ','+','-','|',' ',' ','|',' ','|'},
    {'|',' ','|','-',' ',' ',' ','-','-',' ',' ',' ','+','-',' ','+',' ','|'},
    {'|',' ','+',' ',' ','+',' ','+','-','-','+',' ','|',' ',' ',' ',' ','|'},
    {'|',' ',' ',' ','-','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','-','-','|'},
    {'+','-','-','-','-','-','-','-','-','-','-','-','+','-','-','-','-','+'},
};
void display_board(){
    for(int i=0;i<b;i++){
        for(int j=0;j<l;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;    
    }
}
void display_menu(){
    cout<<"+--------------------+"<<endl;
    cout<<"|    XOXO   GAME     |"<<endl;
    cout<<"+--------------------+"<<endl;
    cout<<"|                    |"<<endl;
    cout<<"|  1 . START         |"<<endl;
    cout<<"|  2 . INSTRUCTION   |"<<endl;
    cout<<"|  3 . EXIT          |"<<endl;
    cout<<"|                    |"<<endl;
    cout<<"+--------------------+"<<endl;
}
void help(){
    cout<<"GAME OBJECTIVE : MOVE O TO X\n\n"<<endl;
    cout<<"     CONTROLS    "<<endl;
    cout<<" w -> move up"<<endl;
    cout<<" s -> move down"<<endl;
    cout<<" a -> move left"<<endl;
    cout<<" d -> move right"<<endl;
    cout<<endl<<endl;
}
int player_move(char x){
    matrix[li][lj]=' ';
    switch(x){
        case 'w':
            li=li-1;
            break;
        case 's':
            li=li+1;
            break;
        case 'a':
            lj=lj-1;
            break;
        case 'd':
            lj=lj+1;
            break;
        default:
            cout<<"ENTER MOVE : w,s,a,d "<<endl;
            break;
    }
    if(matrix[li][lj]!=' '){
        if(matrix[li][lj]=='X'){
            cout<<"||     XO WINNER     ||\n\n\n"<<endl;
            return -1;
        }
        cout<<"||     XD LOSER     ||\n\n\n"<<endl;
        return -1;
    }
    else{
        matrix[li][lj]='O';
        return 1;
    }
}
void start(){
    li=1,lj=0;
    matrix[li][lj]='O';
    display_board();
    while(1){
        cout<<"\nENTER MOVE : ";
        char input;
        cin>>input;
        system("cls");
        if(isdigit(input)){
            cout<<"ENTER MOVE : w,s,a,d "<<endl;
            continue;    
        }
        if(player_move(input)==-1)
            break;
        display_board();
    }
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




