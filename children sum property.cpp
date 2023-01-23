#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#include<iomanip>
#define mod 1000000007;
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void changeTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    int child = 0;
    if (root->left) child += root->left->data;
    if (root->right) child += root->right->data;
    if (child >= root->data) root->data = child;
    else {
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left) total += root->left->data;
    if (root->right) total += root->right->data;
    if (root->left || root->right) root->data = total;
}

void printNodes(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << endl;
    printNodes(root->left);
    printNodes(root->right);
}

int main() {
    Node* one = new Node(10);
    Node* ten = new Node(10);
    Node* twenty = new Node(20);
    Node* two = new Node(2);
    Node* five = new Node(5);
    Node* thirty = new Node(30);
    Node* fourty = new Node(40);
    one->left = ten;
    one->right = twenty;
    ten->left = two;
    ten->right = five;
    twenty->left = thirty;
    twenty->right = fourty;
    changeTree(one);
    printNodes(one);
    
    return 0;
};
