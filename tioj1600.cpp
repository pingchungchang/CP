#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
vector<ll> primes;
bitset<mxn> isp;
ll n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
			primes.push_back(i);
		}
	}
	for(auto &i:primes)i *= i;
	cout<<primes.size()<<endl;return 0;
}
