#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll arr[4];
	for(auto &i:arr)cin>>i;
	ll p1 = max_element(arr,arr+4)-arr;
	ll p2 = (p1 == 0?1:0);
	for(int i = 0;i<4;i++){
		if(i == p1)continue;
		if(arr[p2]<arr[i])p2 = i;
	}
	if(p1>1&&p2<=1)cout<<"YES\n";
	else if(p1<=1&&p2>1)cout<<"YEs\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
