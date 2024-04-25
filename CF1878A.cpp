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
	int k;
	cin>>k;
	set<int> st;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		st.insert(tmp);
	}
	if(st.find(k) != st.end())cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
