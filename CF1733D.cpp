#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 5050;
ll n,x,y;

ll calc(ll a,ll b){
	if(a>b)swap(a,b);
	int mid = (a+b)>>1;
	if(a>2||b<n-1)return min(x*(b-a),y*2);
	else if(mid-a>1&&b-mid>1)return min(x*(b-a),y*2);
	else return x*(b-a);
}

ll dfs(vector<int> now){
	ll ans = 1e18;
	for(int i = 1;i<now.size();i++){
		auto tmp = now;
		tmp.erase(i);
		ans = min(ans,calc(now[0],now[i])+dfs(tmp));
	}
	return ans;
}

void solve(){
	cin>>n>>x>>y;
	vector<int> v;
	string a,b;
	cin>>a>>b;
	for(int i = 0;i<n;i++){
		if(a[i] != b[i])v.push_back(i);
	}
	if(v.size()&1){
		cout<<-1<<'\n';
		return;
	}
	if(v.size()<=6){
		cout<<dfs(v);
	}
	deque<int> dq;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
