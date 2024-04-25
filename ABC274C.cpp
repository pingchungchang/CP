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
const int mxn = 4e5+10;
int ans[mxn];
int par[mxn];
int dep[mxn];
int main(){
	int n;
	cin>>n;
	int arr[n] = {};
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		 par[i*2] = par[i*2+1] = arr[i-1];
		 dep[i*2] = dep[i*2+1] = dep[arr[i-1]]+1;
	}
	for(int i = 1;i<=n*2+1;i++)cout<<dep[i]<<'\n';
}

