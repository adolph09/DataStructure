#pragma once

template <typename T>
class List {
public:
    List() : head(nullptr) {}

    struct Node {
        T element;
        Node *next, *prev;
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

    Node * find_prev(const T &x)    // find previous node by first same element
    {
        Node *tmp;

        if (tmp = find(x))
            return tmp->prev;
        return nullptr;
    }

    void insert(const T &x)
    {
        Node *new_node = new Node;

        new_node->element = x;
        new_node->next = head->next;
        new_node->prev = head;
        head->next = new_node;
        if (is_exist(head->next))
            return;
        head->next->prev = new_node;
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

    void print()
    {
        Node *tmp;

        for (tmp = head->next; tmp != nullptr; tmp = tmp->next)
            cout << tmp->element;
        cout << endl;
    }
private:
    Node *head;
};