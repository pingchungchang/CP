#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(auto &i:s)i = ('1'-i)+'0';
    cout<<s;
}