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
	int n;
	while(cin>>n){
		if(!n)return 0;
		int arr[n];
		for(auto &i:arr)cin>>i;
		sort(arr,arr+n);
		for(auto &i:arr)cout<<i<<' ';
		cout<<'\n';
	}
}

