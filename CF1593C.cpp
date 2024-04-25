#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 4e5+10;
int n,m;
int arr[mxn];

void solve(){
	cin>>n>>m;
	for(int i = 0;i<m;i++)cin>>arr[i];
	sort(arr,arr+m);
	ll total = 0;
	for(int i = m-1;i>=0;i--){
		total += n-arr[i];
		if(total>=n){
			cout<<m-i-1<<'\n';
			return;
		}
	}
	cout<<m<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
