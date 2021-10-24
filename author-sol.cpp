#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// we need to find the minimum element and count its frequency
		// and check if it is possible to change the other elements to the minimum element
		int mn = *min_element(a.begin(), a.end());
		int cnt = count(a.begin(), a.end(), mn);
		bool all = false;
		for (int i = 0; i < n; i++) {
			// case 1: element is equal to the minimum value
			// if the element is equal to the minimum element, then skip 
			// case 2: element is greater than the minimum value
			// if the minimum element is within the range of the results of a[i] % M
			// [0, ceil(a[i] / 2) - 1] (inclusive), then change only the elementst that are
			// greater than the minimum element, otherwise, we need to change all of them
			if (a[i] == mn) {
				continue;
			} else {
				if (a[i] <= 2LL * mn) {
					all = true;
					break;
				}
			}
		}
		cout << (!all ? n - cnt : n) << '\n';
	}
	return 0;
}
