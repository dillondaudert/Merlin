Merlin
A Programming Language written using Bison/Flex

The Bison grammar is defined in TESTsymbol.y (working name)
The lexical scanner is defined in TESTsymbol.l (working name)

A Makefile is not provided yet

To compile: 

make


The program is not quite polished. There are a few errors; for one, unnamed values are saved in the symbol table but are re-referentable so it causes some interesting interactions. Functions are nestable but cause some recursive calling of yyparse() that isn't quite solved. Loops are not implemented :(.


