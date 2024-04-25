#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e7;
bitset<mxn> isp;
vector<int> primes;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
		}
	}
	cout<<primes[n-1];
}
