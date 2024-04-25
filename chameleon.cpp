#include "chameleon.h"
#include <vector>
#include <bits/stdc++.h>

#define pii pair<int,int>
#define fs first
#define sc second

using namespace std;

const int mxn = 1010;
vector<int> bigraph[mxn];
bitset<mxn> mat[mxn];
int N;

namespace BUILD{

	int deg[mxn];
	vector<int> v[2];

	void get_edge(int now){
		int l = 0,r = v[0].size()-1;
		while(l != r){
			int mid = (l+r)>>1;
			vector<int> vv = {now};
			for(int i = 0;i<=mid;i++){
				if(mat[now][v[0][i]])continue;
				vv.push_back(v[0][i]);
			}
			if(Query(vv) != vv.size())r = mid;
			else l = mid+1;
		}
		//cout<<now<<":"<<v[0][l]<<endl;
		mat[now][v[0][l]] = mat[v[0][l]][now] = true;
		bigraph[now].push_back(v[0][l]);
		bigraph[v[0][l]].push_back(now);
		deg[now]++,deg[v[0][l]]++;
		return;
	}
	bool done(int now){
		vector<int> vv;
		for(auto &i:v[0]){
			if(mat[now][i])continue;
			vv.push_back(i);
		}
		vv.push_back(now);
		if(Query(vv) != vv.size())return false;
		else return true;
	}

	void GO(){
		vector<int> rest;
		for(int i = 1;i<=N*2;i++)rest.push_back(i);
		while(!rest.empty()){
			v[0].clear();v[1].clear();
			for(auto &i:rest){
				if(v[0].empty())v[0].push_back(i);
				else{
					v[0].push_back(i);
					if(Query(v[0]) != v[0].size()){
						v[0].pop_back();
						v[1].push_back(i);
					}
				}
			}
			//cout<<"---"<<endl;
			//for(auto &i:v[0])cout<<i<<',';cout<<endl;
			//for(auto &i:v[1])cout<<i<<',';cout<<endl;
			rest.clear();
			for(auto &i:v[1]){
				do{
					get_edge(i);
				}while(deg[i]<3&&!done(i));
			}
			rest = v[1];
		}
		return;
	}

	int col[mxn];

	void dfs(int now,int c){
		col[now] = c;
		for(auto nxt:bigraph[now]){
			if(col[nxt] == -1)dfs(nxt,c^1);
		}
		return;
	}
	void COLOR(){
		memset(col,-1,sizeof(col));
		for(int i = 1;i<=N*2;i++){
			if(col[i] == -1)dfs(i,1);
		}
		return;
	}
	void PRINT(){
		for(int i = 1;i<=N*2;i++){
			cout<<i<<":";for(auto &j:bigraph[i])cout<<j<<',';cout<<endl;
		}
		cout<<endl;
		for(int i = 1;i<=N*2;i++)cout<<col[i];cout<<endl;
		return;
	}

}

namespace GETANS{
	vector<pii> ans;
	void GO(){
		for(int i = 1;i<=N*2;i++){
			if(bigraph[i].size()==1)continue;
			assert(bigraph[i].size()==3);
			vector<int> nei = bigraph[i];
			vector<int> v[2] = {{i,bigraph[i][0],bigraph[i][1]},{i,bigraph[i][0],bigraph[i][2]}};
			int tmp[2] = {Query(v[0]),Query(v[1])};
			int now = i;
			if(tmp[0] == 1)mat[now][nei[2]] = mat[nei[2]][now] = 0;
			else if(tmp[1] == 1)mat[now][nei[1]] = mat[nei[1]][now] = 0;
			else mat[now][nei[0]] = mat[nei[0]][now] = 0;
		}
		for(int i = 1;i<=N*2;i++){
			for(int j = i+1;j<=N*2;j++){
				if(mat[i][j])ans.push_back({i,j});
			}
		}
		for(auto &i:ans){
			Answer(i.fs,i.sc);
		}
		return;
	}
}

void Solve(int NN) {
	N = NN;
	//cout<<"HI"<<":"<<N<<endl;
	BUILD::GO();
	//cout<<"HI"<<":"<<N<<endl;
	BUILD::COLOR();
	//BUILD::PRINT();
	//cout<<"HI"<<":"<<N<<endl;
	GETANS::GO();
	//cout<<"HI"<<":"<<N<<endl;
}
