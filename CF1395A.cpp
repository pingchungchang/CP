#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int arr[4];
	for(auto &i:arr)cin>>i;
	int s = 0;
	for(auto &i:arr)s += (i&1);
	if(s<=1){
		cout<<"YES\n";
		return;
	}
	if(*min_element(arr,arr+3)>0){
		for(auto &i:arr)i--;
		arr[3] += 2;
	}
	s = 0;
	s = 0;
	for(auto &i:arr)s += (i&1);
	if(s<=1){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
