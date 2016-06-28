#include "binary_tree.h"
#include <iostream>
#include <ctime>

using namespace std;


class Test {

private:

    vector < float > nums;

    vector < vector < float >* > tree;

public:

    Test(int count_element) {

        for (int it = 0; it < count_element; it++) {
            nums.push_back(rand() % 100);
        }
        print(generate_tree(nums));
    }

    void add_vector(int deep, float value, vector < vector < float >* > *tree) {
        if (tree->size() <= deep) {
            tree->push_back(new vector < float >);
        }
        tree->at(deep)->push_back(value);
    }

    void represent_tree(int deep, TreeNode *cur, vector < vector < float >* > *tree) {

        add_vector(deep, cur->value, tree);

        if (cur->left != NULL) {
            represent_tree(deep + 1, cur->left, tree);
        }
        else {
            add_vector(deep + 1, NULL, tree);
        }
        if (cur->right != NULL) {
            represent_tree(deep + 1, cur->right, tree);
        }
        else {
            add_vector(deep + 1, NULL, tree);
        }
    }

    void print(TreeNode *root) {
        cout << "------------" << endl;
        for (int it = 0; it < nums.size(); it++) {
            cout << nums[it] << " ";
        }
        cout << endl << "------------" << endl;
        represent_tree(0, root, &tree);
        for (int i = 0; i < tree.size(); i++) {
            for (int j = 0; j < tree[i]->size(); j++) {
                cout << tree[i]->at(j) << " ";
            }
            cout << endl;
            tree[i]->clear();
        }
    }

    ~Test() {
        nums.clear();
        tree.clear();
    }
};



int main() {

    srand(time(NULL));

    for (int test = 0; test <= 5; test++) {
        Test *new_test = new Test(rand() % 20 + 1);
        delete new_test;
    }

    return 0;
}