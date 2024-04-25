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
	int p = 0;
	int ans = 0;
	ll total = 0;
	for(int i = 0;i<n;i++){
		if(i >= p){
			total = arr[i];
			p = i+1;
		}
		while(p < n&&total+arr[p]<=s){
			total += arr[p];
			p++;
		}
		if(total<=s)ans = max(ans,p-i);
		total -= arr[i];
	}
	cout<<ans;
}

