#include<bits/stdc++.h>
using namespace std;

char player='X';
char computer='O';

int boardSize=3;

void drawBoard(vector<vector<char>>&board){
    board={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
}

void displayBoard(vector<vector<char>>&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<"\t"<<board[i][j]<<" ";
        }cout<<endl;
    }
}

bool matchDraw(vector<vector<char>>&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j]!=player && board[i][j]!=computer){
                return false;
            }
        }
    }
    return true;
}

bool allCheck(vector<vector<char>>&board,char findChar){
    //row check
    int countt=0;
    for(int i=0;i<boardSize;i++){
        countt=0;
        for(int j=0;j<boardSize;j++){
            if(board[i][j]==findChar) countt++;
        }if(countt==3) return true;
    }

    //column check
    for(int j=0;j<boardSize;j++){
        countt=0;
        for(int i=0;i<boardSize;i++){
            if(board[i][j]==findChar) countt++;
        }if(countt==3) return true;
    }

    //diagonal check
    countt=0;
    for(int i=0;i<board.size();i++){
        if(board[i][i]==findChar) countt++;
    }if(countt==3) return true;

    countt=0;
    for(int i=0,j=2;i<board.size();i++,j--){
        if(board[i][j]==findChar) countt++;
    }if(countt==3) return true;

    return false;
}

int minmax(vector<vector<char>>board,bool playerTurnOn){
    int score;
    bool checkPlayer=allCheck(board,player);
    bool checkComputer=allCheck(board,computer);
    bool draw=matchDraw(board);
    if(checkPlayer) return score=1;
    else if(checkComputer) return score=-1;
    else if(draw) return score=0;
    else{
        if(playerTurnOn){
            int bestScore=-1000;
            for(int i=0;i<boardSize;i++){
                for(int j=0;j<boardSize;j++){
                    if(board[i][j]!=player && board[i][j]!=computer){
                        char slotChar=board[i][j];
                        board[i][j]=player;
                        int tempScore=minmax(board,!playerTurnOn);
                        board[i][j]=slotChar;
                        if(tempScore>bestScore){
                            bestScore=tempScore;
                        }
                    }
                }
            }
            return bestScore;
        }else{
            int bestScore=1000;
            for(int i=0;i<boardSize;i++){
                for(int j=0;j<boardSize;j++){
                    if(board[i][j]!=player && board[i][j]!=computer){
                        char slotChar=board[i][j];
                        board[i][j]=computer;
                        int tempScore=minmax(board,!playerTurnOn);
                        board[i][j]=slotChar;
                        if(tempScore<bestScore){
                            bestScore=tempScore;
                        }
                    }
                }
            }
            return bestScore;
        }
    }
}

void computerTurn(vector<vector<char>>&board){
    int score=INT_MAX;
    int corX,corY;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]!=player && board[i][j]!=computer){
                char slotChar=board[i][j];
                board[i][j]=computer;
                bool playerTurnOn=true;
                int tempScore=minmax(board,playerTurnOn);
                board[i][j]=slotChar;
                if(tempScore<score){
                    score=tempScore;
                    corX=i,corY=j;
                }
            }
        }
    }
    board[corX][corY]=computer;
}

void studentInfo(){
    cout<<endl;
    cout<<"Name : Md Shafikul Rahman "<<endl;
    cout<<"Reg : 2019831066"<<endl<<endl;
}

int main(){
    studentInfo();
    vector<vector<char>>board;
    drawBoard(board);
    displayBoard(board);
    bool playerTurn=true;
    while(1){
        cout<<"Your Turn :: ";
        int x;cin>>x;
        board[(x-1)/3][(x-1)%3]=player;
        cout<<endl;
        displayBoard(board);
        bool checkPlayer=allCheck(board,player);
        bool checkComputer=allCheck(board,computer);
        if(checkPlayer){
            cout<<"YOU WIN !! "<<endl;
            break;
        }
        else if(checkComputer){
            cout<<"YOU LOSS :("<<endl;
            break;
        }
        else if(matchDraw(board)){
            cout<<"Match Draw !! "<<endl;
            break;
        }
        else{
            cout<<"Computer Turn :: "<<endl;
            computerTurn(board);
            cout<<endl;
            displayBoard(board);
            checkPlayer=allCheck(board,player);
            checkComputer=allCheck(board,computer);
            if(checkPlayer){
                cout<<"YOU WIN !! "<<endl;
                break;
            }
            else if(checkComputer){
                cout<<"YOU LOSS :("<<endl;
                break;
            }
            else if(matchDraw(board)){
                cout<<"Match Draw !! "<<endl;
                break;
            }
        }
    }
    return 0;
}