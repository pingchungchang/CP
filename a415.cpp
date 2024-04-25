#include <bits/stdc++.h>
using namespace std;

struct node{
	int id;
	int col;
	vector<pair<int,int>> paths;
	node(){
		id = 0;
		col = 0;
	}
};

map<tuple<int,int>,vector<pair<tuple<int,int>,int>>> mp;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> lens(n);
	for(int i = 0;i<n;i++){
		int l,k;
		cin>>l>>k;
		for(int j = 1;j<=k;j++){
			int x;
			cin>>x;
			if(j == 1)continue;
			tuple<int,int> now = make_tuple(l,j);
			tuple<int,int> form = make_tuple(l,j-1);
			mp[now].push_back(make_pair(form,x));
			mp[form].push_back(make_pair(now,x));
		}
		lens[i] = k;
	}
	for(int i = 0;i<m;i++){
		int ia,ib,a,b;
		cin>>ia>>a>>ib>>b;
		tuple<int,int> ma = make_tuple(ia,a);
		tuple<int,int> mb = make_tuple(ib,b);
		mp[ma].push_back(make_pair(mb,0));
		mp[mb].push_back(make_pair(ma,0));
	}
	set<tuple<int,int>> goneto;
	int hour,minute,sr,sc,er,ec;
	cin>>hour>>minute>>sr>>sc>>er>>ec;
	
}
