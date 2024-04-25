#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 2e6;
bitset<mxn> isp;
ll sum = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			sum += i;
			for(int j = i+i;j<mxn;j+=i){
				isp[j] = true;
			}
		}
	}
	cout<<sum;
}
