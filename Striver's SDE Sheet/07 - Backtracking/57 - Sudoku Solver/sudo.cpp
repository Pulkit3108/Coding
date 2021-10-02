#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool valid(vector<vector<char>> &b,int r,int c,char ch){
    for(int i=0;i<9;i++){
        if(b[i][c]==ch){
            return false;
        }
        if(b[r][i]==ch){
            return false;
        }
        if(b[3*(r/3)+i/3][3*(c/3)+i%3]==ch){
            return false;
        } 
    }
    return true;
}
bool recur(vector<vector<char>> &b){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(b[i][j]=='.'){
                for(char k='1';k<='9';k++){
                    if(valid(b,i,j,k)){
                        b[i][j]=k;
                        if(recur(b)){
                            return true;
                        }
                        else{
                            b[i][j]='.';
                        }
                    } 
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board){
    recur(board);   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        vector<vector<char>> b;
        for(int i=0;i<9;i++){
            vector<char> c(9,'.');
            for(int j=0;j<9;j++){
                char ch;
                cin>>ch;
                c[j]=ch;
            }
            b.push_back(c);
        }
        solveSudoku(b);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
