#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int arr[3];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<3;i++)for(int j = i+1;j<3;j++){
		if(arr[i]+arr[j]>=10){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
