#include <bits/stdc++.h>
using namespace std;

struct player{
	vector<string> mov;
	player(){}
};
queue<int> bases;
vector<player> v(9);
int outs = 0;
int tar;
pair<int,int> now;
int ans = 0;
void in(){
	for(int i = 0;i<3;i++)bases.push(0);
	while(bases.size()>3)bases.pop();
}
void runbase(int n){
	bases.push(1);
	for(int i = 0;i<n-1;i++)bases.push(0);
	while(bases.size()>3){
		ans += bases.front();
		bases.pop();
	}
	return;
}
void solve(){
	in();
	while(outs != tar){
		if(v[now.first].mov[now.second][1] == 'O'){
			outs++;
			if(outs%3 == 0)in();
		}
		else if(v[now.first].mov[now.second][0] == 'H')runbase(4);
		else runbase(v[now.first].mov[now.second][0]-'0');
		now.first++;
		if(now.first == 9){
			now.second++;
			now.first = 0;
		}
	}
	cout<<ans;
}
int main(){
	for(int i = 0;i<9;i++){
		int k;
		cin>>k;
		for(int j = 0;j<k;j++){
			string s;
			cin>>s;
			v[i].mov.push_back(s);
		}
	}
	cin>>tar;
	now = make_pair(0,0);
	solve();
}
