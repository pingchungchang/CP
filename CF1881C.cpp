#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll
const ll inf = 1e9;

int calc(char a,char b){
	if(b>=a)return b-a;
	else return inf;
}

void solve(){
	int n;
	cin>>n;
	string arr[n];
	vector<vector<int>> done(n,vector<int>(n,0));
	for(auto &i:arr){
		cin>>i;
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(done[i][j])continue;
			int tans = 1e9;
			done[i][j] = done[j][n-1-i] = done[n-1-j][i] = done[n-1-i][n-1-j] = 1;
			for(char c = 'a';c<='z';c++){
				int tsum = 0;
				tsum = calc(arr[i][j],c)+calc(arr[j][n-1-i],c)+calc(arr[n-1-j][i],c)+calc(arr[n-1-i][n-1-j],c);
				tans = min(tans,tsum);
			}
			ans += tans;
			//cout<<i<<' '<<j<<":"<<tans<<endl;
		}
	}
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
