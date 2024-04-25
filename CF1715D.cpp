#include <bits/stdc++.h>
using namespace std;


struct Q{
	int a,b,x;
	Q(){}
};
const int mxn = 2e5+10;
int ans[mxn];
int bit[mxn];
vector<Q> req;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	while(q--){
		req.push_back(Q());
		cin>>req.back().a>>req.back().b>>req.back().x;
		if(req.back().a>req.back().b)swap(req.back().a,req.back().b);
	}
	for(int i = 1<<29;i>0;i>>=1){
		fill(bit,bit+n+1,-1);
		vector<int> z;
		vector<vector<int>> paths(n+1);
		for(auto &j:req){
			if(!(j.x&i))bit[j.a] = bit[j.b] = 0,z.push_back(j.a),z.push_back(j.b);
			else if(j.a == j.b)bit[j.a] = (j.x&i);
			else paths[j.a].push_back(j.b),paths[j.b].push_back(j.a);
		}
		sort(z.begin(),z.end());
		z.erase(unique(z.begin(),z.end()),z.end());
		for(auto &j:z){
			for(auto &k:paths[j])bit[k] = i;
		}
		for(int j = 1;j<=n;j++){
			if(bit[j] == -1){
				bit[j] = 0;
				for(auto nxt:paths[j])if(bit[nxt] == -1)bit[nxt] = i;
			}
		}
		for(int j = 1;j<=n;j++)ans[j]|=bit[j];
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return 0;
}
