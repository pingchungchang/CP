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
	int n,m;
	cin>>n>>m;
	int cnt[10] = {};
	int tar;
	queue<pii> q;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		q.push(make_pair(i,k));
		cnt[k]++;
	}
	int tmp = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		bool flag = true;
		for(int i = 9;i>now.sc;i--){
			if(cnt[i] != 0){
//				cout<<endl<<i<<endl;
				q.push(now);
				flag = false;
				break;
			}
		}
		if(flag){
			tmp++;
			cnt[now.sc]--;
		}
		if(flag&&now.fs == m)break;
	}
	cout<<tmp<<'\n';
}
int main(){
	io
	int t;
	cin>>t;while(t--)solve();
}

