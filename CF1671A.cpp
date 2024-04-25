#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    char c = s[0];
    int k = 1;
    s += '#';
    for(int i = 1;i<s.size();i++){
        if(s[i] != c){
            if(k == 1){
                cout<<"NO\n";
                return;
            }
            c = s[i];
            k = 1;
        }
        else k++;
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
