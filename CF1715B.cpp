#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	ll n,k,b,s;
	cin>>n>>k>>b>>s;
	ll arr[n];
	ll total = 0;
	for(int i = 0;i<n;i++){
		arr[i] = k-1;
		total += arr[i];
	}
	total += b*k;
	for(int i = 0;i<n;i++){
		if(total>s){
			if(total-s<=arr[i]){
				arr[i] -= total-s;
				total = s;
			}
			else{
				total -= arr[i];
				arr[i] = 0;
			}
		}
	}
	arr[0] += b*k;
	if(total != s){
		cout<<"-1\n";
		return;
	}
	for(auto i:arr)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

