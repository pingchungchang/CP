#include <bits/stdc++.h>
using namespace std;
#define ll long long

mt19937 seed(time(NULL));
#define rnd(l,r) uniform_int_distribution<ll>(l,r)(seed)

/*
ofstream fout("input.txt");
#define cout fout
const ll inf2 = 1e15;
const ll inf1 = 1e9;

*/

const int inf = 1e9;
vector<int> v;

void make(){
	cout<<1;
	for(int i = 0;i<3;i++)cout<<rnd(0,1);cout<<endl;
	return;
}

int main(){
	srand(time(NULL));
	int n = rnd(1,10);
	cout<<n<<' '<<rnd(1,20)<<' '<<rnd(1,20)<<endl;
	for(int i = 0;i<n;i++){
		cout<<rnd(1,10)<<' ';
	}cout<<endl;
	for(int i = 1;i<n;i++){
		cout<<rnd(1,10)<<' ';
	}cout<<endl;
	return 0;
}
