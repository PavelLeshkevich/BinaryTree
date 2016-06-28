//
// Created by pablo on 28.06.16.
//

#ifndef BINARYTREE_BINARY_TREE_H
#define BINARYTREE_BINARY_TREE_H

#endif //BINARYTREE_BINARY_TREE_H

#include <vector>
#include <algorithm>

struct TreeNode {

    float value;

    TreeNode *left;

    TreeNode *right;

};

void add_tree(TreeNode *cur_node, TreeNode *new_node) {
    if (cur_node->value > new_node->value) {
        if (cur_node->left == NULL) {
            cur_node->left = new_node;
            return;
        }
        else {
            add_tree(cur_node->left, new_node);
        }
    }
    else {
        if (cur_node->right == NULL) {
            cur_node->right = new_node;
            return;
        }
        else {
            add_tree(cur_node->right, new_node);
        }
    }
}

TreeNode *generate_tree(std::vector < float > nums) {

    random_shuffle(nums.begin(), nums.end());

    TreeNode *root = new TreeNode;
    if (nums.size() > 0) {

        root->left = root->right = NULL;
        root->value = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            TreeNode *new_node = new TreeNode;
            new_node->left = new_node->right = NULL;
            new_node->value = nums[i];

            add_tree(root, new_node);
        }
        return root;
    }
    else {
        return NULL;
    }
}