#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(auto &i:s){
        if(m == 0)i = 'x';
        else if(i == 'o')m--;
    }
    cout<<s;
}