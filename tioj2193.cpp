#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
	int id;
	int cm;
	int val;
	node(){
		id = 0;
		cm = 0;
		val = 0;
	}
};
int cnt(int n){
	int ans = 0;
	while(n != 0){
		if((n&1))ans++;
		n>>=1;
	}
	return ans;
}
bool cmp(node a,node b){
	if(a.cm!=b.cm)return a.cm<b.cm;
	else return a.id<b.id;
}
int main(){
	int n;
	cin>>n;
	vector<node> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].val;
		v[i].id = i;
		v[i].cm = cnt(v[i].val);
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v)cout<<i.val<<' ';
}

