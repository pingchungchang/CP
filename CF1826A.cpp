#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<=n;i++){
		int cnt = 0;
		for(auto &j:arr)if(j > i)cnt++;
		if(cnt == i){
			cout<<i<<'\n';
			return;
		}
	}
	cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}