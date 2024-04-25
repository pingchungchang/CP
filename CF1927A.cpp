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
	string s;
	cin>>s;
	pii range = make_pair(n,0);
	for(int i = 0;i<n;i++){
		if(s[i] == 'B')range.fs = min(range.fs,i),range.sc = max(range.sc,i);
	}
	cout<<max(0,range.sc-range.fs+1)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
