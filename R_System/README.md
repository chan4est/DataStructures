# Important Notes Learned

## AVL Tree vs. R-B Tree
**AVL Trees** are more balanced, but they may have more rotations during an insert and delete. If search is frequent, use AVL

**R-B Trees** have faster rotations O(1) but might be a bit 'fatter'. If insert and deletions are more frequent, use R-B.

## Recursive vs. Iterative
Generally better to use non-recursive methods when possible.

Recursive functions are usually elegant, but require more memory (because of the stack).

Iterative methods look ugly, and might be slower, but use less memory.

