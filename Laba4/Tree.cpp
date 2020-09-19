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

void init(Node* root, int count)
{
    int start = -10, end = 10;
    for (int i = 0; i < count; i++)
    {
        int random = start + rand() % (end - start);
        if (i % 2 == 0)
        {
            root->right = newNode(random);
        }
        else
        {
            root->left = newNode(random);
        }
    }
}
/* Function to find sum of all the elements*/
int all_root(Node* root)
{
    if (root == NULL)
        return 0;
    return root->key + all_root(root->left) + all_root(root->right);
}

/* Driver program to test above functions*/
int main()
{
    srand(time_t(NULL));

    Node* root = new Node;
    root->left = root->right = NULL;
    int count = 10;
    init(root, count);
    int sum = all_root(root);
    cout << "Sum of all the elements is: " << sum << endl;

    return 0;
}