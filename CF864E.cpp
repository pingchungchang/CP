#include <bits/stdc++.h>
using namespace std;

#define mxn 2000
#define fs first
#define sc second
struct node{
    int t;
    int val;
    int num;
    int d;
    node(){}
    bool operator<(const node& a)const{
        return d<a.d;
    }
};
int main(){
    int n;
    cin>>n;
    vector<node>v(n,node());
    for(int i = 0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[i].val = c;
        v[i].t = a;
        v[i].d = b;
        v[i].num = i+1;
    }
    sort(v.begin(),v.end());
    vector<vector<pair<int,vector<int>>>> dp(2,vector<pair<int,vector<int>>>(mxn+10,make_pair(0,vector<int>(0))));
    int now = 1,pre = 0;
    for(int i = 0;i<n;i++){
        swap(now,pre);
        dp[now] = vector<pair<int,vector<int>>>(mxn+10,make_pair(0,vector<int>(0)));
        for(int j = 0;j<=mxn;j++){
            dp[now][j] = dp[pre][j];
            if(j != 0)dp[now][j] = max(dp[now][j],dp[now][j-1]);
            if(j>=v[i].t&&j<v[i].d){
                if(dp[now][j].fs<dp[pre][j-v[i].t].fs+v[i].val){
                    dp[now][j] = dp[pre][j-v[i].t];
                    dp[now][j].fs += v[i].val;
                    dp[now][j].sc.push_back(v[i].num);
                }
            }
        }
    }
    cout<<dp[now][mxn].fs<<'\n'<<dp[now][mxn].sc.size()<<'\n';
    for(auto i:dp[now][mxn].sc)cout<<i<<' ';
}
