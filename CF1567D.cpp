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

void solve(){
	ll n,x;
	cin>>n>>x;
	string s = to_string(n);
	vector<ll> cnt(s.size(),0);
	ll total = 0;
	for(int i = 0;i<s.size();i++){
		cnt[i] = s[i]-'0';
		total += cnt[i];
	}
	if(total<x){
		while(total<x){
			bool flag = false;
			for(int i = (ll)s.size()-2;i>=0;i--){
				if(total<x&&cnt[i] != 0){
					cnt[i]--;
					cnt[i+1]+= 10;
					total += 9;
					flag = true;
					break;
				}
				if(flag)break;
			}
		}
	}
	ll k = x;
	vector<vector<int>> ans(x,vector<int>(s.size(),0));
	int now = 0;
	for(int i = 0;i<s.size();i++){
		while(cnt[i]>0){
			ans[now][i] ++;
			cnt[i]--;
			now = (now+1)%k;
//			cout<<cnt[i]<<endl;
		}
	}
	for(int i= 0;i<k;i++){
		string ss;
		for(auto j:ans[i])ss += to_string(j);
		cout<<stoi(ss)<<' ';
	}
	cout<<'\n';
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

