#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int MAX_N = 100 + 10;
const int MAX_VALUE = int(1e6) + 10, INF = ~0U >> 3;

int a[MAX_N];

int dp[MAX_N][MAX_VALUE];

int work() {
	int A, n;
	cin >> A >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int mx = a[n - 1] + 1;
	A = min(A, mx);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= mx; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][A] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= mx; ++j) {
			int c = dp[i][j];
			if (c == INF)
				continue;
			if (j > a[i]) {
				dp[i + 1][min(j + a[i], mx)] = min(dp[i + 1][min(j + a[i], mx)],
						c);
				continue;
			}
			//erase
			dp[i + 1][j] = min(dp[i + 1][j], c + 1);
			//eat
			if (j > 1) {
				int k = j;
				while (k <= a[i]) {
					k += k - 1;
					++c;
				}
				k += a[i];
				k = min(k, mx);
				dp[i + 1][k] = min(dp[i + 1][k], c);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= mx; ++i) {
		ans = min(ans, dp[n][i]);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		cout << work() << endl;
	}
}
