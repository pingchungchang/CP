#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g1(n),g2(n);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		g1[a].push_back(b);
		g1[b].push_back(a);
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		g2[a].push_back(b);
		g2[b].push_back(a);
	}
	for(int i = 0;i<n;i++){
		sort(g1[i].begin(),g1[i].end());
		sort(g2[i].begin(),g2[i].end());
	}
	vector<int> v(n);
	for(int i =0;i<n;i++){
		v[i] = i;
	}
	do{
		bool ans = true;
		for(int i = 0;i<n;i++){
			int now = v[i];
			if(g1[now].size()!=g2[i].size()){
				ans = false;
				break;
			}
			vector<int> p2;
			for(int j =0;j<g1[now].size();j++){
				p2.push_back(v[g2[i][j]]);
			}
			sort(p2.begin(),p2.end());
			for(int j = 0;j<p2.size();j++){
				if(p2[j]!= g1[now][j]){
					ans = false;
					break;
				}
			}
		}
		if(ans){
			cout<<"Yes";
			return 0;
		}
	}while(next_permutation(v.begin(),v.end()));
	cout<<"No";
	return 0;
	return 0;
}
