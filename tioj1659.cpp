#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5050;
vector<int> primes;
bitset<mxn> isp;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
		}
	}
	int n;
	while(cin>>n){
		cout<<"primes between 1 ~ "<<n<<": ";
		for(auto &i:primes){
			if(i<=n)cout<<i<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
