#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cin>>n>>m;
	if(m == 0){
		cout<<0;
		return 0;
	}
	vector<int> ver(n+1);
	for(int i = 0;i<n;i++)cin>>ver[i];
	ver[n] = 1e9;
	vector<pair<int,pair<int,int>>> hor(m);
	for(int i = 0;i<m;i++)cin>>hor[i].second.first>>hor[i].second.second>>hor[i].first;
	sort(hor.begin(),hor.end());
	vector<int> lim;
	int p = 0;
	while(p != m){
		vector<pair<int,int>> v;
		int p2 = p;
		while(p2<m&&hor[p2].first == hor[p].first){
			v.push_back(make_pair(hor[p2].second.first,hor[p2].second.second));
			p2++;
		}
		p = p2;
		int form = 1;
		for(int i = 0;i<v.size();i++){
			if(v[i].first == form){
				form = v[i].second+1;
			}
			else break;
		}
		lim.push_back(form);
	}
//	for(int i = 0;i<lim.size();i++)cout<<lim[i]<<' ';
//	return 0;
	int ans = INT_MAX;
	sort(lim.begin(),lim.end());
	for(int i = n;i>=0;i--){
		int del = upper_bound(lim.begin(),lim.end(),ver[i])-lim.begin();
		if(del<0)del =0;
		ans = min(ans,(int)lim.size()-del+i);
//		cout<<lim.size()-del+i<<' ';
	}
	cout<<ans;
}
