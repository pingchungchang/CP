#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	io
	pii ver[4] = {make_pair(1,1),make_pair(1,2),make_pair(1,3),make_pair(1,4)};
	pii hor[4] = {make_pair(3,1),make_pair(3,3),make_pair(4,1),make_pair(4,3)};
	int p1 = 0,p2 = 0;
	string s;
	getline(cin,s);
	for(auto i:s){
		if(i == '0'){
			cout<<ver[p1].fs<<' '<<ver[p1].sc<<'\n';
			p1++;
		}
		else{
			cout<<hor[p2].fs<<' '<<hor[p2].sc<<'\n';
			p2++;
		}
		p1 %=4;
		p2 %=4;
//		cout<<p1<<' '<<p2<<',';
	}
}

