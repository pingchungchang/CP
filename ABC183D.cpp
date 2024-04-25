#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mxn = 2e5+10;
ll arr[mxn];
int main(){
	io
	ll n,w;
	cin>>n>>w;
	for(int i = 0;i<n;i++){
		ll a,b,p;
		cin>>a>>b>>p;
		arr[a] += p;
		arr[b] -= p;
	}
	ll now = 0;
	for(auto &i:arr){
		now += i;
		if(now>w){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}

