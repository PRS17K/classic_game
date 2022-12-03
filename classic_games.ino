
#include <Adafruit_GFX.h> 
#include <RGBmatrixPanel.h> 
#define CLK 11
#define OE 9
#define LAT 10
#define A A0
#define B A1
#define C A2   
RGBmatrixPanel matrix(A, B, C,  CLK, LAT, OE, false); // 매트릭스 실행 시키기 위한 조건값들


int coin=-1; //시작화면

int first1=0;
int first2=0;
int first3=0;

int sound;
int sound2;



int  a; // 미로 변수
  int  b;
  int c,d;
  int x1=0,y1=10;
  int i;
  int j;
  int x2=31;
  int y2=5;
  int e[512];
  int f[512];
  int cnt1=0;
  int selectmap=0;// 미로 변수

int a2; //피구 변수
int b2;
int c2;
int d2;
int e2=0;
int f2=0;
int x12=2,y12=7;
int x22=3,y22=8;
int x32=2,y32=9;
int x42,y42;
int x52,y52;
int x62,y62;
int g2=0,h2=0;


int z12=29,w12=7;
int z22=28,w22=8;
int z32=29,w32=9;
int z42,w42;
int z52,w52;
int z62,w62;
int i2=0,j2=0;
int k2,l2;
int o2;
int count12=0;
int count22=0;
int life12=4;
int life22=4;
int m2,n2;
int soundstart,soundstart2;// 피구 변수



int x13=0, y13=7;//똥 변수
int x23=0, y23=9;

int a3=0;
int c3=0;
int dd;
int ddd[10];
int dddd[10];
int cnt3=1;
int b3=0;
int i3;
int time3=1;
int echoPin1 = 3;
int trigPin1 = 2;
int echoPin2 = 5;
int trigPin2 = 4;

int dcount=0;
int life13=0;
int life23=0;
int end3=0; 
float before;
float before2; 
int dstart;
int dstart2;
int ii , ii2;

//똥변수






void setup(){
  
  
  Serial.begin(9600);
  pinMode(7,OUTPUT); //소리
  pinMode(A4,INPUT_PULLUP); // 조이스틱2 좌우
  pinMode(A5,INPUT_PULLUP); // 조이스틱2 위 아래
  pinMode(A8,INPUT_PULLUP); // 조이스틱1 좌우
  pinMode(A9,INPUT_PULLUP); // 조이스틱1 위 아래
  pinMode(0,INPUT_PULLUP); // 조이스틱1 버튼 누르기
  pinMode(1,INPUT_PULLUP); // 조이스틱2 버튼 누르기
  pinMode(trigPin1, OUTPUT); // 초음파 거리 측정센서1
  pinMode(echoPin1, INPUT); // 초음파 거리 측정센서1
  pinMode(trigPin2, OUTPUT); // 초음파 거리 측정센서2
  pinMode(echoPin2, INPUT); // 초음파 거리 측정센서2
  matrix.begin();

   //게임 선택화면으로 돌아오기
    matrix.fillScreen(matrix.Color333(0, 0, 0)); // 화면 초기화
    start:
    matrix.setCursor(1, 0);  // 매트릭스 상의 커서를 (1,0)에 지정
  matrix.setTextSize(1);   // 8픽셀을 사이즈1로 설정
   matrix.setTextColor(matrix.Color333(7,0,0)); // 출력할 문자의 색을 지정 (R,G,B)
      matrix.print('p'); // 출력할 문자
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('r');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('e');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('s');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('s');
      
      matrix.setCursor(1, 8);  
  matrix.setTextSize(1);   
  matrix.setTextColor(matrix.Color333(4,7,0));
  matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('r');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('e');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('s');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('s');

      
int sensorValue1=analogRead(A8); // 조이스틱 좌 우의 아날로그 값을 변수에 받아줌
  int sensorValue2=analogRead(A9); // 조이스틱 위 아래의 아날로그 값을 변수에 받아줌

   if(sensorValue1>=800) coin=1; //조이스틱을 오른쪽으로 하면 coin에 1의 값을 받고 미로게임이 실행
    else if(sensorValue1<=200) coin=2; //왼쪽
    else if(sensorValue2>=800) coin=3; //위쪽

    if(coin==-1) goto start; // 아무 입력값이 없을 때는 계속 시작화면으로


  if(coin==1){ //미로게임 시작
    matrix.fillScreen(matrix.Color333(0, 0, 0));
    select : // 맵 선택
     matrix.setCursor(1, 0);  
  matrix.setTextSize(1);  
   matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('m');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('a');
      matrix.setTextColor(matrix.Color333(0,7,4));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,7,4));
      matrix.print('1');
      
      
      matrix.setCursor(1, 8);  
  matrix.setTextSize(1);   
 matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('m');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('a');
      matrix.setTextColor(matrix.Color333(0,7,4));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,7,4));
      matrix.print('2');

      int sensorValue1=analogRead(A4);

   if(sensorValue1>=800) selectmap=1; //오른쪽 (맵1)
    else if(sensorValue1<=200) selectmap=2; //왼쪽 (맵2)

      if(selectmap==0) goto select; //아무 입력 값이 없을 때 선택화면으로
      
  else if(selectmap==1){    // 선택한 첫번째 맵
    matrix.fillScreen(matrix.Color333(0, 0, 0));
    for(j=3; j<12; j++){ 
  matrix.drawPixel(j,15,matrix.Color333(7,0,7)); // 매트릭스의 (j,15)좌표에 보라색의 색이 빛나게 해줌
  e[cnt1]=j; // 미로의 x좌표에 대한 정보를 순서대로 배열에 입력
  f[cnt1]=15; // 미로의 y좌표에 대한 정보를 순서대로 배열에 입력
  cnt1++;
}
for(j=14; j<21; j++) {
  matrix.drawPixel(j,15,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=15;
  cnt1++;
}
for(j=23; j<30; j++) {
  matrix.drawPixel(j,14,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=14;
  cnt1++;
}
for(j=6; j<13; j++) {
  matrix.drawPixel(27,j,matrix.Color333(7,0,7));
  e[cnt1]=27;
  f[cnt1]=j;
  cnt1++;
}
for(j=5; j<14; j++) {
  matrix.drawPixel(29,j,matrix.Color333(7,0,7));
  e[cnt1]=29;
  f[cnt1]=j;
  cnt1++;
}
for(j=16; j<20; j++) {
  matrix.drawPixel(j,1,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=1;
  cnt1++;
}
for(j=0; j<10; j++) {
  matrix.drawPixel(2,j,matrix.Color333(7,0,7));
  e[cnt1]=2;
  f[cnt1]=j;
  cnt1++; 
}
for(j=11; j<28; j++) {
  matrix.drawPixel(j,4,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=4;
  cnt1++;
}
for(j=11; j<15; j++) {
  matrix.drawPixel(3,j,matrix.Color333(7,0,7));
  e[cnt1]=3;
  f[cnt1]=j;
  cnt1++;
}
for(j=4; j<10; j++) {
  matrix.drawPixel(4,j,matrix.Color333(7,0,7));
  e[cnt1]=4;
  f[cnt1]=j;
  cnt1++;
}
for(j=5; j<10; j++) {
  matrix.drawPixel(j,4,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=4;
  cnt1++;
}
for(j=8; j<11; j++) {
  matrix.drawPixel(8,j,matrix.Color333(7,0,7));
  e[cnt1]=8;
  f[cnt1]=j;
  cnt1++;
}
for(j=11; j<17; j++) {
  matrix.drawPixel(j,8,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=8;
  cnt1++;
}
for(j=6; j<12; j++) {
  matrix.drawPixel(25,j,matrix.Color333(7,0,7));
  e[cnt1]=25;
  f[cnt1]=j;
  cnt1++;
}
for(j=21; j<27; j++) {
  matrix.drawPixel(j,2,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=2;
  cnt1++;
}
for(j=11; j<19; j++) {
  matrix.drawPixel(j,6,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=6;
  cnt1++;
}
for(j=0; j<3; j++) {
  matrix.drawPixel(j,11,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=7; j<15; j++) {
  matrix.drawPixel(j,11,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=6; j<10; j++) {
  matrix.drawPixel(j,6,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=6;
  cnt1++;
}
for(j=11; j<15; j++) {
  matrix.drawPixel(j,13,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=18; j<24; j++) {
  matrix.drawPixel(j,9,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=9;
  cnt1++;
}
for(j=7; j<11; j++) {
  matrix.drawPixel(31,j,matrix.Color333(7,0,7));
  e[cnt1]=31;
  f[cnt1]=j;
  cnt1++;
}
for(j=11; j<14; j++) {
  matrix.drawPixel(5,j,matrix.Color333(7,0,7));
  e[cnt1]=5;
  f[cnt1]=j;
  cnt1++;
}
for(j=7; j<10; j++) {
  matrix.drawPixel(6,j,matrix.Color333(7,0,7));
  e[cnt1]=6;
  f[cnt1]=j;
  cnt1++;
}
for(j=19; j<22; j++) {
  matrix.drawPixel(j,13,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=21; j<25; j++) {
  matrix.drawPixel(j,11,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=7; j<10; j++) {
  matrix.drawPixel(j,13,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=0; j<3; j++) {
  matrix.drawPixel(4,j,matrix.Color333(7,0,7));
  e[cnt1]=4;
  f[cnt1]=j;
  cnt1++;
}
for(j=5; j<8; j++) {
  matrix.drawPixel(j,2,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=2;
  cnt1++;
}
for(j=9; j<13; j++) {
  matrix.drawPixel(j,2,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=2;
  cnt1++;
}
for(j=20; j<24; j++) {
  matrix.drawPixel(j,6,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=6;
  cnt1++;
}
for(j=0; j<3; j++) {
  matrix.drawPixel(14,j,matrix.Color333(7,0,7));
  e[cnt1]=14;
  f[cnt1]=j;
  cnt1++;
}
for(j=1; j<4; j++) {
  matrix.drawPixel(28,j,matrix.Color333(7,0,7));
  e[cnt1]=28;
  f[cnt1]=j;
  cnt1++;
}
for(j=0; j<2; j++) {
  matrix.drawPixel(j,9,matrix.Color333(7,0,7));
  e[cnt1]=j;
  f[cnt1]=9;
  cnt1++;
}

matrix.drawPixel(3,1,matrix.Color333(7,0,7));
  e[cnt1]=3;
  f[cnt1]=1;
  cnt1++;
  
matrix.drawPixel(11,14,matrix.Color333(7,0,7));
  e[cnt1]=11;
  f[cnt1]=14;
  cnt1++;
 
matrix.drawPixel(14,14,matrix.Color333(7,0,7));
  e[cnt1]=14;
  f[cnt1]=14;
  cnt1++;
  
for(j=23; j<25; j++) {
  matrix.drawPixel(j,13,matrix.Color333(7,0,7));
    e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=14; j<16; j++) {
  matrix.drawPixel(31,j,matrix.Color333(7,0,7));
    e[cnt1]=31;
  f[cnt1]=j;
  cnt1++;
}
matrix.drawPixel(30,12,matrix.Color333(7,0,7));
  e[cnt1]=30;
  f[cnt1]=12;
  cnt1++;
  
matrix.drawPixel(30,5,matrix.Color333(7,0,7));
  e[cnt1]=30;
  f[cnt1]=5;
  cnt1++;
  
matrix.drawPixel(12,3,matrix.Color333(7,0,7));
  e[cnt1]=12;
  f[cnt1]=3;
  cnt1++;
  
matrix.drawPixel(16,2,matrix.Color333(7,0,7));
  e[cnt1]=16;
  f[cnt1]=2;
  cnt1++;
  
matrix.drawPixel(7,12,matrix.Color333(7,0,7));
  e[cnt1]=7;
  f[cnt1]=12;
  cnt1++;
  
matrix.drawPixel(9,12,matrix.Color333(7,0,7));
  e[cnt1]=9;
  f[cnt1]=12;
  cnt1++;
  
matrix.drawPixel(5,9,matrix.Color333(7,0,7));
  e[cnt1]=5;
  f[cnt1]=9;
  cnt1++;
  
matrix.drawPixel(9,8,matrix.Color333(7,0,7));
  e[cnt1]=9;
  f[cnt1]=8;
  cnt1++;
  
matrix.drawPixel(9,5,matrix.Color333(7,0,7));
  e[cnt1]=9;
  f[cnt1]=5;
  cnt1++;
  
matrix.drawPixel(11,5,matrix.Color333(7,0,7));
  e[cnt1]=11;
  f[cnt1]=5;
  cnt1++;
  
matrix.drawPixel(16,5,matrix.Color333(7,0,7));
  e[cnt1]=16;
  f[cnt1]=5;
  cnt1++;
  
matrix.drawPixel(18,5,matrix.Color333(7,0,7));
  e[cnt1]=18;
  f[cnt1]=5;
  cnt1++;
  
matrix.drawPixel(20,7,matrix.Color333(7,0,7));
  e[cnt1]=20;
  f[cnt1]=7;
  cnt1++;
  
matrix.drawPixel(18,8,matrix.Color333(7,0,7));
  e[cnt1]=18;
  f[cnt1]=8;
  cnt1++;
  
for(j=0; j<2; j++) {
  matrix.drawPixel(21,j,matrix.Color333(7,0,7));
    e[cnt1]=21;
  f[cnt1]=j;
  cnt1++;
}
for(j=0; j<2; j++) {
  matrix.drawPixel(26,j,matrix.Color333(7,0,7));
    e[cnt1]=26;
  f[cnt1]=j;
  cnt1++;
}
for(j=29; j<31; j++) {
  matrix.drawPixel(j,1,matrix.Color333(7,0,7));
    e[cnt1]=j;
  f[cnt1]=1;
  cnt1++;
}
for(j=30; j<32; j++) {
  matrix.drawPixel(j,3,matrix.Color333(7,0,7));
    e[cnt1]=j;
  f[cnt1]=3;
  cnt1++;
}
for(j=9; j<11; j++) {
  matrix.drawPixel(14,j,matrix.Color333(7,0,7));
    e[cnt1]=14;
  f[cnt1]=j;
  cnt1++;
}
for(j=9; j<11; j++) {
  matrix.drawPixel(16,j,matrix.Color333(7,0,7));
    e[cnt1]=16;
  f[cnt1]=j;
  cnt1++;
}
for(j=12; j<14; j++) {
  matrix.drawPixel(16,j,matrix.Color333(7,0,7));
    e[cnt1]=16;
  f[cnt1]=j;
  cnt1++;
}
matrix.drawPixel(17,13,matrix.Color333(7,0,7));
  e[cnt1]=17;
  f[cnt1]=13;
  cnt1++;
  
matrix.drawPixel(19,11,matrix.Color333(7,0,7));
  e[cnt1]=19;
  f[cnt1]=11;
  cnt1++;
  
for(j=10; j<12; j++) {
  matrix.drawPixel(18,j,matrix.Color333(7,0,7));
    e[cnt1]=18;
  f[cnt1]=j;
  cnt1++;
}
  }

else if(selectmap==2){ // 선택한 두번째 맵
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  for(j=0; j<7; j++){
  matrix.drawPixel(j,0,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=0;
  cnt1++;
}
for(j=10; j<16; j++) {
  matrix.drawPixel(j,0,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=0;
  cnt1++;
}
for(j=8; j<11; j++) {
  matrix.drawPixel(j,1,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=1;
  cnt1++;
}
for(j=2; j<5; j++) {
  matrix.drawPixel(j,2,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=2;
  cnt1++;
}
for(j=14; j<16; j++) {
  matrix.drawPixel(j,2,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=2;
  cnt1++;
}
for(j=4; j<7; j++) {
  matrix.drawPixel(j,3,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=3;
  cnt1++;
}
for(j=8; j<11; j++) {
  matrix.drawPixel(j,3,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=3;
  cnt1++; 
}
for(j=14; j<16; j++) {
  matrix.drawPixel(j,3,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=3;
  cnt1++;
}
for(j=0; j<3; j++) {
  matrix.drawPixel(j,4,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=4;
  cnt1++;
}
for(j=6; j<9; j++) {
  matrix.drawPixel(j,4,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=4;
  cnt1++;
}
for(j=14; j<16; j++) {
  matrix.drawPixel(j,4,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=4;
  cnt1++;
}
for(j=6; j<11; j++) {
  matrix.drawPixel(j,6,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=6;
  cnt1++;
}
for(j=12; j<14; j++) {
  matrix.drawPixel(j,6,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=6;
  cnt1++;
}
for(j=12; j<16; j++) {
  matrix.drawPixel(j,7,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=7;
  cnt1++;
}
for(j=10; j<13; j++) {
  matrix.drawPixel(j,8,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=8;
  cnt1++;
}
for(j=14; j<16; j++) {
  matrix.drawPixel(j,8,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=8;
  cnt1++;
}
for(j=2; j<7; j++) {
  matrix.drawPixel(j,9,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=9;
  cnt1++;
}
for(j=0; j<3; j++) {
  matrix.drawPixel(j,10,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=10;
  cnt1++;
}
for(j=8; j<10; j++) {
  matrix.drawPixel(j,10,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=10;
  cnt1++;
}
for(j=2; j<4; j++) {
  matrix.drawPixel(j,11,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=5; j<9; j++) {
  matrix.drawPixel(j,11,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=10; j<12; j++) {
  matrix.drawPixel(j,11,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=13; j<16; j++) {
  matrix.drawPixel(j,12,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=12;
  cnt1++;
}
for(j=0; j<3; j++) {
  matrix.drawPixel(j,13,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=4; j<6; j++) {
  matrix.drawPixel(j,13,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=11; j<14; j++) {
  matrix.drawPixel(j,13,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=0; j<16; j++) {
  matrix.drawPixel(j,15,matrix.Color333(7,0,0));
  e[cnt1]=j;
  f[cnt1]=15;
  cnt1++;
}
for(j=1; j<4; j++) {
  matrix.drawPixel(0,j,matrix.Color333(7,0,0));
  e[cnt1]=0;
  f[cnt1]=j;
  cnt1++;
}
for(j=6; j<10; j++) {
  matrix.drawPixel(0,j,matrix.Color333(7,0,0));
  e[cnt1]=0;
  f[cnt1]=j;
  cnt1++;
}
for(j=11; j<13; j++) {
  matrix.drawPixel(0,j,matrix.Color333(7,0,0));
  e[cnt1]=0;
  f[cnt1]=j;
  cnt1++;
}
for(j=5; j<7; j++) {
  matrix.drawPixel(2,j,matrix.Color333(7,0,0));
  e[cnt1]=2;
  f[cnt1]=j;
  cnt1++;
}
for(j=4; j<7; j++) {
  matrix.drawPixel(4,j,matrix.Color333(7,0,0));
  e[cnt1]=4;
  f[cnt1]=j;
  cnt1++;
}
for(j=7; j<9; j++) {
  matrix.drawPixel(6,j,matrix.Color333(7,0,0));
  e[cnt1]=6;
  f[cnt1]=j;
  cnt1++;
}
for(j=12; j<14; j++) {
  matrix.drawPixel(7,j,matrix.Color333(7,0,0));
  e[cnt1]=7;
  f[cnt1]=j;
  cnt1++;
}
for(j=8; j<10; j++) {
  matrix.drawPixel(8,j,matrix.Color333(7,0,0));
  e[cnt1]=8;
  f[cnt1]=j;
  cnt1++;
}
for(j=13; j<15; j++) {
  matrix.drawPixel(9,j,matrix.Color333(7,0,0));
  e[cnt1]=9;
  f[cnt1]=j;
  cnt1++;
}
for(j=4; j<6; j++) {
  matrix.drawPixel(10,j,matrix.Color333(7,0,0));
  e[cnt1]=10;
  f[cnt1]=j;
  cnt1++;
}
for(j=9; j<11; j++) {
  matrix.drawPixel(11,j,matrix.Color333(7,0,0));
  e[cnt1]=11;
  f[cnt1]=j;
  cnt1++;
}
for(j=2; j<6; j++) {
  matrix.drawPixel(12,j,matrix.Color333(7,0,0));
  e[cnt1]=12;
  f[cnt1]=j;
  cnt1++;
}
for(j=10; j<12; j++) {
  matrix.drawPixel(13,j,matrix.Color333(7,0,0));
  e[cnt1]=13;
  f[cnt1]=j;
  cnt1++;
}
for(j=5; j<7; j++) {
  matrix.drawPixel(15,j,matrix.Color333(7,0,0));
  e[cnt1]=15;
  f[cnt1]=j;
  cnt1++;
}
for(j=9; j<11; j++) {
  matrix.drawPixel(15,j,matrix.Color333(7,0,0));
  e[cnt1]=15;
  f[cnt1]=j;
  cnt1++;
}
for(j=13; j<15; j++) {
  matrix.drawPixel(15,j,matrix.Color333(7,0,0));
  e[cnt1]=15;
  f[cnt1]=j;
  cnt1++;
}

matrix.drawPixel(0,14,matrix.Color333(7,0,0));
  e[cnt1]=0;
  f[cnt1]=14;
  cnt1++;
  
matrix.drawPixel(2,8,matrix.Color333(7,0,0));
  e[cnt1]=2;
  f[cnt1]=8;
  cnt1++;
 
matrix.drawPixel(5,14,matrix.Color333(7,0,0));
  e[cnt1]=5;
  f[cnt1]=14;
  cnt1++;
matrix.drawPixel(6,1,matrix.Color333(7,0,0));
  e[cnt1]=6;
  f[cnt1]=1;
  cnt1++;
  matrix.drawPixel(15,1,matrix.Color333(7,0,0));
  e[cnt1]=15;
  f[cnt1]=1;
  cnt1++;

for(j=16; j<23; j++){
  matrix.drawPixel(j,0,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=0;
  cnt1++;
}
for(j=26; j<32; j++) {
  matrix.drawPixel(j,0,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=0;
  cnt1++;
}
for(j=24; j<27; j++) {
  matrix.drawPixel(j,1,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=1;
  cnt1++;
}
for(j=18; j<21; j++) {
  matrix.drawPixel(j,2,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=2;
  cnt1++;
}
for(j=30; j<32; j++) {
  matrix.drawPixel(j,2,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=2;
  cnt1++;
}
for(j=20; j<23; j++) {
  matrix.drawPixel(j,3,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=3;
  cnt1++;
}
for(j=24; j<27; j++) {
  matrix.drawPixel(j,3,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=3;
  cnt1++; 
}
for(j=30; j<32; j++) {
  matrix.drawPixel(j,3,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=3;
  cnt1++;
}
for(j=16; j<19; j++) {
  matrix.drawPixel(j,4,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=4;
  cnt1++;
}
for(j=22; j<25; j++) {
  matrix.drawPixel(j,4,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=4;
  cnt1++;
}
for(j=30; j<32; j++) {
  matrix.drawPixel(j,4,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=4;
  cnt1++;
}
for(j=22; j<27; j++) {
  matrix.drawPixel(j,6,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=6;
  cnt1++;
}
for(j=28; j<30; j++) {
  matrix.drawPixel(j,6,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=6;
  cnt1++;
}
for(j=28; j<32; j++) {
  matrix.drawPixel(j,7,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=7;
  cnt1++;
}
for(j=26; j<29; j++) {
  matrix.drawPixel(j,8,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=8;
  cnt1++;
}
for(j=30; j<32; j++) {
  matrix.drawPixel(j,8,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=8;
  cnt1++;
}
for(j=18; j<23; j++) {
  matrix.drawPixel(j,9,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=9;
  cnt1++;
}
for(j=16; j<19; j++) {
  matrix.drawPixel(j,10,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=10;
  cnt1++;
}
for(j=24; j<26; j++) {
  matrix.drawPixel(j,10,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=10;
  cnt1++;
}
for(j=18; j<20; j++) {
  matrix.drawPixel(j,11,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=21; j<25; j++) {
  matrix.drawPixel(j,11,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=26; j<28; j++) {
  matrix.drawPixel(j,11,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=11;
  cnt1++;
}
for(j=29; j<32; j++) {
  matrix.drawPixel(j,12,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=12;
  cnt1++;
}
for(j=16; j<19; j++) {
  matrix.drawPixel(j,13,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=20; j<22; j++) {
  matrix.drawPixel(j,13,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=27; j<30; j++) {
  matrix.drawPixel(j,13,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=13;
  cnt1++;
}
for(j=16; j<32; j++) {
  matrix.drawPixel(j,15,matrix.Color333(0,0,7));
  e[cnt1]=j;
  f[cnt1]=15;
  cnt1++;
}
for(j=1; j<4; j++) {
  matrix.drawPixel(16,j,matrix.Color333(0,0,7));
  e[cnt1]=16;
  f[cnt1]=j;
  cnt1++;
}
for(j=6; j<10; j++) {
  matrix.drawPixel(16,j,matrix.Color333(0,0,7));
  e[cnt1]=16;
  f[cnt1]=j;
  cnt1++;
}
for(j=11; j<13; j++) {
  matrix.drawPixel(16,j,matrix.Color333(0,0,7));
  e[cnt1]=16;
  f[cnt1]=j;
  cnt1++;
}
for(j=5; j<7; j++) {
  matrix.drawPixel(18,j,matrix.Color333(0,0,7));
  e[cnt1]=18;
  f[cnt1]=j;
  cnt1++;
}
for(j=4; j<7; j++) {
  matrix.drawPixel(20,j,matrix.Color333(0,0,7));
  e[cnt1]=20;
  f[cnt1]=j;
  cnt1++;
}
for(j=7; j<9; j++) {
  matrix.drawPixel(22,j,matrix.Color333(0,0,7));
  e[cnt1]=22;
  f[cnt1]=j;
  cnt1++;
}
for(j=12; j<14; j++) {
  matrix.drawPixel(23,j,matrix.Color333(0,0,7));
  e[cnt1]=23;
  f[cnt1]=j;
  cnt1++;
}
for(j=8; j<10; j++) {
  matrix.drawPixel(24,j,matrix.Color333(0,0,7));
  e[cnt1]=24;
  f[cnt1]=j;
  cnt1++;
}
for(j=13; j<15; j++) {
  matrix.drawPixel(25,j,matrix.Color333(0,0,7));
  e[cnt1]=25;
  f[cnt1]=j;
  cnt1++;
}
for(j=4; j<6; j++) {
  matrix.drawPixel(26,j,matrix.Color333(0,0,7));
  e[cnt1]=26;
  f[cnt1]=j;
  cnt1++;
}
for(j=9; j<11; j++) {
  matrix.drawPixel(27,j,matrix.Color333(0,0,7));
  e[cnt1]=27;
  f[cnt1]=j;
  cnt1++;
}
for(j=2; j<6; j++) {
  matrix.drawPixel(28,j,matrix.Color333(0,0,7));
  e[cnt1]=28;
  f[cnt1]=j;
  cnt1++;
}
for(j=10; j<12; j++) {
  matrix.drawPixel(29,j,matrix.Color333(0,0,7));
  e[cnt1]=29;
  f[cnt1]=j;
  cnt1++;
}
for(j=5; j<7; j++) {
  matrix.drawPixel(31,j,matrix.Color333(0,0,7));
  e[cnt1]=31;
  f[cnt1]=j;
  cnt1++;
}
for(j=9; j<11; j++) {
  matrix.drawPixel(31,j,matrix.Color333(0,0,7));
  e[cnt1]=31;
  f[cnt1]=j;
  cnt1++;
}
for(j=13; j<15; j++) {
  matrix.drawPixel(31,j,matrix.Color333(0,0,7));
  e[cnt1]=31;
  f[cnt1]=j;
  cnt1++;
}

matrix.drawPixel(16,14,matrix.Color333(0,0,7));
  e[cnt1]=16;
  f[cnt1]=14;
  cnt1++;
  
matrix.drawPixel(18,8,matrix.Color333(0,0,7));
  e[cnt1]=18;
  f[cnt1]=8;
  cnt1++;
 
matrix.drawPixel(21,14,matrix.Color333(0,0,7));
  e[cnt1]=21;
  f[cnt1]=14;
  cnt1++;
matrix.drawPixel(22,1,matrix.Color333(0,0,7));
  e[cnt1]=22;
  f[cnt1]=1;
  cnt1++;
  matrix.drawPixel(31,1,matrix.Color333(0,0,7));
  e[cnt1]=31;
  f[cnt1]=1;
  cnt1++;  
}
  } // 미로게임의 미로 그려주기 완료


else if(coin==2){ // 슈팅게임 선택
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  for(o2=0;o2<16;o2++){ // 중앙선 그려주는 작업
matrix.drawPixel(15,o2,matrix.Color333(2,7,2));
matrix.drawPixel(16,o2,matrix.Color333(2,7,2));
}
for(k2=0;k2<16; k2++){ //p1의 목숨칸
  for(l2=0; l2<2; l2++){
    matrix.drawPixel(l2,k2,matrix.Color333(7,0,7));
  }
}
for(k2=0;k2<16; k2++){ //p2의 목숨칸
  for(l2=30; l2<32; l2++){
    matrix.drawPixel(l2,k2,matrix.Color333(7,0,7));
  }
}
}

      
}

void loop(){
  

  if(coin==1){ //미로게임이 선택
    
    if(first1==0){ // 미로게임이 선택 된 후 첫번째 루프일 때 ( 각 변수들의 초기값 초기화)
      
      first1=1; // 두번째 루프부터는 여기에 들어오지 못하게
      
  if(selectmap==1){  // 첫번째 맵일 때 각 플레이어들의 시작지점 지정
   x1=0; y1=10;
   x2=31;
   y2=5;
  }
  else if(selectmap==2){  // 두번째 맵일 때 각 플레이어들의 시작지점 지정
    x1=0; y1=5;
    x2=16;
    y2=5;
  }

    }
  
if(selectmap==1){ // 첫번재 맵이 선택
    int g=0;
int h=0;

int sensorValue1=analogRead(A4);
int sensorValue2=analogRead(A5);
int sensorValue3=analogRead(A8);
int sensorValue4=analogRead(A9);


//플레이어 1
a=0; // 아날로그 값의 입력이 없으면 가만히 서 있게 하기
b=0; // 아날로그 값의 입력이 없으면 가만히 서 있게 하기

if(sensorValue3>=800) // 조이스틱의 아날로그 값을 읽어 오른쪽으로 움직 일 수 있게
{
a=1; // p1의 x좌표에 더해줄 값
b=0; // p1의 y좌표에 더해줄 값
}
if(sensorValue4>=800) // 조이스틱의 아날로그 값을 읽어 위쪽으로 움직 일 수 있게
{
b=1;
a=0;
}
if(sensorValue3<=200) // 조이스틱의 아날로그 값을 읽어 왼쪽으로 움직 일 수 있게
{
a=-1;
b=0;
}
if(sensorValue4<=200) // 조이스틱의 아날로그 값을 읽어 아래쪽으로 움직 일 수 있게
{
b=-1;
a=0;
}


matrix.drawPixel(x1,y1,matrix.Color333(0,0,0)); // p1의 지나온 흔적들 지우기
x1+=a; 
y1+=b; 
for(j=0; j<cnt1; j++){ // 미로 벽의 정보를 입력해둔 값들과 p1의 x좌표, y좌표 값들을 순서대로 비교해 벽의 좌표와 플레이어의 다음좌표가 겹치는 경우가 한번이라도 있는지 확인
  if(x1==e[j] && y1==f[j]){ // 벽과 겹친다면
    matrix.drawPixel(x1-a,y1-b,matrix.Color333(0,0,0)); // 현재 위치 지우고
    x1=0;
    y1=10; // 플레이어1의 시작위치로 다시 이동
    matrix.drawPixel(x1,y1,matrix.Color333(0,7,0));
    g=1; // 밑의 기능을 수행하지 않게 하기
    break;
  }
}

if(g==0){ // 플레이어의 다음좌표와 벽이 겹치지 않는다면
if(x1>31 || x1<0 || y1<0 || y1>15){ // 플레이어의 다음좌표가 화면을 벗어난다면
  matrix.drawPixel(x1-a,y1-b,matrix.Color333(0,0,0)); // 현재 위치 지우고
  x1=0; //시작지점으로
  y1=10;
  matrix.drawPixel(x1,y1,matrix.Color333(0,7,0));
}

else{ // 벽에 부딪히지도, 화면 밖으로 나가지도 않으면
  matrix.drawPixel(x1,y1,matrix.Color333(0,7,0)); // 정상적으로 다음좌표로 이동

 if(x1==31 && y1==5) { // p1이 도착지점에 도달하면...!
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // 화면 초기화 후 우승 글자 출력
  matrix.setCursor(1, 0);  
  matrix.setTextSize(1);   
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('1');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(0,7,0));
      matrix.print('n');
      
  matrix.setCursor(1, 8);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('1');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(0,7,0));
      matrix.print('n');
      
      coin=-1; // 게임 선택 초기화
      first1=0; // 루프 초기화
      selectmap=0; // 맵선택 초기화
      
      delay(5000); // 5초
      setup(); // 셑업 함수로 돌아가서 게임 선택부터 다시 실행
 }
}
}

//플레이어 1과 같은 방식으로 플레이어 2를 움직임 (다른점 : 시작지점과, 도착지점, 색)
c=0;
d=0;

if(sensorValue1>=800)
{
c=1;
d=0;
}
if(sensorValue2>=800)
{
d=1;
c=0;
}
if(sensorValue1<=200)
{
c=-1;
d=0;
}
if(sensorValue2<=200)
{
d=-1;
c=0;
}

matrix.drawPixel(x2,y2,matrix.Color333(0,0,0));
x2+=c;
y2+=d;
for(j=0; j<cnt1; j++){
  if(x2==e[j] && y2==f[j]){
    matrix.drawPixel(x2-c,y2-d,matrix.Color333(0,0,0));
    x2=31;
    y2=5;
    matrix.drawPixel(x2,y2,matrix.Color333(0,7,0));
    h=1;
    break;
  }
}
if(h==0){
if(x2>31 || x2<0 || y2<0 || y2>15){
  matrix.drawPixel(x2-c,y2-d,matrix.Color333(0,0,0));
  x2=31;
  y2=5;
  matrix.drawPixel(x2,y2,matrix.Color333(0,0,7));
}
else{
  matrix.drawPixel(x2,y2,matrix.Color333(0,0,7));

 if(x2==0 && y2==10) {
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(1, 0);  
  matrix.setTextSize(1);   
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('2');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(0,7,0));
      matrix.print('n');
      
      matrix.setCursor(1, 8);  
  matrix.setTextSize(1);   
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('2');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(0,7,0));
      matrix.print('n');
      coin=-1;
      first1=0;
      selectmap=0;
      delay(5000);
      setup();
 }
}
}

 delay(200);
  }

else if(selectmap==2){ //2번째 맵 선택 ( 1번째 맵 선택과 다른 점 : 미로의 벽, p1과p2의 출발지점 및 도착지점)
int g=0;
int h=0;

int sensorValue1=analogRead(A4);
int sensorValue2=analogRead(A5);
int sensorValue3=analogRead(A8);
int sensorValue4=analogRead(A9);
Serial.println(sensorValue1);

a=0;
b=0;

if(sensorValue3>=800)
{
a=1;
b=0;
}
if(sensorValue4>=800)
{
b=1;
a=0;
}
if(sensorValue3<=200)
{
a=-1;
b=0;
}
if(sensorValue4<=200)
{
b=-1;
a=0;
}


matrix.drawPixel(x1,y1,matrix.Color333(0,0,0));
x1+=a;
y1+=b;
for(j=0; j<cnt1; j++){
  if(x1==e[j] && y1==f[j]){
    matrix.drawPixel(x1-a,y1-b,matrix.Color333(0,0,0));
    x1=0;
    y1=5;
    matrix.drawPixel(x1,y1,matrix.Color333(0,7,0));
    g=1;
    break;
  }
}
if(g==0){
if(x1>31 || x1<0 || y1<0 || y1>15){
  matrix.drawPixel(x1-a,y1-b,matrix.Color333(0,0,0));
  x1=0;
  y1=5;
  matrix.drawPixel(x1,y1,matrix.Color333(0,7,0));
}
else{
  matrix.drawPixel(x1,y1,matrix.Color333(0,7,0));

 if(x1==15 && y1==11) {
   matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('1');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(0,7,0));
      matrix.print('n');
      
  matrix.setCursor(1, 8);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('1');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(0,7,0));
      matrix.print('n');
      coin=-1;
      first1=0;
      selectmap=0;
      delay(5000);
      setup();
 }
}
}

c=0;
d=0;
if(sensorValue1>=800)
{
c=1;
d=0;
}
if(sensorValue2>=800)
{
d=1;
c=0;
}
if(sensorValue1<=200)
{
c=-1;
d=0;
}
if(sensorValue2<=200)
{
d=-1;
c=0;
}

matrix.drawPixel(x2,y2,matrix.Color333(0,0,0));
x2+=c;
y2+=d;
for(j=0; j<cnt1; j++){
  if(x2==e[j] && y2==f[j]){
    matrix.drawPixel(x2-c,y2-d,matrix.Color333(0,0,0));
    x2=16;
    y2=5;
    matrix.drawPixel(x2,y2,matrix.Color333(0,7,0));
    h=1;
    break;
  }
}

if(h==0){
if(x2>31 || x2<0 || y2<0 || y2>15){
  matrix.drawPixel(x2-c,y2-d,matrix.Color333(0,0,0));
  x2=16;
  y2=5;
  matrix.drawPixel(x2,y2,matrix.Color333(0,7,0));
}
else{
  matrix.drawPixel(x2,y2,matrix.Color333(0,7,0));

 if(x2==31 && y2==11) {
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('2');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(0,7,0));
      matrix.print('n');
      
      matrix.setCursor(1, 8);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('2');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(0,7,0));
      matrix.print('n');
      coin=-1;
      first1=0;
      selectmap=0;
      delay(5000);
      setup();
 }
}
}

 delay(200);


  }
  }





  else if(coin==2){ //슈팅게임을 선택
    if(first2==0){ // 현재 루프의 첫번째라면 ( 각 변수들의 초기값 초기화)
      first2=1; // 두번째부터는 들어오지 못하게

 e2=0;
 f2=0;
 
 x12=2; y12=7; // 우주선은 점 3개로 구성되어 있기 때문에 한 우주선 당 세개의 좌표가 필요
 x22=3; y22=8;
 x32=2; y32=9;
 
 g2=0; h2=0;


 z12=29; w12=7;
 z22=28; w22=8;
 z32=29; w32=9;

 i2=0; j2=0;

 count12=0;
 count22=0;
 
 life12=4; // 목숨
 life22=4;
 
 soundstart=0; // 총 쏠 때 소리나게 하기 위한 변수
 soundstart2=0;
// 피구 변수
    }
    int sensorValue3=analogRead(A4);
int sensorValue4=analogRead(A5);
int sensorValue1=analogRead(A8);
int sensorValue2=analogRead(A9);
int sw1 = digitalRead(0); // 스위치가 눌리는지 판별
int sw2 = digitalRead(1); // 스위치가 눌리는지 판별

a2=0;
b2=0;

//조이스틱1
if(sensorValue1>=800)
{
a2=1;
b2=0;
}
if(sensorValue2>=800)
{
b2=1;
a2=0;
}
if(sensorValue1<=200)
{
a2=-1;
b2=0;
}
if(sensorValue2<=200)
{
b2=-1;
a2=0;
}

  matrix.drawPixel(x12,y12,matrix.Color333(0,0,0)); // 우주선1 흔적 지우기
  matrix.drawPixel(x22,y22,matrix.Color333(0,0,0));
  matrix.drawPixel(x32,y32,matrix.Color333(0,0,0));
  
x12+=a2;
y12+=b2;
x22+=a2;
y22+=b2;
x32+=a2;
y32+=b2;

if(x12<2 || y12<0 || x22==15 || y32>15){ // 우주선1의 다음 좌표가 목숨칸이나 중앙선에 겹쳐 진다면
  x12-=a2;
  y12-=b2;
  x22-=a2;
  y22-=b2;
  x32-=a2;
  y32-=b2; // 다음좌표로 가지 못하게 하고 그 자리에 그냥 가만히 있게 한다.
}

  matrix.drawPixel(x12,y12,matrix.Color333(7,0,0)); // 우주선1 출력 ( 미로게임과 같은 메커니즘)
  matrix.drawPixel(x22,y22,matrix.Color333(7,0,0));
  matrix.drawPixel(x32,y32,matrix.Color333(7,0,0)); 

//조이스틱2
c2=0;
d2=0;
if(sensorValue3>=800)
{
c2=1;
d2=0;
}
if(sensorValue4>=800)
{
d2=1;
c2=0;
}
if(sensorValue3<=200)
{
c2=-1;
d2=0;
}
if(sensorValue4<=200)
{
d2=-1;
c2=0;
}

 matrix.drawPixel(z12,w12,matrix.Color333(0,0,0));
 matrix.drawPixel(z22,w22,matrix.Color333(0,0,0));
 matrix.drawPixel(z32,w32,matrix.Color333(0,0,0));

z12+=c2;
w12+=d2;
z22+=c2;
w22+=d2;
z32+=c2;
w32+=d2;
if(z12>29 || w12<0 || z22==16 || w32>15){
  z12-=c2;
  w12-=d2;
  z22-=c2;
  w22-=d2;
  z32-=c2;
  w32-=d2;
} 
 matrix.drawPixel(z12,w12,matrix.Color333(0,0,7));
 matrix.drawPixel(z22,w22,matrix.Color333(0,0,7));
 matrix.drawPixel(z32,w32,matrix.Color333(0,0,7)); // 우주선1과 같은 메커니즘



 if(sw1 == LOW){ // 우주선1의 조이스틱이 버튼을 눌렀다면
  e2=1; // 총알이 나가서 움직이고 있음을 표시 ( 총알이 한번에 여러번 나갈 수 없음)
  if(soundstart==0){ 
  for( sound=0; sound<25; sound++){ // 소리 잠깐 나게 하기
    digitalWrite(7,HIGH);
    delayMicroseconds(1136);
    digitalWrite(7,LOW);
    delayMicroseconds(1136);
   }
   soundstart=1; // 총알 나갈 때 소리가 났다는 표시. 다음 총알 때 까지 대기
  }
 }
 if(e2==1){ // 총알이 움직이고 있는 중이라면
  count12++;
  if(count12==1){ // 총알이 처음 쏴지는것이라면 우주선의 현재 좌표에 따라서 총알이 나가게 하기
    x42=x22+1; // 직선방향 총알
    y42=y22;
    if(x42==15) x42=17; // 총알이 쏴질 때 중앙선과 바로 닫는다면 중앙성 건너뛰고 발사되게
    matrix.drawPixel(x42,y42,matrix.Color333(7,2,0));
    x52=x22+1; // 대각선 방향 총알
    y52=y22-1;
    if(x52==15) x52=17; // 총알이 쏴질 때 중앙선과 바로 닫는다면 중앙성 건너뛰고 발사되게
    matrix.drawPixel(x52,y52,matrix.Color333(7,2,0));
    x62=x22+1; // 반대쪽 대각선 방향 총알
    y62=y22+1;
    if(x62==15) x62=17; // 총알이 쏴질 때 중앙선과 바로 닫는다면 중앙성 건너뛰고 발사되게
    matrix.drawPixel(x62,y62,matrix.Color333(7,2,0));
  }
  else{ // 총알이 처음 쏴지고 난 후부터는 우주선의 현재 좌표에 상관 없이 총알이 날라가게
    matrix.drawPixel(x42,y42,matrix.Color333(0,0,0)); // 총알 흔적 지우기
    matrix.drawPixel(x52,y52,matrix.Color333(0,0,0));
    matrix.drawPixel(x62,y62,matrix.Color333(0,0,0));
    x42+=1; // 직선 방향 총알 진행
    
    x52+=1; // 대각선 방향의 총알
    if(g2==0) y52-=1; // g2가 0이면 이 총알은 아래 대각선으로 가는중
    else y52+=1; // g2가 0이 아니면 이 총알은 위 대각선으로 가는중
    
    x62+=1; // 반대 대각선 방향의 총알
    if(h2==0)y62+=1; // h2가 0이면 이 총알은 위 대각선으로 가는중
    else y62-=1; // h2가 0이 아니면 이 총알은 아래 대각선으로 가는중
    
    if(x42>29 || x52>29 || x62>29){
      if(x42>29 && x52>29 && x62>29){ // 총알 모두가 밖으로 나가면
        e2=0; // 다시 총알 쏠 수도 있고
        soundstart=0; // 총알 쏠 때 소리도 나고
        count12=0; // 그렇답니다.
       matrix.drawPixel(x42-1,y42,matrix.Color333(0,0,0));
       matrix.drawPixel(x52-1,y52,matrix.Color333(0,0,0));
       matrix.drawPixel(x62-1,y62,matrix.Color333(0,0,0));
      }
      else if(x42>29){
        if(x52>29) matrix.drawPixel(x52-1,y52,matrix.Color333(0,0,0));
        if(x62>29) matrix.drawPixel(x62-1,y62,matrix.Color333(0,0,0));
        matrix.drawPixel(x42-1,y42,matrix.Color333(0,0,0));
      }
      else if(x52>29){
        if(x42>29) matrix.drawPixel(x42-1,y42,matrix.Color333(0,0,0));
        if(x62>29) matrix.drawPixel(x62-1,y62,matrix.Color333(0,0,0));
        matrix.drawPixel(x52-1,y52,matrix.Color333(0,0,0));
        g2=0; // 대각선 방향 초기화
      }
      else if(x62>29){
        if(x52>29) matrix.drawPixel(x52-1,y52,matrix.Color333(0,0,0));
        if(x42>29) matrix.drawPixel(x42-1,y42,matrix.Color333(0,0,0));
        matrix.drawPixel(x62-1,y62,matrix.Color333(0,0,0));
        h2=0; // 대각선 방향 초기화
      }
    }
    else if(x42==15 || x52==15 || x62==15){ // 총알이 중앙선 침범하려고 하면 중앙선 넘어서 나오게 하기
     if(x42==15){
      x42=17;
      if(x52==15) x52=17;
      if(x62==15) x62=17;
      matrix.drawPixel(x42,y42,matrix.Color333(7,2,0));
      matrix.drawPixel(x52,y52,matrix.Color333(7,2,0));
      matrix.drawPixel(x62,y62,matrix.Color333(7,2,0));
     }
     else if(x52==15){
      x52=17;
      if(x42==15) x42=17;
      if(x62==15) x62=17;
      matrix.drawPixel(x42,y42,matrix.Color333(7,2,0));
      matrix.drawPixel(x52,y52,matrix.Color333(7,2,0));
      matrix.drawPixel(x62,y62,matrix.Color333(7,2,0));
     }
     else if(x62==15){
      x62=17;
      if(x52==15) x52=17;
      if(x42==15) x42=17;
      matrix.drawPixel(x42,y42,matrix.Color333(7,2,0));
      matrix.drawPixel(x52,y52,matrix.Color333(7,2,0));
      matrix.drawPixel(x62,y62,matrix.Color333(7,2,0));
     }
    }
    else{ // 별 일 없으면 그대로 진행
    matrix.drawPixel(x42,y42,matrix.Color333(7,2,0));
    matrix.drawPixel(x52,y52,matrix.Color333(7,2,0));
    matrix.drawPixel(x62,y62,matrix.Color333(7,2,0));
    } 
    if(y52==0 ) g2=1;  // 벽에 닿으면 대각선 방향 바꾸기
    else if(y52==15) g2=0; // 벽에 닿으면 대각선 방향 바꾸기
    if(y62==15 ) h2=1; // 벽에 닿으면 대각선 방향 바꾸기
    else if(y62==0) h2=0; // 벽에 닿으면 대각선 방향 바꾸기
  }
  
  // 총알이 상대 우주선에 닿았을 경우
  if( (x42==z12 && y42==w12) || (x42==z22 && y42==w22) || (x42==z32 && y42==w32) || (x52==z12 && y52==w12) || (x52==z22 && y52==w22) || (x52==z32 && y52==w32) || (x62==z12 && y62==w12) || (x62==z22 && y62==w22) || (x62==z32 && y62==w32)){
    if(life22==4){ // 한번 맞으면
      for(m2=0; m2<4; m2++){
        matrix.drawPixel(30,m2,matrix.Color333(3,3,3));
        matrix.drawPixel(31,m2,matrix.Color333(3,3,3));
      }
    }
    else if(life22==3){ //두번 맞으면
      for(m2=4; m2<8; m2++){
        matrix.drawPixel(30,m2,matrix.Color333(3,3,3));
        matrix.drawPixel(31,m2,matrix.Color333(3,3,3));
      }
    }
    else if(life22==2){ // 세번 맞으면
      for(m2=8; m2<12; m2++){
        matrix.drawPixel(30,m2,matrix.Color333(3,3,3));
        matrix.drawPixel(31,m2,matrix.Color333(3,3,3));
      }
    }
    else if(life22==1){ //네번 맞으면 끝~!
      matrix.fillScreen(matrix.Color333(0, 0, 0));
      matrix.setCursor(1, 0);  
  matrix.setTextSize(1);  
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('1');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('n');
      
      matrix.setCursor(1, 8);  
  matrix.setTextSize(1);   
  matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('1');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('n');
      coin=-1;
      first2=0;
      

      delay(5000);
      setup(); // 미로게임과 같은 메커니즘
    }
    life22--; // 목숨 차감
  }
 }
 



 if(sw2 == LOW){ //sw1과 같은 메커니즘입니다.
  f2=1;
  if(soundstart2==0){
  for( sound2=0; sound2<25; sound2++){
    digitalWrite(7,HIGH);
    delayMicroseconds(1136);
    digitalWrite(7,LOW);
    delayMicroseconds(1136);
   }
   soundstart2=1;
  }
 }
 if(f2==1){
  count22++;
  if(count22==1){
    z42=z22-1;
    w42=w22;
    if(z42==16) z42=14;
    matrix.drawPixel(z42,w42,matrix.Color333(0,2,7));
    z52=z22-1;
    w52=w22-1;
    if(z52==16)z52=14; 
    matrix.drawPixel(x52,y52,matrix.Color333(7,2,0));
    z62=z22-1;
    w62=w22+1;
    if(z62==16)z62=14;
    matrix.drawPixel(x62,y62,matrix.Color333(7,2,0));
  }
  else{
    matrix.drawPixel(z42,w42,matrix.Color333(0,0,0));
    matrix.drawPixel(z52,w52,matrix.Color333(0,0,0));
    matrix.drawPixel(z62,w62,matrix.Color333(0,0,0));
    z42-=1;
    z52-=1;
    if(i2==0) w52-=1;
    else w52+=1;
    z62-=1;
    if(j2==0)w62+=1;
    else w62-=1;
    if(z42<2 || z52<2 || z62<2){
      if(z42<2 && z52<2 && z62<2){
        f2=0;
        soundstart2=0;
        count22=0;
       matrix.drawPixel(z42+1,w42,matrix.Color333(0,0,0));
       matrix.drawPixel(z52+1,w52,matrix.Color333(0,0,0));
       matrix.drawPixel(z62+1,w62,matrix.Color333(0,0,0));
      }
      else if(z42<2){
        if(z52<2) matrix.drawPixel(z52+1,w52,matrix.Color333(0,0,0));
        if(z62<2) matrix.drawPixel(z62+1,w62,matrix.Color333(0,0,0));
        matrix.drawPixel(z42+1,w42,matrix.Color333(0,0,0));
      }
      else if(z52<2){
        if(z42<2) matrix.drawPixel(z42+1,w42,matrix.Color333(0,0,0));
        if(z62<2) matrix.drawPixel(z62+1,w62,matrix.Color333(0,0,0));
        matrix.drawPixel(z52+1,w52,matrix.Color333(0,0,0));
        i2=0;
      }
      else if(z62<2){
        if(z52<2) matrix.drawPixel(z52+1,w52,matrix.Color333(0,0,0));
        if(z42<2) matrix.drawPixel(z42+1,w42,matrix.Color333(0,0,0));
        matrix.drawPixel(z62+1,w62,matrix.Color333(0,0,0));
        j2=0;
      }
    }
    else if(z42==16 || z52==16 || z62==16){
     if(z42==16){
      z42=14;
      if(z52==16) z52=14;
      if(z62==16) z62=14;
      matrix.drawPixel(z42,w42,matrix.Color333(0,3,7));
      matrix.drawPixel(z52,w52,matrix.Color333(0,3,7));
      matrix.drawPixel(z62,w62,matrix.Color333(0,3,7));
     }
     else if(z52==16){
      z52=14;
      if(z42==16) z42=14;
      if(z62==16) z62=14;
      matrix.drawPixel(z42,w42,matrix.Color333(0,3,7));
      matrix.drawPixel(z52,w52,matrix.Color333(0,3,7));
      matrix.drawPixel(z62,w62,matrix.Color333(0,3,7));
     }
     else if(z62==16){
      z62=14;
      if(z42==16) z42=14;
      if(z52==16) z52=14;
      matrix.drawPixel(z42,w42,matrix.Color333(0,3,7));
      matrix.drawPixel(z52,w52,matrix.Color333(0,3,7));
      matrix.drawPixel(z62,w62,matrix.Color333(0,3,7));
     }
    }
    else{
    matrix.drawPixel(z42,w42,matrix.Color333(0,3,7));
    matrix.drawPixel(z52,w52,matrix.Color333(0,3,7));
    matrix.drawPixel(z62,w62,matrix.Color333(0,3,7));
    }
   if(w52==0 ) i2=1;
    else if(w52==15) i2=0;
    if(w62==15 ) j2=1;
    else if(w62==0) j2=0;
  }
 if( (z42==x12 && w42==y12) || (z42==x22 && w42==y22) || (z42==x32 && w42==y32) || (z52==x12 && w52==y12) || (z52==x22 && w52==y22) || (z52==x32 && w52==y32) || (z62==x12 && w62==y12) || (z62==x22 && w62==y22) || (z62==x32 && w62==y32)){
    if(life12==4){
      for(n2=0; n2<4; n2++){
        matrix.drawPixel(0,n2,matrix.Color333(3,3,3));
        matrix.drawPixel(1,n2,matrix.Color333(3,3,3));
      }
    }
    else if(life12==3){
      for(n2=4; n2<8; n2++){
        matrix.drawPixel(0,n2,matrix.Color333(3,3,3));
        matrix.drawPixel(1,n2,matrix.Color333(3,3,3));
      }
    }
    else if(life12==2){
      for(n2=8; n2<12; n2++){
        matrix.drawPixel(0,n2,matrix.Color333(3,3,3));
        matrix.drawPixel(1,n2,matrix.Color333(3,3,3));
      }
    }
    else if(life12==1){
      matrix.fillScreen(matrix.Color333(0, 0, 0));
      matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('2');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('n');
      
      matrix.setCursor(1, 8);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
  matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('2');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('n');
      coin=-1;
      first2=0;
      
      delay(5000);
      setup();
    }
    life12--;
  
  }

}
delay(75);
  }




  else if(coin==3){ // 똥피하기 게임 선택
    if(first3==0){// 현재 루프의 첫번째라면 ( 각 변수들의 초기값 초기화)
    matrix.fillScreen(matrix.Color333(0, 0, 0));
      first3=1; // 두번째에는 못들어오게
      
x13=0;  y13=7; // p1 위치
 x23=0; y23=9; // p2 위치

 a3=0;
 c3=0;

 cnt3=1;
 b3=0;
 time3=1;
 echoPin1 = 3; // 초음파거리 측정센서들의 디지털 값
 trigPin1 = 2;
echoPin2 = 5;
trigPin2 = 4; //

 dcount=0; // 떨어진 똥 갯수
 life13=0; // 맞은 횟수
 life23=0; // 맞은 횟수
 end3=0; // 끝나면 똥 안떨어지게 하기 위해서
 

    }
    
 digitalWrite(trigPin1, LOW);
    digitalWrite(echoPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);

  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
    unsigned long duration = pulseIn(echoPin1, HIGH); 
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  float distance = ((float)(340 * duration) / 10000) / 2;  
 

  digitalWrite(trigPin2, LOW);
    digitalWrite(echoPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);

    unsigned long duration2 = pulseIn(echoPin2, HIGH); 
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  float distance2 = ((float)(340 * duration2) / 10000) / 2;  


  
  matrix.drawPixel(x13,y13,matrix.Color333(7,0,0)); // 처음 위치
  matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
  
  if(cnt3<10 && time3 % 4==1){ // 한번에 떨어지는 똥의 갯수는 총 10개, 똥은 루프 4번 돌 때마다 한개씩 떨어지게
    dd=rand()%16; // 16개의 칸중 무작위 칸 (자세한 설명은 보고서 참조)
    ddd[b3]=dd;
    dddd[b3]=30;
    b3++; 
    if(b3==10) b3=0;
    cnt3++;
    dcount++;
  }
  if(dcount==40){ // 똥이 30개가 떨어지면 끝
    end3=1; // 똥이 안떨어지게 하기
    if(life13>life23){ // p1이 똥을 더 많이 맞았다면
      matrix.fillScreen(matrix.Color333(0, 0, 0));
      matrix.setCursor(1, 0); 
  matrix.setTextSize(1);   
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('2');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('n');
      
      matrix.setCursor(1, 8);  
  matrix.setTextSize(1);   
  matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('2');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('n');
      coin=-1;
      first3=0;
      delay(5000);
      setup();
    }
    else if(life23>life13){ //p2가 똥을 더 많이 맞았다면
      matrix.fillScreen(matrix.Color333(0, 0, 0));
      matrix.setCursor(1, 0);  
  matrix.setTextSize(1);   
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('1');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('n');
      
      matrix.setCursor(1, 8);  
  matrix.setTextSize(1); 
  matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('p');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('1');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('w');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('i');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('n');
      coin=-1;
      first3=0;
      delay(5000);
      setup(); // 미로게임과 같은 메커니즘
    }

    
    else if(life13==life23){ // 똥을 맞은 횟수가 둘 다 같다면
      matrix.fillScreen(matrix.Color333(0, 0, 0));
      matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('d');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('r');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('a');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('w');

      matrix.setCursor(1, 8);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high
      matrix.setTextColor(matrix.Color333(7,0,0));
      matrix.print('d');
      matrix.setTextColor(matrix.Color333(7,4,0));
      matrix.print('r');
      matrix.setTextColor(matrix.Color333(7,7,0));
      matrix.print('a');
      matrix.setTextColor(matrix.Color333(4,7,0));
      matrix.print('w');
      coin=-1;
      first3=0;
      delay(5000);
      setup();
    }
  }



  
if(end3==0){ // 똥 떨어지는게 끝나지 않았으면
  if(distance>10){ // 거리 측정 센서가 10cm 이상의 거리를 인식한 경우 플레이어를 움직일 수 있음
    a3=1; // 움직이게 하기위한 조건값
    
  }
  if(a3==1){
       // 센서와의 거리가 특정 거리 사이라면 특정 좌표에 나타나게 함
    if(distance>36 && distance<=39){ 
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=8; 
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>33 && distance<=36){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=7;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>39 && distance<=42){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=9;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>42 && distance<=45){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=10;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>45 && distance<=48){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=11;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>48 && distance<=51){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=12;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>51 && distance<=54){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=13;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>54 && distance<=57){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=14;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>57 && distance<=60){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=15;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>12 && distance<=15){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=0;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>15 && distance<=18){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=1;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>18 && distance<=21){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=2;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>21 && distance<=24){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=3;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>24 && distance<=27){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=4;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>27 && distance<=30){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=5;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
    else if(distance>30 && distance<=33){
      matrix.drawPixel(x13,y13,matrix.Color333(0,0,0));
      y13=6;
      matrix.drawPixel(x13,y13,matrix.Color333(7,0,0));
    }
  } 

  if(distance2>10){ //p1과 같은 메커니즘
    c3=1;
   
  }
  if(c3==1){
     matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
    if(distance2>36 && distance2<=39){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=8; 
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>33 && distance2<=36){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=7;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>39 && distance2<=42){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=9;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>42 && distance2<=45){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=10;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>45 && distance2<=48){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=11;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>48 && distance2<=51){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=12;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>51 && distance2<=54){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=13;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>54 && distance2<=57){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=14;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>57 && distance2<=60){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=15;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>12 && distance2<=15){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=0;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>15 && distance2<=18){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=1;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>18 && distance2<=21){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=2;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>21 && distance2<=24){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=3;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>24 && distance2<=27){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=4;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>27 && distance2<=30){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=5;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
    else if(distance2>30 && distance2<=33){
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,0));
      y23=6;
      matrix.drawPixel(x23,y23,matrix.Color333(0,0,7));
    }
  } 
  
  for(i3=0; i3<10; i3++){ // 똥 출력하기(4개의 점들을 합치면 똥1개)
    matrix.drawPixel(dddd[i3]+2,ddd[i3],matrix.Color333(0,0,0));
    matrix.drawPixel(dddd[i3]+1,ddd[i3],matrix.Color333(0,0,0));
    matrix.drawPixel(dddd[i3]+1,ddd[i3]-1,matrix.Color333(0,0,0));
    matrix.drawPixel(dddd[i3]+1,ddd[i3]+1,matrix.Color333(0,0,0));
    matrix.drawPixel(dddd[i3],ddd[i3],matrix.Color333(3,4,3));
    matrix.drawPixel(dddd[i3]-1,ddd[i3],matrix.Color333(3,4,3));
    matrix.drawPixel(dddd[i3]-1,ddd[i3]-1,matrix.Color333(3,4,3));
    matrix.drawPixel(dddd[i3]-1,ddd[i3]+1,matrix.Color333(3,4,3));
    if((dddd[i3]==x13 && ddd[i3]==y13) || ((dddd[i3]-1)==x13 && ddd[i3]==y13) || ((dddd[i3]-1)==x13 && (ddd[i3]-1)==y13) || ((dddd[i3]-1)==x13 && (ddd[i3]+1)==y13)){ // 똥에 맞으면
      life13++; // 맞은거 카운트
      for( sound=0; sound<25; sound++){ //맞을 때 소리나기
        digitalWrite(7,HIGH);
        delayMicroseconds(1136);
        digitalWrite(7,LOW);
        delayMicroseconds(1136);
     }
    }
    if((dddd[i3]==x23 && ddd[i3]==y23) || ((dddd[i3]-1)==x23 && ddd[i3]==y23) || ((dddd[i3]-1)==x23 && (ddd[i3]-1)==y23) || ((dddd[i3]-1)==x23 && (ddd[i3]+1)==y23)){ // 같은 메커니즘
      life23++;
      for( sound2=0; sound2<25; sound2++){
        digitalWrite(7,HIGH);
        delayMicroseconds(1136);
        digitalWrite(7,LOW);
        delayMicroseconds(1136);
     }
    }
    dddd[i3]-=2; // 똥 떨어지게 하기
    if(dddd[i3]==-2) { // 똥이 아예 떨어져 버리면 새로운 똥 나오게 하기
      cnt3--;
      matrix.drawPixel(0,ddd[i3],matrix.Color333(0,0,0));
    }
  }
}
  delay(100);
  time3++;
 }

  
}
