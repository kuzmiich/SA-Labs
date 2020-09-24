#include<iostream>
#include<ctime>

using namespace std;

struct Node {
    int key;
    Node* left = nullptr, * right = nullptr;

    /* utility that allocates a new Node with the given key  */
    Node* newNode(int key)
    {
        Node* node = new Node;
        node->key = key;
        node->left = node->right = NULL;

        return node;
    }
    /* init start tree thanks to random numbers*/
    Node* init()
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
    int sum_node(Node* root)
    {
        if (root == NULL)
            return 0;
        return (root->key + sum_node(root->left) + sum_node(root->right));
    }
    /* Displaying the address, information part, and address part of each element */
    void print_adr_infoPart_adrPart(Node* root) 
    {
        if (root)
        {
            Node* p = root->left;
            Node* b = root->right;
            print_adr_infoPart_adrPart(root->left);
            cout << root->key << endl;
            cout << &(root->key) << endl;
            cout << p << endl;
            cout << b << endl;
            print_adr_infoPart_adrPart(root->right);
        }
        
    }
};

int main()
{
    srand(time_t(NULL));
    Node* logic = new Node;

    Node* root = logic->init();

    int sum = logic->sum_node(root);

    logic->print_adr_infoPart_adrPart(root);

    cout << "Sum of all the elements is: " << sum << endl;

    return 0;
}