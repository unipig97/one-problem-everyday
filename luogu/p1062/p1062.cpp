#include <iostream>
#include <cstring>

using namespace std;
/*
we can see that :
	if we think binary 0101 as 3-based,
	that means 1 * 3^0 + 0 * 3^1 + 1 * 3^2 + 0 * 3^3.
	it's so similar!
	so we change n to binary,such as 10 - 1010
	then we calc it as 3-based:  0 * 3^0 + 1 * 3^1 + 0 * 3^2 + 1 * 3^3 = 30.
	That's TURE!
*/
void dec2bin(int val,int dst[12], int& cnt) {
	while (val != 0) {
		dst[cnt++] = val % 2;
		val /= 2;
	}
}

int main() {
	int k,n;
	cin >> k >> n;
	int bin[12];
	int cnt=0;
	dec2bin(n, bin,cnt);

	long long res = 0;
	long long tep = 1;
	for (int i = 0;i<cnt; i++) {
		res += bin[i] * tep;
		tep *= k;
	}
	cout << res << endl;
	return 0;
}