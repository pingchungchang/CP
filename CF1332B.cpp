#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
	vector<int> col[primes.size()];
	int n;
	cin>>n;
	int ans[n];
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 0;j<primes.size();j++){
			if(k%primes[j] == 0){
				col[j].push_back(i);
				break;
			}
		}
	}
	int C = 0;
	for(auto &i:col){
		if(i.empty())continue;
		C++;
		for(auto &j:i)ans[j] = C;
	}
	cout<<C<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
