#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	int now = n-2;
	int step = 1;
	int ans = 0;
	while(now>=0){
		if(v[now]!= v[n-1]){
			now -= step;
			step *= 2;
			ans++;
		}
		else{
			step++;
			now--;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
