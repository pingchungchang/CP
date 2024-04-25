#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const ll inf = 1e12;
const ll mxn = 2e5+10;
ll arr[mxn];
ll n;
vector<ll> v[2];

inline ll f(ll a,ll b,ll c){
	return a*b+c*(a+b);
}

inline ll calc(ll tar){
	for(auto &i:v)i.clear();
	for(int i = 1;i<=n;i++){
		v[arr[i]>=-tar].push_back(arr[i]);//v:increasing
	}
	ll re = 0;
	if(!v[0].empty()&&!v[1].empty()){
		for(auto &i:v[0])re += f(i,v[1].back(),tar);
		for(auto &i:v[1])re += f(i,v[0][0],tar);
		re -= f(v[0][0],v[1].back(),tar);
	}
	else if(v[0].empty()){
		for(int i = 1;i<v[1].size();i++)re += f(v[1][0],v[1][i],tar);
	}
	else if(v[1].empty()){
		for(int i = 0;i+1<v[0].size();i++)re += f(v[0][i],v[0].back(),tar);
	}
	return re;
}

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	ll l = -2e6,r = 2e6;
	while(r-l>1){
		ll mid = (l+r)>>1;
		if(calc(mid)>calc(mid+1))r = mid;
		else l = mid;
	}
	ll big = max(calc(l),calc(r));
	if(big<calc(mxn*30)||big<calc(-mxn*30))cout<<"INF\n";
	else cout<<big<<'\n';
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
