#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 3e5+10;
int cnt[mxn*20];

void solve(){
	int n;
	cin>>n;
	bool one = false;
	vector<ll> v;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(k == 1)one = true;
		else if(!v.empty()&&v.back() == k)continue;
		else v.push_back(k);
	}
	if(!one){
		cout<<"1\n";
		return;
	}
	cnt[1] = one;
	unordered_set<ll> st;
	for(int i = 0;i<v.size();i++){
		ll now = 1;
		for(int j = i;j<v.size()&&now<=n*30;j++){
			now = now*v[j]/__gcd(now,v[j]);
			st.insert(now);
		}
	}
	vector<ll> all;
	for(auto &i:st)all.push_back(i);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 0;i<all.size();i++){
		if(all[i] != i+2){
			cout<<i+2<<'\n';
			return;
		}
	}
	cout<<all.size()+2<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
