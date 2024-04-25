#include <bits/stdc++.h>
using namespace std;

int tar[3] = {2,0,1};
vector<pair<int,int>> mov;
int now = 0;
void move(int n,int p,int np){
	if(n == 0)return;
	move(n-1,3-p-np,np);
	mov.push_back(make_pair(np,p));
	move(n-1,p,3-p-np);
	return;
}
void rec(int n){
	if(n == 0)return;
	if(now == tar[n%3])rec(n-1);
	else{
		move(n-1,3-now-tar[n%3],now);
		mov.push_back(make_pair(now,tar[n%3]));
		now = 3-now-tar[n%3];
		rec(n-1);
	}
}
int main(){
	int n;
	cin>>n;
	rec(n);
	vector<stack<int>> v(3);
	for(int i = n;i>=1;i--){
		v[0].push(i);
	}
	for(auto i:mov){
		printf("ring %d : %c => %c\n",v[i.first].top(),i.first+'A',i.second+'A');
		v[i.second].push(v[i.first].top());
		v[i.first].pop();
	}
	printf("共需%d個移動",mov.size());
}

