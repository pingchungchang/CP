#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#define int ll
int n;
void solve(){
	set<int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(st.find(k) ==st.end())st.insert(k);
		else st.erase(k);
	}
	cout<<*st.begin()<<'\n';
	return;
}
main(){
	io
	while(cin>>n)solve();
}

