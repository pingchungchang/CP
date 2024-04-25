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
int a,b;
int cnt = 0;
void solve(){
	cnt++;
	if(a == 0&&b == 0){
		cout<<"Case "<<cnt<<" is a tree.\n";		
		return;
	}
	map<int,vector<int>> mp;
	map<int,int> deg;
	mp[a].push_back(b);
	deg[b]++;
	bool flag = true;
	while(cin>>a>>b){
		if(a == 0&&b == 0)break;
		mp[a].push_back(b);
		deg[b]++;
	}
	int root = -1;
	for(auto &i:mp){
		if(root != -1&&deg[i.fs] == 0)flag = false;
		if(root == -1&&deg[i.fs] == 0){
			root = i.fs;
		}
	}
	set<int> goneto;
	goneto.insert(root);
	queue<int> q;
	q.push(root);
//	for(auto &i:mp){
//		cout<<i.fs<<": ";
//		for(auto &j:i.sc)cout<<j<<',';cout<<'\n';
//	}
//	cout<<flag<<"\n";
	while(!q.empty()){
		if(!flag)break;
		auto now = q.front();
		q.pop();
		for(auto nxt:mp[now]){
			if(goneto.find(nxt) != goneto.end()){
				flag = false;
				break;
			}
			else{
				goneto.insert(nxt);
				q.push(nxt);
			}
		}
	}
	for(auto &i:deg){
		if(goneto.find(i.fs) == goneto.end())flag = false;
	}
	for(auto &i:mp){
		if(goneto.find(i.fs) == goneto.end())flag = false;
	}
	if(flag){
		cout<<"Case "<<cnt<<" is a tree.\n";
	}
	else cout<<"Case "<<cnt<<" is not a tree.\n";
	return;
}
int main(){
	io
	while(cin>>a>>b){
		if(a == -1&&b == -1)return 0;
		solve();
	}
}

