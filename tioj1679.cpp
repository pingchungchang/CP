#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


map<char,int> col;

int main(){
	col['C'] = 0,col['D'] = 1,col['H'] = 2,col['S'] = 3;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<pair<char,int>> v;
	for(int i = 0;i<n;i++){
		string a;
		int b;
		cin>>a>>b;
		v.push_back({a[0],b});
	}
	sort(v.rbegin(),v.rend(),[&](pair<char,int> a,pair<char,int> b){
			if(a.sc != b.sc)return a.sc<b.sc;
			else return col[a.fs]<col[b.fs];});
	int m;
	cin>>m;
	cout<<v[m-1].fs<<' '<<v[m-1].sc;
}
