#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a,b;
    while(cin>>a>>b){
        cout<<s.substr(a-1,b-a+1)<<'\n';
    }
}
//failed
