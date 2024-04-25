#include <bits/stdc++.h>
using namespace std;

int arr[440][440] = {};
int n,m;
int sum(int r1,int c1,int r2,int c2){
    return arr[r2][c2]-arr[r2][c1-1]-arr[r1-1][c2]+arr[r1-1][c1-1];
}
void solve(){
    cin>>n>>m;
    for(int i = 0;i<n;i++)for(int j = 0;j<m;j++){
        char c;
        cin>>c;
        arr[i+1][j+1] = c-'0';
        arr[i+1][j+1]^=1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            arr[i][j] = arr[i][j] + arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    int ans = INT_MAX;
    for(int i = 1;i<=n;i++){
        for(int j = i+4;j<=n;j++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            for(int k = 2;k<=m;k++){
                int total = sum(i,k,j,k)+sum(i,1,i,k)+sum(j,1,j,k)-2*(sum(i,k,i,k)+sum(j,k,j,k))-sum(i+1,1,j-1,k-1);
                pq.push(make_pair(total,k));
            }
            for(int k = 1;k<=m;k++){
                while(!pq.empty()&&pq.top().second<k+3)pq.pop();
                if(pq.empty())break;
                cout<<i<<' '<<j<<' '<<k<<' '<<pq.top().second<<pq.top().first<<endl;
                ans = min(ans,pq.top().first-sum(i,1,i,k)-sum(j,1,j,k)+sum(i,k,j,k)-sum(i,k,i,k)-sum(j,k,j,k))+sum(i+1,1,j-1,k)+(j-i-1)*(k-pq.top().second-1);
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
