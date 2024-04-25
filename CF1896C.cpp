#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 4e5+10;
int n,k;
pii arr[mxn];
int ans[mxn],brr[mxn];


void solve(){
	cin>>n>>k;
	for(int i = 0;i<n;i++)cin>>arr[i].fs,arr[i].sc = i;
	for(int i = 0;i<n;i++)cin>>brr[i];
	sort(arr,arr+n);sort(brr,brr+n);
	for(int i = n;i<n*2;i++)brr[i] = brr[i-n];
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(brr[i+k]<arr[i].fs)cnt++;
	}
	if(cnt != k){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(int i = 0;i<n;i++){
		ans[arr[i].sc] = brr[i+k];
	}
	for(int i = 0;i<n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
