#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	deque<string> dq;
	string in;
	int ans = 0;
	while(cin>>in){
		dq.push_back(in);
		if(dq.size()>3)dq.pop_front();
		if(dq.size() == 3&&dq[0] == "A"&&dq[1] == "5"&&dq[2] == "cow")ans++;
	}
	cout<<ans;
}
