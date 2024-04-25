#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &dp,vector<int> &v,int now,deque<int> used){
    if(now>=v.size()){
        return used.size();
    }
    else if(used.empty()){
        deque<int> u1;
        u1.push_back(now);
        return max(dfs(dp,v,now+1,u1),dfs(dp,v,now+1,used));
    }
    else{
        if(v[used.front()]>=v[now]){
            if(dp[used.front()][used.back()] == -1){
                deque<int> u;
                u.push_front(used.front());
                u.push_back(used.back());
                dp[used.front()][used.back()] = dfs(dp,v,now+1,u)+used.size()-2;
            }
            if(dp[now][used.back()] == -1){
                deque<int> u;
                u.push_front(now);
                u.push_back(used.back());
                dp[now][used.back()] = dfs(dp,v,now+1,u)+used.size()-1;
            }
            return max(dp[now][used.back()],dp[used.front()][used.back()]);
        }
        else if(v[used.back()]<=v[now]){
            if(dp[used.front()][used.back()] == -1){
                deque<int> u;
                u.push_front(used.front());
                u.push_back(used.back());
                dp[used.front()][used.back()] = dfs(dp,v,now+1,u)+used.size()-2;
                // cout<<dp[used.front()][used.back()]<<endl;
            }
            if(dp[used.front()][now] == -1){
                deque<int> u;
                u.push_front(used.front());
                u.push_back(now);
                dp[used.front()][now] = dfs(dp,v,now+1,u)+used.size()-1;
            }
            return max(dp[used.front()][now],dp[used.front()][used.back()]);
        }
        else{
            return dfs(dp,v,now+1,used);
        }
    }
}
int main(){
    int n;
    scanf("%d\n",&n);
    for(int x=0;x<n;x++){
        int m;
        scanf("%d\n",&m);
        vector<int> v(m,0);
        for(int i = 0;i<m;i++){
            int k;
            scanf("%d",&k);
           // cout<<k<<endl;
            v[i] = k;
            if(x!=n-1&&i!=m-1) scanf("\n");
        }
        vector<vector<int>> dp(m,vector<int>(m,-1));
        deque<int> used;
        int ans = dfs(dp,v,0,used);
        printf("%d\n",ans);
    }
}