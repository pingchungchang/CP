#include <bits/stdc++.h>
using namespace std;

#define ll long long
int findhead(vector<int> &v,int i){
	while(v[i] != i){
		v[i] = v[v[i]];
		i= v[i];
	}
	return i;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i =0;i<n;i++){
		v[i] = i;
	}
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		int ha = findhead(v,a);
		int hb = findhead(v,b);
		v[ha] = hb;
	}
	vector<int> roads;
	for(int i =0;i<n;i++){
		if(v[i] == i)roads.push_back(i);
	}
	cout<<roads.size()-1<<'\n';
	for(int i =0;i<roads.size()-1;i++){
		cout<<roads[i]+1<<' '<<roads[i+1]+1<<'\n';
	}
}
