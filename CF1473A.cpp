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

void solve(){
	int n,d;
	cin>>n>>d;
	int arr[n];
	pii p = {1e9,1e9};
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		if(p.fs>arr[i]){
			swap(p.fs,p.sc);
			p.fs = arr[i];
		}
		else if(p.sc>arr[i]){
			p.sc = arr[i];
		}
	}
	if(*max_element(arr,arr+n)<=d){
		cout<<"YES\n";
		return;
	}
	else if(p.fs+p.sc<=d)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

