#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
int dist[mxn];
int arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dist,-1,sizeof(dist));
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	queue<int> q;
	for(int i = 1;i<=n;i++){
		bool flag = false;
		if(i-arr[i]>=1){
			paths[i-arr[i]].push_back(i);
			if(arr[i-arr[i]]%2 != arr[i]%2)flag = true;
		}
		if(i+arr[i]<=n){
			paths[i+arr[i]].push_back(i);
			if(dist[i] == -1&&arr[i+arr[i]]%2 != arr[i]%2)flag = true;
		}
		if(flag)dist[i] = 1,q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt] != -1)continue;
			dist[nxt] = dist[now]+1;
			q.push(nxt);
		}
	}
	for(int i = 1;i<=n;i++)cout<<dist[i]<<' ';
	return 0;
}
