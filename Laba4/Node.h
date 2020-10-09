#ifndef Node
#define myTree

#include <iostream>
using namespace std;

struct Node {
    int key;//informational field
    Node* left = nullptr,//address field
        * right = nullptr;

    /* utility that allocates a new Node with the given key  */
    static Node* newNode(int key)
    {
        static Node* node = new Node;
        node->key = key;
        node->left = node->right = NULL;

        return node;
    }
    /* init start tree thanks to random numbers*/
    static Node* init()
    {
        int start = -10, end = 10;

        int random = start + rand() % (end - start);
        Node* root = newNode(random);

        int random1 = start + rand() % (end - start);
        root->left = newNode(random1);

        int random2 = start + rand() % (end - start);
        root->right = newNode(random2);

        int random3 = start + rand() % (end - start);
        root->left->left = newNode(random3);

        int random4 = start + rand() % (end - start);
        root->left->right = newNode(random4);

        int random5 = start + rand() % (end - start);
        root->right->left = newNode(random5);

        int random6 = start + rand() % (end - start);
        root->right->right = newNode(random6);

        return root;
    }
    /* Function to find sum of all the elements*/
    static int sum_node(Node* root)
    {
        if (root == NULL)
            return 0;
        return (root->key + sum_node(root->left) + sum_node(root->right));
    }
    /* Displaying the address, information part, and address part of each element */
    static void print_info(Node* root)
    {
        if (root)
        {
            Node* p = root->left;
            Node* r = root->right;
            print_info(root->left);
            cout << root->key << endl;
            cout << &(root->key) << endl;
            cout << p << endl;
            cout << r << endl;
            print_info(root->right);
        }

    }
};
#endif