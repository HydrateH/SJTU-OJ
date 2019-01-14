#include "iostream"
#include "cmath"
#include "list"
#include "map"
#include "numeric"
using namespace std;

//01������
class newTree {
public:
	newTree *p1=nullptr;
	newTree *p2 = nullptr;
	bool data;
};


int main() {
	//ͷ������
	newTree *head=new newTree;

	int n, m;
	cin >> n >> m;
	int *nums = new int[n];
	
	//�洢�������
	list<int> List;
	List.push_back(0);
	//���ҵ�ͼ
	map<int,int> Map;
	//�����Ƴ�
	bool **shitBool = new bool *[n];

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		nums[i] = temp;
		//ת��Ϊ������
		shitBool[i] = new bool[31]{ 0 };
		for (int j = 30; temp != 0; j--) {
			shitBool[i][j] = temp % 2;
			temp /= 2;
		}
		//����������
		auto p = head;
		for (int j = 0; j < 31; j++) {
			if (!shitBool[i][j]) {
				//û�оʹ���
				if (p->p1 == nullptr)
					p->p1 = new newTree;
				p = p->p1;
				p->data = false;
			}
			else {
				//û�оʹ���
				if (p->p2 == nullptr)
					p->p2 = new newTree;
				p = p->p2;
				p->data = true;
			}
		}
	}

	//Ѱ�������
	for (int i = 0; i < n; i++) {
		int temp = nums[i];
		//ת��Ϊ������
		bool *newTemp = shitBool[i];
		temp = nums[i];
		//ѭ������
		auto p = head;
		int cpNum = 0;
		int currentResult = 0;
		
		//Ѱ�ҵ�ǰ���ֶ�Ӧ�������ֵ
		for (int j = 0; j < 31; j++) {
			if (!newTemp[j]) {
				if (p->p2 != nullptr) {
					p = p->p2;
					currentResult = currentResult * 2 + 1;
				}
				else {
					p = p->p1;
					currentResult = currentResult * 2;
				}
				cpNum= p->data+cpNum*2;
			}
			else {
				if (p->p1 != nullptr) {
					p = p->p1;
					currentResult = currentResult * 2 + 1;
				}
				else {
					p = p->p2;
					currentResult = currentResult * 2;
				}
				cpNum = p->data + cpNum * 2;
			}
		}

		//�ж��Ƿ��ظ�������
		auto mapFinder = Map.find(cpNum);
		if (mapFinder==Map.end()||mapFinder->second!=temp) {
			//����map����
			Map.insert(pair<int, int>(temp, cpNum));

			//����
			auto tempp = List.rbegin();
			for (; tempp != List.rend(); tempp++) {
				if (*tempp > currentResult)
					break;
			}
			if (tempp != List.rbegin()) {
				List.insert(tempp.base(), currentResult);
				if (List.size() > m)
					List.pop_back();
			}
		}
	}

	cout << accumulate(List.begin(), List.end(), 0)%int(1e9+7);

	return 0;
}