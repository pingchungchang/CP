#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
int main(){
    pii a,b;
    cin>>a.fs>>a.sc>>b.fs>>b.sc;
    pii d1 = make_pair(b.fs-a.fs,b.sc-a.sc);
    pii d2 = make_pair(-d1.sc,d1.fs);
    pii c = make_pair(b.fs+d2.fs,b.sc+d2.sc);
    pii d = make_pair(c.fs+a.fs-b.fs,c.sc+a.sc-b.sc);
    cout<<c.fs<<' '<<c.sc<<' '<<d.fs<<' '<<d.sc;
}
