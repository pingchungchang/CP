#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


vector<vector<int>> bit;
int n;
void modify(int r,int c,int v){
	for(;c<=n;c += c&-c){
		bit[r][c] += v;
	}
	return;
}

int getval(int r,int s,int e){
	int returns = 0;
	for(;e>0;e -= e&-e)returns += bit[r][e];
	s--;
	for(;s>0;s -= s&-s)returns -= bit[r][s];
	return returns;
}
void solve(){
	cin>>n;
	vector<int> arr(n+1);
	ll ans = 0;
	bit = vector<vector<int>>(2,vector<int>(n+1,0));
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int p2 = 1;p2<=n;p2++){
		bit[1] = vector<int>(n+1,0);
		for(int p3 = n;p3>p2;p3--){
			ans += 1LL*getval(0,1,arr[p3])*getval(1,1,arr[p2]);
			modify(1,arr[p3],1);
		}
		modify(0,arr[p2],1);
//		cout<<p2<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

