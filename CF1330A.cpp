#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,x;
	cin>>n>>x;
	set<int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	for(int i = 1;i<=303;i++){
		if(st.find(i) == st.end()&&!x){
			cout<<i-1<<'\n';
			return;
		}
		if(st.find(i) == st.end()){
			x--;
			st.insert(i);
		}
	}
	assert(false);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
