#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void listar(unsigned char armarios) {
  unsigned char pos;
  for (int i = 0; i < 8; i++) {
    pos = (unsigned char)pow(2, i);
    printf((armarios & pos) ? " x " : " %d ", i + 1);
  }
  puts("");
}

unsigned char ocupar(unsigned char armarios) {
  unsigned char ocup;
  do {
    ocup = rand() % 8;
    ocup = (unsigned char)pow(2, ocup);
  } while ((ocup | armarios) == armarios);
  armarios = ocup | armarios;
  return armarios;
}

unsigned char desocupar(unsigned char armarios, unsigned char remov) {
  armarios &= ~(unsigned char)pow(2, remov - 1);
  return armarios;
}

int main(void) {
  unsigned char armario = 0, esc, tir;
  do {
    listar(armario);
    srand(time(NULL));
    printf("Insira o valor do armário: %hhu\n", armario);
    puts("1- Ocupar armário");
    puts("2- Desocupar armário");
    puts("3- Sair");
    printf("Escolha: ");
    scanf("%hhu", &esc);
    switch (esc) {
    case 1:
      if (armario == 255) {
        puts("Os armários estao todos ocupados!");
      } else {
        armario = ocupar(armario);
      }
      break;
    case 2: 
      printf("\nQual armário que deseja desocupar?\n");
      printf("Escolha: ");
      scanf("%hhu", &tir);
      if ((armario | (unsigned char)pow(2, tir - 1)) == armario) {
        armario = desocupar(armario, tir);
      } else {
        printf("O armário %d já se encontra desocupado\n", tir);
      }
      printf("");
      break;
    case 3:
      system("cls"); 
      puts("\n\nPrograma encerrado!");
      break;
    default:
      puts("\nOperacao invalida!");
      puts("");
    }
  } while (esc != 3);
  return 0;
}