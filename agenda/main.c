#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda
{
  int registro;
  char nome[20];
  float nota;
} Agenda;

void aloca(Agenda **p, int tam);
void cadastro(Agenda *p);
void mostra(Agenda *p, int tam);

int main()
{
  Agenda *ag = NULL;
  int op, cont = 0;

  do
  {
    system("cls");
    printf("Menu\n [1] Cadastro\n [2] Mostrar\n [3] Sair\n");
    printf("Digite a opcao: ");
    scanf("%i", &op);
    fflush(stdin);

    switch (op)
    {
    case 1:
      aloca(&ag, cont + 1);
      cadastro(ag + cont);
      cont++;
      break;
    case 2:
      mostra(ag, cont);
      break;
    }
  } while (op < 3);

  return 0;
}

void aloca(Agenda **p, int tam)
{
  if ((*p = (Agenda *)realloc(*p, tam * sizeof(Agenda))) == NULL)
  {
    printf("Erro de alocacao de memoria!\n");
    exit(1);
  }
}

void cadastro(Agenda *p)
{
  static int reg = 1;
  p->registro = reg;
  reg++;

  printf("Nome: ");
  gets(p->nome);
  fflush(stdin);

  do
  {
    printf("Nota: ");
    scanf("%f", &p->nota);
    fflush(stdin);
  } while (p->nota < 0 || p->nota > 10);

  system("pause");
}

void mostra(Agenda *p, int tam)
{
  int i;

  system("cls");

  for (i = 0; i < tam; i++, p++)
  {
    printf("Registro: %i\n", p->registro);
    printf("Nome: %s\n", p->nome);
    printf("Nota: %.2f\n", p->nota);
    printf("\n");
  }

  system("pause");
}