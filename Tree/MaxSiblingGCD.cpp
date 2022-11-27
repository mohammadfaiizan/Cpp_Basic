// C++ program to find the maximum
// GCD of the siblings of a binary tree

#include <bits/stdc++.h>
using namespace std;

// Function to find maximum GCD
int max_gcd(vector<pair<int, int> >& v)
{
	// No child or Single child
	if (v.size() == 1 || v.size() == 0)
		return 0;

	sort(v.begin(), v.end());

	// To get the first pair
	pair<int, int> a = v[0];
	pair<int, int> b;
	int ans = INT_MIN;
	for (int i = 1; i < v.size(); i++) {
		b = v[i];

		// If both the pairs belongs to
		// the same parent
		if (b.first == a.first)

			// Update ans with the max
			// of current gcd and
			// gcd of both children
			ans
				= max(ans,
					__gcd(a.second,
							b.second));

		// Update previous
		// for next iteration
		a = b;
	}
	return ans;
}

// Driver function
int main()
{
	vector<pair<int, int> > v;
	v.push_back(make_pair(5, 4));
	v.push_back(make_pair(5, 8));
	v.push_back(make_pair(4, 6));
	v.push_back(make_pair(4, 9));
	v.push_back(make_pair(8, 10));
	v.push_back(make_pair(10, 20));
	v.push_back(make_pair(10, 30));

	cout << max_gcd(v);
	return 0;
}
