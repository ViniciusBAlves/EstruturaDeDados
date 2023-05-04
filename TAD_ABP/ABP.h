struct TreeNode
{
    int info;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNodePtr;

enum SearchMode
{
    LEFT_PREFIXED, RIGHT_PREFIXED, LEFT_CENTRAL, RIGHT_CENTRAL, LEFT_POSTFIXED, RIGHT_POSTFIXED
};

TreeNodePtr* createTree();
TreeNodePtr* inspectTree(TreeNodePtr *node, int key);
TreeNodePtr* insertTree(TreeNodePtr *node, int info);
TreeNodePtr* removeTree(TreeNodePtr *node, int key);
void printTree(TreeNodePtr *node, int mode);

