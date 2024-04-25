#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<int> ans;

void solve(){
	int n;
	cin>>n;
	int val[n+1] = {};
	for(int i =1;i<=n;i++)cin>>val[i];
	pii arr[n+1];
	for(int i = 1;i<n;i++)arr[i].sc = i+1;
	arr[n].sc = 1;
	for(int i = 2;i<=n;i++)arr[i].fs = i-1;
	arr[1].fs = n;
	vector<pii> edges[2];
	bool roll = false;
	for(int i = 1;i<n;i++){
		if(__gcd(val[i],val[i+1]) == 1)edges[roll].push_back(make_pair(i,i+1));
	}
	if(__gcd(val[n],val[1]) == 1)edges[roll].push_back(make_pair(n,1));
	int del[n+1] = {};
	while(!edges[roll].empty()){
		for(auto &i:edges[roll]){
			if(del[i.fs]||del[i.sc])continue;
			else{
				//cout<<i.fs<<','<<i.sc<<endl;
				del[i.sc] = true;
				ans.push_back(i.sc);
				int pre = arr[i.sc].fs,nxt = arr[i.sc].sc;
				arr[pre].sc = nxt;
				arr[nxt].fs = pre;
				if(__gcd(val[pre],val[nxt]) == 1)edges[roll^1].push_back(make_pair(pre,nxt));
			}
		}
		edges[roll].clear();
		roll ^= 1;
	}
	cout<<ans.size()<<' ';for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	ans.clear();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
