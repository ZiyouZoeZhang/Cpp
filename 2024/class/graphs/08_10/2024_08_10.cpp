/*

Part1、「「最小生成树」之kruskal算法习题  Wormhole Sort /  Moocast方法讲解；
Part2、「最小生成树」之prim算法，主要包括
	(1）prim算法步骤、代码实现；
	(2）prim算法与Dijkstra算法的异同点；
Part3、「最小生成树」总结。
	(1）kruskal算法与prim算法的异同点；
	(2）生成树算法扩展应用以及标准步骤。
		1）抽象出节点、边，形成图结构；
		2） 抽象出联通块并形成树结构，进一步形成冗余边的剔除；
		3） 难点1在构建图，一些竞赛题会基于条件构建有限图结构，形成时间复杂度的降低。

 */

//demonstratio of prim's algorithm
#include <bits/stdc++.h>
using namespace std;

long long prim(const vector<vector<pair<int, int>>> &neighbors) {
	const int n = neighbors.size();  // just a shorthand
	long long min_cost = 0;
	vector<long long> dist(n, std::numeric_limits<long long>().max());
	dist[0] = 0;
	std::priority_queue<pair<long long, int>> q;
	q.push({0, 0});
	vector<bool> visited(n);
	int added = 0;
	while (added < n) {
		if (q.empty()) { return -1; }
		auto [curr_cost, v] = q.top();
		q.pop();
		curr_cost *= -1;
		if (dist[v] < curr_cost) { continue; }

		added++;
		visited[v] = true;
		min_cost += curr_cost;
		for (auto &[next, n_cost] : neighbors[v]) {
			if (!visited[next] && n_cost < dist[next]) {
				dist[next] = n_cost;
				q.push({-n_cost, next});
			}
		}
	}
	return min_cost;
}

int main (){
    int N;
    vector<vector<pair<int, int>>> neighbors;

    for (int i=0; i<N; i++){
        sort(neighbors[i].begin(), neighbors[i].end(), [](pair<int, int> a, pair<int, int>  b){return a.second < b.second;});
    }

    cout<< prim(neighbors)<<endl;

    return 0;
}