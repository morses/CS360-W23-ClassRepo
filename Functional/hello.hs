import Data.Char

doubleMe :: Int -> Int
doubleMe x = 2 * x

addOne x = x + 1

main = putStrLn "Hello World"

dot :: Num a => (a,a,a) -> (a,a,a) -> a
--dot (0,0,0) (0,0,0) = 0
dot (a,b,c) (x,y,z) = a*x + b*y + c*z

sndList [] = error "Won't work for an empty list"
sndList [x] = error "There is no second element"
sndList (x:y:ys) = y

showEvenness x 
    | even x = "You're even"
    | odd x = "You're odd"
    | otherwise = "You're special"

-- "Hello" -> 1
-- "HeLLo" -> 3
-- "hello" -> 0

-- using a list comprehension
countUpper [] = 0
countUpper (x:xs)
    | isUpper x = 1 + countUpper xs
    | otherwise = 0 + countUpper xs

countUpper' [] = 0
countUpper' (x:xs) = if isUpper x 
    then 1 + countUpper' xs 
    else 0 + countUpper' xs

foo x y = 100*(x + y/2)

foo2 = foo 4

-- using explicit recursion
p2 :: a -> [a] -> [a]
p2 x []     = []
p2 x [y]    = [y]
p2 x (y:ys) = y:x:p2 x ys


--foldr (\x acc -> acc + x) 0 [1..10]

-- ["abc","hello","forget","world"] -> [3,5,6,5]
p3 = foldr (\x acc -> length x:acc) [] ["abc","hello","forget","world"]