#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	int p = 1;
	sort(v.begin(),v.end());
	for(int i = 1;i<n;i++){
		if(v[i]-v[i-1]<v[p]-v[p-1])p = i;
	}
	cout<<v[p-1]<<' ';
	for(int i = p+1;i<n;i++)cout<<v[i]<<' ';
	for(int i = 0;i<p-1;i++)cout<<v[i]<<' ';
	cout<<v[p]<<"\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

