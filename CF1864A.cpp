#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,x,y;
	cin>>x>>y>>n;
	ll arr[n+1];
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2;i<=n;i++){
		arr[i] = arr[i-1]+(n-i+1);
	}
	//for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
	if(arr[n]>y){
		cout<<"-1\n";
		return;
	}
	//return;
	ll d = y-arr[n];
	for(int i = 1;i<=n;i++)arr[i] += d;
	if(arr[1]<x){
		cout<<"-1\n";
		return; 
	}
	arr[1] = x;
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
