#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n,s;
	cin>>n>>s;
	int arr[n+1] = {};
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] += arr[i-1];
	}
	if(arr[n]<s){
		cout<<-1<<'\n';
		return;
	}
	int ans= INT_MAX;
	int p1 = 0,p2 = 0;
	while(p2 <= n){
		if(arr[p2]-arr[p1]<s)p2++;
		else if(arr[p2]-arr[p1]>s){
			p1++;
		}
		else{
			ans = min(ans,n-(p2-p1));
			p2++;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

