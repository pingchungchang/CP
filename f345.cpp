#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = n-1;i>=0;i--)cout<<arr[i]<<' ';
	return 0;
}
