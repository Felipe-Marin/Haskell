--1
isEven :: Int->Bool
isEven n = mod n 2 == 0

--2
somaquad :: Int->Int->Int
somaquad x y = x^2+y^2

--3
doubleFirst :: [Int]->Int
doubleFirst x = head x^2

--4
hasEqHeads :: [Int]->[Int]->Bool
hasEqHeads x y = head x == head y

--5
addMr :: [String]->[String]
addMr x = map ("Mr."++) x

--6
nSpace :: String->Int
nSpace x = length(filter(==' ') x)

--7
calcList :: [Double]->[Double]
calcList x = map (\n->3*n^2+2/n+1) x

--8
dep1970 :: [Int]->[Int]
dep1970 x = map(2015-) (filter(>1970) (map(2015-) x))

--9
serie :: Double->[Double]->Double
serie x y = sum(map(/x) y)

--10
charFound :: Char -> String -> Bool
charFound c s = filter(==c)s /=""

--11
htmlListItems :: [String]->[String]
htmlListItems x = map(++"</LI>") (map ("<LI>"++) x)

--12
--takeWhile (<5) [1,2,3,4,5]
--[1,2,3,4]
--takeWhile (/=' ') "Fulana de Tal"
--"Fulana"
--takeWhile(\n->2*n<20) [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
--[1,2,3,4,5,6,7,8,9]

--13
endA :: [String]->[String]
endA s = filter(\n->last n=='a')s