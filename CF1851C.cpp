#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	int l = -1,r = -1;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(arr[i] == arr[0])cnt++;
		if(cnt == k){
			l = i;
			break;
		}
	}
	cnt = 0;
	for(int i = n-1;i>=0;i--){
		if(arr[i] == arr[n-1])cnt++;
		if(cnt == k){
			r = i;
			break;
		}
	}
	if(l == -1||r == -1)cout<<"NO\n";
	else if(arr[0] == arr[n-1]&&l != -1){
		cout<<"YES\n";
	}
	else if(l<r){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
