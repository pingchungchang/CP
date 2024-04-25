#include <bits/stdc++.h>
using namespace std;

void solve(){
	set<int> st;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	for(int i = 0;i<n;i++){
		cout<<max((int)st.size(),i+1)<<" ";
	}
	cout<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
