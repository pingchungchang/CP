#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans = 0;
    for(auto &i:s)if(i == 'w')ans+=2;else ans ++;
    cout<<ans;
}