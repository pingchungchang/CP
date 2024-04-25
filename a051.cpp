#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m;

void solve(){
	vector<vector<int>> v(n);
	vector<bool> goneto(n,false);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
	}
	int a,b;
	cin>>a>>b;
	a--,b--;
	queue<int> q;
	q.push(a);
	goneto[a] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto nxt:v[now]){
			if(goneto[nxt] == false){
				goneto[nxt] = true;
				q.push(nxt);
			}
		}
	}
	if(goneto[b] == true){
		cout<<"Yes\n";
	}
	else cout<<"No\n";
	return;	
}
int main(){
	while(cin>>n>>m){
		solve();
	}
}

