#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 330;
vector<string> all;
mf_graph<int> graph;

bool isp(string &s){
	for(int i = 0;i<s.size();i++){
		if(s[i] != s.end()[-1-i])return false;
	}
	return true;
}
inline bool cover(string &a,string &b){
	for(int i = 0;i+b.size()<=a.size();i++){
		if(a.substr(i,b.size()) == b)return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		string now;
		for(int j = i;j<s.size();j++){
			now += s[j];
			if(isp(now))all.push_back(now);
		}
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	int n = all.size();
	graph = mf_graph<int>(n*2+2);
	//for(auto &i:all)cout<<i<<' ';cout<<endl;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i == j)continue;
			if(cover(all[i],all[j]))graph.add_edge(i+1,j+n+1,1);
			if(cover(all[i],all[j])){
				//cout<<all[i]<<' '<<all[j]<<endl;
			}
		}
	}
	for(int i = 0;i<n;i++)graph.add_edge(0,i+1,1);
	for(int i = 0;i<n;i++)graph.add_edge(i+n+1,n*2+1,1);
	cout<<n-graph.flow(0,n*2+1);
}
