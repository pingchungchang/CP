#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	pii big = {0,0};
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		big = max(big,make_pair(arr[i],i));
	}
	if(big.sc == 0)cout<<0;
	else cout<<big.fs-arr[0]+1;
}
