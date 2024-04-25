#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> hors;
map<int,vector<int>> vers;
map<tuple<int,int>,int> goneto;
int main(){
	int h,w,n;
	cin>>h>>w>>n;
	pair<int,int> xx;
	pair<int,int> tar;
	cin>>xx.first>>xx.second>>tar.first>>tar.second;
	queue<tuple<int,int,int>> q;
	for(int i  =0;i<n;i++){
		int a,b;
		cin>>a>>b;
		hors[a].push_back(b);
		vers[b].push_back(a);
	}
	for(auto &it:hors){
		sort(it.second.begin(),it.second.end());
	}
	for(auto &it:vers){
		sort(it.second.begin(),it.second.end());
	}
	q.push(make_tuple(xx.first,xx.second,0));
	goneto[make_tuple(xx.first,xx.second)] = 0;
	while(!q.empty()){
		tuple<int,int,int> buf = q.front();
		q.pop();
		pair<int,int> now = make_pair(get<0>(buf),get<1>(buf));
		int mv = get<2>(buf);
		if(now.first == tar.first&&now.second == tar.second){
			cout<<mv;
			return 0;
		}
		if(hors.count(now.first) != 0){
			vector<int> &v = hors[now.first];
			int pos = upper_bound(v.begin(),v.end(),now.second)-v.begin();
			if(pos != v.size()&&goneto.count(make_tuple(now.first,v[pos]-1)) == 0){
				goneto[make_tuple(now.first,v[pos]-1)] = mv+1;
				q.push(make_tuple(now.first,v[pos]-1,mv+1));
			}
			pos--;
			if(pos >= 0&&goneto.count(make_tuple(now.first,v[pos]+1)) == 0){
				goneto[make_tuple(now.first,v[pos]+1)] = mv+1;
				q.push(make_tuple(now.first,v[pos]+1,mv+1));
			}
		}
		if(vers.count(now.second) != 0){
			vector<int> &v = vers[now.second];
			int pos = upper_bound(v.begin(),v.end(),now.first)-v.begin();
			if(pos != v.size()&&goneto.count(make_tuple(v[pos]-1,now.second)) == 0){
				goneto[make_tuple(v[pos]-1,now.second)] = mv+1;
				q.push(make_tuple(v[pos]-1,now.second,mv+1));
			}
			pos--;
			if(pos >=0&&goneto.count(make_tuple(v[pos]+1,now.second)) == 0){
				goneto[make_tuple(v[pos]+1,now.second)] = mv+1;
				q.push(make_tuple(v[pos]+1,now.second,mv+1));
			}
		}
	}
	cout<<-1;
	return 0;
}
