#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

vector<int> choice[21];
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans = n;
	for(auto &i:choice[n]){
		int tmp[n];
		int cnt = 0;
		for(int j = 0;j<n;j++){
			tmp[j] = arr[j];
			if((1<<j)&i){
				cnt += n-j;
				tmp[j] = __gcd(tmp[j],j+1);
			}
		}
		int re = tmp[0];
		for(auto &j:tmp)re = __gcd(re,j);
		if(re == 1)ans = min(ans,cnt);
//		cout<<i<<' '<<re<<' '<<cnt<<',';
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	for(int i = 0;i<21;i++){
		for(int j = 0;j<(1<<i);j++){
			int cnt = 0;
			for(int k = 0;k<i;k++){
				if((1<<k)&j)cnt += i-k;
			}
			if(cnt>i)continue;
			else choice[i].push_back(j);
		}
	}
//	for(int i = 1;i<=20;i++){
//		cout<<i<<": ";cout<<choice[i].size();
//		for(auto &j:choice[i])cout<<j<<',';
//		cout<<'\n';
//	}
//	return 0;
	int t;
	cin>>t;
	while(t--)solve();
}

