#include <iostream>
#include <set>
#define f first
#define s second
using namespace std;

int main (){
    int N, M, total=0;
    cin>>N>>M;
    set<pair<int, int>>milk; //price, amount

    for (int i=0; i<M; i++){
        int p, a; //price, amout
        cin>>p>>a;
        if (total<N) {
            milk.insert(make_pair(p, min(N-total, a)));
        } else {
            auto itr = milk.begin();
            while (a >= N-total && p < (*itr).f && itr!=milk.end()) {
                //p better than itr.first
                if ((*itr).s <= a) {//enough
                    total -= a;
                    itr++;
                    milk.erase(itr-1);
                }
            }
        }
    }

}