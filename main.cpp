#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSafe(int row,int col,vector<string>board,int n)
{
    int duprow=row;
    int dupcol=col;

    //(row-1,col-1)
    while(row>=0 && col>=0){
        if(board[row][col]=='Q')
            return false;
        row--;
        col--;
    }

    //(col-1,row)
    col = dupcol;
    row = duprow;
 while(col>=0){
     if(board[row][col]=='Q')
         return false;
     col--;
 }

//(row+1,col-1)
 col = dupcol;
 row = duprow;
while(col>=0 && row<n){
  if(board[row][col]=='Q')
      return false;
  col--;
  row++;
}
    return true;
}

void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
{
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }

}
vector<vector<string>>solveNQueen(int n)
{
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}

int main()
{
    cout<<"welcome c++ world"<<endl;
    int numberOfQueen=0;
    int totalNumOfOutput=0;
    cout<<"Enter Number of Queen"<<endl;
    cin>>numberOfQueen;
    vector<vector<string>>output = solveNQueen(numberOfQueen);
    for(int i=0;i<numberOfQueen;i++){
        cout<<"output Number "<<i+1<<endl;
    for(auto v:output[i]){
        for(auto str:v){
            cout<<str<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    totalNumOfOutput=i;
    }


    cout<<endl<<endl;



    return 0;//a.exec();
}
