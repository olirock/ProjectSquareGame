/* PROJECT SQUARE
Jogo elaborado para a matéria de Computação 1 - UFRRJ - Instituto Multidisciplinar
Baseado no jogo Donkey Kong 1981.

Integrantes:
-Isaac Klein (Panda Games)
-isaacklein2.0@hotmail.com
-Lucas Dominato
-
-Pierre Rossi
-
-Raphael Rocha
-

Versão 1.0
* 3 Fases
* Aberturas personalizadas
* Menu animado

*/

#include <SDL/SDL.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <time.h>
#include <SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>


#define LARGURA 800
#define ALTURA 600
#define BITS 32
#define FPS 10
#define TIMEMAX 20

int abertura = 1,
    abertura2 = 0,
    enter = 0,
    menu = 0,
    jogo1 = 0,
    jogo0 = 0,
    jogo = 0,
    Direita = 0,
    Esquerda = 0,
    Cima = 0,
    Baixo = 0,
    larguraTELA = 800,
    alturaTELA = 600,
    pula = 0,
    jogarnovamente = 0,
    gravidade = 1,
    contpulo = 0,
    descida = 0,
    easteregg = 0,
    velpulo = 0,
    timetora = 0,
    menubaixo = 0,
    menucima = 0,
    menudireita=0,
    menuesquerda = 0,
    pick = 0,
    selecao = 0,
    ON = 1,
    TUTORIAL = 0,
    RECORDES = 0 ,
    CREDITOS = 0,
    GAMEOVER = 0,
    vidas = 3,
    imortal = 0,
    loading = 0,
    historinha = 0,
    timehist = 0,
    UP = 0,
    DOWN = 0,
    WEWE = 0,
    morre = 0;
float score=0.0;
Uint32 start;

// declarando surfaces
SDL_Surface* square;
SDL_Surface* background;
SDL_Surface* background2;
SDL_Surface* background3;
SDL_Surface* screen;
SDL_Surface* escada1;
SDL_Surface* escada2;
SDL_Surface* plataforma1;
SDL_Surface* plataforma2;
SDL_Surface* aberturaisaac;
SDL_Surface* tampadireita;
SDL_Surface* tampaesquerda;
SDL_Surface* rec4;
SDL_Surface* rec3;
SDL_Surface* rec5;
SDL_Surface* rec6;
SDL_Surface* rec;
SDL_Surface* rec2;
SDL_Surface* arma;
SDL_Surface* arma2;
SDL_Surface* arma3;
SDL_Surface* quebrada1;
SDL_Surface* quebrada2;
SDL_Surface* sobedesce;
SDL_Surface* pilhatoras;
SDL_Surface* triangulo;
SDL_Surface* loadinghud;
SDL_Surface* squara;
SDL_Surface* HUD;
SDL_Surface* rural;
SDL_Surface* menuhud;
SDL_Surface* gameover;
SDL_Surface* creditoshud;
SDL_Surface* tutorialhud;
SDL_Surface* recordeshud;
SDL_Surface* jogarbut;
SDL_Surface* credbut;
SDL_Surface* tutobut;
SDL_Surface* recorbut;
SDL_Surface* sairbut;
SDL_Surface* jogarnovbut;
SDL_Surface* voltaraomenu;
SDL_Surface* icon;
SDL_Surface* icongo;
SDL_Surface* aberturadome;
SDL_Surface* historia;
SDL_Surface* WeWe;
SDL_Surface* verm1;
SDL_Surface* verm2;
SDL_Surface* verm3;
SDL_Surface* verm4;
SDL_Surface* verm5;
SDL_Surface* verm6;
SDL_Surface* verm7;
SDL_Surface* newrecorde;
SDL_Event event;
SDL_Event eventomenu;
TTF_Font *fonte; //objeto que carregara fontes
Mix_Chunk* efeito_1;
Mix_Chunk* efeito_2;
Mix_Chunk* efeito_3;
Mix_Chunk* game_over;
Mix_Music* abertura_isaac;
Mix_Music* dome;
Mix_Chunk* wewe;
Mix_Music* menu_princ;
Mix_Music* recordes_1;
Mix_Music* historia_1;
Mix_Music* venceu;
Mix_Music* jogo_rodando;
Mix_Music* creditos_1;
Mix_Music* tutorial1;


void IMAGENS()
{
    newrecorde = IMG_Load("Imagens/newrecord.png");
    rural = IMG_Load("Imagens/rural.png");
    verm1 = IMG_Load("Imagens/orbeverm.png");
    verm2 = IMG_Load("Imagens/orbeverm.png");
    verm3 = IMG_Load("Imagens/orbeverm.png");
    verm4 = IMG_Load("Imagens/orbeverm.png");
    verm5 = IMG_Load("Imagens/orbeverm.png");
    verm6 = IMG_Load("Imagens/orbeverm.png");
    verm7 = IMG_Load("Imagens/orbeverm.png");
    loadinghud = IMG_Load("Imagens/carregando.png");
    WeWe = IMG_Load("Imagens/wewe.png");
    recordeshud = IMG_Load("Imagens/recordes.png");
    historia = IMG_Load("Imagens/historia.png");
    aberturadome = IMG_Load("Imagens/dome_abertura.png");
    icongo = IMG_Load("Imagens/orbe.png");
    jogarnovbut = IMG_Load("Imagens/JOGARbotao.png");
    voltaraomenu = IMG_Load("Imagens/voltaraomenu.png");
    gameover = IMG_Load("Imagens/gameover.png");
    sairbut = IMG_Load("Imagens/SAIRbotao.png");
    recorbut = IMG_Load("Imagens/RECORDESbotao.png");
    icon = IMG_Load("Imagens/orbe.png");
    menuhud = IMG_Load("Imagens/menu.png");
    creditoshud = IMG_Load("Imagens/credito.png");
    tutorialhud = IMG_Load("Imagens/tutorial.png");
    jogarbut = IMG_Load("Imagens/JOGARbotao.png");
    credbut = IMG_Load("Imagens/CREDITOSbotao.png");
    tutobut = IMG_Load("Imagens/TUTORIALbotao.png");
    arma = IMG_Load("Imagens/orbe.png");
    arma2 = IMG_Load("Imagens/orbe.png");
    arma3 = IMG_Load("Imagens/orbe.png");
    HUD = IMG_Load("Imagens/hud.png");
    squara = IMG_Load("Imagens/quadrada.png");
    triangulo = IMG_Load("Imagens/vilao.png");
    pilhatoras = IMG_Load("Imagens/tora-pilha.png");
    square = IMG_Load("Imagens/direita.png");
    background = IMG_Load("Imagens/fundo.png");
    background2 = IMG_Load("Imagens/fundofase2.png");
    background3 = IMG_Load("Imagens/fundofase3.png");
    escada1 = IMG_Load("Imagens/escada-floresta.png");
    plataforma1 = IMG_Load("Imagens/plataformafloresta.png");
    plataforma2 = IMG_Load("Imagens/plataforma-grama.png");
    rec = IMG_Load("Imagens/2.png");
    rec2 = IMG_Load("Imagens/2.png");
    rec3 = IMG_Load("Imagens/2.png");
    rec4 = IMG_Load("Imagens/2.png");
    rec5= IMG_Load("Imagens/2.png");
    rec6 = IMG_Load("Imagens/2.png");
    tampadireita = IMG_Load("Imagens/tampadireita.png");
    tampaesquerda = IMG_Load("Imagens/tampaesquerda.png");
    aberturaisaac = IMG_Load("Imagens/newabertura.png");
    quebrada1 = IMG_Load("Imagens/escada-q1.png");
    quebrada2 = IMG_Load("Imagens/escada-q2.png");
    sobedesce = IMG_Load("Imagens/sobedesce.png");

}

//COMANDO PARA DESENHAR TEXTO
void desenhaTexto(char* texto, SDL_Surface* dst, int x, int y, SDL_Color cor)
{
    SDL_Surface* src = TTF_RenderText_Blended(fonte, texto, cor);
    SDL_Rect dst_rect = {x, y, 0, 0};

    SDL_BlitSurface(src, 0, dst, &dst_rect);

    SDL_FreeSurface(src);
}

void sons()
{
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2 ,2048);
    Mix_AllocateChannels(4);
    Mix_Volume(0,128);
    Mix_Volume(1,128);
    Mix_Volume(2,128);
    Mix_Volume(3,128);
    Mix_VolumeMusic(90);
    efeito_1 = Mix_LoadWAV("Sons/menu.wav");
    efeito_2 = Mix_LoadWAV("Sons/Jump.wav");
    efeito_3 = Mix_LoadWAV("Sons/Morte.ogg");
    game_over = Mix_LoadWAV("Sons/gameover.ogg");
    abertura_isaac = Mix_LoadMUS("Sons/aberturaisaac.mp3");
    dome = Mix_LoadMUS("Sons/dome.ogg");
    menu_princ = Mix_LoadMUS("Sons/menuprincipal.ogg");
    recordes_1 = Mix_LoadMUS("Sons/recorde.ogg");
    historia_1 = Mix_LoadMUS("Sons/historia.ogg");
    venceu = Mix_LoadMUS("Sons/youwin.ogg");
    jogo_rodando = Mix_LoadMUS("Sons/jogando.ogg");
    creditos_1 = Mix_LoadMUS("Sons/creditos.mp3");
    tutorial1 = Mix_LoadMUS("Sons/tutorial.ogg");
    wewe = Mix_LoadWAV("Sons/youwin.mp3");
}

void escrever_recordes()//escrever record no menu
{
    FILE* fp = fopen("score.txt", "r");
    if(fp == NULL)
    {
      printf("não foi possivel abrir o arquivo");
      //exit(1);
    }
    SDL_Color cor = {255,255,255};
    fonte = TTF_OpenFont("Fontes/Jazz_Ball_Regular.ttf",20);
    char nome_1[11],nome_2[11],nome_3[11],nome_4[11],nome_5[11];
    char pont_1[6],pont_2[6],pont_3[6],pont_4[6];
    float score_1,score_2,score_3,score_4,aux;

    fscanf(fp,"%s", nome_1);
    fscanf(fp,"%f", &score_1);
    fscanf(fp,"%s", nome_2);
    fscanf(fp,"%f", &score_2);
    fscanf(fp,"%s", nome_3);
    fscanf(fp,"%f", &score_3);
    //fscanf(fp,"%s", nome_4);
    //fscanf(fp,"%f", &score_4);

    sprintf(pont_1,"%.0f", score_1);
    sprintf(pont_2,"%.0f", score_2);
    sprintf(pont_3,"%.0f", score_3);
    //sprintf(pont_4,"%.0f", score_4);

    desenhaTexto(nome_1, screen, 275, 247, cor);
    desenhaTexto(pont_1, screen, 470, 247, cor);
    desenhaTexto(nome_2, screen, 275, 338, cor);
    desenhaTexto(pont_2, screen, 470, 338, cor);
    desenhaTexto(nome_3, screen, 275, 429, cor);
    desenhaTexto(pont_3, screen, 470, 429, cor);
    //desenhaTexto(nome_4, screen, 180, 410, cor);
    //desenhaTexto(pont_4, screen, 300, 410, cor);
    //desenhaTexto(nome_1, screen, 180, 10, cor);
    //desenhaTexto(nome_1, screen, 180, 10, cor);

    //printf("Nome : %s pontuacao: %s\n", nome_1,score_1);
    //printf("Nome : %s pontuacao: %s\n", nome_2,score_2);
    //printf("Nome : %s pontuacao: %s\n", nome_3,score_3);
    //printf("Nome : %s pontuacao: %s\n", nome_4,score_4);
    TTF_CloseFont(fonte);
    fclose(fp);
}

void draw_object(float charX, float charY, int destX, int destY, int largurachar, int alturachar, SDL_Surface* source, SDL_Surface* destination)
{
   SDL_Rect chr, destino;

   chr.x = charX;
   chr.y = charY;
   chr.w = largurachar;
   chr.h = alturachar;

   destino.x = destX;
   destino.y = destY;
   destino.w = largurachar;
   destino.h = alturachar;

   SDL_BlitSurface(source, &chr, destination, &destino);
}

char* imprimeTela()//pra poder digitar o nome na tela
{
    int escreve=0, cont=0, i;
    char *aux = (char*)malloc(11*sizeof(char));
//------------------LIMPANDO LIXO DE MEMORIA-------------------//
    for(i=0;i<11;i++){ aux[i]='\0'; }
//-------------------------------------------------------------//
    SDL_Color cor = {255,255,255};
    fonte = TTF_OpenFont("Fontes/Jazz_Ball_Regular.ttf",35);//para o player escrever o nome
    SDL_BlitSurface(newrecorde, 0, screen, 0);
    SDL_Flip(screen);//para que a tela apareça a 1° vez
    while(escreve==0)
    {
        start = SDL_GetTicks();
        while (SDL_PollEvent(&event)) // Loop de eventos
        {

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {

            }

            if(event.type == SDL_KEYDOWN)
            {
              switch(event.key.keysym.sym){

                case SDLK_a:
                    if(cont<10)
                    {
                        aux[cont]='A';
                        cont++;
                    }
                    break;
                case SDLK_b:
                    if(cont<10)
                    {
                        aux[cont]='B';
                        cont++;
                    }
                    break;
                case SDLK_c:
                    if(cont<10)
                    {
                        aux[cont]='C';
                        cont++;
                    }
                    break;
                case SDLK_d:
                    if(cont<10)
                    {
                        aux[cont]='D';
                        cont++;
                    }
                    break;
                case SDLK_e:
                    if(cont<10)
                    {
                        aux[cont]='E';
                        cont++;
                    }
                    break;
                case SDLK_f:
                    if(cont<10)
                    {
                        aux[cont]='F';
                        cont++;
                    }
                    break;
                case SDLK_g:
                    if(cont<10)
                    {
                        aux[cont]='G';
                        cont++;
                    }
                    break;
                case SDLK_h:
                    if(cont<10)
                    {
                        aux[cont]='H';
                        cont++;
                    }
                    break;
                case SDLK_i:
                    if(cont<10)
                    {
                        aux[cont]='I';
                        cont++;
                    }
                    break;
                case SDLK_j:
                    if(cont<10)
                    {
                        aux[cont]='J';
                        cont++;
                    }
                    break;
                case SDLK_k:
                    if(cont<10)
                    {
                        aux[cont]='K';
                        cont++;
                    }
                    break;
                case SDLK_l:
                    if(cont<10)
                    {
                        aux[cont]='L';
                        cont++;
                    }
                    break;
                case SDLK_m:
                    if(cont<10)
                    {
                        aux[cont]='M';
                        cont++;
                    }
                    break;
                case SDLK_n:
                    if(cont<10)
                    {
                        aux[cont]='N';
                        cont++;
                    }
                    break;
                case SDLK_o:
                    if(cont<10)
                    {
                        aux[cont]='O';
                        //sprintf(aux,"%s%c",aux,'o');
                        cont++;
                        //printf("%s\n",aux);
                    }
                    break;
                case SDLK_p:
                    if(cont<10)
                    {
                        aux[cont]='P';
                        cont++;
                    }
                    break;
                case SDLK_q:
                    if(cont<10)
                    {
                        aux[cont]='Q';
                        cont++;
                    }
                    break;
                case SDLK_r:
                    if(cont<10)
                    {
                        aux[cont]='R';
                        cont++;
                    }
                    break;
                case SDLK_s:
                    if(cont<10)
                    {
                        aux[cont]='S';
                        cont++;
                    }
                    break;
                case SDLK_t:
                    if(cont<10)
                    {
                        aux[cont]='T';
                        cont++;
                    }
                    break;
                case SDLK_u:
                    if(cont<10)
                    {
                        aux[cont]='U';
                        cont++;
                    }
                    break;
                case SDLK_v:
                    if(cont<10)
                    {
                        aux[cont]='V';
                        cont++;
                    }
                    break;
                case SDLK_w:
                    if(cont<10)
                    {
                        aux[cont]='W';
                        cont++;
                    }
                    break;
                case SDLK_x:
                    if(cont<10)
                    {
                        aux[cont]='X';
                        cont++;
                    }
                    break;
                case SDLK_y:
                    if(cont<10)
                    {
                        aux[cont]='Y';
                        cont++;
                    }
                    break;
                case SDLK_z:
                    if(cont<10)
                    {
                        aux[cont]='Z';
                        cont++;
                    }
                    break;
                case SDLK_0:
                    if(cont<10)
                    {
                        aux[cont]='0';
                        cont++;
                    }
                    break;
                case SDLK_1:
                    if(cont<10)
                    {
                        aux[cont]='1';
                        cont++;
                    }
                    break;
                case SDLK_2:
                    if(cont<10)
                    {
                        aux[cont]='2';
                        cont++;
                    }
                    break;
                case SDLK_3:
                    if(cont<10)
                    {
                        aux[cont]='3';
                        cont++;
                    }
                    break;
                case SDLK_4:
                    if(cont<10)
                    {
                        aux[cont]='4';
                        cont++;
                    }
                    break;
                case SDLK_5:
                    if(cont<10)
                    {
                        aux[cont]='5';
                        cont++;
                    }
                    break;
                case SDLK_6:
                    if(cont<10)
                    {
                        aux[cont]='6';
                        cont++;
                    }
                    break;
                case SDLK_7:
                    if(cont<10)
                    {
                        aux[cont]='7';
                        cont++;
                    }
                    break;
                case SDLK_8:
                    if(cont<10)
                    {
                        aux[cont]='8';
                        cont++;
                    }
                    break;
                case SDLK_9:
                    if(cont<10)
                    {
                        aux[cont]='9';
                        cont++;
                    }
                    break;
                case SDLK_BACKSPACE:
                    if(cont>0)
                    {
                        aux[cont-1]='\0';
                        cont--;
                    }
                    break;
                case SDLK_RETURN:
                    printf("\n%s\n","Enter");
                    return aux;
                    escreve=1;
                    break;
              }//switch
            }//button down

        }//pool event
        SDL_BlitSurface(newrecorde, 0, screen, 0);
        desenhaTexto(aux,screen,325,265,cor);
        if(1000/FPS >(SDL_GetTicks()-start))
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        SDL_Flip( screen);
    }//principal
    TTF_CloseFont(fonte);//para sempre printar as palavras na tela
    free(aux);
}

void verifica_recorde()//vai verificar se o recorde é maior que o ultimo recorde,se for vai poder escrever na tela e depois vai ordenar os recordes
{
    char nome[4][11], aux[11];
    float ponto[4], auxFloat;
    int i=0, j=0;
    FILE* fp = fopen("score.txt", "r+");
    if(fp == NULL)
    {
      printf("não foi possivel abrir o arquivo");
      exit(1);
    }

    for(i=0; i<4; i++)
    {
        fscanf(fp,"%s",nome[i]);
        fscanf(fp,"%f",&ponto[i]);
        printf("%s %f\n",nome[i],ponto[i]);
    }

    if(score>ponto[3])
    {
        strcpy(nome[3], imprimeTela());
        ponto[3]=score;
        for( i=0; i < 4; i++)
        {
            for(j=0; j<i+1; j++ )
            {
                if( ponto[i] > ponto[j] )
                {
                    strcpy(aux,nome[i]);
                    strcpy(nome[i],nome[j]);
                    strcpy(nome[j],aux);

                    auxFloat = ponto[i];
                    ponto[i]=ponto[j];
                    ponto[j]=auxFloat;
                }
            }
        }
    }

    rewind(fp);

    for(i=0;i<4;i++)
    {
        fprintf(fp, "%s\n", nome[i]);
        fprintf(fp, "%.0f\n", ponto[i]);
    }

    fclose(fp);

}

// COMANDO QUE BLITA O PERSONAGEM - INICIO
void draw_player(float charX, float charY, int destX, int destY, int largurachar, int alturachar, SDL_Surface* source, SDL_Surface* destination)
{
   SDL_Rect chr, destino;

   chr.x = charX;
   chr.y = charY;
   chr.w = largurachar;
   chr.h = alturachar;

   destino.x = destX;
   destino.y = destY;
   destino.w = largurachar;
   destino.h = alturachar;

   SDL_BlitSurface(source, &chr, destination, &destino);

}
// COMANDO QUE BLITA O PERSONAGEM - FINAL

// CRIAÇÃO DA VARIAVEL PARA CONTROLE DO PLAYER - INICIO
typedef struct PLAYER Player;
struct PLAYER
{
     int sx, sy, dx, dy, velx, vely;
     int largura, altura, pulo;
};

Player player;


void squareInfo()
{
    player.largura = 52, player.altura = 23, player.pulo = 0;
	player.sx =0, player.sy = 0, player.dx =45, player.dy = 563, player.velx = 15, player.vely = 8.8;
}

// CRIAÇÃO DA VARIAVEL PARA CONTROLE DO PLAYER - FINAL


// COMANDO QUE BLITA A ESCADA - INICIO
/*void draw_object(float charX, float charY, int destX, int destY, int largurachar, int alturachar, SDL_Surface* source, SDL_Surface* destination)
{
   SDL_Rect chr, destino;

   chr.x = charX;
   chr.y = charY;
   chr.w = largurachar;
   chr.h = alturachar;

   destino.x = destX;
   destino.y = destY;
   destino.w = largurachar;
   destino.h = alturachar;

   SDL_BlitSurface(source, &chr, destination, &destino);
}*/
// COMANDO QUE BLITA A ESCADA - FINAL

// CRIAÇÃO DA VARIAVEL DOS OBJETOS - INICIO
typedef struct OBJETO Objeto;
struct OBJETO
{
     float sx, sy, dx, dy;
     int largura, altura;
};

Objeto queb1,
    queb2,
    queb3,
    queb4,
    queb5,
    pilhatora,
    ab1,
    ab2,
    tampa1,
    tampa2,
    recan,
    recan2,
    recan3,
    recan4,
    recan5,
    recan6,
    orbe,
    orbe2,
    orbe3,
    obj_escada1,
    obj_escada2,
    obj_escada3,
    obj_escada4,
    obj_escada5,
    triang,
    quadra,
    hud,
    obj_plataforma1,
    obj_plataforma2,
    obj_plataforma3,
    obj_plataforma4,
    obj_plataforma5,
    obj_plataforma6,
    MENU,
    TUTO,
    CRED,
    RECOR,
    Bjogar,
    Bcred,
    Btuto,
    Brecor,
    Bsair,
    Bvoltar,
    orbemenu,
    orbego,
    wEwE,
    GameOver,
    Bjognov,
    HIST,
    LOAD,
    verm[7],
    rur;
//Estrutura que funciona como um rect para blitar cada escada e plataforma na tela

void menuInfo()
{
    MENU.largura = 800, MENU.altura = 600;
	MENU.sx =0, MENU.sy = 0, MENU.dx = 0, MENU.dy = 0;

    TUTO.largura = 800, TUTO.altura = 600;
	TUTO.sx =0, TUTO.sy = 0, TUTO.dx = 0, TUTO.dy = 0;

    CRED.largura = 800, CRED.altura = 600;
	CRED.sx =0, CRED.sy = 0, CRED.dx = 0, CRED.dy = 0;

	RECOR.largura = 800, RECOR.altura = 600;
	RECOR.sx =0, RECOR.sy = 0, RECOR.dx = 0, RECOR.dy = 0;

	HIST.largura = 800, HIST.altura = 600;
	HIST.sx =0, HIST.sy = 0, HIST.dx = 0, HIST.dy = 0;

	LOAD.largura = 800, LOAD.altura = 600;
	LOAD.sx =0, LOAD.sy = 0, LOAD.dx = 0, LOAD.dy = 0;
    //1
    Bjogar.largura = 279, Bjogar.altura = 31;
	Bjogar.sx =0, Bjogar.sy = 0, Bjogar.dx = 360, Bjogar.dy = 311;
    //2
	Bcred.largura = 223, Bcred.altura = 31;
	Bcred.sx =0, Bcred.sy = 0, Bcred.dx = 360, Bcred.dy = 425;
    //3
	Btuto.largura = 214, Btuto.altura = 31;
	Btuto.sx =0, Btuto.sy = 0, Btuto.dx = 360, Btuto.dy = 368;
	//4
	Brecor.largura = 256, Brecor.altura = 31;
	Brecor.sx =0, Brecor.sy = 0, Brecor.dx = 360, Brecor.dy = 482;
	//5
	Bsair.largura = 214, Bsair.altura = 31;
	Bsair.sx =0, Bsair.sy = 0, Bsair.dx = 360, Bsair.dy = 539;

    orbemenu.largura = 19, orbemenu.altura = 31;
	orbemenu.sx =0, orbemenu.sy = 0, orbemenu.dx = 360, orbemenu.dy = 311;

	GameOver.largura = 800, GameOver.altura = 600;
	GameOver.sx =0, GameOver.sy = 0, GameOver.dx = 0, GameOver.dy = 0;

	wEwE.largura = 800, wEwE.altura = 600;
	wEwE.sx =0, wEwE.sy = 0, wEwE.dx = 0, wEwE.dy = 0;

    Bjognov.largura = 279, Bjognov.altura = 31;
	Bjognov.sx =0, Bjognov.sy = 0, Bjognov.dx = 250, Bjognov.dy = 100;

	Bvoltar.largura = 357, Bvoltar.altura = 31;
	Bvoltar.sx =0, Bvoltar.sy = 0, Bvoltar.dx = 270, Bvoltar.dy = 50;

    orbego.largura = 19, orbego.altura = 31;
	orbego.sx =0, orbego.sy = 0, orbego.dx = 250, orbego.dy = 50;

	rur.largura = 297, rur.altura = 334;
	rur.sx =0, rur.sy = 0, rur.dx = 356, rur.dy = 241;
}

void quebradaInfo()
{
    queb1.largura = 50, queb1.altura = 89;
	queb1.sx =0, queb1.sy = 0, queb1.dx = 205, queb1.dy = 498;

    queb2.largura = 50, queb2.altura = 89;
	queb2.sx =0, queb2.sy = 0, queb2.dx = 520, queb2.dy = 410;

    queb3.largura = 50, queb3.altura = 89;
	queb3.sx =0, queb3.sy = 0, queb3.dx = 420, queb3.dy = 322;

    queb4.largura = 50, queb4.altura = 89;
	queb4.sx =0, queb4.sy = 0, queb4.dx = 100, queb4.dy = 234;

    queb5.largura = 50, queb5.altura = 89;
	queb5.sx =0, queb5.sy = 0, queb5.dx = 55,queb5.dy = 146;

	pilhatora.largura = 130, pilhatora.altura = 85;
	pilhatora.sx =0, pilhatora.sy = 0, pilhatora.dx = 220,pilhatora.dy = 62;
}

void tampaInfo()
{
    tampa1.largura = 19, tampa1.altura = 600;
	tampa1.sx =0, tampa1.sy = 0, tampa1.dx = 0, tampa1.dy = 0;

    tampa2.largura = 19, tampa2.altura = 600;
	tampa2.sx =0, tampa2.sy = 0, tampa2.dx = 781, tampa2.dy = 0;

    hud.largura = 800, hud.altura = 50;
	hud.sx =0, hud.sy = 0, hud.dx = 0, hud.dy = 0;

	triang.largura = 76.25, triang.altura = 67;
	triang.sx =0, triang.sy = 0, triang.dx = 70, triang.dy = 80;

	quadra.largura = 33, quadra.altura = 23;
	quadra.sx =0, quadra.sy = 0, quadra.dx = 170, quadra.dy = 124;

    verm[0].largura = 14, verm[0].altura = 24;
	verm[0].sx =0, verm[0].sy = 0, verm[0].dx = 500, verm[0].dy = 450;

	verm[1].largura = 14, verm[1].altura = 24;
	verm[1].sx =0, verm[1].sy = 0, verm[1].dx = 700, verm[1].dy = 520;

	verm[2].largura = 14, verm[2].altura = 24;
	verm[2].sx =0, verm[2].sy = 0, verm[2].dx = 300, verm[2].dy = 280;

	verm[3].largura = 14, verm[3].altura = 24;
	verm[3].sx =0, verm[3].sy = 0, verm[3].dx = 650, verm[3].dy = 200;

    verm[4].largura = 14, verm[4].altura = 24;
	verm[4].sx =0, verm[4].sy = 0, verm[4].dx = 60, verm[4].dy = 525;

	verm[5].largura = 14, verm[5].altura = 24;
	verm[5].sx =0, verm[5].sy = 0, verm[5].dx = 730, verm[5].dy = 165;
}

void abInfo()
{
    ab1.largura = 800, ab1.altura = 600;
	ab1.sx =0, ab1.sy = 0, ab1.dx = 0, ab1.dy = 0;

	ab2.largura = 800, ab2.altura = 600;
	ab2.sx =0, ab1.sy = 0, ab2.dx = 0, ab2.dy = 0;
}

void escadaInfo()
{
    obj_escada1.largura = 50, obj_escada1.altura = 89;
	obj_escada1.sx =0, obj_escada1.sy = 0, obj_escada1.dx = 465, obj_escada1.dy = 498;

    obj_escada2.largura = 50, obj_escada2.altura = 89;
	obj_escada2.sx =0, obj_escada2.sy = 0, obj_escada2.dx = 90, obj_escada2.dy = 410;

    obj_escada3.largura = 50, obj_escada3.altura = 89;
	obj_escada3.sx =0, obj_escada3.sy = 0, obj_escada3.dx = 615, obj_escada3.dy = 322;

    obj_escada4.largura = 50, obj_escada4.altura = 89;
	obj_escada4.sx =0, obj_escada4.sy = 0, obj_escada4.dx = 315, obj_escada4.dy = 234;

    obj_escada5.largura = 50, obj_escada5.altura = 89;
	obj_escada5.sx =0, obj_escada5.sy = 0, obj_escada5.dx = 165,obj_escada5.dy = 146;
}//"Rects" para cada escada

void recanInfo()
{
    recan.largura = 53.75, recan.altura = 19;
	recan.sx =0, recan.sy = 0, recan.dx = 220, recan.dy = 126;

    recan2.largura = 53.75, recan2.altura = 19;
	recan2.sx =0, recan2.sy = 0, recan2.dx = 260, recan2.dy = 62;

	recan3.largura = 53.75, recan3.altura = 19;
	recan3.sx =0, recan3.sy = 0, recan3.dx = 240, recan3.dy = 125;

	recan4.largura = 53.75, recan4.altura = 19;
	recan4.sx =0, recan4.sy = 0, recan4.dx = 240, recan4.dy = 125;

	recan5.largura = 53.75, recan5.altura = 19;
	recan5.sx =0, recan5.sy = 0, recan5.dx = 240, recan5.dy = 125;

	recan6.largura = 53.75, recan6.altura = 19;
	recan6.sx =0, recan6.sy = 0, recan6.dx = 240, recan6.dy = 125;

	orbe.largura = 19, orbe.altura = 31;
	orbe.sx =0, orbe.sy = 0, orbe.dx = 40, orbe.dy = 355;

}

void plataformaInfo()
{
    obj_plataforma1.largura = 800, obj_plataforma1.altura = 33;
	obj_plataforma1.sx =0, obj_plataforma1.sy = 0, obj_plataforma1.dx = 0, obj_plataforma1.dy = 578;

    obj_plataforma2.largura = 800, obj_plataforma2.altura = 14;
	obj_plataforma2.sx =0, obj_plataforma2.sy = 0, obj_plataforma2.dx = 0, obj_plataforma2.dy = 498;

    obj_plataforma3.largura = 800, obj_plataforma3.altura = 14;
	obj_plataforma3.sx =0, obj_plataforma3.sy = 0, obj_plataforma3.dx = 0, obj_plataforma3.dy = 410;

    obj_plataforma4.largura = 800, obj_plataforma4.altura = 14;
	obj_plataforma4.sx =0, obj_plataforma4.sy = 0, obj_plataforma4.dx = 0, obj_plataforma4.dy = 322;

    obj_plataforma5.largura = 800, obj_plataforma5.altura = 14;
	obj_plataforma5.sx =0, obj_plataforma5.sy = 0, obj_plataforma5.dx = 0, obj_plataforma5.dy = 234;

    obj_plataforma6.largura = 800, obj_plataforma6.altura = 14;
	obj_plataforma6.sx =0, obj_plataforma6.sy = 0, obj_plataforma6.dx = 0, obj_plataforma6.dy = 146;

}
// CRIAÇÃO DA VARIAVEL DOS OBJETOS - INICIO

void FASE2()
{
    obj_plataforma1.largura = 800, obj_plataforma1.altura = 33;
	obj_plataforma1.sx =0, obj_plataforma1.sy = 0, obj_plataforma1.dx = 0, obj_plataforma1.dy = 578;

    obj_plataforma2.largura = 800, obj_plataforma2.altura = 14;
	obj_plataforma2.sx =0, obj_plataforma2.sy = 0, obj_plataforma2.dx = 0, obj_plataforma2.dy = 498;

    obj_plataforma3.largura = 800, obj_plataforma3.altura = 14;
	obj_plataforma3.sx =0, obj_plataforma3.sy = 0, obj_plataforma3.dx = 0, obj_plataforma3.dy = 410;

    obj_plataforma4.largura = 800, obj_plataforma4.altura = 14;
	obj_plataforma4.sx =0, obj_plataforma4.sy = 0, obj_plataforma4.dx = 0, obj_plataforma4.dy = 322;

    obj_plataforma5.largura = 800, obj_plataforma5.altura = 14;
	obj_plataforma5.sx =0, obj_plataforma5.sy = 0, obj_plataforma5.dx = 0, obj_plataforma5.dy = 234;

    obj_plataforma6.largura = 800, obj_plataforma6.altura = 14;
	obj_plataforma6.sx =0, obj_plataforma6.sy = 0, obj_plataforma6.dx = 0, obj_plataforma6.dy = 146;

    recan.largura = 53.75, recan.altura = 19;
	recan.sx =0, recan.sy = 0, recan.dx = 220, recan.dy = 126;

	recan3.largura = 53.75, recan3.altura = 19;
	recan3.sx =0, recan3.sy = 0, recan3.dx = 240, recan3.dy = 125;

	recan4.largura = 53.75, recan4.altura = 19;
	recan4.sx =0, recan4.sy = 0, recan4.dx = 240, recan4.dy = 125;

	recan5.largura = 53.75, recan5.altura = 19;
	recan5.sx =0, recan5.sy = 0, recan5.dx = 240, recan5.dy = 125;

	recan6.largura = 53.75, recan6.altura = 19;
	recan6.sx =0, recan6.sy = 0, recan6.dx = 240, recan6.dy = 125;

	orbe.largura = 19, orbe.altura = 31;
	orbe.sx =0, orbe.sy = 0, orbe.dx = 40, orbe.dy = 355;

    verm[0].largura = 14, verm[0].altura = 24;
	verm[0].sx =0, verm[0].sy = 0, verm[0].dx = 80, verm[0].dy = 250;

	verm[1].largura = 14, verm[1].altura = 24;
	verm[1].sx =0, verm[1].sy = 0, verm[1].dx = 703, verm[1].dy = 560;

	verm[2].largura = 14, verm[2].altura = 24;
	verm[2].sx =0, verm[2].sy = 0, verm[2].dx = 400, verm[2].dy = 280;

	verm[3].largura = 14, verm[3].altura = 24;
	verm[3].sx =0, verm[3].sy = 0, verm[3].dx = 722, verm[3].dy = 200;

    verm[4].largura = 14, verm[4].altura = 24;
	verm[4].sx =0, verm[4].sy = 0, verm[4].dx = 46, verm[4].dy = 450;

	verm[5].largura = 14, verm[5].altura = 24;
	verm[5].sx =0, verm[5].sy = 0, verm[5].dx = 705, verm[5].dy = 246;

    obj_escada1.largura = 50, obj_escada1.altura = 89;
	obj_escada1.sx =0, obj_escada1.sy = 0, obj_escada1.dx = 675, obj_escada1.dy = 498;

    obj_escada2.largura = 50, obj_escada2.altura = 89;
	obj_escada2.sx =0, obj_escada2.sy = 0, obj_escada2.dx = 60, obj_escada2.dy = 410;

    obj_escada3.largura = 50, obj_escada3.altura = 89;
	obj_escada3.sx =0, obj_escada3.sy = 0, obj_escada3.dx = 675, obj_escada3.dy = 322;

    obj_escada4.largura = 50, obj_escada4.altura = 89;
	obj_escada4.sx =0, obj_escada4.sy = 0, obj_escada4.dx = 60, obj_escada4.dy = 234;

    obj_escada5.largura = 50, obj_escada5.altura = 89;
	obj_escada5.sx =0, obj_escada5.sy = 0, obj_escada5.dx = 165,obj_escada5.dy = 146;

    tampa1.largura = 19, tampa1.altura = 600;
	tampa1.sx =0, tampa1.sy = 0, tampa1.dx = 0, tampa1.dy = 0;

    tampa2.largura = 19, tampa2.altura = 600;
	tampa2.sx =0, tampa2.sy = 0, tampa2.dx = 781, tampa2.dy = 0;

    hud.largura = 800, hud.altura = 50;
	hud.sx =0, hud.sy = 0, hud.dx = 0, hud.dy = 0;

	triang.largura = 76.25, triang.altura = 67;
	triang.sx =0, triang.sy = 0, triang.dx = 70, triang.dy = 80;

	quadra.largura = 33, quadra.altura = 23;
	quadra.sx =0, quadra.sy = 0, quadra.dx = 170, quadra.dy = 124;

    queb1.largura = 50, queb1.altura = 89;
	queb1.sx =0, queb1.sy = 0, queb1.dx = 300, queb1.dy = 498;

    queb2.largura = 50, queb2.altura = 89;
	queb2.sx =0, queb2.sy = 0, queb2.dx = 450, queb2.dy = 410;

    queb3.largura = 50, queb3.altura = 89;
	queb3.sx =0, queb3.sy = 0, queb3.dx = 300, queb3.dy = 322;

    queb4.largura = 50, queb4.altura = 89;
	queb4.sx =0, queb4.sy = 0, queb4.dx = 450, queb4.dy = 234;

    queb5.largura = 50, queb5.altura = 89;
	queb5.sx =0, queb5.sy = 0, queb5.dx = 300,queb5.dy = 146;

	pilhatora.largura = 130, pilhatora.altura = 85;
	pilhatora.sx =0, pilhatora.sy = 0, pilhatora.dx = 220,pilhatora.dy = 62;

	player.largura = 52, player.altura = 23, player.pulo = 0;
	player.sx =0, player.sy = 0, player.dx =45, player.dy = 563, player.velx = 15, player.vely = 8.8;
}

void FASE3()
{
    obj_plataforma1.largura = 800, obj_plataforma1.altura = 33;
	obj_plataforma1.sx =0, obj_plataforma1.sy = 0, obj_plataforma1.dx = 0, obj_plataforma1.dy = 578;

    obj_plataforma2.largura = 800, obj_plataforma2.altura = 14;
	obj_plataforma2.sx =0, obj_plataforma2.sy = 0, obj_plataforma2.dx = 0, obj_plataforma2.dy = 498;

    obj_plataforma3.largura = 800, obj_plataforma3.altura = 14;
	obj_plataforma3.sx =0, obj_plataforma3.sy = 0, obj_plataforma3.dx = 0, obj_plataforma3.dy = 410;

    obj_plataforma4.largura = 800, obj_plataforma4.altura = 14;
	obj_plataforma4.sx =0, obj_plataforma4.sy = 0, obj_plataforma4.dx = 0, obj_plataforma4.dy = 322;

    obj_plataforma5.largura = 800, obj_plataforma5.altura = 14;
	obj_plataforma5.sx =0, obj_plataforma5.sy = 0, obj_plataforma5.dx = 0, obj_plataforma5.dy = 234;

    obj_plataforma6.largura = 800, obj_plataforma6.altura = 14;
	obj_plataforma6.sx =0, obj_plataforma6.sy = 0, obj_plataforma6.dx = 0, obj_plataforma6.dy = 146;

    recan.largura = 53.75, recan.altura = 19;
	recan.sx =0, recan.sy = 0, recan.dx = 220, recan.dy = 126;

    recan2.largura = 53.75, recan2.altura = 19;
	recan2.sx =0, recan2.sy = 0, recan2.dx = 260, recan2.dy = 62;

	recan3.largura = 53.75, recan3.altura = 19;
	recan3.sx =0, recan3.sy = 0, recan3.dx = 240, recan3.dy = 125;

	recan4.largura = 53.75, recan4.altura = 19;
	recan4.sx =0, recan4.sy = 0, recan4.dx = 260, recan4.dy = 125;

	recan5.largura = 53.75, recan5.altura = 19;
	recan5.sx =0, recan5.sy = 0, recan5.dx = 240, recan5.dy = 125;

	recan6.largura = 53.75, recan6.altura = 19;
	recan6.sx =0, recan6.sy = 0, recan6.dx = 260, recan6.dy = 125;

	orbe.largura = 19, orbe.altura = 31;
	orbe.sx =0, orbe.sy = 0, orbe.dx = 40, orbe.dy = 355;

	orbe3.largura = 19, orbe3.altura = 31;
	orbe3.sx =0, orbe3.sy = 0, orbe3.dx = 40, orbe3.dy = 267;

	orbe2.largura = 19, orbe2.altura = 31;
	orbe2.sx =0, orbe2.sy = 0, orbe2.dx = 40, orbe2.dy = 443;

    verm[0].largura = 14, verm[0].altura = 24;
	verm[0].sx =0, verm[0].sy = 0, verm[0].dx = 23, verm[0].dy = 525;

	verm[1].largura = 14, verm[1].altura = 24;
	verm[1].sx =0, verm[1].sy = 0, verm[1].dx = 540, verm[1].dy = 175;

	verm[2].largura = 14, verm[2].altura = 24;
	verm[2].sx =0, verm[2].sy = 0, verm[2].dx = 250, verm[2].dy = 360;

	verm[3].largura = 14, verm[3].altura = 24;
	verm[3].sx =0, verm[3].sy = 0, verm[3].dx = 738, verm[3].dy = 435;

    verm[4].largura = 14, verm[4].altura = 24;
	verm[4].sx =0, verm[4].sy = 0, verm[4].dx = 400, verm[4].dy = 165;

    obj_escada1.largura = 50, obj_escada1.altura = 89;
	obj_escada1.sx =0, obj_escada1.sy = 0, obj_escada1.dx = 345, obj_escada1.dy = 498;

    obj_escada2.largura = 50, obj_escada2.altura = 89;
	obj_escada2.sx =0, obj_escada2.sy = 0, obj_escada2.dx = 435, obj_escada2.dy = 410;

    obj_escada3.largura = 50, obj_escada3.altura = 89;
	obj_escada3.sx =0, obj_escada3.sy = 0, obj_escada3.dx = 540, obj_escada3.dy = 322;

    obj_escada4.largura = 50, obj_escada4.altura = 89;
	obj_escada4.sx =0, obj_escada4.sy = 0, obj_escada4.dx = 630, obj_escada4.dy = 234;

    obj_escada5.largura = 50, obj_escada5.altura = 89;
	obj_escada5.sx =0, obj_escada5.sy = 0, obj_escada5.dx = 165,obj_escada5.dy = 146;

    tampa1.largura = 19, tampa1.altura = 600;
	tampa1.sx =0, tampa1.sy = 0, tampa1.dx = 0, tampa1.dy = 0;

    tampa2.largura = 19, tampa2.altura = 600;
	tampa2.sx =0, tampa2.sy = 0, tampa2.dx = 781, tampa2.dy = 0;

    hud.largura = 800, hud.altura = 50;
	hud.sx =0, hud.sy = 0, hud.dx = 0, hud.dy = 0;

	triang.largura = 76.25, triang.altura = 67;
	triang.sx =0, triang.sy = 0, triang.dx = 70, triang.dy = 80;

	quadra.largura = 33, quadra.altura = 23;
	quadra.sx =0, quadra.sy = 0, quadra.dx = 170, quadra.dy = 124;

    queb1.largura = 50, queb1.altura = 89;
	queb1.sx =0, queb1.sy = 0, queb1.dx = 165, queb1.dy = 498;

    queb2.largura = 50, queb2.altura = 89;
	queb2.sx =0, queb2.sy = 0, queb2.dx = 165, queb2.dy = 410;

    queb3.largura = 50, queb3.altura = 89;
	queb3.sx =0, queb3.sy = 0, queb3.dx = 165, queb3.dy = 322;

    queb4.largura = 50, queb4.altura = 89;
	queb4.sx =0, queb4.sy = 0, queb4.dx = 165, queb4.dy = 234;

    queb5.largura = 50, queb5.altura = 89;
	queb5.sx =0, queb5.sy = 0, queb5.dx = 165,queb5.dy = 146;

	pilhatora.largura = 130, pilhatora.altura = 85;
	pilhatora.sx =0, pilhatora.sy = 0, pilhatora.dx = 220,pilhatora.dy = 62;

	player.largura = 52, player.altura = 23, player.pulo = 0;
	player.sx =0, player.sy = 0, player.dx =45, player.dy = 563, player.velx = 15, player.vely = 8.8;
}

void INICIALIZACAO()
{
    SDL_Init(SDL_INIT_AUDIO);
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_WM_SetCaption("Project Square 1.1", NULL);
    screen = SDL_SetVideoMode(LARGURA,ALTURA,BITS,SDL_SWSURFACE);
    IMAGENS();
    squareInfo();
    plataformaInfo();
    escadaInfo();
    recanInfo();
    tampaInfo();
    abInfo();
    quebradaInfo();
    menuInfo();
}

int COLISAO(Player player, Objeto obj_escada1) // Player player é como se fosse meu rect,o mesmo para Objeto objeto
{
    if((player.dx + player.largura > obj_escada1.dx && player.dx < obj_escada1.dx + obj_escada1.largura) &&
    (player.dy + player.altura > obj_escada1.dy && player.dy < obj_escada1.dy + obj_escada1.altura))
      return 1;

    else
      return 0;
}

void MOVIMENTO()
{
	if(Direita)
    {
    	SDL_Surface *aux = square;
    	square = IMG_Load("Imagens/direita.png");
    	SDL_FreeSurface(aux);
    	player.sy=0;
        player.sx += player.largura;

        player.dx += player.velx;
    }
    if(Esquerda)
    {
    	SDL_Surface *aux = square;
    	square = IMG_Load("Imagens/esquerda.png");
    	SDL_FreeSurface(aux);
        player.sy=0;
        player.sx -= player.largura;
        player.dx -= player.velx;
    }

     if( pula )
     {
       if(!descida)
       {
       if(contpulo <= 12)

       {
         velpulo = (12-contpulo);
         player.dy -= velpulo;
         contpulo+=2;

         if(contpulo== 12)
         {
         descida = 1;
         }

       }
      }
       if(descida)
       {
          if(contpulo >= 0)
          {
            velpulo = (12-(contpulo-2));
            player.dy +=velpulo;
            contpulo-=2;

            if(contpulo == 0)
            { descida = 0;
              pula = 0;
            }
          }
       }


     }


    if(Cima)
    {
    //subir escada1

    if(COLISAO(player, obj_escada1) && Cima)
    {
          if (player.dx == obj_escada1.dx)
          {
            player.dy -= player.vely;
            player.dx=obj_escada1.dx;
          }
    }

    //subir escada2
    if(COLISAO(player, obj_escada2) && Cima)
    {
          if (player.dx == obj_escada2.dx)
          {
           player.dy -= player.vely;
           player.dx=obj_escada2.dx;
          }
    }
    //subir escada3
    if(COLISAO(player, obj_escada3) && Cima)
    {
          if (player.dx == obj_escada3.dx)
          {
           player.dy -= player.vely;
           player.dx=obj_escada3.dx;
          }
    }
    //subir escada4
    if(COLISAO(player, obj_escada4) && Cima)
    {
          if (player.dx == obj_escada4.dx)
          {
           player.dy -= player.vely;
           player.dx=obj_escada4.dx;
          }
    }
    //subir escada5
    if(COLISAO(player, obj_escada5) && Cima)
    {
          if (player.dx == obj_escada5.dx)
          {
           player.dy -= player.vely;
           player.dx=obj_escada5.dx;
          }
    }
    }
    if(Baixo)
    {

    //descer escada1
    if( (COLISAO(player, obj_escada1) && Baixo))
    {
          player.dx = obj_escada1.dx;
          player.dy +=player.vely;
        }
    if(player.dy==obj_escada1.dy-23 && player.dx==obj_escada1.dx && Baixo)
    {
        player.dy+=player.vely;
    }
    //descer escada2
    if(COLISAO(player, obj_escada2) && Baixo)
    {
          if(player.dy + player.altura <= obj_escada2.dy+obj_escada2.altura)
          {
          player.dx=obj_escada2.dx;
          player.dy +=player.vely;
          if(player.dy>475)
            player.dy=475;
          }
    }
    if(player.dy==obj_escada2.dy-23 && player.dx==obj_escada2.dx && Baixo)
    {
        player.dy+=player.vely;
        if(player.dy>475)
            player.dy=475;
    }
    //descer escada3
    if(COLISAO(player, obj_escada3) && Baixo)
    {
          if(player.dy + player.altura <= obj_escada3.dy+obj_escada3.altura)
          {
          player.dx=obj_escada3.dx;
          player.dy +=player.vely;
          if(player.dy>387)
            player.dy=387;
          }
    }
    if(player.dy==obj_escada3.dy-23 && player.dx==obj_escada3.dx && Baixo)
    {
        player.dy+=player.vely;
        if(player.dy>387)
            player.dy=387;
    }
    //descer escada4
    if(COLISAO(player, obj_escada4) && Baixo)
    {
          if(player.dy + player.altura <= obj_escada4.dy+obj_escada4.altura)
          {
          player.dx=obj_escada4.dx;
          player.dy +=player.vely;
          if(player.dy>299)
            player.dy=299;
          }
    }
    if(player.dy==obj_escada4.dy-23 && player.dx==obj_escada4.dx && Baixo)
    {
        player.dy+=player.vely;
        if(player.dy>299)
            player.dy=299;
    }
    //descer escada5
    if(COLISAO(player, obj_escada5) && Baixo)
    {
          if(player.dy + player.altura <= obj_escada5.dy+obj_escada5.altura)
          {
          player.dx=obj_escada5.dx;
          player.dy +=player.vely;
          if(player.dy>211)
            player.dy=211;
          }
    }
    if(player.dy==obj_escada5.dy-23 && player.dx==obj_escada5.dx && Baixo)
    {
        player.dy+=player.vely;
        if(player.dy>211)
            player.dy=211;
    }
    }
    }


void NAVEGACAO()
{
    if(menubaixo)
    {
    orbemenu.dy+=57;
    if(orbemenu.dy>539)
        {
        orbemenu.dy=311;
        }
    }
    if(menucima)
    {
    orbemenu.dy-=57;
    if(orbemenu.dy<311)
        {
        orbemenu.dy=539;
        }
    }
    if(selecao == 1)
		{

			if(orbemenu.dy == 311)
			{
				menu = 0;
				historinha = 1;
            }
			else if(orbemenu.dy == 368)
			{
				TUTORIAL = 1;
				Mix_HaltMusic();
				Mix_PlayMusic(tutorial1,-1);
			}
			else if(orbemenu.dy == 425)
			{
				CREDITOS = 1;
				Mix_HaltMusic();
				Mix_PlayMusic(recordes_1,-1);
			}
			else if(orbemenu.dy == 482)
			{
                RECORDES = 1;
                Mix_HaltMusic();
				Mix_PlayMusic(creditos_1,-1);
			}
			else if(orbemenu.dy == 539)
			{
                exit(0);
			}


}
}

void EVENTOMENU()
{
    if(SDL_PollEvent(&eventomenu))
    {
    if(eventomenu.type == SDL_QUIT){exit(0);}
        if(eventomenu.type == SDL_KEYDOWN)
        {
            switch(eventomenu.key.keysym.sym)
            {
            case SDLK_DOWN:
             Mix_PlayChannel(0,efeito_1,0);
             menubaixo = 1;
             break;
            case SDLK_UP:
             Mix_PlayChannel(0,efeito_1,0);
             menucima = 1;
             break;
            case SDLK_RETURN:
             selecao = 1;
			 break;
            }
        }
        if(eventomenu.type == SDL_KEYUP)
         {
            switch(eventomenu.key.keysym.sym)
            {
            case SDLK_DOWN:
             menubaixo=0;
             break;
            case SDLK_UP:
             menucima=0;
             break;
            }
            }
    NAVEGACAO();
}
}

void TECLADO()
{
	if(SDL_PollEvent(&event))
    {
    if(event.type == SDL_QUIT){exit(0);}
        if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                if(!morre && (COLISAO(player, obj_escada1) && player.dy<=559 && player.dy>=476) || (COLISAO(player, obj_escada2) && player.dy<=471 && player.dy>=387) || (COLISAO(player, obj_escada3) && player.dy<=384 && player.dy>=299 ) || (COLISAO(player, obj_escada4) && player.dy<=295 && player.dy>=211) || (COLISAO(player, obj_escada5) && player.dy<=208 && player.dy>=123))
                     {
                         Direita = 0;
                     }
                    else
                     Direita = 1;
                     break;
                case SDLK_LEFT:
                if(!morre && (COLISAO(player, obj_escada1) && player.dy<=559 && player.dy>=476) || (COLISAO(player, obj_escada2) && player.dy<=471 && player.dy>=387) || (COLISAO(player, obj_escada3) && player.dy<=384 && player.dy>=299 ) || (COLISAO(player, obj_escada4) && player.dy<=295 && player.dy>=211) || (COLISAO(player, obj_escada5) && player.dy<=208 && player.dy>=123))
                     {
                         Esquerda = 0;
                     }
                  else
                   Esquerda = 1;
                    break;
                case SDLK_UP:
                    if(!pula)
                        Cima = 1;
                     break;
                case SDLK_DOWN:
                    if(!pula)
                        Baixo=1;
                     break;
                 case SDLK_SPACE:
                  Mix_PlayChannel(1,efeito_2,0);
                  if((COLISAO(player, obj_escada1) && player.dy<=559 && player.dy>=476) || (COLISAO(player, obj_escada2) && player.dy<=471 && player.dy>=387) || (COLISAO(player, obj_escada3) && player.dy<=384 && player.dy>=299 ) || (COLISAO(player, obj_escada4) && player.dy<=295 && player.dy>=211) || (COLISAO(player, obj_escada5) && player.dy<=208 && player.dy>=123))
                     {
                         pula = 0;
                     }

                    else if(!pula)
                     {
                         pula = 1;
                     }
                     break;
                    case SDLK_ESCAPE:
                    exit(0);
                     break;

            }
        }

         if(event.type == SDL_KEYUP)
         {
            switch(event.key.keysym.sym)
            {
                case SDLK_RIGHT:Direita = 0;player.sx=0;
                     break;
                case SDLK_LEFT:Esquerda=0;player.sx= 473;
                     break;
                case SDLK_UP:
                    Cima= 0;
                    break;
                case SDLK_DOWN:Baixo = 0;
                    break;

            }
         }

    }
    MOVIMENTO();
}

void MORTE()
{
    if(COLISAO(player,recan))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan.dx = 220;
        recan.dy = 126;
    }
    if(COLISAO(player,recan2))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan2.dx = 260;
        recan2.dy = 62;
    }
    if(COLISAO(player,recan3))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan3.dx = 260;
        recan3.dy = 125;
    }
    if(COLISAO(player,recan4))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan4.dx = 260;
        recan4.dy = 125;
    }
    if(COLISAO(player,recan5))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan5.dx = 260;
        recan5.dy = 125;
    }
    if(COLISAO(player,recan6))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan6.dx = 260;
        recan6.dy = 125;
    }
    if(COLISAO(player,orbe))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score+= 100;
        orbe.dx = 900;
        recan.dx = 240;
        recan.dy = 650;
        recan2.dx = 260;
        recan2.dy = 650;
        recan6.dx = 240;
        recan6.dy = 650;
        recan5.dx = 240;
        recan5.dy = 650;
        recan4.dx = 240;
        recan4.dy = 650;
        recan3.dx = 240;
        recan3.dy = 650;
        timetora = 0;

        if(timetora==10)
        {
        recan.dx = 240;
        recan.dy = 126;
        recan2.dx = 260;
        recan2.dy = 62;
        recan6.dx = 240;
        recan6.dy = 125;
        recan5.dx = 240;
        recan5.dy = 125;
        recan4.dx = 240;
        recan4.dy = 125;
        recan3.dx = 240;
        recan3.dy = 125;
        timetora = 0;
        }

     if(morre)
        {
        square = IMG_Load("Imagens/morte.png");
        player.altura=28;
        player.largura=36;
        player.sx+=36;
        if(player.sx>=320)
            {
            morre=0;
            square = IMG_Load("Imagens/direita.png");
            player.altura=23;
            player.largura=52;
            player.dx=45;
            player.dy = 563;
            player.sx=0;
            }
        }

    }
    if(COLISAO(player,verm[0]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[0].dx=900;
    }
    if(COLISAO(player,verm[1]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[1].dx=900;
    }
    if(COLISAO(player,verm[2]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[2].dx=900;
    }
    if(COLISAO(player,verm[3]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[3].dx=900;
    }
    if(COLISAO(player,verm[4]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[4].dx=900;
    }
    if(COLISAO(player,verm[5]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[5].dx=900;
    }
}

void MORTE2()
{

    if(COLISAO(player,recan))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        //player.dx= 45;
        //player.dy= 563;
        recan.dx = 220;
        recan.dy = 126;
        morre = 1;
        player.sx=0;

    }
    if(morre)
        {
        square = IMG_Load("Imagens/morte.png");
        player.altura=28;
        player.largura=36;
        player.sx+=36;
        if(player.sx>=320)
            {
            morre=0;
            square = IMG_Load("Imagens/direita.png");
            player.altura=23;
            player.largura=52;
            player.dx=45;
            player.dy = 563;
            player.sx=0;

            }
        }
    if(COLISAO(player,recan2))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan2.dx = 260;
        recan2.dy = 62;
    }
    if(COLISAO(player,recan3))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan3.dx = 260;
        recan3.dy = 125;
    }
    if(COLISAO(player,recan4))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan4.dx = 260;
        recan4.dy = 125;
    }
    if(COLISAO(player,recan5))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan5.dx = 260;
        recan5.dy = 125;
    }
    if(COLISAO(player,recan6))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan6.dx = 260;
        recan6.dy = 125;
    }
    if(COLISAO(player,orbe))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score+= 100;
        orbe.dx = 900;
        recan.dx = 240;
        recan.dy = 650;
        recan2.dx = 260;
        recan2.dy = 650;
        recan6.dx = 240;
        recan6.dy = 650;
        recan5.dx = 240;
        recan5.dy = 650;
        recan4.dx = 240;
        recan4.dy = 650;
        recan3.dx = 240;
        recan3.dy = 650;
        timetora = 0;

        if(timetora==10)
        {
        recan.dx = 240;
        recan.dy = 126;
        recan2.dx = 260;
        recan2.dy = 62;
        recan6.dx = 240;
        recan6.dy = 125;
        recan5.dx = 240;
        recan5.dy = 125;
        recan4.dx = 240;
        recan4.dy = 125;
        recan3.dx = 240;
        recan3.dy = 125;
        timetora = 0;
        }
    }
    if(COLISAO(player,verm[0]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[0].dx=900;
    }
    if(COLISAO(player,verm[1]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[1].dx=900;
    }
    if(COLISAO(player,verm[2]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[2].dx=900;
    }
    if(COLISAO(player,verm[3]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[3].dx=900;
    }
    if(COLISAO(player,verm[4]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[4].dx=900;
    }
    if(COLISAO(player,verm[5]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[5].dx=900;
    }
    if(COLISAO(player,verm[6]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[5].dx=900;
    }
}

void MORTE3()
{
    if(COLISAO(player,recan))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan.dx = 220;
        recan.dy = 126;
    }
    if(COLISAO(player,recan2))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan2.dx = 260;
        recan2.dy = 125;
    }
    if(COLISAO(player,recan3))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan3.dx = 260;
        recan3.dy = 125;
    }
    if(COLISAO(player,recan4))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan4.dx = 260;
        recan4.dy = 125;
    }
    if(COLISAO(player,recan5))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan5.dx = 260;
        recan5.dy = 125;
    }
    if(COLISAO(player,recan6))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        vidas--;
        score = score - 10;
        morre = 1;
        player.sx=0;
        recan6.dx = 260;
        recan6.dy = 125;
    }
    if(COLISAO(player,orbe))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score+= 100;
        orbe.dx = 900;
        recan.dx = 240;
        recan.dy = 650;
        recan2.dx = 260;
        recan2.dy = 650;
        recan6.dx = 240;
        recan6.dy = 650;
        recan5.dx = 240;
        recan5.dy = 650;
        recan4.dx = 240;
        recan4.dy = 650;
        recan3.dx = 240;
        recan3.dy = 650;
        timetora = 0;

        if(timetora==10)
        {
        recan.dx = 240;
        recan.dy = 126;
        recan2.dx = 260;
        recan2.dy = 62;
        recan6.dx = 240;
        recan6.dy = 125;
        recan5.dx = 240;
        recan5.dy = 125;
        recan4.dx = 240;
        recan4.dy = 125;
        recan3.dx = 240;
        recan3.dy = 125;
        timetora = 0;
        }
}
    if(COLISAO(player,orbe2))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score+= 100;
        orbe2.dx = 900;
        recan.dx = 240;
        recan.dy = 650;
        recan2.dx = 260;
        recan2.dy = 650;
        recan6.dx = 240;
        recan6.dy = 650;
        recan5.dx = 240;
        recan5.dy = 650;
        recan4.dx = 240;
        recan4.dy = 650;
        recan3.dx = 240;
        recan3.dy = 650;
        timetora = 0;

        if(timetora==10)
        {
        recan.dx = 240;
        recan.dy = 126;
        recan2.dx = 260;
        recan2.dy = 62;
        recan6.dx = 240;
        recan6.dy = 125;
        recan5.dx = 240;
        recan5.dy = 125;
        recan4.dx = 240;
        recan4.dy = 125;
        recan3.dx = 240;
        recan3.dy = 125;
        timetora = 0;
        }
}
    if(COLISAO(player,orbe3))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score+= 100;
        orbe3.dx = 900;
        recan.dx = 240;
        recan.dy = 650;
        recan2.dx = 260;
        recan2.dy = 650;
        recan6.dx = 240;
        recan6.dy = 650;
        recan5.dx = 240;
        recan5.dy = 650;
        recan4.dx = 240;
        recan4.dy = 650;
        recan3.dx = 240;
        recan3.dy = 650;
        timetora = 0;

        if(timetora==10)
        {
        recan.dx = 240;
        recan.dy = 126;
        recan2.dx = 260;
        recan2.dy = 62;
        recan6.dx = 240;
        recan6.dy = 125;
        recan5.dx = 240;
        recan5.dy = 125;
        recan4.dx = 240;
        recan4.dy = 125;
        recan3.dx = 240;
        recan3.dy = 125;
        timetora = 0;
        }
    }

     if(morre)
        {
        square = IMG_Load("Imagens/morte.png");
        player.altura=28;
        player.largura=36;
        player.sx+=36;
        if(player.sx>=320)
            {
            morre=0;
            square = IMG_Load("Imagens/direita.png");
            player.altura=23;
            player.largura=52;
            player.dx=45;
            player.dy = 563;
            player.sx=0;

            }
        }

    if(COLISAO(player,verm[0]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[0].dx=900;
    }
    if(COLISAO(player,verm[1]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[1].dx=900;
    }
    if(COLISAO(player,verm[2]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[2].dx=900;
    }
    if(COLISAO(player,verm[3]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[3].dx=900;
    }
    if(COLISAO(player,verm[4]))
    {
        Mix_PlayChannel(2 ,efeito_3,0);
        score = score + 10;
        verm[4].dx=900;
    }
}

void MENUGAMEOVER()
{
    //3
    if(pick == 1)
		{
            if(orbego.dy == 100)
			{
                WEWE = 0;
                GAMEOVER = 0;
				jogo = 0;
				jogo0 = 0;
				jogo1 = 0;
				jogarnovamente = 1;
                menu = 0;
			}
			if(orbego.dy == 50)
			{
                WEWE = 0;
                GAMEOVER = 0;
				jogo = 0;
				jogo0 = 0;
				jogo1 = 0;
				jogarnovamente = 0;
				menu = 1;
				pick=0;
				selecao=0;
			}
        }
    if(UP)
        orbego.dy=50;

    if(DOWN)
        orbego.dy=100;

}

void OBSTACULO()
{
    int vela,velb,posDIR,posESQ;

    srand( (unsigned)time(NULL) );

    //obstaculo inferior
    if(recan.dy==126 || recan.dy==302 || recan.dy==478)
    {
        SDL_Surface *aux2 = rec;
    	rec = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan.sx+=recan.largura;
        recan.dx+=23;
        if(recan.sx>=(215-53.75))
        {recan.sx=0;}
    }

    if(recan.dy==214 || recan.dy==390 || recan.dy==566)
    {
        SDL_Surface *aux2 = rec;
    	rec = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan.sx-=recan.largura;
        recan.dx-=23;
        if(recan.sx<0)
        {recan.sx=(215-53.75);}
    }

    if(recan.dx>880)
    {
    //do 6 pro 5
        if(recan.dy==126)
        {
            recan.dy=214;
            recan.dx=880; //-
        }
    //do 4 pro 3
        if(recan.dy==302)
        {
            recan.dy=390;
            recan.dx=880; //-
        }
    //do 2 pro 1
        if(recan.dy==478)
        {
            recan.dy=566;
            recan.dx=880; //-
        }
    }

    if(recan.dx<=-80)
    {
    //do 5 pro 4
        if(recan.dy==214)
        {
            recan.dy=302;
            recan.dx=-80; //+
        }
    //do 3 pro 2
        if(recan.dy==390)
        {
            recan.dy=478;
            recan.dx=-80; //+
        }
    //do 1 pro 6
        if(recan.dy==566)
        {
            recan.dy=126;
            recan.dx=220;
        }
    }

    //obstaculo superior
    if(recan2.dy==62 || recan2.dy==249 || recan2.dy==425)
    {
        SDL_Surface *aux2 = rec2;
    	rec2 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan2.sx+=recan.largura;
        recan2.dx+=20;
        if(recan2.sx>=(215-53.75))
        {recan2.sx=0;}
    }

    if(recan2.dy==161 || recan2.dy==337 || recan2.dy==513)
    {
        SDL_Surface *aux2 = rec2;
    	rec2 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan2.sx-=recan.largura;
        recan2.dx-=20;
        if(recan2.sx<0)
        {recan2.sx=(215-53.75);}
    }

    if(recan2.dx>=880)
    {
    posDIR=rand() % 3;

    if(posDIR==0)
    {
    //do 6 pro 5
        //if(recan2.dy==75)
        //{
            recan2.dy=161;
            recan2.dx=880; //-
        //}
    }
    if(posDIR==1)
    {
    //do 4 pro 3
    //if(recan2.dy==249)
        //{
            recan2.dy=337;
            recan2.dx=880; //-
        //}
    }
    if(posDIR==2)
    {
    //do 2 pro 1
    //if(recan2.dy==425)
        //{
            recan2.dy=513;
            recan2.dx=880; //-
        //}
    }
    }

    if(recan2.dx<=-80)
    {
    posESQ=rand() % 3;

    if(posESQ==0)
    {
    //do 5 pro 4
        //if(recan2.dy==161)
        //{
            recan2.dy=249;
            recan2.dx=-80; //+
        //}
    }
    if(posESQ==1)
    {
    //do 3 pro 2
        //if(recan2.dy==337)
        //{
            recan2.dy=425;
            recan2.dx=-80; //+
        //}
    }
    if(posESQ==2)
    {
    //do 1 pro 6
        //if(recan2.dy==513)
        //{
            recan2.dy=62;
            recan2.dx=260;
        //}
    }
    }

    if(recan3.dy==126 || recan3.dy==302 || recan3.dy==478)
    {
        SDL_Surface *aux3 = rec3;
    	rec3 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux3);
        recan3.sx+=recan3.largura;
        //recan.dx+=20;
        recan3.dx+=22;

        if(recan3.sx>=(215-53.75))
        {recan3.sx=0;}
    }

    if(recan3.dy==214 || recan3.dy==390 || recan3.dy==566)
    {
        SDL_Surface *aux3 = rec3;
    	rec3 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux3);
        recan3.sx-=recan3.largura;
        recan3.dx-=22;
        if(recan3.sx<0)
        {recan3.sx=(215-53.75);}
    }

    if(recan3.dx>880)
    {
    //do 6 pro 5
        if(recan3.dy==126)
        {
            recan3.dy=214;
            recan3.dx=880; //-
        }
    //do 4 pro 3
        if(recan3.dy==302)
        {
            recan3.dy=390;
            recan3.dx=880; //-
        }
    //do 2 pro 1
        if(recan3.dy==478)
        {
            recan3.dy=566;
            recan3.dx=880; //-
        }
    }

    if(recan3.dx<=-80)
    {
    //do 5 pro 4
        if(recan3.dy==214)
        {
            recan3.dy=302;
            recan3.dx=-80; //+
        }
    //do 3 pro 2
        if(recan3.dy==390)
        {
            recan3.dy=478;
            recan3.dx=-80; //+
        }
    //do 1 pro 6
        if(recan3.dy==566)
        {
            recan3.dy=125;
            recan3.dx=240;
        }
    }

    if(recan4.dy==126 || recan4.dy==302 || recan4.dy==478)
    {
        SDL_Surface *aux2 = rec4;
    	rec4 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan4.sx+=recan4.largura;
        recan4.dx+=21;
        if(recan4.sx>=(215-53.75))
        {recan4.sx=0;}
    }

    if(recan4.dy==214 || recan4.dy==390 || recan4.dy==566)
    {
        SDL_Surface *aux2 = rec4;
    	rec4 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan4.sx-=recan.largura;
        recan4.dx-=21;
        if(recan4.sx<0)
        {recan4.sx=(215-53.75);}
    }

    if(recan4.dx>880)
    {
    //do 6 pro 5
        if(recan4.dy==126)
        {
            recan4.dy=214;
            recan4.dx=880; //-
        }
    //do 4 pro 3
        if(recan4.dy==302)
        {
            recan4.dy=390;
            recan4.dx=880; //-
        }
    //do 2 pro 1
        if(recan4.dy==478)
        {
            recan4.dy=566;
            recan4.dx=880; //-
        }
    }

    if(recan4.dx<=-80)
    {
    //do 5 pro 4
        if(recan4.dy==214)
        {
            recan4.dy=302;
            recan4.dx=-80; //+
        }
    //do 3 pro 2
        if(recan4.dy==390)
        {
            recan4.dy=478;
            recan4.dx=-80; //+
        }
    //do 1 pro 6
        if(recan4.dy==566)
        {
            recan4.dy=125;
            recan4.dx=240;
        }
    }
    if(recan5.dy==126 || recan5.dy==302 || recan5.dy==478)
    {
        SDL_Surface *aux2 = rec5;
    	rec5 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan5.sx+=recan5.largura;
        recan5.dx+=20;
        if(recan5.sx>=(215-53.75))
        {recan5.sx=0;}
    }

    if(recan5.dy==214 || recan5.dy==390 || recan5.dy==566)
    {
        SDL_Surface *aux2 = rec5;
    	rec5 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan5.sx-=recan.largura;
        recan5.dx-=20;
        if(recan5.sx<0)
        {recan5.sx=(215-53.75);}
    }

    if(recan5.dx>880)
    {
    //do 6 pro 5
        if(recan5.dy==126)
        {
            recan5.dy=214;
            recan5.dx=880; //-
        }
    //do 4 pro 3
        if(recan5.dy==302)
        {
            recan5.dy=390;
            recan5.dx=880; //-
        }
    //do 2 pro 1
        if(recan5.dy==478)
        {
            recan5.dy=566;
            recan5.dx=880; //-
        }
    }

    if(recan5.dx<=-80)
    {
    //do 5 pro 4
        if(recan5.dy==214)
        {
            recan5.dy=302;
            recan5.dx=-80; //+
        }
    //do 3 pro 2
        if(recan5.dy==390)
        {
            recan5.dy=478;
            recan5.dx=-80; //+
        }
    //do 1 pro 6
        if(recan5.dy==566)
        {
            recan5.dy=125;
            recan5.dx=240;
        }
    }
    if(recan6.dy==126 || recan6.dy==302 || recan6.dy==478)
    {
        SDL_Surface *aux2 = rec6;
    	rec6 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan6.sx+=recan6.largura;
        recan6.dx+=19;
        if(recan6.sx>=(215-53.75))
        {recan6.sx=0;}
    }

    if(recan6.dy==214 || recan6.dy==390 || recan6.dy==566)
    {
        SDL_Surface *aux2 = rec6;
    	rec6 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan6.sx-=recan.largura;
        recan6.dx-=19;
        if(recan6.sx<0)
        {recan6.sx=(215-53.75);}
    }

    if(recan6.dx>880)
    {
    //do 6 pro 5
        if(recan6.dy==126)
        {
            recan6.dy=214;
            recan6.dx=880; //-
        }
    //do 4 pro 3
        if(recan6.dy==302)
        {
            recan6.dy=390;
            recan6.dx=880; //-
        }
    //do 2 pro 1
        if(recan6.dy==478)
        {
            recan6.dy=566;
            recan6.dx=880; //-
        }
    }

    if(recan6.dx<=-80)
    {
    //do 5 pro 4
        if(recan6.dy==214)
        {
            recan6.dy=302;
            recan6.dx=-80; //+
        }
    //do 3 pro 2
        if(recan6.dy==390)
        {
            recan6.dy=478;
            recan6.dx=-80; //+
        }
    //do 1 pro 6
        if(recan6.dy==566)
        {
            recan6.dy=125;
            recan6.dx=240;
        }
    }
     MORTE();
}

void OBSTACULO2()
{
    int vela,velb,posDIR,posESQ;

    srand( (unsigned)time(NULL) );

    //obstaculo inferior
    if(recan.dy==126 || recan.dy==302 || recan.dy==478)
    {
        SDL_Surface *aux2 = rec;
    	rec = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan.sx+=recan.largura;
        recan.dx+=23;
        if(recan.sx>=(215-53.75))
        {recan.sx=0;}
    }

    if(recan.dy==214 || recan.dy==390 || recan.dy==566)
    {
        SDL_Surface *aux2 = rec;
    	rec = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan.sx-=recan.largura;
        recan.dx-=23;
        if(recan.sx<0)
        {recan.sx=(215-53.75);}
    }

    if(recan.dx>880)
    {
    //do 6 pro 5
        if(recan.dy==126)
        {
            recan.dy=214;
            recan.dx=880; //-
        }
    //do 4 pro 3
        if(recan.dy==302)
        {
            recan.dy=390;
            recan.dx=880; //-
        }
    //do 2 pro 1
        if(recan.dy==478)
        {
            recan.dy=566;
            recan.dx=880; //-
        }
    }

    if(recan.dx<=-80)
    {
    //do 5 pro 4
        if(recan.dy==214)
        {
            recan.dy=302;
            recan.dx=-80; //+
        }
    //do 3 pro 2
        if(recan.dy==390)
        {
            recan.dy=478;
            recan.dx=-80; //+
        }
    //do 1 pro 6
        if(recan.dy==566)
        {
            recan.dy=126;
            recan.dx=220;
        }
    }

    if(recan3.dy==126 || recan3.dy==302 || recan3.dy==478)
    {
        SDL_Surface *aux3 = rec3;
    	rec3 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux3);
        recan3.sx+=recan3.largura;
        //recan.dx+=20;
        recan3.dx+=22;

        if(recan3.sx>=(215-53.75))
        {recan3.sx=0;}
    }

    if(recan3.dy==214 || recan3.dy==390 || recan3.dy==566)
    {
        SDL_Surface *aux3 = rec3;
    	rec3 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux3);
        recan3.sx-=recan3.largura;
        recan3.dx-=22;
        if(recan3.sx<0)
        {recan3.sx=(215-53.75);}
    }

    if(recan3.dx>880)
    {
    //do 6 pro 5
        if(recan3.dy==126)
        {
            recan3.dy=214;
            recan3.dx=880; //-
        }
    //do 4 pro 3
        if(recan3.dy==302)
        {
            recan3.dy=390;
            recan3.dx=880; //-
        }
    //do 2 pro 1
        if(recan3.dy==478)
        {
            recan3.dy=566;
            recan3.dx=880; //-
        }
    }

    if(recan3.dx<=-80)
    {
    //do 5 pro 4
        if(recan3.dy==214)
        {
            recan3.dy=302;
            recan3.dx=-80; //+
        }
    //do 3 pro 2
        if(recan3.dy==390)
        {
            recan3.dy=478;
            recan3.dx=-80; //+
        }
    //do 1 pro 6
        if(recan3.dy==566)
        {
            recan3.dy=125;
            recan3.dx=240;
        }
    }

    if(recan4.dy==126 || recan4.dy==302 || recan4.dy==478)
    {
        SDL_Surface *aux2 = rec4;
    	rec4 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan4.sx+=recan4.largura;
        recan4.dx+=21;
        if(recan4.sx>=(215-53.75))
        {recan4.sx=0;}
    }

    if(recan4.dy==214 || recan4.dy==390 || recan4.dy==566)
    {
        SDL_Surface *aux2 = rec4;
    	rec4 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan4.sx-=recan.largura;
        recan4.dx-=21;
        if(recan4.sx<0)
        {recan4.sx=(215-53.75);}
    }

    if(recan4.dx>880)
    {
    //do 6 pro 5
        if(recan4.dy==126)
        {
            recan4.dy=214;
            recan4.dx=880; //-
        }
    //do 4 pro 3
        if(recan4.dy==302)
        {
            recan4.dy=390;
            recan4.dx=880; //-
        }
    //do 2 pro 1
        if(recan4.dy==478)
        {
            recan4.dy=566;
            recan4.dx=880; //-
        }
    }

    if(recan4.dx<=-80)
    {
    //do 5 pro 4
        if(recan4.dy==214)
        {
            recan4.dy=302;
            recan4.dx=-80; //+
        }
    //do 3 pro 2
        if(recan4.dy==390)
        {
            recan4.dy=478;
            recan4.dx=-80; //+
        }
    //do 1 pro 6
        if(recan4.dy==566)
        {
            recan4.dy=125;
            recan4.dx=240;
        }
    }
    if(recan5.dy==126 || recan5.dy==302 || recan5.dy==478)
    {
        SDL_Surface *aux2 = rec5;
    	rec5 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan5.sx+=recan5.largura;
        recan5.dx+=20;
        if(recan5.sx>=(215-53.75))
        {recan5.sx=0;}
    }

    if(recan5.dy==214 || recan5.dy==390 || recan5.dy==566)
    {
        SDL_Surface *aux2 = rec5;
    	rec5 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan5.sx-=recan.largura;
        recan5.dx-=20;
        if(recan5.sx<0)
        {recan5.sx=(215-53.75);}
    }

    if(recan5.dx>880)
    {
    //do 6 pro 5
        if(recan5.dy==126)
        {
            recan5.dy=214;
            recan5.dx=880; //-
        }
    //do 4 pro 3
        if(recan5.dy==302)
        {
            recan5.dy=390;
            recan5.dx=880; //-
        }
    //do 2 pro 1
        if(recan5.dy==478)
        {
            recan5.dy=566;
            recan5.dx=880; //-
        }
    }

    if(recan5.dx<=-80)
    {
    //do 5 pro 4
        if(recan5.dy==214)
        {
            recan5.dy=302;
            recan5.dx=-80; //+
        }
    //do 3 pro 2
        if(recan5.dy==390)
        {
            recan5.dy=478;
            recan5.dx=-80; //+
        }
    //do 1 pro 6
        if(recan5.dy==566)
        {
            recan5.dy=125;
            recan5.dx=240;
        }
    }
    if(recan6.dy==126 || recan6.dy==302 || recan6.dy==478)
    {
        SDL_Surface *aux2 = rec6;
    	rec6 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan6.sx+=recan6.largura;
        recan6.dx+=19;
        if(recan6.sx>=(215-53.75))
        {recan6.sx=0;}
    }

    if(recan6.dy==214 || recan6.dy==390 || recan6.dy==566)
    {
        SDL_Surface *aux2 = rec6;
    	rec6 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan6.sx-=recan.largura;
        recan6.dx-=19;
        if(recan6.sx<0)
        {recan6.sx=(215-53.75);}
    }

    if(recan6.dx>880)
    {
    //do 6 pro 5
        if(recan6.dy==126)
        {
            recan6.dy=214;
            recan6.dx=880; //-
        }
    //do 4 pro 3
        if(recan6.dy==302)
        {
            recan6.dy=390;
            recan6.dx=880; //-
        }
    //do 2 pro 1
        if(recan6.dy==478)
        {
            recan6.dy=566;
            recan6.dx=880; //-
        }
    }

    if(recan6.dx<=-80)
    {
    //do 5 pro 4
        if(recan6.dy==214)
        {
            recan6.dy=302;
            recan6.dx=-80; //+
        }
    //do 3 pro 2
        if(recan6.dy==390)
        {
            recan6.dy=478;
            recan6.dx=-80; //+
        }
    //do 1 pro 6
        if(recan6.dy==566)
        {
            recan6.dy=125;
            recan6.dx=240;
        }
    }
     MORTE2();
}

void OBSTACULO3()
{
    int vela,velb,posDIR,posESQ;

    srand( (unsigned)time(NULL) );

    //obstaculo inferior
    if(recan.dy==126 || recan.dy==302 || recan.dy==478)
    {
        SDL_Surface *aux2 = rec;
    	rec = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan.sx+=recan.largura;
        recan.dx+=23;
        if(recan.sx>=(215-53.75))
        {recan.sx=0;}
    }

    if(recan.dy==214 || recan.dy==390 || recan.dy==566)
    {
        SDL_Surface *aux2 = rec;
    	rec = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan.sx-=recan.largura;
        recan.dx-=23;
        if(recan.sx<0)
        {recan.sx=(215-53.75);}
    }

    if(recan.dx>880)
    {
    //do 6 pro 5
        if(recan.dy==126)
        {
            recan.dy=214;
            recan.dx=880; //-
        }
    //do 4 pro 3
        if(recan.dy==302)
        {
            recan.dy=390;
            recan.dx=880; //-
        }
    //do 2 pro 1
        if(recan.dy==478)
        {
            recan.dy=566;
            recan.dx=880; //-
        }
    }

    if(recan.dx<=-80)
    {
    //do 5 pro 4
        if(recan.dy==214)
        {
            recan.dy=302;
            recan.dx=-80; //+
        }
    //do 3 pro 2
        if(recan.dy==390)
        {
            recan.dy=478;
            recan.dx=-80; //+
        }
    //do 1 pro 6
        if(recan.dy==566)
        {
            recan.dy=126;
            recan.dx=220;
        }
    }

    //obstaculo superior
    if(recan2.dy==62 || recan2.dy==249 || recan2.dy==425)
    {
        SDL_Surface *aux2 = rec2;
    	rec2 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan2.sx+=recan.largura;
        recan2.dx+=20;
        if(recan2.sx>=(215-53.75))
        {recan2.sx=0;}
    }

    if(recan2.dy==161 || recan2.dy==337 || recan2.dy==513)
    {
        SDL_Surface *aux2 = rec2;
    	rec2 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan2.sx-=recan.largura;
        recan2.dx-=20;
        if(recan2.sx<0)
        {recan2.sx=(215-53.75);}
    }

    if(recan2.dx>=880)
    {
    posDIR=rand() % 3;

    if(posDIR==0)
    {
    //do 6 pro 5
        //if(recan2.dy==75)
        //{
            recan2.dy=161;
            recan2.dx=880; //-
        //}
    }
    if(posDIR==1)
    {
    //do 4 pro 3
    //if(recan2.dy==249)
        //{
            recan2.dy=337;
            recan2.dx=880; //-
        //}
    }
    if(posDIR==2)
    {
    //do 2 pro 1
    //if(recan2.dy==425)
        //{
            recan2.dy=513;
            recan2.dx=880; //-
        //}
    }
    }

    if(recan2.dx<=-80)
    {
    posESQ=rand() % 3;

    if(posESQ==0)
    {
    //do 5 pro 4
        //if(recan2.dy==161)
        //{
            recan2.dy=249;
            recan2.dx=-80; //+
        //}
    }
    if(posESQ==1)
    {
    //do 3 pro 2
        //if(recan2.dy==337)
        //{
            recan2.dy=425;
            recan2.dx=-80; //+
        //}
    }
    if(posESQ==2)
    {
    //do 1 pro 6
        //if(recan2.dy==513)
        //{
            recan2.dy=62;
            recan2.dx=260;
        //}
    }
    }

    if(recan3.dy==126 || recan3.dy==302 || recan3.dy==478)
    {
        SDL_Surface *aux3 = rec3;
    	rec3 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux3);
        recan3.sx+=recan3.largura;
        //recan.dx+=20;
        recan3.dx+=22;

        if(recan3.sx>=(215-53.75))
        {recan3.sx=0;}
    }

    if(recan3.dy==214 || recan3.dy==390 || recan3.dy==566)
    {
        SDL_Surface *aux3 = rec3;
    	rec3 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux3);
        recan3.sx-=recan3.largura;
        recan3.dx-=22;
        if(recan3.sx<0)
        {recan3.sx=(215-53.75);}
    }

    if(recan3.dx>880)
    {
    //do 6 pro 5
        if(recan3.dy==126)
        {
            recan3.dy=214;
            recan3.dx=880; //-
        }
    //do 4 pro 3
        if(recan3.dy==302)
        {
            recan3.dy=390;
            recan3.dx=880; //-
        }
    //do 2 pro 1
        if(recan3.dy==478)
        {
            recan3.dy=566;
            recan3.dx=880; //-
        }
    }

    if(recan3.dx<=-80)
    {
    //do 5 pro 4
        if(recan3.dy==214)
        {
            recan3.dy=302;
            recan3.dx=-80; //+
        }
    //do 3 pro 2
        if(recan3.dy==390)
        {
            recan3.dy=478;
            recan3.dx=-80; //+
        }
    //do 1 pro 6
        if(recan3.dy==566)
        {
            recan3.dy=125;
            recan3.dx=240;
        }
    }

    if(recan4.dy==62 || recan4.dy==249 || recan4.dy==425)
    {
        SDL_Surface *aux2 = rec4;
    	rec4 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan4.sx+=recan.largura;
        recan4.dx+=20;
        if(recan4.sx>=(215-53.75))
        {recan4.sx=0;}
    }

    if(recan4.dy==161 || recan4.dy==337 || recan4.dy==513)
    {
        SDL_Surface *aux2 = rec4;
    	rec4 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan4.sx-=recan.largura;
        recan4.dx-=20;
        if(recan4.sx<0)
        {recan4.sx=(215-53.75);}
    }

    if(recan4.dx>=880)
    {
    //do 6 pro 5
        if(recan4.dy==75)
        {
            recan4.dy=161;
            recan4.dx=880; //-
        }
    //do 4 pro 3
        if(recan4.dy==249)
        {
            recan4.dy=337;
            recan4.dx=880; //-
        }
    //do 2 pro 1
        if(recan4.dy==425)
        {
            recan4.dy=513;
            recan4.dx=880; //-
        }
    }

    if(recan4.dx<=-80)
    {
    //do 5 pro 4
        if(recan2.dy==161)
        {
            recan4.dy=249;
            recan4.dx=-80; //+
        }
    //do 3 pro 2
        if(recan2.dy==337)
        {
            recan4.dy=425;
            recan4.dx=-80; //+
        }
    //do 1 pro 6
        if(recan2.dy==513)
        {
            recan4.dy=61;
            recan4.dx=260;
        }
    }

    if(recan5.dy==126 || recan5.dy==302 || recan5.dy==478)
    {
        SDL_Surface *aux2 = rec5;
    	rec5 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan5.sx+=recan5.largura;
        recan5.dx+=20;
        if(recan5.sx>=(215-53.75))
        {recan5.sx=0;}
    }

    if(recan5.dy==214 || recan5.dy==390 || recan5.dy==566)
    {
        SDL_Surface *aux2 = rec5;
    	rec5 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan5.sx-=recan.largura;
        recan5.dx-=20;
        if(recan5.sx<0)
        {recan5.sx=(215-53.75);}
    }

    if(recan5.dx>880)
    {
    //do 6 pro 5
        if(recan5.dy==126)
        {
            recan5.dy=214;
            recan5.dx=880; //-
        }
    //do 4 pro 3
        if(recan5.dy==302)
        {
            recan5.dy=390;
            recan5.dx=880; //-
        }
    //do 2 pro 1
        if(recan5.dy==478)
        {
            recan5.dy=566;
            recan5.dx=880; //-
        }
    }

    if(recan5.dx<=-80)
    {
    //do 5 pro 4
        if(recan5.dy==214)
        {
            recan5.dy=302;
            recan5.dx=-80; //+
        }
    //do 3 pro 2
        if(recan5.dy==390)
        {
            recan5.dy=478;
            recan5.dx=-80; //+
        }
    //do 1 pro 6
        if(recan5.dy==566)
        {
            recan5.dy=125;
            recan5.dx=240;
        }
    }
    if(recan6.dy==62 || recan6.dy==249 || recan6.dy==425)
    {
        SDL_Surface *aux2 = rec6;
    	rec6 = IMG_Load("Imagens/2.png");
    	SDL_FreeSurface(aux2);
        recan6.sx+=recan.largura;
        recan6.dx+=20;
        if(recan6.sx>=(215-53.75))
        {recan6.sx=0;}
    }

    if(recan6.dy==161 || recan6.dy==337 || recan6.dy==513)
    {
        SDL_Surface *aux2 = rec6;
    	rec6 = IMG_Load("Imagens/1.png");
    	SDL_FreeSurface(aux2);
        recan6.sx-=recan.largura;
        recan6.dx-=20;
        if(recan6.sx<0)
        {recan6.sx=(215-53.75);}
    }

    if(recan6.dx>=880)
    {
    //do 6 pro 5
        if(recan6.dy==75)
        {
            recan6.dy=161;
            recan6.dx=880; //-
        }
    //do 4 pro 3
        if(recan6.dy==249)
        {
            recan6.dy=337;
            recan6.dx=880; //-
        }
    //do 2 pro 1
        if(recan6.dy==425)
        {
            recan6.dy=513;
            recan6.dx=880; //-
        }
    }

    if(recan6.dx<=-80)
    {
    //do 5 pro 4
        if(recan6.dy==161)
        {
            recan6.dy=249;
            recan6.dx=-80; //+
        }
    //do 3 pro 2
        if(recan6.dy==337)
        {
            recan6.dy=425;
            recan6.dx=-80; //+
        }
    //do 1 pro 6
        if(recan6.dy==513)
        {
            recan6.dy=61;
            recan6.dx=260;
        }
    }
     MORTE3();
}
void FIM()
{
    SDL_FreeSurface(background); // limpa os terminais com as imagens
    SDL_FreeSurface(square);
    SDL_Quit(); //Encerra o SDL
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
}



int main(int argc, char* args[])
{
    sons();
    //while(repeticao==1){
    INICIALIZACAO();
        //menu();
    int segundos = 600, minutos=20, i;
  	char string_minuto[2], string_segundo[3], string_vida[6],string_score[6];
		int pontos = 0;
  	for(i=0;i<2; i++)//limpar lixo de memória na string
      string_minuto[i]='\0';
  	for(i=0;i<3; i++)//limpar lixo de memória na string
      string_segundo[i]='\0';
	  for(i=0;i<6; i++)//limpar lixo de memória na string
      string_vida[i]='\0';


    while(ON)
    {
    Mix_PlayMusic(abertura_isaac,0);
    while(abertura)
    {
    start = SDL_GetTicks();

    if(aberturaisaac == NULL)
    {
    printf("Erro ao carregar a imagem: %s\n", IMG_GetError());
    }

    ab1.sx+=ab1.largura;

    if(ab1.sx==4000)
    {
    ab1.sx=0;
    ab1.sy+=alturaTELA;
    }
    if(ab1.sy>4800)
    {
    abertura=0;
    abertura2=1;
    }

    SDL_FillRect(screen,0,0x0);
    draw_object(ab1.sx,ab1.sy,ab1.dx,ab1.dy,ab1.largura,ab1.altura, aberturaisaac, screen);

    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }

    Mix_HaltMusic();
    Mix_PlayMusic(dome,0);
    while(abertura2)
    {
    start = SDL_GetTicks();

    if(aberturadome == NULL)
    {
    printf("Erro ao carregar a imagem: %s\n", IMG_GetError());
    }

    ab2.sx+=ab2.largura;

    if(ab2.sx==4800)
    {
    ab2.sx=0;
    ab2.sy+=alturaTELA;
    }
    if(ab2.sy>1800)
    {
    abertura=0;
    abertura2=0;
    menu = 1;
    }

    SDL_FillRect(screen,0,0x0);
    draw_object(ab2.sx,ab2.sy,ab2.dx,ab2.dy,ab2.largura,ab2.altura, aberturadome, screen);

    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
    Mix_HaltMusic();

    if(jogarnovamente!=1)
        {
        menu = 1;
        jogo0=0;
        jogo1=0;
        jogo=0;
        pick=0;
        historinha=0;
        loading=0;
        selecao=0;
        GAMEOVER=0;
        WEWE=0;
        }
    if(menu == 1)
        Mix_PlayMusic(menu_princ,-1);


    while(menu!=0)
    {
    start = SDL_GetTicks();


    EVENTOMENU();
        while(TUTORIAL == 1)
		{

			SDL_Event eventomenu;

			while(SDL_PollEvent(&eventomenu))
			{

				switch(eventomenu.type)
				{

					case SDL_QUIT:
						exit(0);
						break;

                    case SDL_KEYUP:

						switch(eventomenu.key.keysym.sym)
						{

							case SDLK_ESCAPE:
								TUTORIAL = 0;
								selecao = 0;
								Mix_HaltMusic();
								Mix_PlayMusic(menu_princ,-1);
								break;

							default:
								break;
                        }
					default:
						break;

				}
			}
			SDL_FillRect(screen,0,0x0);
			draw_object(TUTO.sx,TUTO.sy,TUTO.dx,TUTO.dy,TUTO.largura,TUTO.altura, tutorialhud, screen);SDL_Flip(screen);

			if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
    while(CREDITOS == 1)
		{

			SDL_Event eventomenu;

			while(SDL_PollEvent(&eventomenu))
			{

				switch(eventomenu.type)
				{

					case SDL_QUIT:
						exit(0);
						break;

                    case SDL_KEYUP:

						switch(eventomenu.key.keysym.sym)
						{

							case SDLK_ESCAPE:
								CREDITOS = 0;
								selecao = 0;
								easteregg = 0;
								Mix_HaltMusic();
								Mix_PlayMusic(menu_princ,-1);
								break;
                            case SDLK_SPACE:
                                easteregg++;

							default:
								break;
                        }
					default:
						break;

				}
			}
			SDL_FillRect(screen,0,0x0);
			draw_object(CRED.sx,CRED.sy,CRED.dx,CRED.dy,CRED.largura,CRED.altura, creditoshud, screen);
			if(easteregg==3)
                draw_object(rur.sx,rur.sy,rur.dx,rur.dy,rur.largura,rur.altura, rural, screen);
			SDL_Flip(screen);

			if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }

    while(RECORDES == 1)
		{
			SDL_Event eventomenu;

			while(SDL_PollEvent(&eventomenu))
			{

				switch(eventomenu.type)
				{

					case SDL_QUIT:
						exit(0);
						break;

                    case SDL_KEYUP:

						switch(eventomenu.key.keysym.sym)
						{

							case SDLK_ESCAPE:
								RECORDES = 0;
								selecao = 0;
								Mix_HaltMusic();
								Mix_PlayMusic(menu_princ,-1);
								break;

							default:
								break;
                        }
					default:
						break;

				}
			}
			SDL_FillRect(screen,0,0x0);
			draw_object(RECOR.sx,RECOR.sy,RECOR.dx,RECOR.dy,RECOR.largura,RECOR.altura, recordeshud, screen);
			escrever_recordes();


			if(1000/FPS >(SDL_GetTicks()-start))
                SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
            SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }

    MENU.sx+=800;

    if(MENU.sx==5600)
    {
    MENU.sx=0;
    }

    orbemenu.sx+=19;
    if(orbemenu.sx>=114)
        orbemenu.sx=0;

    SDL_FillRect(screen,0,0x0);
    draw_object(MENU.sx,MENU.sy,MENU.dx,MENU.dy,MENU.largura,MENU.altura, menuhud, screen);
    draw_object(Bjogar.sx,Bjogar.sy,Bjogar.dx,Bjogar.dy,Bjogar.largura,Bjogar.altura, jogarbut, screen);
    draw_object(Bcred.sx,Bcred.sy,Bcred.dx,Bcred.dy,Bcred.largura,Bcred.altura, credbut, screen);
    draw_object(Btuto.sx,Btuto.sy,Btuto.dx,Btuto.dy,Btuto.largura,Btuto.altura, tutobut, screen);
    draw_object(Bsair.sx,Bsair.sy,Bsair.dx,Bsair.dy,Bsair.largura,Bsair.altura, sairbut, screen);
    draw_object(Brecor.sx,Brecor.sy,Brecor.dx,Brecor.dy,Brecor.largura,Brecor.altura, recorbut, screen);
    draw_object(orbemenu.sx,orbemenu.sy,orbemenu.dx,orbemenu.dy,orbemenu.largura,orbemenu.altura, icon, screen);

    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
    if(menu == 0)
        Mix_HaltMusic();

    Mix_PlayMusic(historia_1, -1);

    while(historinha)
    {
    start = SDL_GetTicks();

    timehist++;

    if(timehist==50)
     {
        jogo0 = 1;
        historinha = 0;
    }

    SDL_FillRect(screen,0,0x0);
    draw_object(HIST.sx,HIST.sy,HIST.dx,HIST.dy,HIST.largura,HIST.altura, historia, screen);

    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
    Mix_HaltMusic();

    if(jogo == 1 || jogo0 == 1 || jogo1 == 1 || jogarnovamente == 1)
        Mix_PlayMusic(jogo_rodando,-1);


    if(jogarnovamente == 1 )
    {
        WEWE = 0;
        GAMEOVER = 0;
        vidas = 3;
        score=0.0;
        segundos = 600, minutos=20;
        pick = 0;
        jogo0 = 1;
        FASE2();
        jogo = 0;
        jogo1 = 0;
        jogo0 = 1;
        jogarnovamente = 0;
    }
    FASE2();
    // FASE !
    while(jogo0 == 1)
    {
    start = SDL_GetTicks();

    TECLADO();
    OBSTACULO2();

    orbe.sx+=19;
    if(orbe.sx>=114)
        orbe.sx=0;

    triang.sx+=76;
    if(triang.sx>848)
        triang.sx=0;
    quadra.sx+=33;
    if(quadra.sx>432)
        quadra.sx=0;
    //animação
    if(player.sx > 525-player.largura)
        player.sx = 312;

    if(player.sx < 0)
        player.sx = player.largura;

    //Inicio da Barreiras da fase
    if(player.dx >= 720)
    {
        player.dx = 720;
    }
    if(player.dx <= 30)
    {
      player.dx = 30;
    }
    if(player.dy>=563)
    {
      player.dy=563;
    }
    if(timetora==0)
        recan.dy=126;
    if(timetora==30)
        recan3.dy=126;
    if(timetora==60)
        recan4.dy=126;
    if(timetora==90)
        recan5.dy=126;
    if(timetora==120)
        recan6.dy=126;

    if(score<0)
        score=0;

    timetora++;

    if(timetora>=390)
    {
        timetora=0;
        orbe.dx = 40;
    }
    verm[0].sx+=15;
    verm[1].sx+=15;
    verm[2].sx+=15;
    verm[3].sx+=15;
    verm[4].sx+=15;
    verm[5].sx+=15;

    if(verm[0].sx>73)
        verm[0].sx=0;
    if(verm[1].sx>73)
        verm[1].sx=0;
    if(verm[2].sx>73)
        verm[2].sx=0;
    if(verm[3].sx>73)
        verm[3].sx=0;
    if(verm[4].sx>73)
        verm[4].sx=0;
    if(verm[5].sx>73)
        verm[5].sx=0;

    if(player.dx== 165 && player.dy==163)
        {
        jogo0=0;
        loading = 1;
        score+=500;
        }


    //Fim da Barreiras da fase
   // printf("%d %d\n",player.dx,player.dy);

    //Blitar a imagem na tela
    SDL_FillRect(screen,0,0x0);
    SDL_BlitSurface(background,0 , screen, 0);

    draw_object(obj_plataforma1.sx,obj_plataforma1.sy,obj_plataforma1.dx,obj_plataforma1.dy,obj_plataforma1.largura,obj_plataforma1.altura, plataforma2, screen);
    draw_object(obj_plataforma2.sx,obj_plataforma2.sy,obj_plataforma2.dx,obj_plataforma2.dy,obj_plataforma2.largura,obj_plataforma2.altura, plataforma1, screen);
    draw_object(obj_plataforma3.sx,obj_plataforma3.sy,obj_plataforma3.dx,obj_plataforma3.dy,obj_plataforma3.largura,obj_plataforma3.altura, plataforma1, screen);
    draw_object(obj_plataforma4.sx,obj_plataforma4.sy,obj_plataforma4.dx,obj_plataforma4.dy,obj_plataforma4.largura,obj_plataforma4.altura, plataforma1, screen);
    draw_object(obj_plataforma5.sx,obj_plataforma5.sy,obj_plataforma5.dx,obj_plataforma5.dy,obj_plataforma5.largura,obj_plataforma5.altura, plataforma1, screen);
    draw_object(obj_plataforma6.sx,obj_plataforma6.sy,obj_plataforma6.dx,obj_plataforma6.dy,obj_plataforma6.largura,obj_plataforma6.altura, plataforma1, screen);

    draw_object(queb1.sx,queb1.sy,queb1.dx,queb1.dy,queb1.largura,queb1.altura, quebrada1, screen);
    draw_object(queb2.sx,queb2.sy,queb2.dx,queb2.dy,queb2.largura,queb2.altura, quebrada2, screen);
    draw_object(queb3.sx,queb3.sy,queb3.dx,queb3.dy,queb3.largura,queb3.altura, quebrada1, screen);
    draw_object(queb4.sx,queb4.sy,queb4.dx,queb4.dy,queb4.largura,queb4.altura, quebrada1, screen);
    draw_object(queb5.sx,queb5.sy,queb5.dx,queb5.dy,queb5.largura,queb5.altura, quebrada1, screen);

    draw_object(obj_escada1.sx,obj_escada1.sy,obj_escada1.dx,obj_escada1.dy,obj_escada1.largura,obj_escada1.altura, escada1, screen);
    draw_object(obj_escada2.sx,obj_escada2.sy,obj_escada2.dx,obj_escada2.dy,obj_escada2.largura,obj_escada2.altura, escada1, screen);
    draw_object(obj_escada3.sx,obj_escada3.sy,obj_escada3.dx,obj_escada3.dy,obj_escada3.largura,obj_escada3.altura, escada1, screen);
    draw_object(obj_escada4.sx,obj_escada4.sy,obj_escada4.dx,obj_escada4.dy,obj_escada4.largura,obj_escada4.altura, escada1, screen);
    draw_object(obj_escada5.sx,obj_escada5.sy,obj_escada5.dx,obj_escada5.dy,obj_escada5.largura,obj_escada5.altura, escada1, screen);

    draw_object(verm[0].sx,verm[0].sy,verm[0].dx,verm[0].dy,verm[0].largura,verm[0].altura, verm1, screen);
    draw_object(verm[1].sx,verm[1].sy,verm[1].dx,verm[1].dy,verm[1].largura,verm[1].altura, verm2, screen);
    draw_object(verm[2].sx,verm[2].sy,verm[2].dx,verm[2].dy,verm[2].largura,verm[2].altura, verm3, screen);
    draw_object(verm[3].sx,verm[3].sy,verm[3].dx,verm[3].dy,verm[3].largura,verm[3].altura, verm4, screen);
    draw_object(verm[4].sx,verm[4].sy,verm[4].dx,verm[4].dy,verm[4].largura,verm[4].altura, verm5, screen);
    draw_object(verm[5].sx,verm[5].sy,verm[5].dx,verm[5].dy,verm[5].largura,verm[5].altura, verm6, screen);

    draw_object(recan.sx,recan.sy,recan.dx,recan.dy,recan.largura,recan.altura, rec, screen);
    draw_object(recan3.sx,recan3.sy,recan3.dx,recan3.dy,recan3.largura,recan3.altura, rec3, screen);
    draw_object(recan4.sx,recan4.sy,recan4.dx,recan4.dy,recan4.largura,recan4.altura, rec4, screen);
    draw_object(recan5.sx,recan5.sy,recan5.dx,recan5.dy,recan5.largura,recan5.altura, rec5, screen);
    draw_object(recan6.sx,recan6.sy,recan6.dx,recan6.dy,recan6.largura,recan6.altura, rec6, screen);

    draw_object(pilhatora.sx,pilhatora.sy,pilhatora.dx,pilhatora.dy,pilhatora.largura,pilhatora.altura, pilhatoras, screen);

    draw_object(triang.sx,triang.sy,triang.dx,triang.dy,triang.largura,triang.altura, triangulo, screen);
    draw_object(quadra.sx,quadra.sy,quadra.dx,quadra.dy,quadra.largura,quadra.altura, squara, screen);

    draw_player(player.sx, player.sy, player.dx, player.dy, player.largura, player.altura, square, screen);

    draw_player(orbe.sx, orbe.sy, orbe.dx, orbe.dy, orbe.largura, orbe.altura, arma, screen);

    draw_object(tampa1.sx,tampa1.sy,tampa1.dx,tampa1.dy,tampa1.largura,tampa1.altura, tampadireita, screen);
    draw_object(tampa2.sx,tampa2.sy,tampa2.dx,tampa2.dy,tampa2.largura,tampa2.altura, tampaesquerda, screen);

    draw_object(hud.sx,hud.sy,hud.dx,hud.dy,hud.largura,hud.altura, HUD, screen);

    draw_object(obj_plataforma1.sx,obj_plataforma1.sy,obj_plataforma1.dx,obj_plataforma1.dy,obj_plataforma1.largura,obj_plataforma1.altura, plataforma2, screen);

    SDL_Color cor = {180,180,180};//objeto de cor
    fonte = TTF_OpenFont("Fontes/Jazz_Ball_Regular.ttf",20);
    segundos--;
    score = score + 0.10;

    if(segundos == 0 && minutos > 0)
    {
      minutos=minutos-1*10;
      score = score + 100;
      segundos = 600;
    }


    if(minutos == 0 && segundos == 0 || vidas<0)
    {
      GAMEOVER = 1;
      jogo0 = 0;
    }

    sprintf(string_minuto,"%d",minutos/10);//convertendo inteiro pra string
    sprintf(string_segundo,"%d",segundos/10);//convertendo inteiro pra string
    desenhaTexto(string_minuto, screen, 380, 10, cor);//primeira posição é o X e a segunda Y
    desenhaTexto(":", screen, 395, 10, cor);//primeira posição é o X e a segunda Y
    desenhaTexto(string_segundo, screen, 400, 10, cor);//primeira posição é o X e a segunda Y
    //cor.r = 10;
    //cor.g =  10;
    //cor.b = 10;
    sprintf(string_vida,"%d",vidas);
    desenhaTexto("VIDAS: ", screen, 100, 10, cor);
    desenhaTexto(string_vida, screen, 180, 10, cor);

    sprintf(string_score,"%.0f",score);
    desenhaTexto("SCORE: ", screen, 600, 10, cor);
    desenhaTexto(string_score, screen, 700, 10, cor);


    TTF_CloseFont(fonte);

    printf("%d %d\n",player.dx,player.dy);



    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }

   }
   timehist=0;
   while(loading)
    {
    start = SDL_GetTicks();

    timehist++;
    LOAD.sx+=LOAD.largura;
    if(LOAD.sx>8800)
        LOAD.sx=0;


    if(timehist==50)
     {
        jogo1 = 1;
        loading = 0;
    }

    SDL_FillRect(screen,0,0x0);
    draw_object(LOAD.sx,LOAD.sy,LOAD.dx,LOAD.dy,LOAD.largura,LOAD.altura, loadinghud, screen);

    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
   if(jogo1 == 1 && jogo0==0)
    {
        segundos = 600, minutos=20;
        jogo0=0;
        jogo = 0;
        FASE3();
        WEWE = 0;
        GAMEOVER = 0;
        orbe.dx = 40;
        pick = 0;
        jogo1 = 1;
        timetora = 0;
    }
    if(jogo == 1 || jogo0 == 1 || jogo1 == 1)
        Mix_PlayMusic(jogo_rodando,-1);

   while(jogo1 == 1)
    {
    start = SDL_GetTicks();

    TECLADO();
    OBSTACULO3();

    orbe.sx+=19;
    if(orbe.sx>=114)
        orbe.sx=0;
    orbe2.sx+=19;
    if(orbe2.sx>=114)
        orbe2.sx=0;
    orbe3.sx+=19;
    if(orbe3.sx>=114)
        orbe3.sx=0;

    verm[0].sx+=15;
    verm[1].sx+=15;
    verm[2].sx+=15;
    verm[3].sx+=15;
    verm[4].sx+=15;
    verm[5].sx+=15;

    if(verm[0].sx>73)
        verm[0].sx=0;
    if(verm[1].sx>73)
        verm[1].sx=0;
    if(verm[2].sx>73)
        verm[2].sx=0;
    if(verm[3].sx>73)
        verm[3].sx=0;
    if(verm[4].sx>73)
        verm[4].sx=0;
    if(verm[5].sx>73)
        verm[5].sx=0;

    triang.sx+=76;
    if(triang.sx>848)
        triang.sx=0;
    quadra.sx+=33;
    if(quadra.sx>432)
        quadra.sx=0;
    //animação
    if(player.sx > 525-player.largura)
        player.sx = 312;

    if(player.sx < 0)
        player.sx = player.largura;

    //Inicio da Barreiras da fase
    if(player.dx >= 720)
    {
        player.dx = 720;
    }
    if(player.dx <= 30)
    {
      player.dx = 30;
    }
    if(player.dy>=563)
    {
      player.dy=563;
    }
    if(timetora==0)
        recan.dy=126;
    if(timetora==0)
        recan2.dy=62;
    if(timetora==30)
        recan3.dy=126;
    if(timetora==60)
        recan4.dy=62;
    if(timetora==90)
        recan5.dy=126;
    if(timetora==120)
        recan6.dy=62;

    if(score<0)
        score=0;

    timetora++;

    if(timetora==360)
    {
        timetora=0;
        orbe.dx = 40;
        orbe2.dx = 40;
        orbe3.dx = 40;
    }

    if(player.dx== 165 && player.dy==163)
        {
        loading = 1;
        jogo=0;
        jogo1=0;
        jogo0=0;
        GAMEOVER=0;
        score+=500;
        }


    //Fim da Barreiras da fase
   // printf("%d %d\n",player.dx,player.dy);

    //Blitar a imagem na tela
    SDL_FillRect(screen,0,0x0);
    SDL_BlitSurface(background2,0 , screen, 0);

    draw_object(obj_plataforma1.sx,obj_plataforma1.sy,obj_plataforma1.dx,obj_plataforma1.dy,obj_plataforma1.largura,obj_plataforma1.altura, plataforma2, screen);
    draw_object(obj_plataforma2.sx,obj_plataforma2.sy,obj_plataforma2.dx,obj_plataforma2.dy,obj_plataforma2.largura,obj_plataforma2.altura, plataforma1, screen);
    draw_object(obj_plataforma3.sx,obj_plataforma3.sy,obj_plataforma3.dx,obj_plataforma3.dy,obj_plataforma3.largura,obj_plataforma3.altura, plataforma1, screen);
    draw_object(obj_plataforma4.sx,obj_plataforma4.sy,obj_plataforma4.dx,obj_plataforma4.dy,obj_plataforma4.largura,obj_plataforma4.altura, plataforma1, screen);
    draw_object(obj_plataforma5.sx,obj_plataforma5.sy,obj_plataforma5.dx,obj_plataforma5.dy,obj_plataforma5.largura,obj_plataforma5.altura, plataforma1, screen);
    draw_object(obj_plataforma6.sx,obj_plataforma6.sy,obj_plataforma6.dx,obj_plataforma6.dy,obj_plataforma6.largura,obj_plataforma6.altura, plataforma1, screen);

    draw_object(queb1.sx,queb1.sy,queb1.dx,queb1.dy,queb1.largura,queb1.altura, quebrada1, screen);
    draw_object(queb2.sx,queb2.sy,queb2.dx,queb2.dy,queb2.largura,queb2.altura, quebrada2, screen);
    draw_object(queb3.sx,queb3.sy,queb3.dx,queb3.dy,queb3.largura,queb3.altura, quebrada1, screen);
    draw_object(queb4.sx,queb4.sy,queb4.dx,queb4.dy,queb4.largura,queb4.altura, quebrada1, screen);
    draw_object(queb5.sx,queb5.sy,queb5.dx,queb5.dy,queb5.largura,queb5.altura, quebrada1, screen);

    draw_object(obj_escada1.sx,obj_escada1.sy,obj_escada1.dx,obj_escada1.dy,obj_escada1.largura,obj_escada1.altura, escada1, screen);
    draw_object(obj_escada2.sx,obj_escada2.sy,obj_escada2.dx,obj_escada2.dy,obj_escada2.largura,obj_escada2.altura, escada1, screen);
    draw_object(obj_escada3.sx,obj_escada3.sy,obj_escada3.dx,obj_escada3.dy,obj_escada3.largura,obj_escada3.altura, escada1, screen);
    draw_object(obj_escada4.sx,obj_escada4.sy,obj_escada4.dx,obj_escada4.dy,obj_escada4.largura,obj_escada4.altura, escada1, screen);
    draw_object(obj_escada5.sx,obj_escada5.sy,obj_escada5.dx,obj_escada5.dy,obj_escada5.largura,obj_escada5.altura, escada1, screen);

    draw_object(verm[0].sx,verm[0].sy,verm[0].dx,verm[0].dy,verm[0].largura,verm[0].altura, verm1, screen);
    draw_object(verm[1].sx,verm[1].sy,verm[1].dx,verm[1].dy,verm[1].largura,verm[1].altura, verm2, screen);
    draw_object(verm[2].sx,verm[2].sy,verm[2].dx,verm[2].dy,verm[2].largura,verm[2].altura, verm3, screen);
    draw_object(verm[3].sx,verm[3].sy,verm[3].dx,verm[3].dy,verm[3].largura,verm[3].altura, verm4, screen);
    draw_object(verm[4].sx,verm[4].sy,verm[4].dx,verm[4].dy,verm[4].largura,verm[4].altura, verm5, screen);
    draw_object(verm[5].sx,verm[5].sy,verm[5].dx,verm[5].dy,verm[5].largura,verm[5].altura, verm6, screen);

    draw_object(recan.sx,recan.sy,recan.dx,recan.dy,recan.largura,recan.altura, rec, screen);
    draw_object(recan2.sx,recan2.sy,recan2.dx,recan2.dy,recan2.largura,recan2.altura, rec2, screen);
    draw_object(recan3.sx,recan3.sy,recan3.dx,recan3.dy,recan3.largura,recan3.altura, rec3, screen);
    draw_object(recan4.sx,recan4.sy,recan4.dx,recan4.dy,recan4.largura,recan4.altura, rec4, screen);
    draw_object(recan5.sx,recan5.sy,recan5.dx,recan5.dy,recan5.largura,recan5.altura, rec5, screen);
    draw_object(recan6.sx,recan6.sy,recan6.dx,recan6.dy,recan6.largura,recan6.altura, rec6, screen);

    draw_object(pilhatora.sx,pilhatora.sy,pilhatora.dx,pilhatora.dy,pilhatora.largura,pilhatora.altura, pilhatoras, screen);

    draw_object(triang.sx,triang.sy,triang.dx,triang.dy,triang.largura,triang.altura, triangulo, screen);
    draw_object(quadra.sx,quadra.sy,quadra.dx,quadra.dy,quadra.largura,quadra.altura, squara, screen);

    draw_player(player.sx, player.sy, player.dx, player.dy, player.largura, player.altura, square, screen);

    draw_player(orbe.sx, orbe.sy, orbe.dx, orbe.dy, orbe.largura, orbe.altura, arma, screen);
    draw_player(orbe2.sx, orbe2.sy, orbe2.dx, orbe2.dy, orbe2.largura, orbe2.altura, arma2, screen);
    draw_player(orbe3.sx, orbe3.sy, orbe3.dx, orbe3.dy, orbe3.largura, orbe3.altura, arma3, screen);

    draw_object(tampa1.sx,tampa1.sy,tampa1.dx,tampa1.dy,tampa1.largura,tampa1.altura, tampadireita, screen);
    draw_object(tampa2.sx,tampa2.sy,tampa2.dx,tampa2.dy,tampa2.largura,tampa2.altura, tampaesquerda, screen);

    draw_object(hud.sx,hud.sy,hud.dx,hud.dy,hud.largura,hud.altura, HUD, screen);

    draw_object(obj_plataforma1.sx,obj_plataforma1.sy,obj_plataforma1.dx,obj_plataforma1.dy,obj_plataforma1.largura,obj_plataforma1.altura, plataforma2, screen);

    SDL_Color cor = {180,180,180};//objeto de cor
    fonte = TTF_OpenFont("Fontes/Jazz_Ball_Regular.ttf",20);
    segundos--;
    score = score + 0.10;

    if(segundos == 0 && minutos > 0)
    {
      minutos=minutos-1*10;
      score = score + 100;
      segundos = 600;
    }


    if(minutos == 0 && segundos == 0 || vidas<0)
    {
      GAMEOVER = 1;
      jogo1 = 0 ;
    }

    sprintf(string_minuto,"%d",minutos/10);//convertendo inteiro pra string
    sprintf(string_segundo,"%d",segundos/10);//convertendo inteiro pra string
    desenhaTexto(string_minuto, screen, 380, 10, cor);//primeira posição é o X e a segunda Y
    desenhaTexto(":", screen, 395, 10, cor);//primeira posição é o X e a segunda Y
    desenhaTexto(string_segundo, screen, 400, 10, cor);//primeira posição é o X e a segunda Y
    //cor.r = 10;
    //cor.g =  10;
    //cor.b = 10;
    sprintf(string_vida,"%d",vidas);
    desenhaTexto("VIDAS: ", screen, 100, 10, cor);
    desenhaTexto(string_vida, screen, 180, 10, cor);

    sprintf(string_score,"%.0f",score);
    desenhaTexto("SCORE: ", screen, 600, 10, cor);
    desenhaTexto(string_score, screen, 700, 10, cor);


    TTF_CloseFont(fonte);

    printf("%d %d\n",player.dx,player.dy);



    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
   timehist=0;
   while(loading)
    {
    start = SDL_GetTicks();

    timehist++;
    LOAD.sx+=LOAD.largura;
    if(LOAD.sx>8800)
        LOAD.sx=0;


    if(timehist==90)
     {
        jogo = 1;
        loading = 0;
    }

    SDL_FillRect(screen,0,0x0);
    draw_object(LOAD.sx,LOAD.sy,LOAD.dx,LOAD.dy,LOAD.largura,LOAD.altura, loadinghud, screen);

    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
   if(jogo==1 && jogo0==0 && GAMEOVER == 0 && jogo1 == 0)
   {
      jogo=1;
    }
   if(jogarnovamente == 1 )
    {
        WEWE = 0;
        GAMEOVER = 0;
        vidas = 3;
        score=0.0;
        segundos = 600, minutos=20;
        pick = 0;
        jogo0 = 1;
        FASE2();
        jogo = 0;
        jogo0 = 1;
    }// COLOCAR TELA DE CARREGANDO
    if(jogo == 1)
    {
        jogo0=0;
        INICIALIZACAO();
        WEWE = 0;
        GAMEOVER = 0;
        orbe.dx = 40;
        recan.dx = 220;
        recan.dy = 126;
        recan2.dx = 260;
        recan2.dy = 62;
        recan6.dx = 240, recan6.dy = 125;
        recan5.dx = 240, recan5.dy = 125;
        recan4.dx = 240, recan4.dy = 125;
        recan3.dx = 240, recan3.dy = 125;
        segundos = 600, minutos=20;
        player.sx =0, player.sy = 0, player.dx =45, player.dy = 563, player.velx = 15, player.vely = 8.8;
        pick = 0;
        jogo = 1;
        timetora = 0;
    }
    if(jogo == 1 || jogo0 == 1 || jogo1 == 1)
        Mix_PlayMusic(jogo_rodando,-1);
    while(jogo == 1)
    {
    start = SDL_GetTicks();
    jogo0 = 0;

    TECLADO();

    OBSTACULO();

    orbe.sx+=19;
    if(orbe.sx>=114)
        orbe.sx=0;

    triang.sx+=76;
    if(triang.sx>848)
        triang.sx=0;
    quadra.sx+=33;
    if(quadra.sx>432)
        quadra.sx=0;
    //animação
    if(player.sx > 525-player.largura)
        player.sx = 312;

    if(player.sx < 0)
        player.sx = player.largura;

    //Inicio da Barreiras da fase
    if(player.dx >= 720)
    {
        player.dx = 720;
    }
    if(player.dx <= 30)
    {
      player.dx = 30;
    }
    if(player.dy>=563)
    {
      player.dy=563;
    }
    if(timetora==0)
        recan.dy=126;
    if(timetora==0)
        recan2.dy=62;
    if(timetora==30)
        recan3.dy=126;
    if(timetora==60)
        recan4.dy=126;
    if(timetora==90)
        recan5.dy=126;
    if(timetora==120)
        recan6.dy=126;

    verm[0].sx+=15;
    verm[1].sx+=15;
    verm[2].sx+=15;
    verm[3].sx+=15;
    verm[4].sx+=15;

    if(verm[0].sx>73)
        verm[0].sx=0;
    if(verm[1].sx>73)
        verm[1].sx=0;
    if(verm[2].sx>73)
        verm[2].sx=0;
    if(verm[3].sx>73)
        verm[3].sx=0;
    if(verm[4].sx>73)
        verm[4].sx=0;

    if(score<0)
        score=0;

    timetora++;

    if(timetora==330)
    {
        timetora=0;
        orbe.dx = 40;
    }

    if(player.dx== 165 && player.dy==163)
        {
        WEWE = 1;
        jogo = 0 ;
        score+=500;
        }


    //Fim da Barreiras da fase
   // printf("%d %d\n",player.dx,player.dy);

    //Blitar a imagem na tela
    SDL_FillRect(screen,0,0x0);
    SDL_BlitSurface(background3,0 , screen, 0);

    draw_object(obj_plataforma1.sx,obj_plataforma1.sy,obj_plataforma1.dx,obj_plataforma1.dy,obj_plataforma1.largura,obj_plataforma1.altura, plataforma2, screen);
    draw_object(obj_plataforma2.sx,obj_plataforma2.sy,obj_plataforma2.dx,obj_plataforma2.dy,obj_plataforma2.largura,obj_plataforma2.altura, plataforma1, screen);
    draw_object(obj_plataforma3.sx,obj_plataforma3.sy,obj_plataforma3.dx,obj_plataforma3.dy,obj_plataforma3.largura,obj_plataforma3.altura, plataforma1, screen);
    draw_object(obj_plataforma4.sx,obj_plataforma4.sy,obj_plataforma4.dx,obj_plataforma4.dy,obj_plataforma4.largura,obj_plataforma4.altura, plataforma1, screen);
    draw_object(obj_plataforma5.sx,obj_plataforma5.sy,obj_plataforma5.dx,obj_plataforma5.dy,obj_plataforma5.largura,obj_plataforma5.altura, plataforma1, screen);
    draw_object(obj_plataforma6.sx,obj_plataforma6.sy,obj_plataforma6.dx,obj_plataforma6.dy,obj_plataforma6.largura,obj_plataforma6.altura, plataforma1, screen);

    draw_object(queb1.sx,queb1.sy,queb1.dx,queb1.dy,queb1.largura,queb1.altura, quebrada1, screen);
    draw_object(queb2.sx,queb2.sy,queb2.dx,queb2.dy,queb2.largura,queb2.altura, quebrada2, screen);
    draw_object(queb3.sx,queb3.sy,queb3.dx,queb3.dy,queb3.largura,queb3.altura, quebrada1, screen);
    draw_object(queb3.sx,queb3.sy,160,queb3.dy,queb3.largura,queb3.altura, quebrada2, screen);
    draw_object(queb4.sx,queb4.sy,queb4.dx,queb4.dy,queb4.largura,queb4.altura, quebrada1, screen);
    draw_object(queb4.sx,queb4.sy,535,queb4.dy,queb4.largura,queb4.altura, quebrada2, screen);
    draw_object(queb5.sx,queb5.sy,queb5.dx,queb5.dy,queb5.largura,queb5.altura, quebrada1, screen);

    draw_object(obj_escada1.sx,obj_escada1.sy,obj_escada1.dx,obj_escada1.dy,obj_escada1.largura,obj_escada1.altura, escada1, screen);
    draw_object(obj_escada2.sx,obj_escada2.sy,obj_escada2.dx,obj_escada2.dy,obj_escada2.largura,obj_escada2.altura, escada1, screen);
    draw_object(obj_escada3.sx,obj_escada3.sy,obj_escada3.dx,obj_escada3.dy,obj_escada3.largura,obj_escada3.altura, escada1, screen);
    draw_object(obj_escada4.sx,obj_escada4.sy,obj_escada4.dx,obj_escada4.dy,obj_escada4.largura,obj_escada4.altura, escada1, screen);
    draw_object(obj_escada5.sx,obj_escada5.sy,obj_escada5.dx,obj_escada5.dy,obj_escada5.largura,obj_escada5.altura, escada1, screen);

    draw_object(verm[0].sx,verm[0].sy,verm[0].dx,verm[0].dy,verm[0].largura,verm[0].altura, verm1, screen);
    draw_object(verm[1].sx,verm[1].sy,verm[1].dx,verm[1].dy,verm[1].largura,verm[1].altura, verm2, screen);
    draw_object(verm[2].sx,verm[2].sy,verm[2].dx,verm[2].dy,verm[2].largura,verm[2].altura, verm3, screen);
    draw_object(verm[3].sx,verm[3].sy,verm[3].dx,verm[3].dy,verm[3].largura,verm[3].altura, verm4, screen);
    draw_object(verm[4].sx,verm[4].sy,verm[4].dx,verm[4].dy,verm[4].largura,verm[4].altura, verm5, screen);

    draw_object(recan.sx,recan.sy,recan.dx,recan.dy,recan.largura,recan.altura, rec, screen);
    draw_object(recan2.sx,recan2.sy,recan2.dx,recan2.dy,recan2.largura,recan2.altura, rec2, screen);
    draw_object(recan3.sx,recan3.sy,recan3.dx,recan3.dy,recan3.largura,recan3.altura, rec3, screen);
    draw_object(recan4.sx,recan4.sy,recan4.dx,recan4.dy,recan4.largura,recan4.altura, rec4, screen);
    draw_object(recan5.sx,recan5.sy,recan5.dx,recan5.dy,recan5.largura,recan5.altura, rec5, screen);
    draw_object(recan6.sx,recan6.sy,recan6.dx,recan6.dy,recan6.largura,recan6.altura, rec6, screen);

    draw_object(pilhatora.sx,pilhatora.sy,pilhatora.dx,pilhatora.dy,pilhatora.largura,pilhatora.altura, pilhatoras, screen);

    draw_object(triang.sx,triang.sy,triang.dx,triang.dy,triang.largura,triang.altura, triangulo, screen);
    draw_object(quadra.sx,quadra.sy,quadra.dx,quadra.dy,quadra.largura,quadra.altura, squara, screen);

    draw_player(player.sx, player.sy, player.dx, player.dy, player.largura, player.altura, square, screen);

    draw_player(orbe.sx, orbe.sy, orbe.dx, orbe.dy, orbe.largura, orbe.altura, arma, screen);

    draw_object(tampa1.sx,tampa1.sy,tampa1.dx,tampa1.dy,tampa1.largura,tampa1.altura, tampadireita, screen);
    draw_object(tampa2.sx,tampa2.sy,tampa2.dx,tampa2.dy,tampa2.largura,tampa2.altura, tampaesquerda, screen);

    draw_object(hud.sx,hud.sy,hud.dx,hud.dy,hud.largura,hud.altura, HUD, screen);

    draw_object(obj_plataforma1.sx,obj_plataforma1.sy,obj_plataforma1.dx,obj_plataforma1.dy,obj_plataforma1.largura,obj_plataforma1.altura, plataforma2, screen);

    SDL_Color cor = {180,180,180};//objeto de cor
    fonte = TTF_OpenFont("Fontes/Jazz_Ball_Regular.ttf",20);
    segundos--;
    score = score + 0.10;

    if(segundos == 0 && minutos > 0)
    {
      minutos=minutos-1*10;
      score = score + 100;
      segundos = 600;
    }


    if(minutos == 0 && segundos == 0 || vidas<0)
    {
      GAMEOVER = 1;
      jogo = 0 ;
    }

    sprintf(string_minuto,"%d",minutos/10);//convertendo inteiro pra string
    sprintf(string_segundo,"%d",segundos/10);//convertendo inteiro pra string
    desenhaTexto(string_minuto, screen, 380, 10, cor);//primeira posição é o X e a segunda Y
    desenhaTexto(":", screen, 395, 10, cor);//primeira posição é o X e a segunda Y
    desenhaTexto(string_segundo, screen, 400, 10, cor);//primeira posição é o X e a segunda Y
    //cor.r = 10;
    //cor.g =  10;
    //cor.b = 10;
    sprintf(string_vida,"%d",vidas);
    desenhaTexto("VIDAS: ", screen, 100, 10, cor);
    desenhaTexto(string_vida, screen, 180, 10, cor);

    sprintf(string_score,"%.0f",score);
    desenhaTexto("SCORE: ", screen, 600, 10, cor);
    desenhaTexto(string_score, screen, 700, 10, cor);


    TTF_CloseFont(fonte);

    printf("%d %d\n",player.dx,player.dy);



    //Atualiza a tela
    if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }

   }
   if(WEWE == 1)
    {
        //draw_object(wEwE.sx,wEwE.sy,wEwE.dx,wEwE.dy,wEwE.largura,wEwE.altura, newrecorde, screen);
        verifica_recorde();//verifica se o recorder que a pessoa fez é maior que o ultimo recorde, se for, vai aparecer tela para escrever
        Mix_HaltMusic();
        Mix_PlayChannel(3, wewe,0);

    }
   while(WEWE == 1)
    {
        start = SDL_GetTicks();

		SDL_Event eventogameover;

        if(SDL_PollEvent(&eventogameover))
        {
            if(eventogameover.type == SDL_QUIT){exit(0);}
            if(eventogameover.type == SDL_KEYDOWN)
            {
                switch(eventogameover.key.keysym.sym)
            {
            case SDLK_RETURN:
                pick = 1;
                break;
            case SDLK_DOWN:
             Mix_PlayChannel(0,efeito_1,0);
             DOWN = 1;
             break;
            case SDLK_UP:
             Mix_PlayChannel(0,efeito_1,0);
             UP = 1;
             break;
            case SDLK_ESCAPE:
                exit(0);
                break;
            }
            }
            if(eventogameover.type == SDL_KEYUP)
            {
                switch(eventogameover.key.keysym.sym)
            {
            case SDLK_UP:
                UP = 0;
                Mix_PlayChannel(0,efeito_1,0);
                break;
            case SDLK_DOWN:
                DOWN = 0;
                Mix_PlayChannel(0,efeito_1,0);
                break;
            }
            }

        MENUGAMEOVER();
        }

        MENUGAMEOVER();

        orbego.sx+=19;
        if(orbego.sx>=114)
            orbego.sx=0;
        wEwE.sx+=wEwE.largura;
        if(wEwE.sx>7200)
            wEwE.sx=0;


    	SDL_FillRect(screen,0,0x0);
		draw_object(wEwE.sx,wEwE.sy,wEwE.dx,wEwE.dy,wEwE.largura,wEwE.altura, WeWe, screen);
		draw_object(Bvoltar.sx,Bvoltar.sy,Bvoltar.dx,Bvoltar.dy,Bvoltar.largura,Bvoltar.altura, voltaraomenu, screen);
		draw_object(Bjognov.sx,Bjognov.sy,Bjognov.dx,Bjognov.dy,Bjognov.largura,Bjognov.altura, jogarnovbut, screen);
		draw_object(orbego.sx,orbego.sy,orbego.dx,orbego.dy,orbego.largura,orbego.altura, icongo, screen);
			if(1000/FPS >(SDL_GetTicks()-start))
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
            SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
     if(GAMEOVER == 1)
    {
        //draw_object(wEwE.sx,wEwE.sy,wEwE.dx,wEwE.dy,wEwE.largura,wEwE.altura, newrecorde, screen);
        verifica_recorde();//verifica se o recorder que a pessoa fez é maior que o ultimo recorde, se for, vai aparecer tela para escrever
        Mix_HaltMusic();
        Mix_PlayChannel(3, game_over,0);
    }
    while(GAMEOVER == 1)
    {
        start = SDL_GetTicks();

		SDL_Event eventogameover;

        if(SDL_PollEvent(&eventogameover))
        {
            if(eventogameover.type == SDL_QUIT){exit(0);}
            if(eventogameover.type == SDL_KEYDOWN)
            {
                switch(eventogameover.key.keysym.sym)
            {
            case SDLK_RETURN:
                pick = 1;
                break;
            case SDLK_DOWN:
             Mix_PlayChannel(0,efeito_1,0);
             DOWN = 1;
             break;
            case SDLK_UP:
             Mix_PlayChannel(0,efeito_1,0);
             UP = 1;
             break;
            case SDLK_ESCAPE:
                exit(0);
                break;
            }
            }
            if(eventogameover.type == SDL_KEYUP)
            {
                switch(eventogameover.key.keysym.sym)
            {
            case SDLK_UP:
                UP = 0;
                Mix_PlayChannel(0,efeito_1,0);
                break;
            case SDLK_DOWN:
                DOWN = 0;
                Mix_PlayChannel(0,efeito_1,0);
                break;
            }
            }

        MENUGAMEOVER();
        }

        MENUGAMEOVER();

        orbego.sx+=19;
        if(orbego.sx>=114)
            orbego.sx=0;

    	SDL_FillRect(screen,0,0x0);
		draw_object(GameOver.sx,GameOver.sy,GameOver.dx,GameOver.dy,GameOver.largura,GameOver.altura, gameover, screen);
		draw_object(Bvoltar.sx,Bvoltar.sy,Bvoltar.dx,Bvoltar.dy,Bvoltar.largura,Bvoltar.altura, voltaraomenu, screen);
		draw_object(Bjognov.sx,Bjognov.sy,Bjognov.dx,Bjognov.dy,Bjognov.largura,Bjognov.altura, jogarnovbut, screen);
		draw_object(orbego.sx,orbego.sy,orbego.dx,orbego.dy,orbego.largura,orbego.altura, icongo, screen);
			if(1000/FPS >(SDL_GetTicks()-start))
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
            SDL_Flip( screen);

        if(SDL_Flip(screen) == -1)
          {
           return 1;
          }
    }
    if(jogo == 0 || jogo0 == 0 || jogo1 == 0)
        Mix_HaltMusic();
    jogarnovamente=1;
   }



    FIM();
    return 0;
}
