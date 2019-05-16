
#include "pilha.h"
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

/* protótipo das funções*/
bool precede(char , char);
int aval_posfixa(const char *);

int main()
{
	pilha p;
	char simb;
	char infixa[40];
	char posfixa[40];
	int i = 0, j = 0;
	stack_init(&p);
	printf("Este programa converte uma expressão Infixa para Pós-fixa");
	printf("\n\nEntre com a expressão infixa: ");
	scanf("%39s", infixa); // lê a expressão infixa
	while (infixa[j] != '\0') { // varredura da expressão infixa
		simb = infixa[j++];
		if (isdigit(simb)) {
			// um operando vai diretamente
			posfixa[i++] = simb; // para a expressão pós-fixa
		}
		else {
			while (!stack_isempty(p) && precede(top(p), simb)) {
				/* Enquanto a pilha não estiver vazia e o operador do topo da
			 	 * pilha tiver precedência sobre o operador corrente na expressão
			 	 * infixa, o operador do topo da pilha é desempilhado ...*/
				posfixa[i++] = pop(&p); // ...e colocado na expressão pós-fixa
			}
			if (simb != ')') {
				push(&p, simb); // o operador da expressão infixa é empilhado
			}
			else {
				pop(&p); // descarta o parêntese da abertura
			}
		} // fim do else
	} // fim do while (varredura)
	while (!stack_isempty(p)) { // esvazia a pilha dos operadores
		posfixa[i++] = pop(&p);
	}
	posfixa[i] = '\0';
	printf("Expressão Pós-fixa: %s\n", posfixa);
	printf("Resultado da expressão: %d\n", aval_posfixa(posfixa));
	return 0;
}

bool precede(char op1, char op2)
{
	return (op1 != '(' && op2 != '(') && (op2 == ')' ||
	       (op1 == '*' || op1 == '/') || (op2 == '+' || op2 == '-'));
}


int aval_posfixa(const char * posfixa)
{
	pilha p;
	int i, x, y;
	char simb;

	stack_init(&p);
	for (i = 0; posfixa[i] != '\0'; i++) {
		simb = posfixa[i];
		if (isdigit(simb)) {
			push(&p, simb - '0');
		}
		else {
			y = pop(&p);
			x = pop(&p);
			switch (simb) {
				case '+': push(&p, x + y);
						  break;
				case '-': push(&p, x - y);
					      break;
				case '*': push(&p, x * y);
						  break;
				case '/': push(&p, x / y);
			}
		}
	}
	return top(p);
}
