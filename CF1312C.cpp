#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll big = 1;
	while(big<1e16)big*=k;
	set<ll> st;
	for(auto &i:arr){
		for(ll j = big;j>=1;j/=k){
			if(i/j != 1&&i/j != 0){
				cout<<"NO\n";
				return;
			}
			if(i/j){
				if(st.find(j)!=st.end()){
					cout<<"NO\n";
					return;
				}
				st.insert(j);
				i -= j;
			}
		}
	}
	cout<<"YES\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
