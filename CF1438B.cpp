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
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	set<int> st;
	for(int i = 0;i<n;i++)cin>>v[i];
	for(auto i:v){
		if(st.find(i) != st.end()){
			cout<<"YES\n";
			return;
		}
		st.insert(i);
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

