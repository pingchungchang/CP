#include <bits/stdc++.h>
using namespace std;

void dfs(int target,string s,int fronts){
	int backs = s.size()-fronts;
	if(backs>fronts)return;
	if(fronts>target)return;
	if(s.size()==target*2){
		if(fronts == backs)cout<<s<<'\n';
		return;
	}
	dfs(target,s+'(',fronts+1);
	if(fronts>=backs){
		dfs(target,s+')',fronts);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	while(cin>>n){
		dfs(n,"",0);
	}
}
