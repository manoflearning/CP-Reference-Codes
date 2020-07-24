#include <iostream>
#include <vector>
using namespace std;

const int MAXV = 2 * 1e5;

vector<int> adj[MAXV + 5];
bool used[MAXV + 5];
int sz[MAXV + 5], dep[MAXV + 5], cdtree[MAXV + 5];

void cd(int now, int prv);
int getSize(int now, int prv);
int getCent(int now, int prv, int cnt);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cd(0, -1);

	return 0;
}

void cd(int now, int prv) {
	int cnt = getSize(now, prv);
	int cent = getCent(now, prv, cnt);
	
	cdtree[now] = prv; //��Ʈ���̵� Ʈ�� �󿡼� ��Ʈ ����� ������ -1�� ǥ�õ�
	used[cent] = true;

	for (auto i : adj[cent])
		if (!used[i]) cd(i, cent);
}

int getSize(int now, int prv) {
	sz[now] = 1;
	for (auto i : adj[now]) {
		if (used[i] || prv == i) continue;
		sz[now] += getSize(i, now);
	}
	return sz[now];
}

int getCent(int now, int prv, int cnt) {
	for (auto& i : adj[now]) {
		if (used[i] || i == prv) continue;
		if (sz[i] > cnt / 2) return getCent(i, now, cnt);
	}
	return now;
}
