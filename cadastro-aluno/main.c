#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
  char nome[30];
  int idade;
  float nota;
} Aluno;

Aluno cadastro();

int main()
{
  Aluno aluno[10];
  char op;
  int i, cont = 0;

  do
  {
    system("cls");
    if (cont < 10)
    {
      aluno[cont] = cadastro();
      cont++;
    }
    else
    {
      printf("Limite de alunos atingido!\n");
    }
    printf("Deseja cadastrar outro aluno? (s/n): ");
    scanf("%c", &op);
    fflush(stdin);
  } while (op == 's' || op == 'S');

  system("cls");

  for (i = 0; i < cont; i++)
  {
    printf("Aluno %i\n", i + 1);
    printf("Nome: %s\n", aluno[i].nome);
    printf("Idade: %i\n", aluno[i].idade);
    printf("Nota: %.2f\n", aluno[i].nota);
    printf("\n");
  }

  return 0;
}

Aluno cadastro()
{
  Aluno aluno;
  printf("Nome: ");
  gets(aluno.nome);
  printf("Idade: ");
  scanf("%i", &aluno.idade);
  printf("Nota: ");
  scanf("%f", &aluno.nota);
  fflush(stdin);
  return aluno;
}