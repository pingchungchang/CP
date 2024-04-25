#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int n;
multiset<pair<int,int>> st;
void solve(){
	st.clear();
	int ans = 0;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(st.find(make_pair(b,a)) != st.end()){
			st.erase(st.find(make_pair(b,a)));
			ans++;
		}
		else st.insert(make_pair(a,b));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
