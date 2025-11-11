#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(vector<vector<char>> board,int row,int col,int n){
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q') return false;
        if(board[i][col]=='Q') return false;
    }

    //left diagonal
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
    }

    //right diagonal
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board,int n,int row,int firstRow){
    if(row==n){
        return true;
    }
    if(row==firstRow){
        return solve(board,n,row+1,firstRow);
    }
    for(int j=0;j<n;j++){ //this is for col
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            if(solve(board,n,row+1,firstRow)){
                return true;
            };
            board[row][j] = '.';
        }
    }

    return false;
}

int main(){
    int n;
    cout<<"Enter size of board (n x n): ";
    cin>>n;

    int firstRow, firstCol;
    cout << "Enter position of first queen (row and column, 0-based index): ";
    cin >> firstRow >> firstCol;

    vector<vector<char>> board(n,vector<char>(n,'.'));
    board[firstRow][firstCol] = 'Q';

    if(solve(board,n,0,firstRow)){
        cout<<"N queens solution:"<<endl;
        printBoard(board,n);
    }else{
        cout<<"\nNo valid position exist for given first queen position"<<endl;
    }

}

