/* prolog implementation of a binary search tree */

/* first define the tree */
/* takes in 3 values as follows */
tree(N, Left, Right).

/* search for a given value */
search(N, tree(N, Left, Right)).
search(N, tree(Root, Left, Right)):- N =< Root, search(N, Left).
search(N,tree(Root, Left, Right)):- search(N, Right).

/* insert a new node onto the tree */
insert(N, empty, tree(N, empty, empty)).
insert(N, tree(Root, Left, Right), tree(Root, LLeft, Right)):- N =< Root, insert(N, Left, LLeft).
insert(N, tree(Root, Left, Right), tree(Root, Left, RRight)):- N > Root, insert(N, Left, RRight).

/* inorder traversal */
inorder(empty, []).
inorder(tree(N, Left, Right), List):- inorder(Left, LeftList), append(LeftList, [N], LeftValue), inorder(Right, RightList), append(LeftValue, RightList, List).

/* preorder traversal */
preoder(empty, []).
preorder(tree(N, Left, Right), List):- preorder(left, LeftList), append([N], LeftList, LeftValue), preorder(Right, RightList), append(LeftValue, RightList, List).

/* postorder traversal */
postorder(empty, []).
postorder(tree(N, Left, Right), List):- postorder(Left, LeftList), postorder(Right, RightList), append(LeftList, RightList, LList), append(LList, [N], List).
