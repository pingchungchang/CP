#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
const ll inf = 4e18;
ll n,A,B,C;
ll arr[mxn][mxn];
ll dist[2][mxn];
bitset<mxn> done[2];

inline ll calc(int e,int s,int tp){
	if(!tp)return arr[s][e]*A;
	else return arr[s][e]*B+C;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>A>>B>>C;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)cin>>arr[i][j];
	}
	tlll now = tlll(0,0,1);
	for(auto &i:dist)for(auto &j:i)j = inf;
	dist[0][1] = dist[1][1] = 0;
	for(int i = 0;i<n*n*2;i++){
		//cout<<get<1>(now)<<' '<<get<2>(now)<<'\n';
		done[get<1>(now)][get<2>(now)] = true;
		for(int j = 1;j<=n;j++){
			if(!get<1>(now))dist[0][j] = min(dist[0][j],dist[get<1>(now)][get<2>(now)]+calc(j,get<2>(now),0));
			dist[1][j] = min(dist[1][j],dist[get<1>(now)][get<2>(now)]+calc(j,get<2>(now),1));
		}
		now = tlll(inf,inf,inf);
		for(int j = 0;j<2;j++)for(int k = 1;k<=n;k++)if(!done[j][k])now = min(now,tlll(dist[j][k],j,k));
		if(get<0>(now) >=inf)break;
	}
	cout<<min(dist[0][n],dist[1][n]);
	return 0;
}
