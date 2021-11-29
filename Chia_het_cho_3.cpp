#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

long long n;
ll sum = 0, _n, ans, E = 0;

int digi(int E) {
	return (ans / (ll)pow(10, E - 1)) % 10;
}

void process()
{
	_n = n;
	ans = n;
	while (_n != 0) {
		sum += _n % 10;
		_n /= 10;
		E++;
	}
	int tmp = (3 - sum % 3);
	for (int i = E; i >= 1; --i) {
		if (0 < digi(i) + tmp && digi(i) + tmp <= 9) {
			while (0 < digi(i) + tmp && digi(i) + tmp <= 9) {
				ans += tmp * (ll)(pow(10, i - 1));
				tmp = 3;
			}
			break;
		}
	}
	if (ans == n) {
		tmp = 3 - tmp;
		if (tmp == 0) tmp = 3;
		for (int i = 1; i <= E; ++i) {
			if (0 < digi(i) - tmp && digi(i) - tmp <= 9) {
				ans -= tmp * (ll)pow(10, i - 1);
				break;
			}
		}
	}
	cout << ans;
}
int main() {
	cin >> n;
	process();
	return 0;
}