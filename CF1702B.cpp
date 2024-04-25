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
	string s;
	cin>>s;
	set<char> st;
	int ans = 1;
	for(auto i:s){
		if(st.find(i) == st.end()&&st.size() == 3){
			ans++;
			st.clear();
			st.insert(i);
		}
		else{
			st.insert(i);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

