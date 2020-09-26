#include <iostream>
#include <ctime>
#include "Node.h"

using namespace std;

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