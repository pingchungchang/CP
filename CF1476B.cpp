#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll l = 0,r = 1e12;
	while(l != r){
		ll mid = (l+r)>>1;
		bool flag = true;
		ll sum = arr[0]+mid;
		for(int i = 1;i<n;i++){
			if(arr[i]*100>sum*k)flag = false;
			sum += arr[i];
		}
		if(!flag)l = mid+1;
		else r = mid;
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
