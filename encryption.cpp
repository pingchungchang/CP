#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string sums;
    while(cin>>s){
        sums+=s;
    }
    int n = sqrt(s.size());
    int k = n;
    if(n*n!=s.size())k++;
    for(int i = 0;i<=n;i++){
        for(int j = i;j<s.size();j+=k){
            cout<<s[j];
        }
        cout<<' ';
    }
}