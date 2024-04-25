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
	int arr[n];
	for(auto &i:arr)cin>>i,i = (i<k?-1:i>k?1:0);
	if(n == 1){
		if(arr[0] == 0)cout<<"YES\n";
		else cout<<"NO\n";
		return;
	}
	bool flag = false;
	for(auto &i:arr)if(!i)flag = true;
	if(!flag){
		cout<<"NO\n";
		return;
	}
	for(int i = 0;i<n;i++){
		for(int j = i-1;j>=max(0,i-2);j--){
			if(arr[i]>=0&&arr[j]>=0){
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
