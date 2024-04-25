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
	string s;
	cin>>s;
	set<char> st;
	int ans = 0;
	for(auto i:s){
		if(st.find(i) == st.end()){
			ans++;
			st.insert(i);
		}
		ans++;
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

