#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> v(n,{0,0});
	for(int i = 0;i<n;i++){
		char k;
		cin>>k;
		v[i][k-'0'] = 1;
	}
	for(int i = 0;i<n;i++){
		char k;
		cin>>k;
		v[i][k-'0'] = 1;
	}
	
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(i == n-1){
			if((v[i][0]&v[i][1]) == 1)ans += 2;
			else if(v[i][0] !=0)ans ++;
			break;
		}
		if((v[i][0]&v[i][1]) == 1)ans+=2;
		else if(v[i][0] == 0){
			v[i+1][1] = 1;
		}
		else{
			if(v[i+1][0] == 0)v[i+1][0] = 1;
			else{
				ans++;
			}
		}
//		cout<<i<<' '<<ans<<',';
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
