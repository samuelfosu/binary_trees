#include "binary_trees.h"

/**
 * is_leaf - checks if a node is a leaf
 * @node: pointer to check node
 *
 * Return: 1 if node is a leaf, otherwise 0
 */

unsigned char is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}


/**
 * depth - measures the depth of a node in a binary tree
 * @tree: pointer to measure the depth
 *
 * Return: depth of the node
 */

size_t depth(const binary_tree_t *tree)
{
	size_t tree_depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree_depth++;
		tree = tree->parent;
	}

	return (tree_depth);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to find a leaf in root node
 *
 * Return: first encountered leaf.
 */

const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);

	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively
 * @tree: A pointer to check root node
 * @leaf_depth: The depth of one leaf in the binary tree
 * @level: Level of current node
 *
 * Return: If the tree is perfect, 1, or 0
 */

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (is_leaf(tree))
		return (level == leaf_depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to check root node
 *
 * Return: 1 if tree is perfect, or 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
