#include <bits/stdc++.h>
using namespace std;

string s[8];
int main(){
    for(auto &i:s)cin>>i;
    pair<int,int> pos;
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(s[i][j] == '*')pos = {7-i,j};
        }
    }
    cout<<(char)(pos.second+'a')<<pos.first+1;
}