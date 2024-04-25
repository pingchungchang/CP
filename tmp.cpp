#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
mt19937 seed(time(NULL));
#define rnd(l,r) uniform_int_distribution<int>(l,r)(seed)

const int mxn = 1e6;

int main(){
	srand(time(NULL));
	int n = rnd(1,mxn);
	cout<<n<<" 1 1"<<endl;
	while(n--)cout<<rnd(1,mxn*1000)<<' ';cout<<endl;
}
