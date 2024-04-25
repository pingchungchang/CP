#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,r,c;
	cin>>n>>m>>r>>c;
	set<int> row,col;
	r--,c--;
	bool flag = false;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			char cc;
			cin>>cc;
			if(cc == 'B'){
				row.insert(i);
				col.insert(j);
				if(i == r&&j == c)flag = true;
			}
		}
	}
	if(flag){
		cout<<0<<'\n';
		return;
	}
	if(row.size()+col.size() == 0){
		cout<<"-1\n";
		return;
	}
	if(row.find(r)!= row.end()||col.find(c)!= col.end())cout<<1<<'\n';
	else cout<<2<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
