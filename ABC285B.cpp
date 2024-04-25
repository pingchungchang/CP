#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int i = 1;i<n;i++){
        int p = 0;
        for(p = 0;p+i<n;p++){
            if(s[p] == s[i+p])break;
        }
        cout<<p<<'\n';
    }
    return 0;
}