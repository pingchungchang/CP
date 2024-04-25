#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


vector<int> v;

inline bool check(vector<int> &v){
	bitset<32> ap;
	ap[0] = true;
	int s = 0;
	for(auto &i:v){
		s ^= i;
		if(ap[s])return false;
		ap[s] = true;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1;i<32;i++)v.push_back(i);
	srand(time(NULL));
	while(!check(v))random_shuffle(v.begin(),v.end());
}
