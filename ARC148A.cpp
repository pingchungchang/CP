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
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int G = 0;
	int k = 0;
	k|=(1<<(arr[0]&1));
	for(int i = 1;i<n;i++){
		G = __gcd(G,arr[i]-arr[i-1]);
		k|=(1<<(arr[i]&1));
	}
	if(G != 1){
		cout<<"1\n";
	}
	else{
		if(__builtin_popcount(k) != 1)cout<<"2\n";
		else cout<<"1\n";
	}
	return 0;
}

