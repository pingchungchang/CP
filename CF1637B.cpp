#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	int ans = 0;
	for(int i = 0;i<n;i++){
//		cout<<i<<n-i<<endl;
		ans += (i+1)*(n-i);
		cin>>v[i];
		if(v[i] == 0){
			ans += (i+1)*(n-i);
		}	
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
