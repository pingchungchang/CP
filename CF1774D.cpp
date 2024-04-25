#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    deque<int> one[m+1];
    deque<int> zero[m+1];
    vector<vector<int>> arr(n+1,vector<int>(m+1,0));
    int cnt[n+1] = {};
    int total = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int k;
            cin>>k;
            arr[i][j] = k;
            total += k;
            cnt[i] += k;
            if(k)one[j].push_back(i);
            else zero[j].push_back(i);
        }
    }
    if(total%n != 0){
        cout<<"-1\n";
        return;
    }
    total /= n;
    vector<tuple<int,int,int>> ans;
    for(int i = 1;i<=n;i++){
        if(cnt[i] == total)continue;
        if(cnt[i]>total){
            for(int j = 1;j<=m;j++){
                if(arr[i][j] == 0)continue;
                while(cnt[i]>total && !zero[j].empty()){
                    auto tmp = zero[j].front();
                    zero[j].pop_front();
                    if(cnt[tmp]>=total||arr[tmp][j] != 0)continue;
                    cnt[tmp]++;
                    cnt[i]--;
                    arr[tmp][j] = 1;
                    arr[i][j] = 0;
                    ans.push_back(make_tuple(i,tmp,j));
                }
            }
        }
        if(cnt[i]<total){
            for(int j= 1;j<=m;j++){
                if(arr[i][j] == 1)continue;
                while(cnt[i]<total&&!one[j].empty()){
                    auto tmp = one[j].front();
                    one[j].pop_front();
                    if(cnt[tmp]<=total||arr[tmp][j] != 1)continue;
                    cnt[tmp]++;
                    cnt[i]--;
                    arr[tmp][j] = 0;
                    arr[i][j]  =1;
                    ans.push_back(make_tuple(i,tmp,j));
                }
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto &i:ans)cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<get<2>(i)<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}