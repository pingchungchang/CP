#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 3e5+10;
ll n;
ll arr[mxn];
deque<ll> dq;
ll lbig[mxn],lsm[mxn],rsm[mxn];

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	dq.push_back(0);
	for(int i = 1;i<=n;i++){
		while(dq.back()>0&&arr[dq.back()]<=arr[i])dq.pop_back();
		lbig[i] = dq.back();
		dq.push_back(i);
	}
	dq.clear();
	dq.push_back(0);
	for(int i = 1;i<=n;i++){
		while(dq.back()>0&&arr[dq.back()]>=arr[i])dq.pop_back();
		lsm[i] = dq.back();
		dq.push_back(i);
	}
	dq.clear();
	dq.push_back(n+1);
	for(int i = n;i>=1;i--){
		while(dq.back()<=n&&arr[dq.back()]>=arr[i])dq.pop_back();
		rsm[i] = dq.back();
		dq.push_back(i);
	}
	/*
	for(int i = 1;i<=n;i++)cout<<lsm[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<lbig[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<rsm[i]<<' ';cout<<endl;
   */
	ll ans = n*(n+1)*n/2-n*(n+1)*(n*2+1)/6;
	for(int i = 1;i<=n;i++){
		ll a = lsm[i];
		ll b = lbig[a],c = i,d = rsm[i];
		assert(b<=a);
		cout<<i<<":"<<(a-b)*(d-c)<<endl;
		ans -= max(0ll,(a-b)*(d-c));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
