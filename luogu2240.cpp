#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


struct node{
	int num,val;
	node(){}
	bool operator<(node b)const{
		return val*b.num<num*b.val;
	}
};

priority_queue<node> pq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,c;
	cin>>n>>c;
	for(int i = 0;i<n;i++){
		node tmp;
		cin>>tmp.num>>tmp.val;
		pq.push(tmp);
	}
	long double ans = 0;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		int coef = min(now.num,c);
		c -= coef;
		ans += (long double)now.val/now.num*coef;
	}
	cout<<fixed<<setprecision(2)<<ans;
}
