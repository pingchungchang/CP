#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int arr[2][mxn];
bool done[mxn];
vector<pii> v[mxn];
int n;

vector<int> calc(int col){
	vector<int> used;
	queue<pii> q;
	vector<int> v1,v2;
	done[col] = true;
	used = {col};
	q.push({col,arr[0][col]});
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(arr[0][now.fs] != now.sc){
			v1.push_back(now.fs);
		}
		auto c = now.sc;
		for(auto &i:v[c]){
			if(done[i.sc])continue;
			done[i.sc] = true;
			used.push_back(i.sc);
			q.push({i.sc,arr[i.fs^1][i.sc]});
		}
	}
	for(auto &i:used)done[i] = false;
	q.push({col,arr[1][col]});
	done[col] = true;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(arr[0][now.fs] != now.sc){
			v2.push_back(now.fs);
		}
		auto c = now.sc;
		for(auto &i:v[c]){
			if(done[i.sc])continue;
			done[i.sc] = true;
			q.push({i.sc,arr[i.fs^1][i.sc]});
		}
	}
	//cout<<col<<":";for(auto &i:v1)cout<<i<<',';cout<<";";for(auto &i:v2)cout<<i<<',';cout<<'\n';
	if(v1.size()>v2.size())return v2;
	else return v1;
}

void solve(){
	for(int i = 0;i<=n;i++){
		done[i] = arr[0][i] = arr[1][i] = 0;
		v[i].clear();
	}
	cin>>n;
	for(int i = 0;i<2;i++){
		for(int j = 0;j<n;j++){
			cin>>arr[i][j];
			v[arr[i][j]].push_back({i,j});
		}
	}
	for(int i = 1;i<=n;i++){
		if(v[i].size() != 2){
			cout<<"-1\n";
			return;
		}
	}
	vector<int> ans;
	for(int i = 0;i<n;i++){
		if(!done[i]){
			auto tmp = calc(i);
			for(auto &j:tmp)ans.push_back(j);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i+1<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
