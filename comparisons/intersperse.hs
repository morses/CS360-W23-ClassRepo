import Data.List (intersperse)

input = "ABCDEFG"
-- example output, intersperse a string with ',' should produce "A,B,C,D,E,F,G"

-- using the built-in function (yes, cheating)
p1 :: a -> [a] -> [a]
p1 = intersperse

-- using explicit recursion
p2 :: a -> [a] -> [a]
p2 x []     = []
p2 x [y]    = [y]
p2 x (y:ys) = y:x:p2 x ys

-- using a fold
p3 :: Foldable t => a -> t a -> [a]
p3 x = foldr (\z acc -> if null acc then z:acc else z:x:acc) []


assert1 = p1 ',' input == p2 ',' input
assert2 = p1 ',' input == p3 ',' input
