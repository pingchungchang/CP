#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
bitset<mxn> isp;
vector<int> small,big;
bitset<mxn> del;
int sq;
int n;
int cnt = 0;

int A(int k){
	if(k>n)return 0;
	cout<<"A "<<k<<endl;
	int re;
	cin>>re;
	return re;
}
int B(int k){
	if(k>n)return 0;
	cout<<"B "<<k<<endl;
	for(int i = k;i<=n;i+=k){
		if(!del[i])cnt--;
		del[i] = true;
	}
	int re;
	cin>>re;
	return re;
}
void C(int k){
	cout<<"C "<<k<<endl;
	exit(0);
}

int find_big(){
	int pre = 0;
	for(int i = 0;i<big.size();i++){
		B(big[i]);
		if(i%sq == sq-1){
			if(cnt != A(1)){
				for(int j = pre;j<=i;j++){
					if(A(big[j]))return big[j];
				}
				//assert(false);
			}
			else pre = i+1;
		}
	}
	if(cnt != A(1)){
		for(int i = pre;i<big.size();i++){
			if(A(big[i]))return big[i];
		}
		//assert(false);
	}
	else return 1;
}

int main(){
	cin>>n;
	sq = sqrt(n);
	for(int i = 2;i<=n;i++){
		if(!isp[i]){
			if(i<=sq)small.push_back(i);
			else big.push_back(i);
			for(int j = i+i;j<=n;j+=i)isp[j] = true;
		}
	}
	sq = sqrt(big.size());
	cnt = n;
	ll ans = 1;
	for(auto &i:small){
		B(i);
		int now = i;
		while(A(now)){
			now *= i;
		}
		now /= i;
		ans *= now;
	}
	/*
	cerr<<"cnt:"<<cnt<<endl;
	for(int i = 1;i<=n;i++)cerr<<del[i];cout<<endl;

   */

	if(cnt == A(1)){
		ans *= find_big();
		C(ans);
		//assert(false);
	}
	else{
		for(auto &i:big){
			if(A(i) == 2){
				ans *= i;
				C(ans);
			}
		}
		C(ans);
		//assert(false);
	}
}
