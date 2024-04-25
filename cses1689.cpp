#include <bits/stdc++.h>
using namespace std;


string in = "1	52	13	34	3	54	11	24 14	33	2	53	12	23	56	9 51 64	35	4	55	10	25	22 32	15	42	39	36	5	8	57 63	50	37	6	41	44	21	26 16	31	40	43	38	7	58	45 49	62	29	18	47	60	27	20 30	17	48	61	28	19	46	59 ";
int main(){
    stringstream ss(in);
    int v[8][8];
    for(int i = 0;i<8;i++)for(int j = 0;j<8;j++)ss>>v[i][j];
    int a,b;
    cin>>a>>b;
    a--,b--;
    int dif = v[b][a];
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++)cout<<(v[i][j]+64-dif)%64+1<<' ';
        cout<<'\n';
    }
    return 0;
}
