#include <bits/stdc++.h>
using namespace std;

mt19937 seed(time(NULL));
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define rnd(l,r) uniform_int_distribution<int>(l,r)(seed)

const int inf = 100;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N = rnd(1,10),Q = rnd(1,10);
	cout<<N<<' '<<Q<<endl;
	for(int i = 1;i<=N;i++)cout<<rnd(1,inf)<<' ';cout<<endl;
	for(int i = 1;i<=Q;i++){
		int p = rnd(0,N-1),v = rnd(1,inf);
		cout<<p<<' '<<v<<endl;
	}
	return 0;
}
