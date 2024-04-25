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
	ll n,s;
	cin>>n>>s;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll total = 0,p = 0,ans = INT_MAX;
	for(int i = 0;i<n;i++){
		if(i>=p){
			p = i+1;
			total = arr[i];
		}
		while(p != n&&total<s)total += arr[p++];
		if(total>=s)ans = min(ans,p-i);
		total -= arr[i];
	}
	if(ans == INT_MAX)cout<<-1;
	else cout<<ans;
}

