#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	int pref = 0;
	for(int i = 0;i<n;i++){
		pref^= v[i];
		int now = 0;
		int groups = 0;
		for(int j = i+1;j<n;j++){
			now^=v[j];
			if(now == pref){
				groups++;
				now =0;
			}
		}
		if(now == 0&&groups != 0){
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
	for(int i = 0;i<t;i++){
		solve();
	}
}
