##Merlin
####A Programming Language written using Bison/Flex


The Bison grammar is defined in grammar.y
The lexical scanner is defined in flex.l


####Compile

`make`


####Merlin syntax

Merlin is an interpreter with a novel, themed syntax. Features included are: 
- dynamic typing
```
a = b = 3
b = "Hello"
```

- dynamic scope

- if-else statements
```
Inquire (A == B) Cast
    Scribe "True"
Smite Alternate Cast
    Scribe "False"
Smite
```

- function declarations
```
Research Print(A)
Cast
    Scribe A
Smite
```

- type promotion
```
a = 3
b = 4.4
a = a + b //Equals 7.4
```

####Notes
The language is not quite polished. There are a few errors.
For one, unnamed values are saved in the symbol table but are re-referentiable $
Functions are nestable but cause some recursive calling of yyparse() that isn't$
Loops are not implemented, but the jury is out if it is even possible to do loo$

