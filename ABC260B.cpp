#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	int id,m,c;
	node(){}
	node(int a,int b,int cc){
		id = a,m = b,c = cc;
	}
};

bool mcmp(node a,node b){
	if(a.m != b.m)return a.m<b.m;
	else return a.id>b.id;
}
bool ccmp(node a,node b){
	if(a.c != b.c)return a.c<b.c;
	else return a.id>b.id;
}
bool tcmp(node a,node b){
	if(a.c+a.m != b.c+b.m)return a.c+a.m<b.c+b.m;
	else return a.id>b.id;
}
int main(){
	io
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	vector<node> v(n);
	for(int i = 0;i<n;i++){
		v[i].id = i+1;
		cin>>v[i].m;
	}
	for(int i = 0;i<n;i++)cin>>v[i].c;
	sort(v.begin(),v.end(),mcmp);
	vector<int> ans;
	for(int i = 0;i<x;i++){
		ans.push_back(v.back().id);
		v.pop_back();
	}
	sort(v.begin(),v.end(),ccmp);
	for(int i = 0;i<y;i++){
		ans.push_back(v.back().id);
		v.pop_back();
	}
	sort(v.begin(),v.end(),tcmp);
	for(int i = 0;i<z;i++){
		ans.push_back(v.back().id);
		v.pop_back();
	}
	sort(ans.begin(),ans.end());
	for(auto i:ans)cout<<i<<'\n';
}

