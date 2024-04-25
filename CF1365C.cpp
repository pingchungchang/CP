#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n+1],brr[n+1];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		arr[k] = i;
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		brr[k] = i;
	}
	map<int,int> mp;
	for(int i = 1;i<=n;i++){
		int d = brr[i]-arr[i];
		if(d<0)d += n;
		if(d>=n)d -= n;
		mp[d]++;
	}
	int ans = 0;
	for(auto &i:mp)ans = max(ans,i.sc);cout<<ans;
}
