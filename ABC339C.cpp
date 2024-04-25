#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
ll arr[mxn];
ll N;

inline bool check(ll k){
	for(int i = 1;i<=N;i++){
		k += arr[i];
		if(k<0)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	ll l = 0,r = 1e18;
	while(l != r){
		ll mid = (l+r)>>1;
		if(check(mid))r = mid;
		else l = mid+1;
	}
	for(int i = 1;i<=N;i++)l += arr[i];
	cout<<l;
}
