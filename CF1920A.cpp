#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int inf = 1e9;

void solve(){
	int n;
	cin>>n;
	pii range = {0,inf};
	vector<int> no;
	while(n--){
		int t,v;
		cin>>t>>v;
		if(t == 3)no.push_back(v);
		else if(t == 1)range.fs = max(range.fs,v);
		else range.sc = min(range.sc,v);
	}
	int ans = range.sc-range.fs+1;
	for(auto &i:no)ans -= (range.fs<=i&&range.sc>=i);
	cout<<max(ans,0)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
