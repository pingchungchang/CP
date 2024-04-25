#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


multiset<pii> ls,rs;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		char c;
		int l,r;
		cin>>c>>l>>r;
		if(c == '-'){
			ls.erase(ls.find(make_pair(l,r)));
			rs.erase(rs.find(make_pair(r,l)));
		}
		else{
			ls.insert({l,r});
			rs.insert({r,l});
		}
		if(ls.size()<2){
			cout<<"NO\n";
			continue;
		}
		auto rm = rs.begin()->fs;
		auto lm = ls.rbegin()->fs;
		if(lm>rm)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
