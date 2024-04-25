#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s[n];
    for(auto &i:s)cin>>i;
    for(int i = n-1;i>=0;i--)cout<<s[i]<<'\n';
    return 0;
}