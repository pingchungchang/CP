#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 110;
vector<int> v[mxn];
int ans[mxn];

void solve(){
	for(auto &i:v)i.clear();
	for(auto &i:ans)i = 0;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		v[k].push_back(i);
	}
	int flag = 0;
	for(int i = 0;i<mxn;i++){
		if(v[i].size() >= 2){
			if(!flag){
				ans[v[i][0]] = 3;
				for(int j = 1;j<v[i].size();j++)ans[v[i][j]] = 2;
				flag = 1;
			}
			else if(flag == 1){
				ans[v[i][0]] = 2;
				for(int j = 1;j<v[i].size();j++)ans[v[i][j]] = 1;
				flag = 2;
			}
		}
	}
	if(flag != 2){
		cout<<"-1\n";
		return;
	}
	for(int i = 0;i<n;i++){
		if(!ans[i])cout<<1<<' ';
		else cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
