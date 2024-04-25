#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	vector<int> v;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<i){
			v.push_back(i);
			ans += lower_bound(v.begin(),v.end(),arr[i])-v.begin();
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

