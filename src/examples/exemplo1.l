/* Se��o de Declara��es */
%{
	/* exemplo1.l */
	#include <stdio.h>

	/* Vari�veis globais para contar o n�mero de linhas e caracteres. */
	int charcount=0, linecount=0;
%}

/* Se��o de Regras de Casamento */
%%

. { charcount++; } /* O '.' � uma express�o regular que faz casamento com qualquer caractere que n�o seja '\n', neste caso, a a��o ir� apenas incrementar o n�mero de caracteres. */
\n { linecount++; charcount++; } /* Incrementa o n�mero de linhas e o n�mero de caracteres ao encontrar '\n'. */

%%

/* Se��o de C�digo Auxiliar */

/* A funcao yywrap � chamada pelo flex quando o final do arquivo � atingido. Neste exemplo, ela n�o faz nada, mas poderia, por exemplo abrir outros arquivos se necess�rio. */
int yywrap() { return 1; }

/* Ponto de entrada do programa. */
int main()
{
	/* Chamada para o analisador l�xico, esta fun��o � declarada automaticamente pelo flex. Neste caso, vai ler da entrada padr�o at� encontrar EOF (CTRL+D). */
	yylex();
	printf("Foram informados %d caracteres em %d linhas\n", charcount, linecount);
	return 0;
}
