#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	pll now = make_pair(0,0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	pll dir[4] = {make_pair(1,0),make_pair(0,-1),make_pair(-1,0),make_pair(0,1)};
	int k = 0;
	for(auto i:s){
		if(i == 'S'){
			now.fs += dir[k].fs;
			now.sc += dir[k].sc;
		}
		else{
			k = (k+1)%4;
		}
	}
	cout<<now.fs<<' '<<now.sc;
}

