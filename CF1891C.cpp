#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 2e5+10;
int arr[mxn];

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll pref = 0,suf = 0,ans = 0;
	for(int i = 0;i<n;i++)suf += arr[i];
	for(int i = 0;i<n;i++){
		pref += arr[i];
		suf -= arr[i];
		if(pref>=suf){
			//cout<<i<<":"<<pref<<','<<suf<<':';
			ans += suf;
			pref -= arr[i];
			suf -= pref;
			arr[i] -= suf;
			ans += n-i-1;
			if(arr[i])ans += (arr[i]+1)/2+(arr[i] != 1);
			break;
		}
	}
	cout<<ans<<'\n';
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
