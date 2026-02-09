/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void rightrotate(TreeNode* parent, TreeNode* node){ // подогнуть левые поддеревья в лозу
        TreeNode* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        parent->right = tmp;
    }

    void leftrotate(TreeNode* parent, TreeNode* node){ // восстановить уровень
        TreeNode* tmp = node->right;
        parent->right = tmp;
        node->right = tmp->left;
        tmp->left = node;
    }

    void makerotation(TreeNode* vine, int n){ // восстановление дерева
        TreeNode* current = vine;
        for(int i = 0; i < n; i++){
            leftrotate(current, current->right);
            current = current->right;
        }
    }

    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* vine = new TreeNode(0, nullptr, root);
        vine->right = root;
        TreeNode* current = vine; //dummy лозы
        while(current->right){          //превращение дерева в лозу
            if(current->right->left){
                rightrotate(current, current->right);
            }
            else
                current = current->right;
        }
        TreeNode* tmp = vine->right;
        int n = 0;
        while(tmp){
            tmp = tmp->right; //подсчет узслов
            n++;
        }
        int m = pow(2, floor(log2(n + 1))) - 1; // сколько узлов может быть в ИДЕАЛЬНОМ дерев
        makerotation(vine, n - m); // данной высоты далее лишние узлы размещаем на нижнем уровне ->
        while(m > 1){//балансировка
            m /= 2;
            makerotation(vine, m);
        }
        return vine->right;
    }
};
