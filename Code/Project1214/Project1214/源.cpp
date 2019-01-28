#include "iostream"
#include "cstdio"
#include "queue"
#include "vector"
#include "cmath"
#include "cstring"
using namespace std;

//��������
template <class T>
class myBinaryTree {
public:
	class node {
	public:
		T data;
		node *lchild = nullptr, *rchild = nullptr, *parent = nullptr;
	};
	node *root = nullptr;
	node **nodeList = nullptr;
	long long sizeOfTree = 0;

	//������
	void createTree(int num) {
		nodeList = new node*[num + 1]{ nullptr };
		sizeOfTree = num;
	}

	void creadNode(int nodeNum, int lchild, int rchild, int data) {
		if (nodeList[nodeNum] == nullptr)
			nodeList[nodeNum] = new node;

		nodeList[nodeNum]->data = data;

		if (lchild != 0) {
			if (nodeList[lchild] == nullptr)
				nodeList[lchild] = new node;
			nodeList[lchild]->parent = nodeList[nodeNum];
			nodeList[nodeNum]->lchild = nodeList[lchild];
		}

		if (rchild != 0) {
			if (nodeList[rchild] == nullptr)
				nodeList[rchild] = new node;
			nodeList[rchild]->parent = nodeList[nodeNum];
			nodeList[nodeNum]->rchild = nodeList[rchild];
		}
	}

	void checkRoot() {
		for (int i = 1; i <= sizeOfTree; i++) {
			if (nodeList[i]->parent == nullptr) {
				root = nodeList[i];
				break;
			}
		}
	}

	//���
	void clear() {
		clear(root);
	}

	void clear(node *p) {
		if (p == nullptr)
			return;
		clear(p->lchild);
		clear(p->rchild);
		delete p;
		p = nullptr;
	}

	//����
	myBinaryTree() {}

	//����
	~myBinaryTree() {
		clear(root);
	}

	//�ж��Ƿ�ǿ�
	bool empty() {
		return root == nullptr;
	}

	//�ж��Ƿ�Ϊ��ȫ������
	bool isCBT() {
		if (empty())
			return false;
		//��α���
		queue<node*> treeQueue;
		bool flag = false;
		//�����
		treeQueue.push(root);

		//����
		while (!treeQueue.empty()) {
			//�ȳ���һ��
			node* temp = treeQueue.front();
			treeQueue.pop();

			//�Һ���������û��
			if (temp->lchild == nullptr&&temp->rchild != nullptr)
				return false;

			if (!flag) {
				//�������Һ���û��
				if (temp->lchild != nullptr&&temp->rchild == nullptr) {
					flag = true;
					//�������
					treeQueue.push(temp->lchild);
				}
				//���Һ��Ӷ�û��
				else if (temp->lchild == nullptr&&temp->rchild == nullptr) {
					flag = true;
				}
				//���Ҷ��к���
				else {
					treeQueue.push(temp->lchild);
					treeQueue.push(temp->rchild);
				}
			}
			else {
				//�ж��Ƿ�ΪҶ��
				if (temp->lchild != nullptr || temp->rchild != nullptr)
					return false;
			}
		}

		return true;
	}

	//���ش�С
	long long size() {
		return sizeOfTree;
	}

	//��α���
	vector<T> levelTraversal() {
		if (sizeOfTree == 0)
			return *new vector<T>;

		vector<T> result; 
		queue<node*> treeQueue;

		//��������
		treeQueue.push(root);

		//��α���
		while (!treeQueue.empty()) {
			//����
			node* temp = treeQueue.front();
			treeQueue.pop();

			//���
			if (temp->lchild != nullptr)
				treeQueue.push(temp->lchild);
			if (temp->rchild != nullptr)
				treeQueue.push(temp->rchild);

			//д��
			result.push_back(temp->data);
		}

		//����
		return result;
	}

	//ǰ�����
	vector<T> preorderTraversal() {
		vector<T> result;
		preorderTraversal(root, result);
		return result;
	}

	void preorderTraversal(node* treeRoot,vector<T> &result) {
		//��ʾ��ǰ
		result.push_back(treeRoot->data);

		if (treeRoot->lchild != nullptr)
			preorderTraversal(treeRoot->lchild,result);
		if (treeRoot->rchild != nullptr)
			preorderTraversal(treeRoot->rchild,result);
	}

	//�������
	vector<T> midorderTraversal() {
		vector<T> result;
		midorderTraversal(root, result);
		return result;
	}

	void midorderTraversal(node* treeRoot, vector<T> &result) {
		if (treeRoot->lchild != nullptr)
			midorderTraversal(treeRoot->lchild, result);
		//��ʾ��ǰ
		result.push_back(treeRoot->data);
		if (treeRoot->rchild != nullptr)
			midorderTraversal(treeRoot->rchild, result);
	}

	//�������
	vector<T> lostorderTraversal() {
		vector<T> result;
		lostorderTraversal(root, result);
		return result;
	}

	void lostorderTraversal(node* treeRoot, vector<T> &result) {
		if (treeRoot->lchild != nullptr)
			lostorderTraversal(treeRoot->lchild, result);
		if (treeRoot->rchild != nullptr)
			lostorderTraversal(treeRoot->rchild, result);
		//��ʾ��ǰ
		result.push_back(treeRoot->data);
	}
};

//�������ֵܶ�������
template <class T>
class mySpecialBinaryTree {
public:
	class node {
	public:
		T data;
		node *lchild = nullptr, *rbrother = nullptr;
		bool isRoot = true;
	};
	node *root = nullptr;
	node **nodeList = nullptr;
	long long sizeOfTree = 0;

	//������
	void createTree(int num) {
		nodeList = new node*[num + 1]{ nullptr };
		sizeOfTree = num;
	}

	void creadNode(int nodeNum, int lchild, int rbrother, int data) {
		if (nodeList[nodeNum] == nullptr)
			nodeList[nodeNum] = new node;

		nodeList[nodeNum]->data = data;

		if (lchild != 0) {
			if (nodeList[lchild] == nullptr)
				nodeList[lchild] = new node;
			nodeList[lchild]->isRoot = false;
			nodeList[nodeNum]->lchild = nodeList[lchild];
		}

		if (rbrother != 0) {
			if (nodeList[rbrother] == nullptr)
				nodeList[rbrother] = new node;
			nodeList[rbrother]->isRoot = false;
			nodeList[nodeNum]->rbrother = nodeList[rbrother];
		}
	}

	void checkRoot() {
		for (int i = 1; i <= sizeOfTree; i++) {
			if (nodeList[i]->isRoot) {
				root = nodeList[i];
				break;
			}
		}
	}

	//���
	void clear() {
		clear(root);
	}

	void clear(node *p) {
		if (p == nullptr)
			return;
		clear(p->lchild);
		clear(p->rbrother);
		delete p;
		p = nullptr;
	}

	//����
	mySpecialBinaryTree() {}

	//����
	~mySpecialBinaryTree() {
		clear(root);
	}

	//�ж��Ƿ�ǿ�
	bool empty() {
		return root == nullptr;
	}

	//���ش�С
	long long size() {
		return sizeOfTree;
	}

	//��α���
	vector<T> levelTraversal() {
		if (sizeOfTree == 0)
			return *new vector<T>;

		vector<T> result;
		queue<node*> treeQueue;

		//��������
		treeQueue.push(root);

		//��α���
		while (!treeQueue.empty()) {
			//����
			node* temp = treeQueue.front();
			treeQueue.pop();

			//���
			for (auto p = temp->lchild; p!= nullptr; p = p->rbrother)
				treeQueue.push(p);
		
			//д��
			result.push_back(temp->data);
		}

		//����
		return result;
	}

	//ǰ�����
	vector<T> preorderTraversal() {
		vector<T> result;
		preorderTraversal(root, result);
		return result;
	}

	void preorderTraversal(node* treeRoot, vector<T> &result) {
		//��ʾ��ǰ
		result.push_back(treeRoot->data);

		if (treeRoot->lchild != nullptr)
			preorderTraversal(treeRoot->lchild, result);
		if (treeRoot->rbrother != nullptr)
			preorderTraversal(treeRoot->rbrother, result);
	}

	//�������
	vector<T> lostorderTraversal() {
		vector<T> result;
		lostorderTraversal(root, result);
		return result;
	}

	void lostorderTraversal(node* treeRoot, vector<T> &result) {
		if (treeRoot->lchild != nullptr)
			lostorderTraversal(treeRoot->lchild, result);
		//��ʾ��ǰ
		result.push_back(treeRoot->data);
		if (treeRoot->rbrother != nullptr)
			lostorderTraversal(treeRoot->rbrother, result);
	}
};

int main() {
	int num;
	mySpecialBinaryTree<int> bTree;
	cin >> num;
	bTree.createTree(num);

	for (int i = 1; i <= num; i++) {
		int lchild, rchild, nodeData;
		scanf("%d %d %d", &lchild, &rchild, &nodeData);
		bTree.creadNode(i, lchild, rchild, nodeData);
	}

	bTree.checkRoot();
	auto ans = bTree.preorderTraversal();

	cout << ans[0];
	for (int i = 1; i < bTree.sizeOfTree; i++)
		printf(" %d", ans[i]);
	ans = bTree.lostorderTraversal();

	cout << endl;

	cout << ans[0];
	for (int i = 1; i < bTree.sizeOfTree; i++)
		printf(" %d", ans[i]);

	ans = bTree.levelTraversal();

	cout << endl;

	cout << ans[0];
	for (int i = 1; i < bTree.sizeOfTree; i++)
		printf(" %d", ans[i]);

	return 0;
}