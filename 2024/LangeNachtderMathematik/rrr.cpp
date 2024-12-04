#include <bits/stdc++.h>

using namespace std;
#define FOR(i)  for(ll i = (0); i < (13); i++)
#define ll long long



int main (){
    ll sum = 0;

    FOR(a){
        FOR(b){
            if (a+b>12) break;
            FOR(c){
                if (a+b+c>12) break;
                FOR(d){
                    if (a+b+c+d>12) break;
                    FOR(e){
                        if (a+b+c+d+e>12) break;
                        FOR(f){
                            if (a+b+c+d+e+f>12) break;
                            FOR(g){
                                if (a+b+c+d+e+f+g>12) break;
                                FOR(i){
                                    if (a+b+c+d+e+f+g+i>12) break;
                                    FOR(j){
                                        if (a+b+c+d+e+f+g+i+j>12) break;
                                        FOR(k){
                                            if (a+b+c+d+e+f+g+i+j+k>12) break;
                                            FOR(l){
                                                if (a+b+c+d+e+f+g+i+j+k+l>12) break;
                                                FOR(m){
                                                    if (a+b+c+d+e+f+g+i+j+k+l+m>12) break;
                                                    FOR(n){
                                                        if (a+b+c+d+e+f+g+i+j+k+l+m+n>12) break;
                                                        FOR(o){
                                                            if (a+b+c+d+e+f+g+i+j+k+l+m+n+o>12) break;
                                                            FOR(p){
                                                                if (a+b+c+d+e+f+g+i+j+k+l+m+n+o+p>12) break;
                                                                FOR(q){
                                                                    if (a+b+c+d+e+f+g+i+j+k+l+m+n+o+p+q>12) break;
                                                                    FOR(r){
                                                                        if (a+b+c+d+e+f+g+i+j+k+l+m+n+o+p+q+r>12) break;
                                                                        FOR(s){
                                                                            if (a+b+c+d+e+f+g+i+j+k+l+m+n+o+p+q+r+s==12){
                                                                                sum++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<sum<<endl;


}