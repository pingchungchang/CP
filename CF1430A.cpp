#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<=n/7;i++){
		int rest = n-i*7;
		for(int j = 0;j<=rest/5;j++){
			int l = rest-j*5;
			if(l%3 == 0){
				cout<<l/3<<' '<<j<<' '<<i<<'\n';
				return;
			}
		}
	}
	cout<<-1<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
