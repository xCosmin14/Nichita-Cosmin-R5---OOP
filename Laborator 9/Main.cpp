#include <iostream>

template <typename K, typename V>
class Map {
    struct Node {
        K key;
        V value;
        int index;
    };

    Node* elements;
    int capacity;
    int currentSize;

    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        Node* newElements = new Node[capacity];
        for (int i = 0; i < currentSize; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

public:
    Map() : elements(nullptr), capacity(0), currentSize(0) {}
    
    ~Map() { delete[] elements; }

    V& operator[](const K& key) {
        for (int i = 0; i < currentSize; i++) {
            if (elements[i].key == key) return elements[i].value;
        }
        if (currentSize == capacity) resize();
        elements[currentSize].key = key;
        elements[currentSize].index = currentSize;
        return elements[currentSize++].value;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value) {
        for (int i = 0; i < currentSize; i++) {
            if (elements[i].key == key) {
                value = elements[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const { return currentSize; }

    void Clear() {
        currentSize = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < currentSize; i++) {
            if (elements[i].key == key) {
                for (int j = i; j < currentSize - 1; j++) {
                    elements[j] = elements[j + 1];
                    elements[j].index = j;
                }
                currentSize--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) {
        for (int i = 0; i < other.currentSize; i++) {
            bool found = false;
            for (int j = 0; j < currentSize; j++) {
                if (elements[j].key == other.elements[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

    struct Iterator {
        Node* ptr;

        struct Item {
            K& key;
            V& value;
            int index;
        };

        Item operator*() { return {ptr->key, ptr->value, ptr->index}; }
        Iterator& operator++() { ptr++; return *this; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    Iterator begin() { return {elements}; }
    Iterator end() { return {elements + currentSize}; }
};

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}
