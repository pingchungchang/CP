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
int main(){
	io
	ll n;
	cin>>n;
	int arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		for(int i = 0;i<b;i++)a = arr[a];
		cout<<a<<'\n';
	}
}

