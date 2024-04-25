#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>
#define ld long double


const int mxn = 2e5+10;
bitset<mxn> go;
int deg[mxn];
ld dp[mxn];
int n,m;
vector<tiii> paths[mxn];

bool check(ld tar){
	for(int i = 1;i<=n;i++){
		dp[i] = -1e9;
	}
	memset(deg,0,sizeof(deg));
	for(int i = 1;i<=n;i++){
		if(!go[i])continue;
		for(auto &j:paths[i]){
			if(go[get<0>(j)])deg[get<0>(j)]++;
		}
	}
	queue<int> q;
	dp[1] = 0;
	q.push(1);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			deg[get<0>(nxt)]--;
			dp[get<0>(nxt)] = max(dp[get<0>(nxt)],dp[now]+get<1>(nxt)-tar*get<2>(nxt));
			if(!deg[get<0>(nxt)])q.push(get<0>(nxt));
		}
	}
	return dp[n]>=0;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		paths[a].push_back(make_tuple(b,c,d));
	}
	queue<int> q;
	go[1] = true;
	q.push(1);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(!go[get<0>(nxt)])go[get<0>(nxt)] = true,q.push(get<0>(nxt));
		}
	}
	ld l = 0,r = 1e5;
	for(int i = 0;i<60;i++){
		ld mid = (l+r)/2;
		if(check(mid))l = mid;
		else r = mid;
	}
	cout<<fixed<<setprecision(10)<<l;
}
