//Lowest Common Ancestor in a BST

Node * LCA_iterative(Node *root, Node *p, Node *q) {
    if (!root || !p || !q) return NULL;
    while (max(p->data, q->data) < root->data) {
        root = root -> left;
    }
    while (min(p->data, q->data) > root->data) {
        root = root -> right;
    }
    return root;
}

Node * LCA_recursive(Node *root, Node *p, Node *q) {
    if (!root || !p || !q) return NULL;
    else if (max(p->data, q->data) < root->data) {
        return LCA_recursive(root->left, p, q);
    } else if(min(p->data, q->data) > root->data) {
        return LCA_recursive(root->right, p, q);
    } else {
        return root;
    }

}