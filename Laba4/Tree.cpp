#include<iostream>
#include<ctime>

using namespace std;

struct Node {
    int key;
    Node* left, * right;
};

/* utility that allocates a new Node with the given key  */
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;

    return node;
}

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

int main()
{
    srand(time_t(NULL));

    Node* root = init();

    int sum = sum_node(root);
    cout << "Sum of all the elements is: " << sum << endl;

    return 0;
}