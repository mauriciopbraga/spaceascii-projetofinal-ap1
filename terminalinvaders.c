//Projeto final - Algoritmos e Programação I
//Jogo Terminal Invaders (baseado em Space Invaders) - O jogo consiste em destruir todas as naves inimigas

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

int main(){

  setlocale(LC_ALL, "portuguese");

  //Setar Título no console
  system("title Terminal Invaders");

  //Variáveis
  int tamanhoy = 23;
  int tamanhox = 40;
  int x, y, yi;
  char arena[tamanhoy][tamanhox];
  char nave = 'A';
  char tironave = '^';
  char inimigo = 'W';
  char escudoinimigo = 'U';
  char tiroinimigo = '*';
  char explosao = 'X';
  int score = 0;
  int scorebonus;
  int vitoria = 1;
  int tiropronto = 1;
  int inimigopronto = 0;
  int i = 1;
  int inimigosvivos;
  char direcao = 'l';
  char pressionartecla;
  int velocidadeinimigo;
  int cair;
  int totaldeinimigos;

  srand(time(NULL));

  //Tela inicial
  Sleep(500);
  printf("\n     ######## ######## ########  ##     ## #### ##    ##    ###    ##\n");
  printf("        ##    ##       ##     ## #### ####  ##  ####  ##  ##   ##  ##\n");
  printf("        ##    ######   ########  ## ### ##  ##  ## ## ## ######### ##\n");
  printf("        ##    ##       ##   ##   ##     ##  ##  ##  #### ##     ## ##\n");
  printf("        ##    ######## ##     ## ##     ## #### ##    ## ##     ## ########\n");
  printf("\n      #### ##    ## ##     ##    ###    ########  ######## ########   ######\n");
  printf("       ##  ###   ## ##     ##  ##   ##  ##     ## ##       ##     ## ##     #\n");
  printf("       ##  ## ## ## ##     ## ######### ##     ## ######   ########    ####\n");
  printf("       ##  ##   ###   ## ##   ##     ## ##     ## ##       ##    ##  #     ##\n");
  printf("      #### ##    ##    ###    ##     ## ########  ######## ##     ##  ######\n\n\n");
  Sleep(1000);
  printf("            Destrua todas as naves inimigas para salvar seu terminal!\n\n");
  Sleep(1000);
  printf("                                Controles: A, D, W\n\n");
  Sleep(1000);
  printf("                                     Boa sorte.\n\n\n");
  Sleep(1000);
  printf("                                  [START - ENTER]");
  getch();

  //Iniciando a arena
  totaldeinimigos = 0;
  for(x = 0; x < tamanhox; x++){
    for(y = 0; y < tamanhoy; y++){
      if((y+1) % 2 == 0 && y < 7 && x > 4 && x < tamanhox - 5 && x % 2 ==0){
        arena[y][x] = inimigo;
        totaldeinimigos++;
      }
      else if((y+1) % 2 == 0 && y >= 7 && y < 9 && x > 4 && x < tamanhox - 5 && x % 2 == 0){
        arena[y][x] = escudoinimigo;
        totaldeinimigos = totaldeinimigos + 2;
      }
      else{
        arena[y][x] = ' ';
      }
    }
  }
  inimigosvivos = totaldeinimigos;

  arena[tamanhoy - 1][tamanhox / 2] = nave;

  while(totaldeinimigos > 0 && vitoria){
    velocidadeinimigo = 1 + 10 * inimigosvivos / totaldeinimigos;
    cair = 0;
    tiropronto++;
  //Exibir arena
  system("cls");
  printf("    SCORE: %d", score);
  printf("\n");
    for(y = 0; y < tamanhoy; y++){
      printf("|");
      for(x = 0; x < tamanhox; x++){
        printf("%c", arena[y][x]);
      }
      printf("|");
      printf("\n");
    }

    //Tempo do tiro
    for(x = 0; x < tamanhox; x++){
      for(y = tamanhoy - 1; y >= 0; y--){
        if(i % 2 == 0 && arena[y][x] == tiroinimigo && (arena[y + 1][x] != inimigo && arena[y + 1][x] != escudoinimigo)){
          arena[y + 1][x] = tiroinimigo;
          arena[y][x] = ' ';
          }
        else if(i%2 == 0 && arena[y][x] == tiroinimigo && (arena[y + 1][x] == inimigo | arena[y+1][x] == escudoinimigo)){
          arena[y][x] = ' ';
        }
      }
    }
    for(x = 0; x < tamanhox; x++){
      for(y = 0; y < tamanhoy; y++){
        if((i % 5) == 0 && (arena[y][x] == escudoinimigo | arena[y][x] == inimigo) && (rand() % 15) > 13 && arena[y + 1][x] != tironave){
          for(yi = y + 1; yi < tamanhoy; yi++){
            if(arena[yi][x] == inimigo | arena[yi][x] == escudoinimigo){
              inimigopronto = 0;
              break;
            }
            inimigopronto = 1;
          }
            if(inimigopronto){
             arena[y+1][x] = tiroinimigo;
            }
          }
          if(arena[y][x] == tironave && arena[y - 1][x] == inimigo){
            arena[y][x] = ' ';
            arena[y-1][x] = explosao;
            inimigosvivos--;
            score = score + 50;
          }
          else if(arena[y][x] == tironave && arena[y - 1][x] == escudoinimigo){
            arena[y][x] = ' ';
            arena[y-1][x] = inimigo;
            inimigosvivos--;
            score = score + 50;
          }
          else if(arena[y][x] == tironave && arena[y - 1][x] == tiroinimigo){
            arena[y][x] = ' ';
          }
          else if(arena[y][x] == explosao){
            arena[y][x] = ' ';
          }
          else if((i + 1) % 2 == 0 && arena[y][x] == tiroinimigo && arena[y + 1][x] == nave){
            arena[y + 1][x] = explosao;
            arena[y][x] = ' ';
            vitoria = 0;
          }
          else if(arena[y][x] == tironave && arena[y - 1][x] != tiroinimigo){
            arena[y][x] = ' ';
            arena[y - 1][x] = tironave;
          }
        }
      }

    //Atualizar inimigos
    for(y = 0; y < tamanhoy; y++){
      if(arena[y][0] == inimigo){
        direcao = 'r';
        cair = 1;
        break;
      }
      if(arena[y][tamanhox - 1] == inimigo){
        direcao = 'l';
        cair = 1;
        break;
      }
    }

    //Atualizar placar
    if(i % velocidadeinimigo == 0){
      if(direcao == 'l'){
        for(x = 0; x < tamanhox - 1; x++){
          for(y = 0; y < tamanhoy; y++){
            if(cair && (arena[y-1][x + 1] == inimigo || arena[y - 1][x + 1] == escudoinimigo)){
              arena[y][x] = arena[y - 1][x + 1];
              arena[y - 1][x + 1] = ' ';
            }
            else if(!cair && (arena[y][x + 1] == inimigo || arena[y][x + 1] == escudoinimigo)){
              arena[y][x] = arena[y][x + 1];
              arena[y][x + 1] = ' ';
            }
          }
        }
      }
      else{
        for(x = tamanhox; x > 0; x--){
          for(y = 0; y < tamanhoy; y++){
            if(cair && (arena[y - 1][x - 1] == inimigo || arena[y - 1][x - 1] == escudoinimigo)){
              arena[y][x] = arena[y - 1][x - 1];
              arena[y - 1][x - 1] = ' ';
            }
            else if(!cair && (arena[y][x - 1] == inimigo || arena[y][x - 1] == escudoinimigo)){
              arena[y][x] = arena[y][x - 1];
              arena[y][x - 1] = ' ';
            }
          }
        }
      }
      for(x = 0; x < tamanhox; x ++){
        if (arena[tamanhoy - 1][x] == inimigo){
          vitoria = 0;
        }
      }
    }

    //Controle nave
    if(kbhit()){
      pressionartecla = getch();
    }
    else{
      pressionartecla = ' ';
    }
    if(pressionartecla == 'a'){
      for(x = 0; x < tamanhox; x = x+1){
        if(arena[tamanhoy-1][x+1] == nave){
          arena[tamanhoy-1][x] = nave;
          arena[tamanhoy-1][x+1] = ' ';
        }
      }
    }
    if(pressionartecla == 'd'){
      for(x = tamanhox - 1; x > 0; x = x-1){
        if(arena[tamanhoy-1][x-1] == nave){
          arena[tamanhoy-1][x] = nave;
          arena[tamanhoy-1][x-1] = ' ';
        }
      }
    }
    if(pressionartecla == 'w' && tiropronto > 2){
      for(x = 0; x < tamanhox; x = x+1){
        if(arena[tamanhoy-1][x] == nave){
          arena[tamanhoy - 2][x] = tironave;
          tiropronto = 0;
        }
      }
    }
    i++;
    Sleep(50);
  }
  system("cls");
      printf("     SCORE: %d", score);
      printf("\n");
          for (y = 0; y < tamanhoy; y ++) {
          printf("|");
              for (x = 0; x < tamanhox; x ++) {
                  printf("%c", arena[y][x]);
              }
          printf("|");
          printf("\n");
          }
  Sleep(1000);
  system("cls");
  if(vitoria != 0){
    Sleep(500);
    printf("\n                              GANHOU!\n\n\n");
    Sleep(1000);
    printf("            PARAB%cNS! VOC%c CONSEGUIU SALVAR SEU TERMINAL\n", 201, 202);
    Sleep(1000);
    printf("\n\n            Score: %d", score);
    Sleep(1000);

    scorebonus = totaldeinimigos * 20 - i;

    printf("\n\n            B%cnus: %d", 212, scorebonus);
    Sleep(1000);
    printf("\n\n            Score Total: %d", score + scorebonus);
    Sleep(1000);
    getch();
  }
  else{
    Sleep(500);
    printf("\n                                      GAME OVER\n\n\n");
    Sleep(1000);
    printf("                        VOC%c N%cO CONSEGUIU SALVAR SEU TERMINAL :(\n", 202, 195);
    Sleep(1000);
    printf("\n\n                                    Score Final: %d\n\n", score);
    Sleep(1000);
    getch();
  }

  return 0;
}
