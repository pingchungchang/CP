#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 9;
vector<tlll> edges;
vector<ll> dp[1ll<<mxn];
ll n,m,k;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		edges.push_back(make_tuple(a,b,c));
		edges.push_back(make_tuple(b,a,c));
	}
	bool roll = false;
	dp[1].push_back(0);
	for(int i = 1;i<(1<<n);i++){
		sort(dp[i].begin(),dp[i].end());
		dp[i].erase(unique(dp[i].begin(),dp[i].end()),dp[i].end());
		for(auto &eid:edges){
			ll ta = get<0>(eid),tb = get<1>(eid),w = get<2>(eid);
			if(!((1<<ta)&i)||((1<<tb)&i))continue;
			for(auto &j:dp[i]){
				dp[i|(1<<tb)].push_back((j+w)%k);
			}
		}
	}
	cout<<*min_element(dp[(1<<n)-1].begin(),dp[(1<<n)-1].end());
}
