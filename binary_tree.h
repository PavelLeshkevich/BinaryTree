//
// Created by pablo on 28.06.16.
//

#ifndef BINARYTREE_BINARY_TREE_H
#define BINARYTREE_BINARY_TREE_H

#endif //BINARYTREE_BINARY_TREE_H

#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {

    float value;

    TreeNode *left;

    TreeNode *right;

};

void build_tree(int left, int right, vector < float > *nums, TreeNode *cur_node, TreeNode *last_node, int deep) {
    if(left < right) {

        int middle = (right + left) / 2;

        cur_node->value = (nums->at(middle) + nums->at(middle + 1)) / 2;

        cur_node->left = new TreeNode;
        cur_node->right = new TreeNode;

        build_tree(left, middle, nums, cur_node->left, cur_node, deep - 1);
        build_tree(middle + 1, right, nums, cur_node->right, cur_node, deep - 1);
    }
    else {
        if(deep == 0) {
            cur_node->value = nums->at(left);
            cur_node->left = cur_node->right = NULL;
        }
        else {
            if (last_node->value < nums->at(left)) {
                cur_node->value = last_node->value;
                cur_node->value += (nums->at(left) - last_node->value) / (deep + 1);
                cur_node->right = new TreeNode;
                cur_node->left = NULL;
                build_tree(left, right, nums, cur_node->right, cur_node, deep - 1);
            }
            else {
                cur_node->value = last_node->value;
                cur_node->value -= (last_node->value - nums->at(left)) / (deep + 1);
                cur_node->left = new TreeNode;
                cur_node->right = NULL;
                build_tree(left, right, nums, cur_node->left, cur_node, deep - 1);
            }
        }
    }
}

TreeNode *generate_tree(vector < float > nums) {

    if(nums.size() == 0) {
        return NULL;
    }

    int const_deep = 0, lg = 1;

    while(lg < nums.size()) {
        const_deep++;
        lg *= 2;
    }

    sort(nums.begin(), nums.end());

    TreeNode *root = new TreeNode;

    build_tree(0, nums.size() - 1, &nums, root, NULL, const_deep);

    return root;

}