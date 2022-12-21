// Problem Link :- https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464



int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    while(node){
        if(x > node->data){
            node = node->right;
        }
        else if(x < node->data){
            ans = node->data;
            node = node->left;
        }
        else{
            return x;
        }
    }
    return ans;
}