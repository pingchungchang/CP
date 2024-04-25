#include <bits/stdc++.h>
using namespace std;

int n;
int cas = 0;
void solve(){
	cas++;
	int gp = 0;
	cout<<"Scenario #"<<cas<<'\n';
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 0;j<k;j++){
			int x;
			cin>>x;
			mp[x] = gp;
		}
		gp++;
	}
	vector<queue<int>> gq;
	string s;
	while(cin>>s){
		if(s == "STOP"){
			cout<<'\n';
			return;
		}
		if(s == "ENQUEUE"){
			int k;
			cin>>k;
			bool done = false;
			for(auto& it:gq){
				if(mp[it.front()] == mp[k]){
					it.push(k);
					done = true;
					break;
				}
			}
			if(done == false){
				queue<int> qq;
				qq.push(k);
				gq.push_back(qq);
			}
		}
		if(s == "DEQUEUE"){
			cout<<gq[0].front()<<'\n';
			gq[0].pop();
			if(gq[0].empty())gq.erase(gq.begin());
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n){
		if(n == 0)return 0;
		solve();
	}	
}
