#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j= 0;j<m;j++){
            int k;
            cin>>k;
            if(!k)cout<<'.';
            else cout<<(char)('A'+k-1);
        }
        cout<<'\n';
    }
    return 0;
}