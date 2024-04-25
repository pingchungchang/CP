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
	int n,k;
	cin>>n>>k;
	int cnt[26] = {};
	for(int i = 0;i<n;i++){
		char c;
		cin>>c;
		cnt[c-'a']++;
	}
	int ans[k] = {};
	int use[k] = {};
	for(int i = 0;i<26;i++){
		for(int j = 0;j<k;j++){
			if(use[j]<n/k&&cnt[i]>0){
				use[j]++;
				cnt[i]--;
				ans[j] |= (1<<i);
			}
		}
	}
	for(int i = 0;i<k;i++){
		for(int j= 0;j<26;j++){
			if(ans[i]&(1<<j));
			else{
				cout<<(char)('a'+j);
				break;
			}
		}
	}
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

