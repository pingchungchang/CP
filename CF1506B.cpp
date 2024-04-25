#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int dp[n][0] = {};
	int now = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '*'){
			now = i;
			break;
		}
	}
	int ans = 1;
	bool flag = true;
	while(flag){
//		cout<<now<<endl;
		for(int j = k;j>=0;j--){
			if(j == 0){
				flag = false;
				break;
			}
			if(now+j>=n)continue;
			if(s[now+j] == '*'){
				now += j;
				ans++;
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

