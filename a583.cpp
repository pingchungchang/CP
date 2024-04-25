#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> v(m);
	for(int i = 0;i<m;i++){
		cin>>v[i].first>>v[i].second;
	}
	int dist = INT_MAX;
	for(int i = 0;i<m;i++){
		for(int j = i+1;j<m;j++){
			int diff = (v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second);
			dist = min(dist,diff);
		}
	}
	double k = sqrt(dist);
	printf("%.4f",k);
}
