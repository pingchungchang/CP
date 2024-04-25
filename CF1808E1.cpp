#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
vector<int> v;

void dfs(int a,int b,int& ans){
    if(v.size() == a){
        int total = 0;
        for(auto &j:v)total += j;
        for(auto &j:v){
            if((total-j)%b == j){
                ans++;
                break;
            }
        }
        return;
    }
    for(int i = 0;i<b;i++){
        v.push_back(i);
        dfs(a,b,ans);
        v.pop_back();
    }
    return;
}
int calc(int a,int b){
    int ans = 0;
    dfs(a,b,ans);
    return ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 1;i<=8;i++){
        for(int k = 1;k<=8;k++){
            cout<<setw(10)<<calc(i,k)<<' ';
        }
        cout<<endl;
    }
}