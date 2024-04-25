#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &coins,vector<int> ans,int now,int nowcoin){
    if(nowcoin == ans.size()-1&&now%coins[nowcoin] == 0){
        printf("(");
        for(int i = 0;i<nowcoin;i++){
            printf("%d,",ans[i]);
        }
        printf("%d)\n",now/coins[nowcoin]);
        return;
    }
    if(nowcoin>=ans.size()) return;
    for(int i = 0;i<=now;i+=coins[nowcoin]){
        dfs(coins,ans,now-i,nowcoin+1);
        ans[nowcoin]++;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> coins(n,0);
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        coins[i] = k;
    }
    int now;
    cin>>now;
    vector<int> nowcoin(n,0);
    dfs(coins,nowcoin,now,0);
}