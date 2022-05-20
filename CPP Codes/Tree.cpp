#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void display(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        display(root->left);
        display(root->right);
    }
}
TreeNode *insert(vector<int> a, TreeNode *root, int i)
{
    if (i < a.size())
    {
        TreeNode *t = new TreeNode(a[i]);
        root = t;
        root->left = insert(a, root->left, 2 * i + 1);
        root->right = insert(a, root->right, 2 * i + 2);
    }
    return root;
}
void dfs(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        dfs(root->left);
        dfs(root->right);
    }
}
void bfs(TreeNode *root)
{
    if (root != NULL)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> d;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        double s = 0;
        int c = q.size();
        for (int i = 0; i < c; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            s += temp->val;
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        d.push_back(s / c);
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 1;
    // cin>>T;
    while (T--)
    {
        TreeNode *root = insert(vector<int>({1, 2, 3, 4, 5, 6, 7}), NULL, 0);
        preorder(root);
    }
    return 0;
}