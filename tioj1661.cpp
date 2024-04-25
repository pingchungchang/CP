#include <bits/stdc++.h>
using namespace std;

int n;
void solve(){
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		int a,b;
		cin>>a>>b;
		swap(v[a],v[b]);
	}
	for(int i = 0;i<n;i++){
		cout<<v[i];
		if(i != n-1)cout<<' ';
		else cout<<'\n';
	}
	return;	
}
int main(){
	while(cin>>n)solve();
}
