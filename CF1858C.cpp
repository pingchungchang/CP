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
	set<int> st;
	for(int i = 1;i<=n;i++){
		st.insert(i);
	}
	vector<int> v = {1};
	st.erase(1);
	while(!st.empty()){
		while(st.find(v.back()*2) != st.end()){
			v.push_back(v.back()*2);
			st.erase(v.back());
		}
		if(!st.empty()){
			v.push_back(*st.begin());
			st.erase(v.back());
		}
	}
	for(auto &i:v)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
