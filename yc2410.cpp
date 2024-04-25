#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int check(vector<int> v){
	set<int> st;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int p = 1;
	int s = 0;
	for(int i = 0;i<8;i++){
		cout<<p<<' ';
		s += p;
		p*=3;
	}
	cout<<s*2;
	return 0;
}
