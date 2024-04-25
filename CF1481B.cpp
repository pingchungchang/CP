#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	arr[0] = 1e9;
	for(int i = 0;i<101*101*101;i++){
		for(int j = 1;j<n;j++){
			if(arr[j]<arr[j+1]){
				arr[j]++;
				k--;
				if(!k){
					cout<<j<<'\n';
					return;
				}
				break;
			}
		}
	}
	cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
