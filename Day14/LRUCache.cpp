// Problem LInk :- https://leetcode.com/problems/lru-cache/ 


class LRUCache {
  public:
    class node {
        public:
        int key;
        int data;
        node * next;
        node * pre;
        node(int _key, int _data) {
            key = _key;
            data = _data;
        }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> pre = head;
  }

  void addNode(node * newNode) {
    node * temp = head -> next;
    newNode -> next = temp;
    newNode -> pre = head;
    head -> next = newNode;
    temp -> pre = newNode;
  }

  void deleteNode(node * delNode) {
    node * delPre = delNode -> pre;
    node * delNext = delNode -> next;
    delPre -> next = delNext;
    delNext -> pre = delPre;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resNode = m[key_];
      int res = resNode -> data;
      m.erase(key_);
      deleteNode(resNode);
      addNode(resNode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int dataue) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deleteNode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> pre -> key);
      deleteNode(tail -> pre);
    }

    addNode(new node(key_, dataue));
    m[key_] = head -> next;
  }
};