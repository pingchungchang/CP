#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	set<int> s1,s2;
	for(int i = 1;i<=n;i++){
		s1.insert(i);
		s2.insert(i);
	}
	int b1 = -1,b2 = -1;
	vector<int> v1,v2;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(b1 != k){
			v1.push_back(k);
			s1.erase(k);
		}
		else{
			v1.push_back(*s1.begin());
			s1.erase(s1.begin());
		}
		v2.push_back(*(--s2.upper_bound(k)));
		s2.erase(--s2.upper_bound(k));
		b2 = max(b2,k);
		b1 = max(b1,k);
	}
	for(int i = 0;i<n;i++){
		cout<<v1[i]<<' ';
	}
	cout<<'\n';
	for(int i = 0;i<n;i++)cout<<v2[i]<<' ';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
