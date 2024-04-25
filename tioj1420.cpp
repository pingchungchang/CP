#include <bits/stdc++.h>
using namespace std;

const int mod = 1e5;
struct node{
	int val;
	bool goneto;
	vector<int> path;
	node(int a){
		val = a;
		goneto = false;
	}
	node(){
		val = -1;
		goneto= false;
	}
};
int tran(int a,int b){
	return a*mod+b;
}
unordered_map<int,node> m;
void dfs(node &k){
	k.goneto = true;
	for(int i = 0;i<k.path.size();i++){
		int nxt = k.path[i];
		if(m[nxt].goneto == false){
			dfs(m[nxt]);
		}
	}
	return;
}
int main(){
	int a,b,d;
	cin>>a>>b>>d;
	for(int asd = 0;asd<d;asd++){
		int r,c;
		cin>>r>>c;
		int now = tran(r,c);
		if(m.count(now) == 0){
			m[now] = node(now);
		}
		for(int i = -1;i<=1;i++){
			for(int j = -1;j<=1;j++){
				if(i == 0&&j==0)continue;
				int k = tran(r+i,c+j);
				if(m.count(k) == false){
					m[k] = node(k);
				}
				m[k].path.push_back(now);
				m[now].path.push_back(k);
			}
		}
	}
	int ans = 0;
	for(auto it = m.begin();it != m.end();it++){
		node& k = it->second;
		if(k.goneto == false){
			dfs(k);
			ans++;
		}
	}
	cout<<ans;
}
