#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<ll> primes;

int main(){
	for(int i = 2;i<978;i++){
		bool flag = true;
		for(int j = 2;j<i;j++){
			if(i%j == 0)flag = false;
		}
		if(flag)primes.push_back(i);
	}
	/*
	srand(time(NULL));
	random_shuffle(primes.begin(),primes.end());

   */
	int sz = 22;
	vector<vector<ll>> groups(sz);
	float sum[sz];
	for(auto &i:sum)i = 1;
	int pt = 0;
	int dx = 1;
	for(auto &i:primes){
		groups[pt].push_back(i);
		sum[pt] *= i;
		//assert(sum[pt]<1e18);
		pt += dx;
		if(pt == -1){
			pt = 0,dx = 1;
		}
		else if(pt == groups.size()){
			pt = groups.size()-1;
			dx= -1;
		}
		if(pt>=groups.size())pt -= groups.size();
	}
	for(int i = 0;i<groups.size();i++){
		cout<<sum[i]<<' ';
		for(auto &j:groups[i])cout<<j<<' ';cout<<'\n';
	}
	cout<<groups.size();
	return 0;
}
