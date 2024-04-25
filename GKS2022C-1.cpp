#include <bits/stdc++.h>
using namespace std;

int tt = 0;
set<char> nums,big,small,special;
void solve(){
    int n;
    tt++;
    string s;
    cin>>n>>s;
    bool nu = false,bi = false,sm = false,sp = false;
    for(char i:s){
        if(nums.find(i) != nums.end())nu = true;
        if(big.find(i) != big.end())bi = true;
        if(small.find(i)!= small.end())sm = true;
        if(special.find(i) != special.end())sp = true;
    }
    if(bi == false)s +='A';
    if(sm == false)s += 'a';
    if(nu == false)s += '1';
    if(sp == false)s += '@';
    while(s.size()<7)s +='a';
    cout<<"Case #"<<tt<<": "<<s<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(char i = '0';i<='9';i++)nums.insert(i);
    for(char i = 'A';i<='Z';i++)big.insert(i);
    for(char i = 'a';i<='z';i++)small.insert(i);
    special.insert('#');special.insert('@');special.insert('&');special.insert('*');
    int t;
    cin>>t;
    while(t--)solve();
}
