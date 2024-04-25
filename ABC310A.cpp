#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,p,q;
	cin>>n>>p>>q;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	cout<<min(q+arr[0],p);
}
