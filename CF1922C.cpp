#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
int arr[mxn];
int n;
int lp[mxn],rp[mxn];

void solve(){
	for(int i =0;i<=n;i++)lp[i] = rp[i] = arr[i] = 0;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	rp[1] = arr[2]-arr[1]-1;
	lp[n] = arr[n]-arr[n-1]-1;
	for(int i = 2;i<n;i++){
		if(arr[i]-arr[i-1]<arr[i+1]-arr[i])lp[i] += arr[i]-arr[i-1]-1;
		else rp[i] += arr[i+1]-arr[i]-1;
		lp[i] += lp[i-1];
		rp[i] += rp[i-1];
	}
	lp[n] += lp[n-1];
	rp[n] += rp[n-1];
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(a<b){
			cout<<arr[b]-arr[a]-(rp[b-1]-rp[a-1])<<'\n';
		}
		else{
			cout<<arr[a]-arr[b]-(lp[a]-lp[b])<<'\n';
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
