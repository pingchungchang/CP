#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	set<int> st;
	for(auto &i:arr)cin>>i,st.insert(i);
	if(st.find(x) != st.end()){
		cout<<"1\n";
		return;
	}
	sort(arr,arr+n);
	ll C = (x+arr[n-1]-1)/arr[n-1];
	if(arr[n-1] != x)C = max(C,2LL);
	cout<<C<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
