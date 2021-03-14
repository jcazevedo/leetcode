#include <unordered_map>

using namespace std;

struct node {
  node* prev;
  node* next;
  int key;
  int value;

  node(int _key, int _value) {
    prev = next = nullptr;
    key = _key;
    value = _value;
  }
};

class LRUCache {
private:
  int cap, len;
  node* tail;
  node* head;
  unordered_map<int, node*> cache;

  void add_node(int k, int v) {
    node* n = new node(k, v);
    if (head == nullptr) {
      head = tail = n;
      len = 1;
    } else {
      n->next = head;
      head->prev = n;
      head = n;
      head->prev = nullptr;
      len++;
      if (len > cap)
        remove_node(tail);
    }
  }

  void remove_node(node* node) {
    cache.erase(node->key);
    if (node->next != nullptr)
      node->next->prev = node->prev;
    if (node->prev != nullptr)
      node->prev->next = node->next;
    if (node == head)
      head = head->next;
    if (node == tail)
      tail = tail->prev;
    delete node;
    len--;
  }

public:
  LRUCache(int capacity) {
    cap = capacity;
    head = tail = nullptr;
    len = 0;
  }

  int get(int key) {
    if (cache.find(key) == cache.end())
      return -1;
    node* node = cache[key];
    int value = node->value;
    remove_node(node);
    add_node(key, value);
    cache[key] = head;
    return head->value;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end())
      remove_node(cache[key]);
    add_node(key, value);
    cache[key] = head;
  }
};
