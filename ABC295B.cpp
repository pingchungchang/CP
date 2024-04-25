#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    string arr[r];
    for(int i = 0;i<r;i++)cin>>arr[i];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(arr[i][j] == '.'&&arr[i][j] == '#')continue;
            for(int k = 0;k<r;k++){
                for(int kk = 0;kk<c;kk++){
                    if(arr[k][kk] == '#'&&abs(k-i)+abs(j-kk)<=arr[i][j]-'0')arr[k][kk] = '.';
                }
            }
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++)cout<<(arr[i][j] == '#'?'#':'.');
        cout<<'\n';
    }
    return 0;
}