#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<unordered_map>
#include<string>
#include<cmath>
#include<string>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
	}
};
void printNodes(Node* root) {
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    while (q.size() > 0) {
        int levelSize = q.size();
        // q size will be equal to current level size
        vector<int> currentLevel;
        // this will make sure that we loop level by level
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            currentLevel.push_back(current->data);
            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        // when we finished the loop, we already populated q with next level
        result.push_back(currentLevel);
    }
    for (auto i : result) {
        for (auto val : i) {
            cout << val << " ";
        }
        cout << endl;
    }
}

Node* insertNode(Node* root, int data) {
	if (root == nullptr) {
		root = new Node(data);
		return root;
	}
	if (data < root->data) {
		root->left = insertNode(root->left, data);
	}
	else {
		root->right = insertNode(root->right, data);
	}
	return root;
}
bool searchANode(Node* root, int data) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    if (data < root->data) {
        return searchANode(root->left, data);
    }
    else {
        return searchANode(root->right, data);
    }
}
int minValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }
    if (root->left == nullptr) {
        return root->data;
    }
    return minValue(root->left);
}
int maxValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }
    if (root->right == nullptr) {
        return root->data;
    }
    return maxValue(root->right);
}
int main() {
	Node* cur = nullptr;
	Node * root = insertNode(cur, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 5);
    insertNode(root, 8);
    insertNode(root, 80);
    printNodes(root);
    cout << "min value is: " << minValue(root) << endl;
    cout << "Max value is: " << maxValue(root) << endl;
	return 0;
}
