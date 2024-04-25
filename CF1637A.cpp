#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<int> v2 = v;
	sort(v2.begin(),v2.end());
	for(int i =0;i<n;i++){
		if(v[i] != v2[i]){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}
