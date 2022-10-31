#include <iostream>
using namespace std;
class bst;
class node
{
    node *left, *right;
    int data;
    friend class bst;
};
class bst
{
    node *root;

    void insert(node *&r, int val)
    {

        if (r == 0)
        {
            r = new node;
            r->data = val;
            r->right = nullptr;
            r->left = NULL;
        }
        else if (val > r->data)
        {
            insert(r->right, val);
        }
        else if (val < r->data)
        {
            insert(r->left, val);
        }
    }
    void inorder(node *r)
    {
        if (r != NULL)
        {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }
    void preorder(node *r)
    {
        if (r != NULL)
        {
            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
    }
    void postorder(node *r)
    {
        if (r != NULL)
        {
            postorder(r->left);
            postorder(r->right);
            cout << r->data << " ";
        }
    }

    node *deletebst(node *r, int val)
    {
        if (val < r->data)
        {
            r->left = deletebst(r->left, val);
        }
        else if (val > r->data)
        {
            r->right = deletebst(r->right, val);
        }
        else
        {
            if (r->left == nullptr)
            {
                node *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == nullptr)
            {
                node *temp = r->left;
                delete r;
                return temp;
            }
            node *temp = inordersucc(r->right);
            r->data = temp->data;
            r->right = deletebst(r->right, temp->data);
        }
        return r;
    }
    node *inordersucc(node *root)
    {
        node *curr = root;
        while (curr && curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }
    int count = 0;
    node *kthSmallest(node *root, int &k)
    {
        // base case
        if (root == NULL)
            return NULL;

        // search in left subtree
        node *left = kthSmallest(root->left, k);

        // if k'th smallest is found in left subtree, return it
        if (left != NULL)
            return left;

        // if current element is k'th smallest, return it
        count++;
        if (count == k)
            return root;

        // else search in right subtree
        return kthSmallest(root->right, k);
    }
    void printKthSmallest(node *root, int k)
    {
        // maintain index to count number of nodes processed so far

        node *res = kthSmallest(root, k);
        if (res == NULL)
            cout << "There are less than k nodes in the BST";
        else
            cout << "K-th Smallest Element is " << res->data;
    }
    /////////////////////////////////////////////////////////////
    int count1 = 0;
    node *kthlargest(node *root, int &k)
    {
        // base case
        if (root == NULL)
            return NULL;

        // search in left subtree
        node *right = kthlargest(root->right, k);

        // if k'th smallest is found in left subtree, return it
        if (right != NULL)
            return right;

        // if current element is k'th smallest, return it
        count1++;
        if (count1 == k)
            return root;

        // else search in right subtree
        return kthlargest(root->left, k);
    }
    void printkthlargest(node *root, int k)
    {
        // maintain index to count number of nodes processed so far

        node *res = kthlargest(root, k);
        if (res == NULL)
            cout << "There are less than k nodes in the BST";
        else
            cout << "K-th Largest Element is " << res->data;
    }
    int calheight(node *r)
    {
        if (r == NULL)
        {
            return 0;
        }
        int lheight = calheight(r->left);
        int rheight = calheight(r->right);
        return max(lheight, rheight) + 1;
    }
    int countnodes(node *r)
    {
        if (r == 0)
        {
            return 0;
        }
        return countnodes(r->left) + countnodes(r->right) + 1;
    }

public:
    bst()
    {
        root = NULL;
    }
    ~bst(){};
    void insert(int val)
    {
        insert(root, val);
    }
    void inorder()
    {

        inorder(root);
    }
    void preorder()
    {

        preorder(root);
    }
    void postorder()
    {

        postorder(root);
    }

    void deletebst(int val)
    {
        deletebst(root, val);
    }
    void kthSmallest(int k)
    {
        kthSmallest(root, k);
    }
    void printKthSmallest(int k)
    {
        printKthSmallest(root, k);
    }
    /////
    void kthlargest(int k)
    {
        kthlargest(root, k);
    }
    void printkthlargest(int k)
    {
        printkthlargest(root, k);
    }
    int calheight()
    {
        return calheight(root);
    }
    int countnodes()
    {
        return countnodes(root);
    }
};
int main()
{
    bst b;
    b.insert(3);
    b.insert(2);
    b.insert(1);
    b.insert(4);
    b.insert(5);
    b.insert(6);
    b.insert(7);

    cout << "TREE: ";
    b.inorder();
    cout << "\n";
    b.printKthSmallest(3);

    cout << "\nafter deleting 4: ";
    b.deletebst(4);
    b.inorder();
    cout << endl;
    b.printkthlargest(3);
    cout << "\nMax Height: ";
    cout << b.calheight();
    cout << "\nNo of nodes: ";
    cout << b.countnodes();
}