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
	map<int,int> mp;
	for(auto &i:arr){
		cin>>i;
		mp[i]++;
	}
	for(auto &i:arr){
		if(mp[i]>1){
			mp[i]--;
			mp[i+1]++;
			i++;
		}
	}
	cout<<mp.size()<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
