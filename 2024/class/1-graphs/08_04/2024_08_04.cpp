/*

Part1  最短距离算法习题课。本次课程学习了3道与最短距离有关的习题，覆盖第2次课后作业的关键习题。
	1、基于特定条件构建图结构边，例如基于X轴坐标相同或者Y轴坐标相同的平面点之间；
	2、利用BFS处理树结构多个点之间同时移动并抽象为最短距离；
	3、基于Dijkstra算法计算最短路径数量以及最短/最长路径边数量；
	4、基于Dijkstra算法处理最短路径时，也可以类似BFS，存储任意节点最短路径时的父节点。
Part2  Disjoint Set Union 结构
	1、并查集适用的问题场景；
	2、并查集的C++自定义代码实现结构DisjointSets（并查集标准结构）,包括parent与sizes成员结构，find、unite与conneted成员方法；

*/

#include <bits/stdc++.h>
using namespace std;

struct DisjointSets {

	vector<int> parents;
	vector<int> sizes;

	DisjointSets(int size) : parents(size), sizes(size, 1) {

		for (int i = 0; i < size; i++) { parents[i] = i; }

	}


	/** @return the "representative" node in x's component */

	int find(int x) {

		return parents[x] == x ? x : (parents[x] = find(parents[x]));

	}

	/** @return whether the merge changed connectivity */

	bool unite(int x, int y) {

		int x_root = find(x);

		int y_root = find(y);

		if (x_root == y_root) { return false; }

 

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }

		sizes[x_root] += sizes[y_root];

		parents[y_root] = x_root;

		return true;

	}

 

	/** @return whether x and y are in the same connected component */

	bool connected(int x, int y) { return find(x) == find(y); }

};