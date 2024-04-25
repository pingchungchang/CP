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
	int arr[n];
	for(auto &i:arr)cin>>i;
	int lans = n,rans = 0;
	set<int> st;
	for(int i = 1;i<=n*2;i++){
		st.insert(i);
	}
	for(auto &i:arr)st.erase(i);
	for(int i = n-1;i>=0;i--){
		if(st.empty())break;
		auto it = st.upper_bound(arr[i]);
		if(it == st.begin())continue;
		else{
			it--;
			lans--;
			st.erase(it);
		}
	}
	for(int i = 1;i<=n*2;i++)st.insert(i);
	for(auto &i:arr)st.erase(i);
	for(int i = 0;i<n;i++){
		if(st.empty())break;
		auto it = st.upper_bound(arr[i]);
		if(it == st.end())continue;
		st.erase(it);
		rans++;
	}
	cout<<rans-lans+1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
