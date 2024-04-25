#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
vector<pii> v;

int gcd(int a,int b){
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
bool check(pii now,int t){
	for(int i = 0;i<t;i++){
		int dif = abs(v[i].s-now.s);
		if(dif%gcd(v[i].f,now.f) != 0)return false;
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	v = vector<pii>(n);
	for(int i = 0;i<n;i++)cin>>v[i].f>>v[i].s;
	for(int asd = 1;asd<n;asd++){
		if(check(v[asd],asd) == false){
			v[asd].s = -1;
			for(int i = 0;i<v[asd].f;i++){
				if(check(make_pair(v[asd].f,i),asd) == true){
					v[asd].s = i;
					break;
				}
			}
		}
		else continue;
	}
	for(auto i:v)cout<<i.first<<' '<<i.second<<'\n';
	return 0;
}
