/**************************************************************
 Name    : CapellaCube
 By      : Gabriel Capella

 Controle um cubo 8x8x8

 Date    : 27 July, 2015
 Version : 0.1
 Notes   : Using a 8x74HC595
 
****************************************************************/
#include <TimerOne.h>


#define AXIS_X 1
#define AXIS_Y 2
#define AXIS_Z 3
#define CUBE_SIZE 8

#include <math.h>
#include <stdint.h>

//Pin connected to ST_CP of 74HC595
int latchPin = 10;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 11;

byte data[8][8];
int vidas = 0;


void setup() {
  Serial.begin(9600);
  Initilize();
  Serial.println(1);//TODO remover
  //Teste de efeitos
  /*
  effect_random_filler(75,1);
  effect_random_filler(75,0);
  fill(0x00);
  effect_rain(100);
  fill(0x00);
  effect_stringfly2("Capella");
  fill(0x00);
  effect_loadbar(100);
  fill(0x00);
  effect_box_shrink_grow(3,1,1,1000);
  fill(0x00);
  boingboing(1000,150, 1, 2);
  fill(0x00);
  */
  effect_stringfly2("TESTE");
  fill(0x00);
  
  //Liga os leds do segundo (de baixo para cima) plano horizontal de forma circular.
  //effect_test();
  //fill(0x00);
  //Escreve uma string na matriz.
  //effect_stringfly2(char * str)
  //Liga todos os leds de cada plano sequencialmente em uma direcao (plane) e em 
  //uma velocidade (speed) em milisegundos. Os valores para plane sao 1, 2 ou 3.
  //effect_planboing (1, 5000);
  //fill(0x00);
  //Semelhante ao effect_planboing mas percorre cada plano varias vezes muito rapidamente.
  //effect_blinky2();
  //fill(0x00);
  //Desnha uma caixa de leds expandindo e retraindo por (iterations) vezes a partir de 
  //um dos vertices (direction) do cubo em um certo tempo (delay).
  //(mode) 2 liga os leds das faces, 3 liga todos os leds do cubo, qualquer outro valor 
  //liga apenas os led dos vertices do cubo.
  //effect_box_shrink_grow (2, 6, 3, 10000);
  //fill(0x00);
  //(delay) (grow)
  //Semelhante ao effect_box_shrink_grow com mode 1, mas comeca no centro do 
  //cubo se (grow) = 1 ou na borda se (grow) = 2.
  //effect_box_woopwoop (10000, 1);
  //fill(0x00);
  // Send a voxel flying from one side of the cube to the other
  // It its at the bottom, send it to the top..
  //Liga sequencialmente uma linha de leds partindo da base para o topo do cubo em (delay) milisegundos.
  //o ponto da base de onde parte a linha de leds e o ponto (x) (y).
  //sendvoxel_z (7, 7, 200, 1000);
  //fill(0x00);
  // Send all the voxels from one side of the cube to the other
  // Start at z and send to the opposite side.
  // Sends in random order.
  //(z) (delay) (wait)
  sendplane_rand_z (10, 500, 10000);
  fill(0x00);
  // For each coordinate along X and Y, a voxel is set either at level 0 or at level 7
  // for n iterations, a random voxel is sent to the opposite side of where it was.
  //void sendvoxels_rand_z (int iterations, int delay, int wait)
  // Big ugly function :p but it looks pretty
  //void boingboing(uint16_t iterations, int delay, unsigned char mode, unsigned char drawmode)
  // Set or clear exactly 512 voxels in a random order.
  //void effect_random_filler (int delay, int state)
  //void effect_rain (int iterations)
  //void effect_z_updown (int iterations, int delay)
  //void effect_z_updown_move (unsigned char positions[64], unsigned char destinations[64], char axis)
  //void effect_axis_updown_randsuspend (char axis, int delay, int sleep, int invert)
  //void draw_positions_axis (char axis, unsigned char positions[64], int invert)
  //void effect_boxside_randsend_parallel (char axis, int origin, int delay, int mode)
  // Light all leds layer by layer,
  // then unset layer by layer
  //void effect_loadbar(int delay)
  // Set n number of voxels at random positions
  //void effect_random_sparkle_flash (int iterations, int voxels, int delay)
  // Set n number of voxels at random positions
  //void effect_random(int voxels, int delay)
  // blink 1 random voxel, blink 2 random voxels..... blink 20 random voxels
  // and back to 1 again.
  //void effect_random_sparkle (void)
  //int effect_telcstairs_do(int x, int val, int delay)
  //void effect_telcstairs (int invert, int delay, int val)
  //void effect_wormsqueeze (int size, int axis, int direction, int iterations, int delay)
  //void effect_smileyspin (int count, int delay, char bitmap)
  //void effect_pathmove (unsigned char *path, int length)
  //void effect_rand_patharound (int iterations, int delay)
  //void effect_pathspiral (int iterations, int delay)
  //void effect_path_text (int delay, char *str)
  //void effect_path_bitmap (int delay, char bitmap, int iterations)
  //
  effect_stringfly2("Harduime 1.0");
  
}

void loop()
{
    vidas++;
    fill(0x00);
    delay(500);
    effect_random(50, 450);

    gol_play(1000);
    delay(1000);
    effect_planboing(3, 700);
    effect_planboing(2, 700);
    fill(0x00);
    String v = String(vidas);
    char vi[6];
    v.toCharArray(vi, 6);
    effect_stringfly2(vi);
    effect_planboing(1, 700);
    effect_planboing(3, 700);
    delay(1000);
}
