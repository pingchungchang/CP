#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
int n,m;
int turn[256][256];
char a[mxn],b[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	scanf("%d",&t);
	scanf("%s%s",&a,&b);
	n = strlen(a),m = strlen(b);
	int ans[3] = {};
	int p1 = 0,p2 = 0;
	for(int i = 0;i<t;i++){
		ans[a[p1] == 'R'&&b[p2] == 'S'?0:a[p1] =='R'&&b[p2] == 'R'?2:a[p1] == 'R'&&b[p2] == 'P'?1:a[p1] == 'S'&&b[p2] == 'P'?0:a[p1] =='S'&&b[p2] == 'S'?2:a[p1] == 'S'&&b[p2] == 'R'?1:a[p1] == 'P'&&b[p2] == 'R'?0:a[p1] =='P'&&b[p2] == 'P'?2:a[p1] == 'P'&&b[p2] == 'S'?1:0]++;
		p1 = (++p1==n?0:p1);
		p2 = (++p2==m?0:p2);
	}
	cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2];
}
