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
	int n;
	cin>>n;
	int arr[n];
	int p = 0;
	for(int i = 1;i<=n;i+=2){
		arr[p++] = i;
	}
	p = n-1;
	for(int i = 2;i<=n;i+=2){
		arr[p--] = i;
	}
	for(auto &i:arr)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

