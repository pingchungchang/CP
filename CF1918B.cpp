#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	pii arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	sort(arr,arr+n);
	for(auto &i:arr)cout<<i.fs<<' ';cout<<'\n';
	for(auto &i:arr)cout<<i.sc<<' ';cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
