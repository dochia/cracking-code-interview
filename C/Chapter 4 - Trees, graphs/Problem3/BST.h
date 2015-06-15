
typedef struct Node
{
        int info;
        struct Node* left;
        struct Node* right;
} TreeNode;

TreeNode* createMinimalBST(int arr[], int len);

TreeNode* createBST(int arr[], int start, int end);

void printPreOrder(TreeNode* start);

void printInOrder(TreeNode* start);
