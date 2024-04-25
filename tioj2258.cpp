#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn = 1e6+10;
int n,k,p;
int arr[mxn];
int pref[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>p;
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	pref[0] = 0;
	for(int i = 1;i<n;i++)pref[i] = max(pref[i-1],arr[i]-arr[i-1]);
	int ans = max(pref[n-1],arr[n-1]-arr[0]);
	int suf = 0;
	for(int i = n-1;i>1;i--){
		int tans = max({pref[i-1],arr[i-1]-arr[0],arr[i]-arr[i-2],arr[n-1]-arr[i-1]});
		ans = min(ans,tans);
	}
	for(int i = n-1;i>=0;i--)pref[i] = max(pref[i+1],arr[i]-arr[i+1]);
	suf = 0;
	for(int i = 0;i+2<n;i++){
		int tans = max({pref[i+1],arr[i+2]-arr[i],arr[i+1]-arr[0],arr[n-1]-arr[i+1]});
		ans = min(ans,tans);
	}
	cout<<ans;
}
