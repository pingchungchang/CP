#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool cmp(int a,int b){
	return abs(a)>abs(b);
}
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	int now = arr[0];
	int ans = 1;
	for(int i = 0;i<n;i++){
		if(1LL*now*arr[i]<0){
			ans++;
			now = arr[i];
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

