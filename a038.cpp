#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    string ans;
    for(int i =s.size()-1;i>=0;i--){
        ans += s[i];
    }
    cout<<stoi(ans);
}