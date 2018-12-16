//2017029589_RyuJibeom_509
//FindingSameKeys

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <set>
#include <vector>

int main(void) {
	int n, m, num;
	scanf("%d %d", &n, &m);
	std::set<int> s1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		s1.insert(num);
	}
	std::set<int> s2;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &num);
		s2.insert(num);
	}
	std::vector<int> v;
	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),std::back_inserter(v));

	printf("%d", v.size());

}