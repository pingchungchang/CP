#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	pii arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	bool flag = true;
	for(auto &i:arr){
		if(i.fs<i.sc){
			flag = false;
		}
	}
	for(int i = 1;i<n;i++){
		if(arr[i].fs-arr[i].sc<arr[i-1].fs-arr[i-1].sc)flag = false;
		if(arr[i].fs<arr[i-1].fs)flag = false;
		if(arr[i].sc<arr[i-1].sc)flag = false;
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
