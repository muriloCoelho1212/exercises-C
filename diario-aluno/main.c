#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
  char nome[80];
  char RA[7];
  float nota[2];
  float media;
} Aluno;

void aloca(Aluno **p, int qtd);
void cadastro(Aluno *p);
int busca(Aluno *p, int qtd);
void controle(Aluno *p);

int main()
{
  Aluno *al = NULL;
  int op, qtd = 0, indice;

  do
  {
    system("cls");
    printf("\nMenu\n");
    printf("[1] Cadastro\n[2] Controle de Notas\n[3] Sair\n");
    printf("Digite uma opcao: ");
    scanf("%i", &op);
    fflush(stdin);

    switch (op)
    {
    case 1:
      aloca(&al, qtd + 1);
      cadastro(al + qtd);
      qtd++;
      break;
    case 2:
      indice = busca(al, qtd);
      if (indice == -1)
      {
        printf("\nRA Inexistente\n");
        system("pause");
      }
      else
      {
        controle(al + indice);
      }
    }
  } while (op != 3);

  return 0;
}

void aloca(Aluno **p, int tam)
{
  if ((*p = (Aluno *)realloc(*p, tam * sizeof(Aluno))) == NULL)
  {
    printf("\nErro de Alocacao");
    exit(1);
  }
}

void cadastro(Aluno *p)
{
  int i;

  printf("\nNome: ");
  gets(p->nome);
  fflush(stdin);
  printf("\nRA: ");
  gets(p->RA);
  fflush(stdin);
  for (i = 0; i < 2; i++)
    *(p->nota + i) = 0;
  p->media = 0;

  printf("\nCadastro efetuado com sucesso\n");
  system("pause");
}

int busca(Aluno *p, int tam)
{
  int i;
  char aux[7];

  printf("\nBusque por um RA: ");
  gets(aux);
  fflush(stdin);
  for (i = 0; i < tam; i++)
    if (strcmp((p + i)->RA, aux) == 0)
      return i;
  return -1;
}

void controle(Aluno *p)
{
  int i;

  p->media = 0;

  printf("\nConferencia: ");
  printf("\nNome: %s", p->nome);
  printf("\nRA: %s", p->RA);

  printf("\n\nDigite as notas de %s\n\n", p->nome);

  for (i = 0; i < 2; i++)
  {
    do
    {
      printf("\nNota %i: ", i + 1);
      scanf("%f", p->nota + i);
      fflush(stdin);
    } while (*(p->nota + i) < 0 || *(p->nota + i) > 10);
  }

  printf("\nNotas digitadas: ");

  for (i = 0; i < 2; i++)
  {
    p->media += *(p->nota + i);
    printf("\nNota %i: %.2f", i + 1, *(p->nota + i));
  }

  p->media /= 2;

  printf("\nMedia: %.2f\n\n", p->media);
  system("pause");
}