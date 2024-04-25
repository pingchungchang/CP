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
void solve(){
	int n,m;
	cin>>n>>m;
	int arr[m];
	for(int i = 0;i<m;i++){
		cin>>arr[i]>>arr[i];
	}
	if(m==n)cout<<"NO\n";
	else cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

