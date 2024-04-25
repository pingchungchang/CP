#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

string arr[2];
int n;

void solve(){
	cin>>n;
	cin>>arr[0]>>arr[1];
	pii now = {0,0};
	string ans;
	int cnt = 1;
	while(now.fs != 1||now.sc != n-1){
		ans += arr[now.fs][now.sc];
		if(now.fs == 1)now.sc++;
		else if(now.sc == n-1)now.fs++;
		else if(arr[now.fs][now.sc+1]<arr[now.fs+1][now.sc]){
			cnt = 1;
			now.sc++;
		}
		else if(arr[now.fs][now.sc+1]>arr[now.fs+1][now.sc]){
			now.fs++;
		}
		else{
			cnt++;
			now.sc++;
		}
	}
	ans += arr[1][n-1];
	cout<<ans<<'\n'<<cnt<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
