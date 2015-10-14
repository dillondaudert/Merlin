all: depend
	gcc -g -lm grammar.tab.c lex.yy.c -o merlin

depend: bison flex

bison:
	bison -d grammar.y
	
flex:
	flex flex.l
	
clean:
	rm merlin grammar.tab.* lex.yy.c
