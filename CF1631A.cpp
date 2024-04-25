#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i =0 ;i<n;i++)cin>>b[i];
	for(int i = 0;i<n;i++)if(a[i]>b[i])swap(a[i],b[i]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	cout<<a[n-1]*b[n-1]<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}
