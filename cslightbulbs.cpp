#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<string,ll> m;
string finish;
void rec(string s,ll t){
    if(m.count(s) == 0)m[s] = t;
    else return;
    if(m.count(finish)!=0)return;
    int n = s.size();

    if(s[n-1] == '0')s[n-1] = '1';
    else if(s[n-1] == '1')s[n-1] = '0';
    if(m.count(s) == 0)rec(s,t+1);
    if(s[n-1] == '0')s[n-1] = '1';
    else if(s[n-1] == '1')s[n-1] = '0';

    for(int i = n-1;i>=1;i--){
        if(s[i] == '1'){
            if(s[i-1] == '0')s[i-1] = '1';
            else if(s[i-1] == '1')s[i-1] = '0';
            rec(s,t+1);
            if(s[i-1] == '0')s[i-1] = '1';
            else if(s[i-1] == '1')s[i-1] = '0';
            return;
        }
    }
}
int main(){
    string s;
    cin>>s;
    if(s.size()==1&&s[0] == '0'){
        cout<<0;
        return 0;
    }
    else if(s.size()==1&&s[0] == '1'){
        cout<<1;
        return 0;
    }
    int n = s.size();
    while(finish.size()!= n)finish+= "0";
    rec(s,0);
    cout<<m[finish];
}
