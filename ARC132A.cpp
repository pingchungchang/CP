#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> r(n);
	vector<int> c(n);
	for(int i = 0;i<n;i++)cin>>r[i];
	for(int j = 0;j<n;j++)cin>>c[j];
	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		int total = r[a-1]+c[b-1];
		if(total>=n+1)cout<<'#';
		else cout<<'.';
	}
}
