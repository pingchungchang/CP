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

vector<string> names;
vector<pii> v;
int n;

string get_str(){
	int len = rnd(1,4);
	string re;
	while(len--)re += 'a'+rnd(0,25);
	return re;
}

pii get_edge(){
	int a = rnd(0,n-1);
	int b;
	while((b = rnd(0,n-1)) == a)b = rnd(0,n-1);
	return pii(a,b);
}

int main(){
	n = rnd(1,20);
	for(int i = 0;i<n;i++){
		string tmp;
		while(find(names.begin(),names.end(),(tmp = get_str())) != names.end());
		names.push_back(tmp);
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)if(i != j)v.push_back(pii(i,j));
	}
	random_shuffle(v.begin()+n,v.end());
	int m = rnd(n,v.size());
	while(v.size()>m)v.pop_back();
	cout<<n<<' '<<v.size()<<endl;
	for(auto &i:names)cout<<i<<' '<<rnd(0,65536)<<endl;
	for(auto &i:v)cout<<names[i.fs]<<' '<<names[i.sc]<<endl;
}
