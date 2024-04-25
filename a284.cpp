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
	int k;
	string s,t;
	node(){}
};
bool cmp(node a,node b){
	if(a.k != b.k)return a.k>b.k;
	else if(a.s != b.s)return a.s<b.s;
	else return a.t<b.t;
}
int main(){
	int n;
	cin>>n;
	vector<node> v(n,node());
	for(int i = 0;i<n;i++){
		cin>>v[i].s>>v[i].t>>v[i].k;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i<n;i++){
		cout<<v[i].s<<' '<<v[i].t<<' '<<v[i].k<<'\n';
	}
}

