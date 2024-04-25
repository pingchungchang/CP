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
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<n-1;i++){
		if(arr[i]%__gcd(arr[i-1],arr[i+1]) != 0){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}


/*
gcd(a,b) = x;
gcd(b,c) = y;
gcd(a,b,c) = gcd(gcd(a,b),gcd(b,c))

*/
