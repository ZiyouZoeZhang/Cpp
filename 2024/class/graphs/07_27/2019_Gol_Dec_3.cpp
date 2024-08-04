//Moortal Cowmbat
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M, K;
string s;

int main (){
    cin>>N>>M>>K>>s;

    ll v[M][M];
    ll mi[30], f[N+1];
    ll ps[N][M]; //把0~N 改成M 的代价
    memset (mi,0x3f,sizeof(mi));
	memset (f,0x3f,sizeof(f));
    memset(ps, 0, N*M);

    for (ll i=0; i<M; i++){
        for (ll j=0; j<M; j++){
            cin>>v[i][j];
        }
    }

    for (ll k=0; k<M; k++){
        for (ll i=0; i<M; i++){
            for (ll j=0; j<M; j++){
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    for (int i=0;i<M;i++)
		for (int j=1;j<=N;j++)
			ps[i][j]=v[s[j]-'a'][i]+ps[i][j-1];
    
    f[0]=0;
	for (ll i=K;i<=N;i++){
		for (ll j=0;j<M;j++) {
			mi[j] = min(mi[j]+v[s[i]-'a'][j], f[i-K]+ (ps[j][i]-ps[j][i-K]));
            f[i] = min(f[i], mi[j]);
        }
    }
    cout<<f[N-1]<<endl;
	return 0;
}