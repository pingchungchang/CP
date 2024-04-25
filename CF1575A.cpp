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
	string s;
	int id;
	node(){}
};
int n,l;
bool cmp(node a,node b){
	for(int i = 0;i<l;i++){
		if(a.s[i] != b.s[i]){
			if((i+1)%2 == 1){
				return a.s[i]<b.s[i];
			}
			else return a.s[i]>b.s[i];
		}
	}
	return a.id<b.id;
}
int main(){
	cin>>n>>l;
	vector<node> v(n,node());
	for(int i = 0;i<n;i++){
		cin>>v[i].s;
		v[i].id = i+1;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i<n;i++)cout<<v[i].id<<' ';
	return 0;
}

