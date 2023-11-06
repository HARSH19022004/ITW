#include <iostream>

using namespace std;

enum class Color { RED, BLACK };

struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;
    Color color;
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node* node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;
        if (rightChild->left != nullptr)
            rightChild->left->parent = node;
        rightChild->parent = node->parent;
        if (node->parent == nullptr)
            root = rightChild;
        else if (node == node->parent->left)
            node->parent->left = rightChild;
        else
            node->parent->right = rightChild;
        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node* node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;
        if (leftChild->right != nullptr)
            leftChild->right->parent = node;
        leftChild->parent = node->parent;
        if (node->parent == nullptr)
            root = leftChild;
        else if (node == node->parent->left)
            node->parent->left = leftChild;
        else
            node->parent->right = leftChild;
        leftChild->right = node;
        node->parent = leftChild;
    }

    void insertFixup(Node* node) {
        while (node != root && node->parent->color == Color::RED) {
            if (node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;
                if (uncle != nullptr && uncle->color == Color::RED) {
                    node->parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        rotateLeft(node);
                    }
                    node->parent->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    rotateRight(node->parent->parent);
                }
            } else {
                Node* uncle = node->parent->parent->left;
                if (uncle != nullptr && uncle->color == Color::RED) {
                    node->parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rotateRight(node);
                    }
                    node->parent->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    rotateLeft(node->parent->parent);
                }
            }
        }
        root->color = Color::BLACK;
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr, nullptr, nullptr, Color::RED};
        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        newNode->parent = parent;
        if (parent == nullptr)
            root = newNode;
        else if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        insertFixup(newNode);
    }

    Node* search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->data)
                return current;
            else if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }
};

int main() {
    RedBlackTree tree;

    int values[] = {10, 20, 30, 40, 50, 60, 70};

    for (int value : values) {
        tree.insert(value);
    }

    Node* node = tree.search(30);

    if (node != nullptr)
        cout << "Value 30 found in the Red-Black Tree." << endl;
    else
        cout << "Value 30 not found in the Red-Black Tree." << endl;

    return 0;
}
