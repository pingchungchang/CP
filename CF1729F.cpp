#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int w,q;
	cin>>w>>q;
	vector<int> v[9];
	int n = s.size();
	s = "#"+s;
	int pref[n+1] = {};
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1];
		pref[i] += s[i]-'0';
		if(i>=w){
			v[(pref[i]-pref[i-w])%9].push_back(i-w+1);
		}
	}
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		int d = (pref[r]-pref[l-1])%9;
		pii ans = {n+1,n+1};
		for(int i = 0;i<9;i++){
			for(int j = 0;j<9;j++){
				if((i*d+j)%9 == k){
					if(i == j&&v[i].size()<2)continue;
					if(v[i].empty()||v[j].empty())continue;
					if(i == j)ans = min(ans,make_pair(v[i][0],v[i][1]));
					else ans = min(ans,make_pair(v[i][0],v[j][0]));
				}
			}
		}
		if(ans.fs>n)cout<<"-1 -1\n";
		else cout<<ans.fs<<' '<<ans.sc<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
