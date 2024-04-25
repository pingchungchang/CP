#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,k;
const int mxn = 1e6+10;
int arr[mxn];

void solve(){
	if(!n&&!k)exit(0);
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n,greater<int>());
	cout<<arr[k-1]<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>k)solve();
}
