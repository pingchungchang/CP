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
	int now = 0;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans[n];
	int p = 0;
	for(auto &i:arr){
		if(now>=i&&i != 0){
			cout<<"-1\n";
			return;
		}
		now += i;
		ans[p++] = now;
	}
	for(int i = 0;i<p;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

