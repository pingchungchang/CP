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
	sort(arr,arr+3);
	int dx = arr[2]+arr[1]-arr[0]-arr[0];
	if((dx+3)/6>arr[0]||dx%3 != 0){
		cout<<"NO\n";
		return;
	}
	if((arr[0]+arr[1]+arr[2])%9 == 0)cout<<"YES\n";
	else cout<<"NO\n";
	return;
	if(dx%6 != 0)arr[0]-=2;
	else arr[0]--;
	if(arr[0]<0){
		cout<<"NO\n";
		return;
	}
	if(arr[0]%3 == 0)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
