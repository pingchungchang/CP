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
	bool one = true;
	for(auto &i:arr){
		cin>>i;
		if(i != 1)one = false;
	}
	if(n == 1){
		cout<<"1\n";
	}
	else if(one){
		if(n&1){
			cout<<"1\n";
		}
		else cout<<"0\n";
	}
	else cout<<"499122177\n";
}
int main(){
	io
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

