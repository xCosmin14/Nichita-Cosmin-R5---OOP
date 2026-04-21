#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Tree {
public:
    struct Node {
        T      value;
        Node** children;
        int    childCount;
        int    childCapacity;

        Node(const T& val)
            : value(val), children(nullptr), childCount(0), childCapacity(0) {}

        ~Node() {
            delete[] children;  
        }

        void addChild(Node* child) {
            grow();
            children[childCount++] = child;
        }

        void insertChild(Node* child, int index) {
            if (index < 0 || index > childCount) index = childCount;
            grow();
            for (int i = childCount; i > index; --i)
                children[i] = children[i - 1];
            children[index] = child;
            ++childCount;
        }

        void removeChildAt(int index) {
            for (int i = index; i < childCount - 1; ++i)
                children[i] = children[i + 1];
            --childCount;
        }

    private:
        void grow() {
            if (childCount == childCapacity) {
                int newCap = (childCapacity == 0) ? 2 : childCapacity * 2;
                Node** arr = new Node*[newCap];
                for (int i = 0; i < childCount; ++i) arr[i] = children[i];
                delete[] children;
                children    = arr;
                childCapacity = newCap;
            }
        }
    };

private:
    Node* root;

    void deleteSubtree(Node* node) {
        if (!node) return;
        for (int i = 0; i < node->childCount; ++i)
            deleteSubtree(node->children[i]);
        delete node;
    }

    Node* findNode(Node* current, bool (*compare)(const T&)) {
        if (!current) return nullptr;
        if (compare(current->value)) return current;
        for (int i = 0; i < current->childCount; ++i) {
            Node* result = findNode(current->children[i], compare);
            if (result) return result;
        }
        return nullptr;
    }

    int countDescendants(Node* node) const {
        if (!node) return 0;
        int total = node->childCount;
        for (int i = 0; i < node->childCount; ++i)
            total += countDescendants(node->children[i]);
        return total;
    }

    void sortNode(Node* node, bool (*compare)(const T&, const T&)) {
        if (!node || node->childCount <= 1) return;
        for (int i = 0; i < node->childCount - 1; ++i) {
            for (int j = 0; j < node->childCount - i - 1; ++j) {
                bool swap;
                if (compare)
                    swap = compare(node->children[j + 1]->value,
                                   node->children[j]->value);
                else
                    swap = node->children[j + 1]->value
                         < node->children[j]->value;
                if (swap) {
                    Node* tmp          = node->children[j];
                    node->children[j]  = node->children[j + 1];
                    node->children[j + 1] = tmp;
                }
            }
        }
    }

    bool removeFromParent(Node* current, Node* target) {
        if (!current) return false;
        for (int i = 0; i < current->childCount; ++i) {
            if (current->children[i] == target) {
                deleteSubtree(current->children[i]);
                current->removeChildAt(i);
                return true;
            }
            if (removeFromParent(current->children[i], target)) return true;
        }
        return false;
    }

    void printTree(Node* node, int depth) const {
        if (!node) return;
        for (int i = 0; i < depth; ++i) cout << "  ";
        cout << node->value << "\n";
        for (int i = 0; i < node->childCount; ++i)
            printTree(node->children[i], depth + 1);
    }

public:
    Tree()         : root(nullptr) {}
    Tree(const T& rootVal) : root(new Node(rootVal)) {}
    ~Tree() { deleteSubtree(root); }

    Node* add_node(const T& val, Node* parent = nullptr) {
        Node* newNode = new Node(val);
        if (!parent) {
            if (root) {
                cout << "[add_node] Radacina exista. Specificati un parinte.\n";
                delete newNode;
                return nullptr;
            }
            root = newNode;
            return root;
        }
        parent->addChild(newNode);
        return newNode;
    }

    Node* get_node(Node* node = nullptr) const {
        return node ? node : root;
    }

    void delete_node(Node* node) {
        if (!node) return;
        if (node == root) {
            deleteSubtree(root);
            root = nullptr;
            return;
        }
        removeFromParent(root, node);
    }

    Node* find(bool (*compare)(const T&)) {
        return findNode(root, compare);
    }

    Node* insert(Node* parent, const T& val, int index) {
        if (!parent) return add_node(val);
        Node* newNode = new Node(val);
        parent->insertChild(newNode, index);
        return newNode;
    }

    void sort(Node* node = nullptr, bool (*compare)(const T&, const T&) = nullptr) {
        sortNode(node ? node : root, compare);
    }

    int count(Node* node = nullptr) const {
        return countDescendants(node ? node : root);
    }

    void print() const { printTree(root, 0); }

    Node* getRoot() const { return root; }
};
