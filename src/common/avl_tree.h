/*
 * avl_tree.h
 *
 *  Created on: Aug 28, 2015
 *      Author: andy
 */

#ifndef SRC_COMMON_AVL_TREE_H_
#define SRC_COMMON_AVL_TREE_H_

using namespace std;

namespace avl_tree {

struct avl_node {
  int data;
  struct avl_node *left;
  struct avl_node *right;
}*root;

/*
 * Class Declaration
 */
class avlTree {
 public:
  int height(avl_node *);
  int diff(avl_node *);
  avl_node* right_right_rotation(avl_node *);
  avl_node* left_left_rotation(avl_node *);
  avl_node* left_right_rotation(avl_node *);
  avl_node* right_left_rotation(avl_node *);
  avl_node* balance(avl_node *);
  avl_node* insert(avl_node *, int);
  void display(avl_node *, int);
  void inorder(avl_node *);
  void preorder(avl_node *);
  void postorder(avl_node *);
  avlTree() {
    root = NULL;
  }
};

/*
 * Height of AVL Tree
 */
int avlTree::height(avl_node *node) {
  int h = 0;
  if (node != NULL) {
    int l_height = height(node->left);
    int r_height = height(node->right);
    int max_height = max(l_height, r_height);
    h = max_height + 1;
  }
  return h;
}

/*
 * Height Difference
 */
int avlTree::diff(avl_node *node) {
  int left_node_height = height(node->left);
  int right_node_height = height(node->right);
  int b_factor = left_node_height - right_node_height;
  return b_factor;
}

/*
 * Right- Right Rotation
 */
avl_node *avlTree::right_right_rotation(avl_node *parent) {
  avl_node *temp_node = parent->right;
  parent->right = temp_node->left;
  temp_node->left = parent;
  return temp_node;
}
/*
 * Left- Left Rotation
 */
avl_node *avlTree::left_left_rotation(avl_node *parent) {
  avl_node *tmp_node = parent->left;
  parent->left = tmp_node->right;
  tmp_node->right = parent;
  return tmp_node;
}

/*
 * Left - Right Rotation
 */
avl_node *avlTree::left_right_rotation(avl_node *parent) {
  avl_node *temp = parent->left;
  parent->left = right_right_rotation(temp);
  return left_left_rotation(parent);
}

/*
 * Right- Left Rotation
 */
avl_node *avlTree::right_left_rotation(avl_node *parent) {
  avl_node *temp = parent->right;
  parent->right = left_left_rotation(temp);
  return right_right_rotation(parent);
}

/*
 * Balancing AVL Tree
 */
avl_node *avlTree::balance(avl_node *temp) {
  int bal_factor = diff(temp);
  if (bal_factor > 1) {
    if (diff(temp->left) > 0)
      temp = left_left_rotation(temp);
    else
      temp = left_right_rotation(temp);
  } else if (bal_factor < -1) {
    if (diff(temp->right) > 0)
      temp = right_left_rotation(temp);
    else
      temp = right_right_rotation(temp);
  }
  return temp;
}

/*
 * Insert Element into the tree
 */
avl_node *avlTree::insert(avl_node *root, int value) {
  if (root == NULL) {
    root = new avl_node;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
  } else if (value < root->data) {
    root->left = insert(root->left, value);
    root = balance(root);
  } else if (value >= root->data) {
    root->right = insert(root->right, value);
    root = balance(root);
  }
  return root;
}

/*
 * Display AVL Tree
 */
void avlTree::display(avl_node *ptr, int level) {
  int i;
  if (ptr != NULL) {
    display(ptr->right, level + 1);
    printf("\n");
    if (ptr == root)
      cout << "Root -> ";
    for (i = 0; i < level && ptr != root; i++)
      cout << "        ";
    cout << ptr->data;
    display(ptr->left, level + 1);
  }
}

/*
 * Inorder Traversal of AVL Tree
 */
void avlTree::inorder(avl_node *tree) {
  if (tree == NULL)
    return;
  inorder(tree->left);
  cout << tree->data << "  ";
  inorder(tree->right);
}
/*
 * Preorder Traversal of AVL Tree
 */
void avlTree::preorder(avl_node *tree) {
  if (tree == NULL)
    return;
  cout << tree->data << "  ";
  preorder(tree->left);
  preorder(tree->right);

}

/*
 * Postorder Traversal of AVL Tree
 */
void avlTree::postorder(avl_node *tree) {
  if (tree == NULL)
    return;
  postorder(tree->left);
  postorder(tree->right);
  cout << tree->data << "  ";
}

TEST_RESULT test() {
  int choice, item;
  avlTree avl;
  while (1) {
    cout << "\n---------------------" << endl;
    cout << "AVL Tree Implementation" << endl;
    cout << "\n---------------------" << endl;
    cout << "1.Insert Element into the tree" << endl;
    cout << "2.Display Balanced AVL Tree" << endl;
    cout << "3.InOrder traversal" << endl;
    cout << "4.PreOrder traversal" << endl;
    cout << "5.PostOrder traversal" << endl;
    cout << "6.Exit" << endl;
    cout << "Enter your Choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter value to be inserted: ";
        cin >> item;
        root = avl.insert(root, item);
        break;
      case 2:
        if (root == NULL) {
          cout << "Tree is Empty" << endl;
          continue;
        }
        cout << "Balanced AVL Tree:" << endl;
        avl.display(root, 1);
        break;
      case 3:
        cout << "Inorder Traversal:" << endl;
        avl.inorder(root);
        cout << endl;
        break;
      case 4:
        cout << "Preorder Traversal:" << endl;
        avl.preorder(root);
        cout << endl;
        break;
      case 5:
        cout << "Postorder Traversal:" << endl;
        avl.postorder(root);
        cout << endl;
        break;
      case 6:
        exit(1);
        break;
      default:
        cout << "Wrong Choice" << endl;
    }
  }
  RETURN_OK();
}

}  // namespace avl_tree

#endif /* SRC_COMMON_AVL_TREE_H_ */
