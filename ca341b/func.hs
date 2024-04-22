-- Haskell Implementation of Binary Tree

-- first define a data type
data Tree x =
    Null | Node x (Tree x) (Tree x)
    deriving (Eq, Ord, Show)

-- creating the binary tree
makeTree :: Ord x => [x] -> Tree x
makeTree [] = Null
makeTree [i] = Node i Null Null
makeTree (i:is) = insert i (makeTree is)

-- insert value into tree
insert :: Ord x => x -> Tree x -> Tree x
insert i Null = Node i Null Null
insert i (Node n leftChild rightChild)
    | i == n = Node n leftChild rightChild
    | i < n = Node n (insert i leftChild) rightChild
    | i > n = Node n leftChild (insert i rightChild)

-- search the tree for a given value
search :: Ord x => x -> Tree x -> Bool
search i Null = False
search i (Node n leftChild rightChild)
    | i == n = True
    | i < n = search i leftChild
    | i > n = search i rightChild

-- get preorder traversal of the tree in list form
preorder :: Tree x -> [x]
preorder Null = []
preorder (Node i leftChild rightChild) = [i] ++ preorder leftChild ++ preorder rightChild

-- get inorder traversal in list form
inorder :: Tree x -> [x]
inorder Null = []
inorder (Node i leftChild rightChild) = inorder leftChild ++ [i] ++ inorder rightChild

-- get the postorder traversal in list form
postorder :: Tree x -> [x]
postorder Null = []
postorder (Node i leftChild rightChild) = postorder leftChild ++ postorder rightChild ++ [i]

