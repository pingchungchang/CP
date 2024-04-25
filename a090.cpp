#include <bits/stdc++.h>
using namespace std;

int n;
int t = 0;
set<int>primes;
bool dp[101] = {};

void dfs(vector<int>now,set<int> all){
    if(now.size() == n){
        if(primes.find(now.back()+now[0]) == primes.end())return;
        for(auto i:now)cout<<i<<' ';
        cout<<'\n';
        return;
    }
    for(auto nxt:all){
        if(primes.find(now.back()+nxt) != primes.end()){
            set<int> cp = all;
            cp.erase(nxt);
            now.push_back(nxt);
            dfs(now,cp);
            now.pop_back();
        }
    }
    return;
}
void solve(){
    cout<<"Case "<<++t<<":\n";
    set<int> all;
    for(int i = 2;i<=n;i++)all.insert(i);
    dfs({1},all);
}
int main(){
    for(int i = 2;i<=100;i++){
        if(dp[i] == false){
            primes.insert(i);
            for(int j = i;j<=100;j+=i)dp[j] = true;
        }
    }
    while(cin>>n)solve();
}
