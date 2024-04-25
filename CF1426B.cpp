#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	bool flag = false;
	for(int i= 0;i<n;i++){
		int arr[2][2];
		cin>>arr[0][0]>>arr[0][1]>>arr[1][0]>>arr[1][1];
		if(arr[0][1] == arr[1][0]){
			flag = true;
		}
	}
	if(m&1)flag = false;
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
