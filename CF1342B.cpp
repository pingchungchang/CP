#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin>>s;
    int z = 0,o = 0;
    for(auto i:s){
        if(i == '0')z++;
        else o++;
    }
    if(z == 0||o == 0)cout<<string(max(o,z),(z == 0?'1':'0'))<<'\n';
    else{
        for(int i = 0;i<z+o;i++){
            cout<<"10";
        }
        cout<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
