#include <bits/stdc++.h>
using namespace std;

vector<int> dsjset(1001);
vector<pair<int,int>> req;
int getval(int i){
	while(dsjset[i]!=i)i = dsjset[i];
	return i;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int t = 0;t<k;t++){
		int a,b;
		cin>>a>>b;
		
		req.push_back(make_pair(a-1,b-1));
		for(int i = 0;i<1001;i++)dsjset[i] = i;
		vector<int> ssize(1001,1);
		int rest = req.size();
		
		for(int i = 0;i<req.size();i++){
			int x = req[i].first;
			int y = req[i].second;
			if(getval(x)!= getval(y)){
				rest --;
				ssize[getval(x)]+= ssize[getval(y)];
				ssize[getval(y)] = 0;
				dsjset[getval(y)] = dsjset[getval(x)];
			}
		}
		sort(ssize.begin(),ssize.end());
		int ans = 0;
		for(int i = 0;i<=rest;i++){
			ans += ssize[ssize.size()-1-i];
		}
		cout<<ans-1<<'\n';
	}
}
