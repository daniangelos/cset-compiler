%{
	#include <stdio.h>
	#define KEYWORD_ELSE 1
	#define ID 2
%}

%%

"else" { return KEYWORD_ELSE; } // reconhece a palavra chave "else"
[_a-zA-Z][_a-zA-Z0-9]* { return ID; } // reconhece identificadores

%%

int yywrap() { return 1; }

/* Ponto de entrada do programa. */
int main()
{
	int token;
	while ((token = yylex())) {
		if (token == KEYWORD_ELSE)
			printf("keyword 'else'\n");
		else if (token == ID)
			printf("identificador\n");
		else
			break;
	}
	return 0;
}
