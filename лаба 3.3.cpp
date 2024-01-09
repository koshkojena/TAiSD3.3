#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
struct Node
{
    char data;
    Node* left;
    Node* right;
    Node(char value)
    {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class BinaryTree 
{
private:
    Node* root;
    Node* createBalancedTree(char values[], int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int mid = (start + end) / 2;
        Node* newNode = new Node(values[mid]);
        newNode->left = createBalancedTree(values, start, mid - 1);
        newNode->right = createBalancedTree(values, mid + 1, end);
        return newNode;
    }
    void printTree(Node* node, int level)
    {
        if (node != nullptr) 
        {
            printTree(node->right, level + 1);
            for (int i = 0; i < level; i++)
            {
                cout << "    ";
            }
            cout << node->data << "\n";
            printTree(node->left, level + 1);
        }
    }
    int countNodesWithKey(Node* node, char key) 
    {
        if (node == nullptr) 
        {
            return 0;
        }
        int count = 0;
        if (node->data == key) 
        {
            count++;
        }
        count += countNodesWithKey(node->left, key);
        count += countNodesWithKey(node->right, key);
        return count;
    }
public:
    BinaryTree(char values[], int size)
    {
        root = createBalancedTree(values, 0, size - 1);
    }
    void printTree() 
    {
        printTree(root, 0);
    }
    int countNodesWithKey(char key)
    {
        return countNodesWithKey(root, key);
    }
};
int main() 
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1241);
    int treeSize;
    cout << "Введите размер дерева: ";
    cin >> treeSize;
    char* values = new char[treeSize];
    cout << "Введите " << treeSize << " элементов для добавления в дерево: ";
    for (int i = 0; i < treeSize; i++)
    {
        cin >> values[i];
    }
    BinaryTree tree(values, treeSize);
    cout << "Дерево:\n";
    tree.printTree();
    char keyToSearch;
    cout << "Введите ключ для поиска: " << endl;
    cin >> keyToSearch;
    int count = tree.countNodesWithKey(keyToSearch);
    cout << "Количество элементов с ключом " << keyToSearch << " в дереве: " << count << endl;
    delete[] values;
    return 0;
}