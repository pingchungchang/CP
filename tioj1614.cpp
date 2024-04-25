#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> b(n);
	vector<int> a(m);
	for(int i = 0;i<n;i++){
		cin>>b[i];
	}
	for(int j = 0;j<m;j++){
		cin>>a[j];
	}
	sort(a.begin(),a.end());
	int ans = 0;
	for(int i = 0;i<n;i++){
		int l = lower_bound(a.begin(),a.end(),b[i])-a.begin();
		int r = m-l;
		if(a[l] == b[i])continue;
		if(r%2 == 0)ans++;
	}
	cout<<ans;
} 
