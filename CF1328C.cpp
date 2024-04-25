#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string ans[2];
	ans[0] = ans[1] = string(n,'0');
	bool flag = false;
	for(int i = 0;i<n;i++){
		if(s[i] == '0'){
			ans[0][i] = ans[1][i] = '0';
		}
		else if(s[i] == '1'){
			if(flag){
				ans[1][i] = '1';
				ans[0][i] = '0';
			}
			else{
				ans[0][i] = '1';
				ans[1][i] = '0';
				flag = true;
			}
		}
		else{
			if(flag){
				ans[1][i] = '2';
				ans[0][i] = '0';
			}
			else{
				ans[0][i] = ans[1][i] = '1';
			}
		}
	}
	cout<<ans[0]<<'\n'<<ans[1]<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
