#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	vector<int> mv;
	vector<int> v;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(k)continue;
		mv.push_back(i);
		v.push_back(arr[i]);
	}
	sort(v.rbegin(),v.rend());
	for(int i = 0;i<mv.size();i++){
		arr[mv[i]] = v[i];
	}
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
