#include <bits/stdc++.h>
using namespace std;

class Compare{
public:
    bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
        return a.first>b.first;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    int t = 0;
    while(cin>>n>>m){
        int arr[n][m];
        for(int i =0;i<n;i++){
            t++;
            for(int j =0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        priority_queue<pair<int,pair<int,int>,vector<pair<int,pair<int,int>>>,Compare> pq;
        pq.push(make_pair(0,make_pair(0,0)));
        int ans = -1;
        while(!pq.empty()){
            pair<int,pair<int,int>> now = pq.top();
            pq.pop();
            if(now.second.first==n-1&&now.second.second==m-1){
                ans = now.first;
                break;
            }
            arr[now.second.first][now.second.second] = -1;
            if(arr[now.second.first][now.second.second]!= -1){
                if(now.second.first<n-1&&arr[now.second.first+1][now.second.second] !=-1){
                    pq.push(make_pair(now.first+arr[now.second.first][now.second.second],make_pair(now.second.first+1,now.second.second)));
                    arr[now.second.first+1][now.second.second] = -1;
                }
                if(now.second.second<m-1&&arr[now.second.first][now.second.second+1]!= -1){
                    pq.push(make_pair(now.first+arr[now.second.first][now.second.second],make_pair(now.second.first,now.second.second+1)));
                    arr[now.second.first][now.second.second+1] = -1;
                }
            }
        }
        cout<<"Case #"<<t<<" :"<<ans<<'\n';
    }
}
