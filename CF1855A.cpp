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
	int arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	int cnt =0;
	for(int i =1;i<=n;i++){
		if(arr[i] == i)cnt++;
	}
	cout<<(cnt+1)/2<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
