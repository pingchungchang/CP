#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = 0;i<n;i++){
		if(v[i] != i+1){
			for(int j = i+1;j<n;j++){
				if(v[j] == i+1){
					reverse(v.begin()+i,v.begin()+j+1);
				}
			}
			break;
		}
	}
	for(auto i:v){
		cout<<i<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
