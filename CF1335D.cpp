#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string arr[9];
	set<pii> pos[10];
	for(auto &i:arr)cin>>i;
	for(auto &i:arr){
		for(auto &j:i)if(j == '2')j = '1';
	}
	for(auto &i:arr)cout<<i<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
