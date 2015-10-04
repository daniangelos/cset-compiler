all: tokenizer parser # compile

tokenizer: src/cset.l
	lex src/cset.l

parser: src/cset.y
	bison src/cset.y -d -v --graph

compile:
	gcc cset.tab.c -ly -lfl -o cset

clean: 
	rm lex.yy.c
	rm cset.tab.*
	rm cset.output
	rm cset.dot
	rm *.o
	rm cset
