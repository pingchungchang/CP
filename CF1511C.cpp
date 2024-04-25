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
	int n,q;
	cin>>n>>q;
	vector<int> cols(51,INT_MAX);
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		cols[k] = min(cols[k],i);
	}
	while(q--){
		int now;
		cin>>now;
		for(int i = 0;i<=50;i++){
			if(cols[i]<cols[now])cols[i]++;
		}
		cout<<cols[now]<<'\n';
		cols[now] = 1;
	}
	return;
}
int main(){
	io
	int t = 1;
	while(t--)solve();
}

