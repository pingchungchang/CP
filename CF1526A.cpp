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
	vector<int> v;
	for(int i = 0;i<n*2;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	int ans[n*2];
	for(int i = 0;i<n*2;i+=2){
		ans[i] = v.back();
		v.pop_back();
	}
	for(int i = 1;i<n*2;i+=2){
		ans[i] = v.back();
		v.pop_back();
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
