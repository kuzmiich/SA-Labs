#include <iostream>
#include <string>

using namespace std;

struct List
{
	char letter;// Inforamation field

	List* next = nullptr; // Address field

	static void add_element(List* lst_letter, char value)
	{
        List* buf = new List;
        buf->next = NULL;
        buf->letter = value;
        if (lst_letter == NULL)
        {
            lst_letter = buf;
        }
        else
        {
            List* pList = lst_letter;
            while (pList->next != NULL) pList = pList->next;
            pList->next = buf;
        }
	}
    static void ParseFio(List* root)
    {
        List* surname = new List;
        List* name = new List;
        List* secondName = new List;
        while (root->letter != ' ')
        {
            surname->add_element(surname, root->letter);
            root = root->next;
        }
        root = root->next;
        while (root->letter != ' ')
        {
            name->add_element(name, root->letter);
            root = root->next;
        }
        root = root->next;
        while (root)
        {
            secondName->add_element(secondName, root->letter);
            root = root->next;
        }
        cout << "Name:\n";
        print(name);
        cout << "Second name:\n";
        print(secondName);
        cout << "Surname\n";
        print(surname);

        delete name, secondName, surname;
    }
	static void print(List* root)
	{
        root = root->next;
        while (root)
        {
            cout << "Adress: " << root << "  Information part: " << root->letter << "  Adress part: " << root->next << endl;
            root = root->next;
        }
        cout << endl;
	}
};

int main()
{
	List* list_letter = new List();
    const int size = 255;
    char str[] = "Kuzmich Ivan Vitalievich";

    for (int i = 0; i < strlen(str); i++)
    {
        list_letter->add_element(list_letter, str[i]);
    }
    list_letter->print(list_letter);
    list_letter->ParseFio(list_letter);

	delete list_letter;
	return 0;
}