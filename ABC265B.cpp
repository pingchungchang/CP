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
int main(){
	io
	ll n,m,t;
	cin>>n>>m>>t;
	ll arr[n-1];
	for(int i = 0;i<n-1;i++)cin>>arr[i];
	ll add[n];
	memset(add,0,sizeof(add));
	for(int i = 0;i<m;i++){
		ll p,v;
		cin>>p>>v;
		add[p-1] = v;
	}
	ll now = 0;
	while(now != n-1){
		if(t<=0){
			cout<<"No";
			return 0;
		}
		t += add[now];
		t -= arr[now];
		now++;
	}
	if(t<=0)cout<<"No";
	else cout<<"Yes";
	return 0;
}

