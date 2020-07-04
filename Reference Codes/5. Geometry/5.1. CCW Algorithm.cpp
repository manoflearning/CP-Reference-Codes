#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
};

//ccw �˰���
ll ccw(point a, point b, point c) {
	//����� ��ȯ�ϸ� ccw, ������ ��ȯ�ϸ� cw, 0�� ��ȯ�ϸ� a, b, c�� �� ���� ���� �ִ�.
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

//�� ���� ab�� cd�� �����ϴ°�?
bool isCross(point a, point b, point c, point d) {
	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);
	//�� ���� �� ���� ���� ���� ���
	if (ab == 0 && cd == 0) {
		pii A = { a.x, a.y }, B = { b.x, b.y }, C = { c.x, c.y }, D = { d.x, d.y };
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		return (A <= D && C <= B);
	}
	//�׷��� ���� ���
	else return (ab <= 0 && cd <= 0);
}
