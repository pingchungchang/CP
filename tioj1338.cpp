#include "lib1338.h"
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define mid ((int)(l+r)>>1)

using namespace std;
const int mxn = 1e6+10;
pll st[mxn][20];
ll arr[mxn];
int n;

void init(int N, long long C[]){
	for(int i = 0;i<N;i++)arr[i] = C[i];
	n = N;
	for(int i = 0;i<N;i++){
		st[i][0].fs = st[i][0].sc = C[i];
	}
	for(int i = 1;i<20;i++){
		for(int j = 0;j+(1<<i)<=N;j++){
			st[j][i].fs = __gcd(st[j][i-1].fs,st[j+(1<<(i-1))][i-1].fs);
			st[j][i].sc = min(st[j][i-1].sc,st[j+(1<<(i-1))][i-1].sc);
		}
	}
	return;
}

pll ask(int l,int r){
	int d = r-l+1;
	int h = 0;
	for(int i = 0;i<20;i++){
		if(d&(1<<i))h = i;
	}
	pll re;
	re.fs = __gcd(st[l][h].fs,st[r-(1<<h)+1][h].fs);
	re.sc = min(st[l][h].sc,st[r-(1<<h)+1][h].sc);
	return re;
}

int query(int L, int R){
	/*
	pll re = {arr[L],arr[L]};
	for(int i = L;i<R;i++){
		re.fs = __gcd(re.fs,arr[i]);
		re.sc = min(re.sc,arr[i]);
	}
	if(re.fs == re.sc)return true;
	else return false;

   */
	R--;
	auto re = ask(L,R);
	//auto re = getval(0,0,n-1,L,R);
	//cout<<L<<' '<<R<<":"<<re.fs<<' '<<re.sc<<'\n';
	if(re.fs == re.sc)return 1;
	else return 0;
}



/*
long long *C;

int main()
{
    int N, Q, a, b, i;
    scanf("%d", &N);
    if (N <= 0) puts("Invalid N");
    C = (long long*)malloc(N * sizeof(long long));
    for (i = 0; i < N; i++) scanf("%lld", C + i);
    init(N, C);
    scanf("%d", &Q);
    if (N <= 0) puts("Invalid Q");
    while (Q--) {
        scanf("%d%d", &a, &b);
        if (a >= b || a < 0 || b > N) {
            puts("Invalid query");
            break;
        }
        printf("%d\n", query(a, b));
    }
    exit(0);
}

*/

