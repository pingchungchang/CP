#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	vector<int> v(n);
	for(int i =0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	int k;
	cin>>k;
	for(int i = 0;i<k;i++){
		int x;
		cin>>x;
		cout<<upper_bound(v.begin(),v.end(),x)-v.begin()<<'\n';
	}
	return 0;
}
