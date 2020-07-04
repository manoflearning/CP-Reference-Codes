#include <iostream>
#include <stack>
using namespace std;

const int MAX = 1e5;

int N;
stack<int> sort;
bool visited[MAX + 5], isCycle;

void topological_sort() {
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i);
	}

	if (isCycle) cout << 0;
	else {
		while (!sort.empty()) {
			cout << sort.top() << '\n';
			sort.pop();
		}
	}
}

void dfs(int v) {
	visited[v] = true;
	for (int next : adj[v]) {
		if (!visited[next]) dfs(next);
		//visited[next]�� ���� ���� next�� ���� finish[next]�� �����̶��, �̴� ����Ŭ�� �������� ���Ѵ�. 
		//�׷����� ����Ŭ�� ������ ��� ���� ���� ������ ���ǵ��� �ʴ´�.
		else if (!finish[next]) isCycle = true;
	}
	finish[v] = true;
	sort.push(v);
}
