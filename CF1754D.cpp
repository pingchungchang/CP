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
const ll mxn = 5e5+10;
ll cnt[mxn];
int main(){
	io
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	for(auto &i:arr)cnt[i]++;
	for(int i = 1;i<mxn;i++){
		cnt[i+1] += cnt[i]/(i+1);
		cnt[i]%=(i+1);
	}
	ll smallest = mxn;
	for(int i = mxn-1;i>=0;i--){
		if(cnt[i])smallest = i;
	}
	if(smallest>=x)cout<<"YES";
	else cout<<"NO";
}

