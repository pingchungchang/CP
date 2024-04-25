#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i = 0;i<s.size()/2;i++){
        swap(s[i*2],s[i*2+1]);
    }
    cout<<s;
}