#include "iostream"

using namespace std;

constexpr int maxnum = 1000;

int main() {
	int l = 0, w = 0;
	int a = 0, b = 0;
	cin >> l >> w;

	//��������
	short hs[maxnum][maxnum];

	//��������
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			cin >> hs[i][j];
		}
	}

	//��Χ
	cin >> a >> b;

	//��¼����
	int max = 0;

	//��һ�μ���
	int temp1 = 0;
	int inittemp = 0;
	for (int i1 = 0; i1 < a; i1++) {
		for (int j1 = 0; j1 < b; j1++) {
			inittemp += hs[i1][j1];
		}
	}
	temp1 = inittemp;
	max = max < inittemp ? inittemp : max;

	//�ƶ�
	for (int i = 0; i < l - a + 1; i++) {
		//���ƶ�
		if (i > 0) {
			int tempa = 0, tempb = 0;
			for (int j1 = 0; j1 < b; j1++) {
				tempa += hs[i-1][j1];
			}
			for (int j1 = 0; j1 < b; j1++) {
				tempb+= hs[i+a-1][j1];
			}
			temp1 = temp1 - tempa + tempb;
			max = max < temp1 ? temp1 : max;
		}

		int temp2 = temp1;
		for (int j = 1; j < w - b + 1; j++) {
			int tempa = 0, tempb = 0;
			//���ƶ�
			for (int i1 = 0;i1 <a; i1++) {
				tempa += hs[i + i1][j-1];
			}
			for (int i1 = 0; i1 < a; i1++) {
				tempb += hs[i + i1][j+b-1];
			}
			temp2 = temp2 - tempa + tempb;
			max = max < temp2 ? temp2 : max;
		}
	}

	//���
	cout << max << endl;

	return 0;
}