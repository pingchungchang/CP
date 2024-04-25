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
	vector<pii> v;
	for(auto &i:arr){
		if(v.empty()||v.back().sc+1 != i)v.push_back({i,i});
		else v.back().sc++;
	}
	reverse(v.begin(),v.end());
	for(int i = 1;i<v.size();i++){
		if(v[i-1].sc+1 != v[i].fs){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
