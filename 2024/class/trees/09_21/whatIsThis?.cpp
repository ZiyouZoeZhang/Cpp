//ok apparantly covered in platinum??
//link to the source code https://usaco.guide/gold/PURS?lang=cpp#implementation

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		Tree<int> tree;

		int arr_len;
		cin >> arr_len;
		long long inv_num = 0;
		for (int i = 0; i < arr_len; i++) {
			int x;
			cin >> x;
			/*
			 * Calculate the # of elements in the tree
			 * that are greater than x.
			 * (.order_of_key(x) gives the # of elements less than x)
			 */
			inv_num += i - tree.order_of_key(x);
			tree.insert(x);
		}

		cout << inv_num << '\n';
	}
}