#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 4e5+10;
int n;
int arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	map<ll,ll> mp;
	for(int i = 0;i<n;i++){
		mp[arr[i]-i]+=arr[i];
	}
	ll ans = 0;
	for(auto &i:mp)ans = max(ans,i.sc);
	cout<<ans;
}
