#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int k = 0;
void dfs(int now,queue<int> q){
	if(q.size()==6){
		if(k != 0)cout<<'\n';
		else k= 1;
		while(!q.empty()){
			cout<<q.front();
			if(q.size()>1)cout<<' ';
			q.pop();
		}
		return;
	}
	if(now>=n){
		return;
	}
	for(int i = now;i<n;i++){
		queue<int> qq = q;
		qq.push(v[i]);
		dfs(i+1,qq);
	}
	return;
}
void solve(){
	v = vector<int>(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	queue<int> q;
	dfs(0,q);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 0;
	while(cin>>n){
		if(n == 0)return 0;
		else solve();
		cout<<"\n";
//		if(t != 0)cout<<"\n\n";
//		else t = 1;
	}
}
