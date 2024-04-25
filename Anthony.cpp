#include "Anthony.h"
#include <vector>
#include <bits/stdc++.h>


namespace ANTHONY{

#define pii pair<int,int>
#define fs first
#define sc second
	using namespace std;
	const int mxn = 2e4+10;
	int N,M;
	vector<pii> paths[mxn];
	vector<pii> edges;

	namespace S1{
		queue<int> q;
		int dist[mxn];
		void BFS(){
			memset(dist,-1,sizeof(dist));
			dist[0] = 0;
			q.push(0);
			while(!q.empty()){
				auto now = q.front();
				q.pop();
				for(auto nxt:paths[now]){
					if(dist[nxt.fs] == -1)dist[nxt.fs] = dist[now]+1,q.push(nxt.fs);
				}
			}
			return;
		}
		vector<int> GO(){
			//cout<<"CASE 1"<<endl;
			vector<int> ans(M,0);
			BFS();
			for(int i = 0;i<M;i++){
				auto [a,b] = edges[i];
				if(dist[a]>dist[b])swap(a,b);
				if(dist[a]==dist[b])ans[i] = (dist[a]+1)%3;
				else ans[i] = dist[b]%3;
				//cout<<a<<' '<<b<<" "<<ans[i]<<endl;
			}
			//for(int i = 0;i<N;i++)cout<<dist[i]<<' ';cout<<endl;
			//cout<<ans.size()<<endl;
			//for(auto &i:ans)cout<<i;cout<<endl;
			return ans;
		}
	}

	namespace S2{
		string bin = "100110";//11:0,12:1
		vector<int> ans;
		void dfs(int now,int fa,int pt){
			for(auto nxt:paths[now]){
				if(nxt.fs == fa)continue;
				if(paths[nxt.fs].size() != 2){
					if(pt>10){
						ans[nxt.sc] = (pt==11?0:1);
						dfs(nxt.fs,now,(pt==11?12:11));
					}
					else{
						if(bin[pt]=='0'){
							ans[nxt.sc] = 0;
							dfs(nxt.fs,now,12);
						}
						else{
							ans[nxt.sc] = 1;
							dfs(nxt.fs,now,11);
						}
					}
				}
				else{
					if(pt==11){
						ans[nxt.sc] = 0;
						dfs(nxt.fs,now,0);
					}
					else if(pt == 12){
						ans[nxt.sc] = 1;
						dfs(nxt.fs,now,1);
					}
					else{
						ans[nxt.sc] = bin[pt]-'0';
						dfs(nxt.fs,now,(pt+1)%bin.size());
					}
				}
			}
			return;
		}
		vector<int> GO(){
			ans.resize(M);
			dfs(0,0,11);
			for(int i = 0;i<M;i++){
				//cout<<edges[i].fs<<' '<<edges[i].sc<<" "<<ans[i]<<endl;
			}
			return ans;
		}
	}

	vector<int> SOLVE(int n,int m,int a,int b,vector<int> va,vector<int> vb){
		N = n,M = m;
		for(int i = 0;i<m;i++){
			edges.push_back({va[i],vb[i]});
			paths[va[i]].push_back({vb[i],i});
			paths[vb[i]].push_back({va[i],i});
		}
		if(a>=3)return S1::GO();
		else return S2::GO();
	}
}  // namespace

std::vector<int> Mark(int N, int M, int A, int B,
                      std::vector<int> U, std::vector<int> V) {
  return ANTHONY::SOLVE(N,M,A,B,U,V);
}
