#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void listar(unsigned char armarios) {
  unsigned char posicao;
  for (int i = 0; i < 8; i++) {
    posicao = (unsigned char)pow(2, i);
    printf((armarios & posicao) ? " x " : " %d ", i + 1);
  }
  puts("");
}

unsigned char ocupar(unsigned char armarios) {
  unsigned char ocupacao;
  do {
    ocupacao = rand() % 8;
    ocupacao = (unsigned char)pow(2, ocupacao);
  } while ((ocupacao | armarios) == armarios);
  armarios = ocupacao | armarios;
  return armarios;
}

unsigned char desocupar(unsigned char armarios, unsigned char remover) {
  armarios &= ~(unsigned char)pow(2, remover - 1);
  return armarios;
}

int main(void) {
  unsigned char armario = 0, escolha, tirar;
  do {
    listar(armario);
    srand(time(NULL));
    printf("Insira o valor do armario: %hhu\n", armario);
    puts("1- Ocupar Armario.");
    puts("2- Desocupar Armario.");
    puts("3- Sair.");
    printf("Escolha: ");
    scanf("%hhu", &escolha);
    switch (escolha) {
    case 1:
      if (armario == 255) {
        puts("Os armarios estao todos ocupados");
      } else {
        armario = ocupar(armario);
      }
      break;
    case 2: 
      printf("\nQual armario que deseja desocupar\n");
      printf("Escolha: ");
      scanf("%hhu", &tirar);
      if ((armario | (unsigned char)pow(2, tirar - 1)) == armario) {
        armario = desocupar(armario, tirar);
      } else {
        printf("O armario %d ja se encontra desocupado\n", tirar);
      }
      printf("");
      break;
    case 3:
      system("cls"); 
      puts("\n\nPrograma encerrado");
      break;
    default:
      puts("\nOperacao invalida!");
      puts("");
    }
  } while (escolha != 3);
  return 0;
}