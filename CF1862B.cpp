#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	vector<int> v;
	for(int i = n-1;i>0;i--){
		v.push_back(arr[i]);
		if(arr[i]<arr[i-1])v.push_back(1);
	}
	v.push_back(arr[0]);
	reverse(v.begin(),v.end());
	cout<<v.size()<<'\n';
	for(auto &i:v)cout<<i<<' ';cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
