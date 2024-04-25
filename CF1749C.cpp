#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

int n;
int arr[110];
bool f(int k){
	int l = -1,r = n-1;
	for(int i = 1;i<=k;i++){
		while(r>=0&&arr[r]>k-i+1)r--;
//		cout<<k<<' '<<i<<' '<<r<<'\n';
		if(r<=i-2)return false;
		r--;
	}
	return true;
}
void solve(){
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(f(i))ans = i;
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

