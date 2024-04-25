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
	int arr[n];
	int bound = -1;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(k == 0)bound = i;
	}
	if(bound == -1){
		cout<<n+1<<' ';
		for(int i = 1;i<=n;i++)cout<<i<<' ';cout<<'\n';
		return;
	}
	for(int i = 1;i<=bound;i++){
		cout<<i<<' ';
	}
	cout<<n+1<<' ';
	for(int i = bound+1;i<=n;i++)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

