#include <bits/stdc++.h>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("vacation.in");

ofstream fout("vacation.out");


const int INF = 1e9;
const int MAXN = 200;

int N, M, K, Q;
int dist[MAXN][MAXN];

void floydWarshall() {
    // Initialize distances
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    // Read flights and set distances
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        dist[u][v] = min(dist[u][v], d);
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {

    fin >> N >> M >> K >> Q;

    floydWarshall();
    
    int validTripCount = 0;
    int totalCost = 0;
    
    for (int i = 0; i < Q; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        
        int minCost = INF;
        
        // Check cost through each hub
        for (int i = 0; i < K; i++) {
            int hubIndex = i;
            if (dist[a][hubIndex] < INF && dist[hubIndex][b] < INF) {
                minCost = min(minCost, dist[a][hubIndex] + dist[hubIndex][b]);
            }
        }
        
        if (minCost < INF) {
            validTripCount++;
            totalCost += minCost;
        }
    }
    
    fout << validTripCount << endl;
    fout << totalCost << endl;

    return 0;
}
