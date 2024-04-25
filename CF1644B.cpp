#include <bits/stdc++.h>
using namespace std;

void p(vector<int> v){
	for(auto i:v)cout<<i<<' ';
	cout<<'\n';
	return;
}
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 1;i<=n;i++){
		v[i-1] = i;
	}
	reverse(v.begin(),v.end());
	p(v);
	for(int i = 0;i<n-1;i++){
		swap(v[i],v[i+1]);
		p(v);
		swap(v[i],v[i+1]);
	}
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
