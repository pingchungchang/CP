#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n,m;
	cin>>n>>m;
	vector<pii> v(m-1);
	pii cmp;
	cin>>cmp.fs>>cmp.sc;
	for(int i = 0;i<m-1;i++)cin>>v[i].fs>>v[i].sc;
	pii p = make_pair(1,1);
	vector<vector<int>> arr(2,vector<int>(n+1,0));
	for(auto i:v){
		if(i.fs != cmp.fs&&i.sc != cmp.fs){
			arr[0][i.fs]++;
			if(i.fs != i.sc)arr[0][i.sc]++;
		}
		else p.fs++;
		if(i.fs != cmp.sc&&i.sc != cmp.sc){
			arr[1][i.fs]++;
			if(i.fs != i.sc)arr[1][i.sc]++;
		}
		else p.sc++;
	}
	for(auto i:arr[0]){
		if(i+p.fs == m){
			cout<<"Yes";
			return 0;
		}
	}
	for(auto i:arr[1]){
		if(i+p.sc == m){
			cout<<"yes";
			return 0;
		}
	}
	cout<<"no";
	return 0;
}

/*
6 9
6 2
4 2
3 6
4 6
2 6
1 4
2 6
4 5
4 2
*/
