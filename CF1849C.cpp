#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	s = "#"+s;
	vector<int> one,zero;
	for(int i = 1;i<=n;i++){
		if(s[i]=='0')zero.push_back(i);
		else one.push_back(i);
	}
	set<pii> st;
	/*
	for(auto &i:zero)cout<<i<<' ';cout<<'\n';
	for(auto &i:one)cout<<i<<' ';cout<<'\n';

   */
	while(q--){
		int l,r;
		cin>>l>>r;
		auto pl = lower_bound(one.begin(),one.end(),l)-one.begin();
		auto pr = upper_bound(zero.begin(),zero.end(),r)-zero.begin();pr--;
		//cout<<l<<' '<<r<<' '<<pl<<' '<<pr<<',';
		if(pl<0||pl==one.size()||pr<0||pr==zero.size()||one[pl]>r||zero[pr]<l||one[pl]>zero[pr])st.insert({0,0});
		else st.insert({one[pl],zero[pr]});
	}
	cout<<st.size()<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
