#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll inf = 2e18;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll A,M,L,R;
	cin>>A>>M>>L>>R;
	A += inf,L += inf,R += inf;
	A %= M;
	cout<<(R-A)/M-(L-1-A)/M;
}
