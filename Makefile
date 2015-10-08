all: tokenizer parser compile

tokenizer: src/cset.l
	flex src/cset.l

parser: src/cset.y
	bison src/cset.y -d -v -t --graph

compile: tree.o table.o cset.o 
	gcc tree.o table.o cset.tab.o -o cset

tree.o: src/tree.h src/tree.c
	gcc src/tree.c -Wall -g -c 

table.o: src/table.h src/table.c
	gcc src/table.c -Wall -g -c

cset.o: cset.tab.c
	gcc cset.tab.c -ly -lfl -g -c

clean: 
	rm lex.yy.c
	rm cset.tab.*
	rm cset.output
	rm cset.dot
	rm *.o
	rm cset
