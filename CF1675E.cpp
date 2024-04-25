#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> pos(27);

int modify(int now,int m){
    if(m<=0)return 0;
    //cout<<m<<endl;
    int tmp = pos[now];
    while(tmp>0&&m>0){
        m--;
        if(pos[tmp] == 0){
            pos[now] = 0;
            break;
        }
        tmp = pos[pos[tmp]-1];
        pos[now] = max(0,tmp);
    }
    for(int i = now-1;i>0;i--){
        pos[i] = min(pos[i+1],pos[i]);
    }
    return m;
}
void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i = 0;i<27;i++)pos[i] = i;
    for(int i = 0;i<n;i++){
        m = modify(s[i]-'a',m);
        //cout<<m<<endl;
    }
    //for(int i = 0;i<27;i++)cout<<(char)('a'+i)<<' '<<(char)(pos[i]+'a')<<endl;
    for(int i = 0;i<n;i++){
        s[i] = pos[s[i]-'a']+'a';
    }
    cout<<s<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
