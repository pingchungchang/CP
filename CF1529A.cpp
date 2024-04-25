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
	pii cnt = {100000000,0};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(cnt.fs == k)cnt.sc++;
		else if(cnt.fs>k)cnt = {k,1};
	}
	cout<<n-cnt.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
