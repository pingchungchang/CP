#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string s;
    int ans = 0;
    for(int i = 0;i<n;i++){
        cin>>s;
        for(auto &j:s)if(j == '#')ans++;
    }
    cout<<ans;
}