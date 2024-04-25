#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v1,v2;
	for(int i = 0;i<k-1;i++)v1.push_back(1);
	v1.push_back(n-(k-1));
	for(int i = 0;i<k-1;i++)v2.push_back(2);
	v2.push_back(n-(k-1)*2);
	int sum = 0;
	bool flag = true;
	for(auto &i:v1){
		sum += i;
		if(i<=0)flag = false;
		if(i%2 != v1[0]%2)flag = false;
	}
	if(flag&&sum == n){
		cout<<"YES\n";
		for(auto &i:v1)cout<<i<<' ';cout<<'\n';
		return;
	}
	sum = 0;
	flag = true;
	for(auto &i:v2){
		sum += i;
		if(i<=0)flag = false;
		if(i%2 != v2[0]%2)flag = false;
	}
	if(flag&&sum == n){
		cout<<"YES\n";
		for(auto &i:v2)cout<<i<<' ';cout<<'\n';
		return;
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
