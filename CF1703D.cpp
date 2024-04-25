#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	set<string> st;
	vector<string> v(n);
	for(auto &i:v){
		cin>>i;
		st.insert(i);
	}
	string ans(n,'0');
	for(int i = 0;i<n;i++){
		for(int j = 1;j<=v[i].size()-1;j++){
			string a = v[i].substr(0,j);
			string b = v[i].substr(j,v[i].size()-j);
			if(st.find(a) != st.end()&&st.find(b) != st.end())ans[i] = '1';
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

