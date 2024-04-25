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
	ll sum = 0;
	for(auto &i:arr)cin>>i;
	if(n==1){
		cout<<"NO\n";
		return;
	}
	for(auto &i:arr){
		i--;
		sum += i;
	}
	int emp = 0;
	for(auto &i:arr)if(!i)emp++;
	if(sum>=emp)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
