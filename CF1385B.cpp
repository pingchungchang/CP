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
	int arr[n*2];
	for(auto &i:arr)cin>>i;
	set<int> st;
	vector<int> ans;
	for(auto &i:arr){
		if(st.find(i) != st.end())continue;
		st.insert(i);
		ans.push_back(i);
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
