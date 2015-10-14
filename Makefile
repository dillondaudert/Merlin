all: depend
	gcc -g -lm TESTsymbol.tab.c lex.yy.c -o merlin

depend: bison flex

bison:
	bison -d TESTsymbol.y
	
flex:
	flex TESTsymbol.l
	
clean:
	rm merlin TESTsymbol.tab.c lex.yy.c
