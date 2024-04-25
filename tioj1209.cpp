#include <bits/stdc++.h>
using namespace std;

struct node{
	int color;
	vector<int> paths;
	node(){
		color =0;
	}
};
vector<node> v;

bool draw(int pos,int col){
	col = -col;
	for(int i =0;i<v[pos].paths.size();i++){
		int nxt = v[pos].paths[i];
		if(v[nxt].color==0){
			v[nxt].color = col;
			if(draw(nxt,col) == false)return false;
		}
		else if(v[nxt].color != col){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0)return 0;
		v = vector<node>(n,node());
		for(int i =0;i<m;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			v[a].paths.push_back(b);
			v[b].paths.push_back(a);
		}
		bool ans = true;
		for(int i =0;i<n;i++){
			if(v[i].color ==0){
				v[i].color = -1;
				ans = ans&draw(i,-1);
			}
		}
		if(ans)cout<<"Yes\n";
		else cout<<"No\n";
	}
}
