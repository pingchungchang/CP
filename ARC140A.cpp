#include <bits/stdc++.h>
using namespace std;

string s;
int n,k;

bool f(int now){
    int all[now][30] = {};
    for(int i = 0;i<n;i++){
        all[i%now][s[i]-'a']++;
    }
    int times = n/now;
    int total = 0;
    for(int i = 0;i<now;i++){
        int big = 0;
        for(int j = 0;j<30;j++)big = max(big,all[i][j]);
        total += times-big;
    }
    if(total<=k)return true;
    else return false;
}
int main(){
    cin>>n>>k>>s;
    int ans = n;
    for(int i = 1;i<=n;i++){
        if(n%i == 0&&f(i)){
            cout<<i<<'\n';
            return 0;
        }
    }
}
