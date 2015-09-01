--1
eleva2::[Int]->[Int]
eleva2 [] = []
eleva2 x = head x^2 : eleva2(tail x)

--2
contido::Char->String->Bool
contido _ [] = False
contido c s = if c == head s
	then True
	else contido c (tail s)

--3
semVogais::String->String
semVogais s
	|s == "" = ""
	|head s == 'a' = semVogais(tail s)
	|head s == 'e' = semVogais(tail s)
	|head s == 'i' = semVogais(tail s)
	|head s == 'o' = semVogais(tail s)
	|head s == 'u' = semVogais(tail s)
	|otherwise = (head s) : semVogais(tail s)

--4
translate::[(Float, Float)]->[(Float, Float)]
translate [] = []
translate l = (fst(head l) + 2,  snd(head l) + 2) : translate(tail l)

--5
aux::Int->Int->[(Int, Int)]
aux x y = if(x<=y)
	then (x, x^2):aux (x+1) y
	else []

geraTabela::Int->[(Int, Int)]
geraTabela 0 = []
geraTabela x = aux 1 x

