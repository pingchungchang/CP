#include <bits/stdc++.h>
using namespace std;


const int mxn= 5e5+10;
int trie[mxn][26];
int pp = 0;
int newnode(){
    pp++;
    memset(trie[pp],0,sizeof(trie[pp]));
    return pp;
}


string arr[mxn];
int ans[mxn];
int root;
void add(string &s){
    int now= root;
    for(auto &i:s){
        if(!trie[now][i-'a'])trie[now][i-'a'] = newnode();
        now = trie[now][i-'a'];
    }
    return;
}
int getans(string &s){
    int now = root;
    int cnt = 0;
    for(auto &i:s){
        if(!trie[now][i-'a'])return cnt;
        cnt++;
        now = trie[now][i-'a'];
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    root = newnode();
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++){
        ans[i] = max(ans[i],getans(arr[i]));
        add(arr[i]);
    }
    pp = 0;
    root = newnode();
    for(int i = n;i>=1;i--){
        ans[i] = max(ans[i],getans(arr[i]));
        add(arr[i]);
    }
    for(int i = 1;i<=n;i++)cout<<ans[i]<<'\n';
    return 0;
}