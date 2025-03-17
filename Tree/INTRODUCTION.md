# Tree

## What is Tree Data Structure?

A **tree** is a hierarchical, non-linear data structure composed of nodes connected by edges. Each node can have only one parent but may have multiple child nodes.

## Terminologies

- **Root Node:** The topmost node in a tree; it has no parent.
- **Parent Node:** A node's upper node from which it is derived.
- **Child Node:** A node derived from another node, making it a child of that node.
- **Leaf Nodes:** Nodes with no child nodes, located at the bottom of the tree.
- **Siblings:** Nodes that share the same parent node.
- **Ancestor Node:** A node's parent or any node above it in the hierarchy.
- **Descendant Node:** Nodes that are children or children's children of a particular node.
- **Subtree:** A segment of the tree that contains a node and all its descendants.
- **Level of a Node:** The depth level at which a node resides.
- **Number of Edges:** The connections between nodes; a tree with N nodes contains (N-1) edges.
- **Depth of a Node:** The length of the path from the root to that node, measured in edges.
- **Height of a Node:** The longest path from the node to a leaf node.
- **Height of the Tree:** The length of the longest path from the root to a leaf node.
- **Degree of a Node:** The total count of subtrees attached to that node; leaf nodes have a degree of 0.

## Usage

- Representing hierarchical data
- File systems
- Data compression
- Compiler design

## Operations

- **Creation:** Creating a new tree or adding a root node.
- **Insertion:** Adding nodes to a tree while maintaining its properties.
- **Traversal:** Visiting nodes in a specific order:
  - **Pre-order traversal**
  - **In-order traversal**
  - **Post-order traversal**
- **Search:** Finding a node based on its value.

## Advantages

- Efficient searching
- Structured representation of hierarchical data
- Easy traversal and manipulation

## Limitations

- Skewed trees can increase search time.
- Requires more memory.
- Complex insertion and deletion operations, especially in self-balancing trees.

## Types of Trees

### General Trees

1. **Binary tree:** Each node has at most two children.
2. **Ternary tree:** Each node has at most three children.
3. **Generic tree:** Each node can have any number of child nodes.

### Types of Binary Trees

1. **Binary tree:** A tree where each node has at most two children — a left child and a right child.
2. **Full binary tree:** Each node has either 0 or 2 children.
3. **Complete binary tree:** All levels are completely filled except possibly the last level, which is filled from left to right.
4. **Perfect binary tree:** All leaf nodes are at the same level without any missing nodes.
5. **Balanced binary tree:** The height of the tree is at most log(n), where n is the number of nodes.
6. **Degenerate tree:** A skewed tree where each node has only one child, resembling a linked list.
7. **Binary search tree (BST):** A binary tree where the left child contains values less than the parent, and the right child contains values greater than the parent.

### Types of Binary Search Trees

1. **AVL tree:** A self-balancing BST where the height difference between left and right subtrees of any node is at most 1.
2. **Red-black tree:** A self-balancing BST where each node contains an extra bit to store its color (red or black).
3. **B-tree:** A self-balancing BST used in databases and file systems. It maintains sorted data and allows searches, sequential access, insertions, and deletions in O(log n) time.
4. **B+ tree:** A variation of the B-tree where all records are stored in leaf nodes (data blocks) and internal nodes contain only keys. Used in databases to reduce disk access.
5. **Segment tree:** Used for storing intervals or segments of data, supporting range queries like finding minimum, maximum, or sum over a range efficiently.

## Algorithms

### Binary Tree Insertion

- If the tree is empty, create a new node.
- If `value < root’s value`, insert into the left subtree.
- If `value > root’s value`, insert into the right subtree.

### Binary Tree Traversal

- **In-order (LNR):** Left → Root → Right
- **Pre-order (NLR):** Root → Left → Right
- **Post-order (LRN):** Left → Right → Root
- **Level-order:** Use a queue, process nodes level by level.

### Search

- If root is `NULL`, return `NULL`.
- If `root’s value` matches the target, return `root`.
- If `target < root’s value`, search in the left subtree.
- If `target > root’s value`, search in the right subtree.

### Deletion

- If `value < root’s value`, recurse on the left subtree.
- If `value > root’s value`, recurse on the right subtree.
- If `value` matches:
  - **Node with 0 or 1 child:** Replace node with child.
  - **Node with 2 children:** Replace with in-order successor and delete successor.

### Find Min/Max

- **Find Min:** Traverse the leftmost path.
- **Find Max:** Traverse the rightmost path.

### Binary Search Tree Insertion

- If tree is empty, create a new node.
- If `value ≤ root’s value`, insert in the left subtree.
- If `value > root’s value`, insert in the right subtree.

### Find Predecessor

- Start at root, traverse right from the left subtree.
- If node’s left subtree exists, find the max in the left subtree.

### Find Successor

- Start at root, traverse left from the right subtree.
- If node’s right subtree exists, find the min in the right subtree.

### Convert to Balanced BST

- Perform in-order traversal and store nodes in an array.
- Recursively construct BST from a sorted array using the middle element as root.

### AVL Tree Insertion

1. Perform BST insertion.
2. Update height.
3. Calculate balance factor.
4. Rotate if necessary:
   - **Left-Left (LL) → Right Rotation**
   - **Right-Right (RR) → Left Rotation**
   - **Left-Right (LR) → Left Rotation + Right Rotation**
   - **Right-Left (RL) → Right Rotation + Left Rotation**

### AVL Tree Deletion

1. Perform standard BST deletion.
2. Update height.
3. Calculate balance factor and perform rotations if necessary.
4. **Balancing:**
   - **Balance Factor:** `height(left subtree) - height(right subtree)`
   - **Rotations:**
     - **Left Rotation:** Moves right-heavy subtree up.
     - **Right Rotation:** Moves left-heavy subtree up.
5. **Find Min Node:** Traverse leftmost path.
