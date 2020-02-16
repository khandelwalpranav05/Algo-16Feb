#include <iostream>

using namespace std;

int factorial(int n) {

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}

	return ans;
}

int main() {

	int n = 5;
	int r = 2;

	// int nfact = 1;

	// for (int i = 1; i <= n; i++) {
	// 	nfact = nfact * i;
	// }

	// int rfact = 1;
	// for (int i = 1; i <= r; i++) {
	// 	rfact = rfact * i;
	// }

	// int nrfact = 1;
	// for (int i = 1; i <= (n - r); i++) {
	// 	nrfact = nrfact * i;
	// }

	// int total = nfact / (rfact * nrfact);
	// cout << total << endl;

	int nfact = factorial(n);
	int rfact = factorial(r);
	int nrfact = factorial(n - r);
	int total = nfact / (rfact * nrfact);
	cout << total << endl;

	cout << factorial(n) / (factorial(r)*factorial(n - r)) << endl;

	return 0;
}