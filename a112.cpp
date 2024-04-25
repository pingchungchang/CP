#include <bits/stdc++.h>
using namespace std;

struct place{
	string name;
	vector<pair<string,int>> animals;
	place(string s){
		name = s;
	}
	place(){}
};
vector<place> places;
void putin(int now,pair<string,int> p){
	for(auto &i:places[now].animals){
		if(i.first == p.first){
			i.second += p.second;
			return;
		}
	}
	places[now].animals.push_back(p);
	return;
}
int main(){
	int n;
	cin>>n;
	map<string,int> mp;
	for(int i = 0;i<n;i++){
		string ani,pos;
		int num;
		cin>>ani>>num>>pos;
		if(mp.count(pos) == 0){
			mp[pos] = places.size();
			places.push_back(place(pos));
		}
		int k = mp[pos];
		putin(k,make_pair(ani,num));
	}
	for(auto i:places){
		cout<<i.name<<":";
		for(int j = 0;j<i.animals.size();j++){
			cout<<i.animals[j].first<<' '<<i.animals[j].second;
			if(j != i.animals.size()-1)cout<<',';
			else cout<<'\n';
		}
	}
}
