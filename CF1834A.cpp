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
	int pos = 0,neg = 0;
	for(auto &i:arr){
		cin>>i;
		if(i == 1)pos++;
		else neg++;
	}
	int ans = 0;
	if(neg&1){
		ans++;
		neg--;
		pos++;
	}
	while(neg>pos){
		neg -= 2;
		pos+=2;
		ans+=2;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
