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
	set<int> st;
	for(int i= 1;i<=n;i++)st.insert(i);
	cout<<2<<'\n';
	while(!st.empty()){
		int now = *st.begin();
		while(st.find(now) != st.end()){
			cout<<now<<' ';
			st.erase(now);
			now *= 2;
		}
	}
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

