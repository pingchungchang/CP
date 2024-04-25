#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<10;i++){
		if((1<<i)>n)break;
		for(int j = 0;j<(1<<i);j++)arr[j] -= 1e9;
	}
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1]){
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
