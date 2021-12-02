#include<iostream>
#include<vector>
#include<cstring>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int n, ans = 0x3f3f3f3f;
int tmp;
int a1[N], a2[N], b1[N], b2[N];
int main() {
	scanf("%d", &n);
	memset(a1, 0, sizeof(a1));
	memset(a2, 0, sizeof(a2));
	memset(b1, 0, sizeof(b1));
	memset(b2, 0, sizeof(b2));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a1[i]);
		b1[i]=b1[i-1]+a1[i];
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a2[i]);

	if (n == 1) printf("%d\n", 0);
	else {
		int tmp = 0;
		for (int i = n; i > 0; i--) {
			tmp += a2[i];
			b2[i] = tmp;
		}
		for (int i = n ; i > 0; i--) {
			if (max(b2[1] - b2[i], b1[n] - b1[i]) < ans) {
				ans = max(b2[1] - b2[i], b1[n] - b1[i]);
			}
		}
		cout << ans << "\n";

	}
	return 0;
}
