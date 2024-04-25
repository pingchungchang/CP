#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 3e5+10;
vector<int> paths[mxn];
int dist[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n1,n2,m;
	cin>>n1>>n2>>m;
	fill(dist,dist+mxn,mxn);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	queue<int> q;
	dist[1] = dist[n1+n2] = 0;
	q.push(1);q.push(n1+n2);
	while(!q.empty()){
		auto now = q.front();q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt]>n1+n2){
				dist[nxt] = dist[now]+1;
				q.push(nxt);
			}
		}
	}
	int m1 = 0,m2 = 0;
	for(int i = 1;i<=n1;i++)m1 = max(m1,dist[i]);
	for(int i = n1+1;i<=n1+n2;i++)m2 = max(m2,dist[i]);
	cout<<m1+m2+1;
	return 0;
}
