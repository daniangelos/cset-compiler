/* Seção de Declarações */
%{
	/* exemplo1.l */
	#include <stdio.h>

	/* Variáveis globais para contar o número de linhas e caracteres. */
	int charcount=0, linecount=0;
%}

/* Seção de Regras de Casamento */
%%

. { charcount++; } /* O '.' é uma expressão regular que faz casamento com qualquer caractere que não seja '\n', neste caso, a ação irá apenas incrementar o número de caracteres. */
\n { linecount++; charcount++; } /* Incrementa o número de linhas e o número de caracteres ao encontrar '\n'. */

%%

/* Seção de Código Auxiliar */

/* A funcao yywrap é chamada pelo flex quando o final do arquivo é atingido. Neste exemplo, ela não faz nada, mas poderia, por exemplo abrir outros arquivos se necessário. */
int yywrap() { return 1; }

/* Ponto de entrada do programa. */
int main()
{
	/* Chamada para o analisador léxico, esta função é declarada automaticamente pelo flex. Neste caso, vai ler da entrada padrão até encontrar EOF (CTRL+D). */
	yylex();
	printf("Foram informados %d caracteres em %d linhas\n", charcount, linecount);
	return 0;
}
