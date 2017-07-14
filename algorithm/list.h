#pragma once

#include <limits.h>

#define ERROR   -1

// the 0th node is head
template <typename T>
class List {
public:
    List() : head(nullptr) {}
    ~List()
    {
        //destory();    // can't call the destory by yourself if ~List() call destory()
    }

    struct Node {
        T element;
        Node *next, *prev;

        Node() : next(nullptr), prev(nullptr) {}
    };

    bool is_empty()
    {
        return head == nullptr;
    }

    bool is_exist(Node *node)
    {
        return node == nullptr;
    }

    Node *get_head()
    {
        if (head)
            return head;
        return nullptr;
    }

    Node *get_tail()
    {
        if (!head)
            return nullptr;

        Node *tmp = head;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        return tmp;
    }

    void init()     // create a list head (not include element)
    {
        head = new Node;
        head->element = (T)0;
        head->next = nullptr;
        head->prev = nullptr;
    }

    Node * find(const T &x)     // find node by first same element
    {
        Node *tmp = head->next;

        while (tmp && tmp->element != x)
            tmp = tmp->next;
        return tmp;
    }

    T find(Node *node)    // find element by node 
    {
        Node *tmp = head->next;

        while (tmp != node)
            tmp = tmp->next;
        if (tmp != nullptr)
            return tmp->element;
        return (T)0;
    }

    T find(int num)     // find 'num'th element
    {
        Node *tmp;

        if (num < 0)
            return ERROR;

        for (tmp = head; tmp && num != 0; num--, tmp = tmp->next)
            ;   // do nothing
        if (tmp)
            return tmp->element;
        return ERROR;
    }

    Node * find_prev(const T &x)    // find previous node by first same element
    {
        Node *tmp;

        if (tmp = find(x))
            return tmp->prev;
        return nullptr;
    }

    int length()
    {
        int len = 0;
        Node *tmp = head->next;

        while (tmp) {
            tmp = tmp->next;
            len++;
        }
        return len;
    }

    void insert(const T &x)
    {
        Node *new_node = new Node;

        new_node->element = x;
        new_node->next = head->next;
        new_node->prev = head;
        if (is_exist(head->next)) {
            head->next = new_node;
            return;
        }
        head->next->prev = new_node;
        head->next = new_node;
    }

    void insert(Node *node, const T &x) // insert 'x' after 'node'
    {
        Node *new_node = new Node;

        new_node->element = x;
        new_node->prev = node;
        if (node->next) {   // if 'node' next is exist
            node->next->prev = new_node;
            new_node->next = node->next;
        }
        node->next = new_node;
    }

    void insert(int num, const T &x)    // insert 'x' after 'num'th node
    {
        if (num < 0)    //insert is same as  'insert(const T &x)' after 0th node 
            return;

        Node *tmp;
        Node *new_node = new Node;

        new_node->element = x;
        for (tmp = head; tmp && num != 0; tmp = tmp->next, num--)
            ; // while num == lenth(), the tail node is tmp
        if (!tmp)
            insert_back(x);
        else {
            insert(tmp, x);
        }
        
    }

    void insert_back(const T &x)    // insert 'x' to list's tail
    {
        Node *new_node = new Node;
        Node *tail = get_tail();

        new_node->element = x;
        tail->next = new_node;
        new_node->prev = tail;
    }

    void destory()
    {
        Node *next, *curr;

        curr = head;
        //head->next = nullptr;
        while (curr) {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void print()
    {
        if (head == nullptr)
            return;

        Node *tmp;
        for (tmp = head->next; tmp != nullptr; tmp = tmp->next)
            cout << tmp->element << " ";
        cout << endl;
    }
private:
    Node *head;
};