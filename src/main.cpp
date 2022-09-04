#include <Arduino.h>
#include<ShiftRegisterBus.h>
#include<DisplayData.h>
#include<GridData.h>
byte current_digit;
uint8_t count=0;

char d[] = {'A','B','C','D','E','F','G','H','I','J','K',
'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char c[] = {'>','<'};

void setup() {
  // put your setup code here, to run once:
  DisplayBus.init();
  GridBus.init();
  pinMode(grid_latch,OUTPUT);
  pinMode(seg_latch,OUTPUT);
  pinMode(seg_strob,OUTPUT);
  pinMode(grid_strob,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:

NumberDisplayOn();
GridNumbeOn();
delay(1000);
ClearNumer();
ClearGrid();
for(int x=1;x<11;x++){
  if(count >10)count =1;
  GridNumber(x);
  Number_30segment(count);
  delay(1000);
  count++;
  ClearGrid();
}
count =0;
for(uint8_t x=0;x< sizeof d;x++){
  ++count;
  if(count > 14)count=1;
GridNumber(count);
Characters_30Segments(d[x]);
delay(1000);
ClearGrid();
}
for(uint8_t x =1;x < 14;x++){
 GridNumber(x);
 Characters_30Segments(c[1]); //>
 delay(200);
 ClearGrid();
}
for(uint8_t x=15;x > 0;x--){
  GridNumber(x);
  Characters_30Segments(c[0]); //<
  delay(200);
  ClearGrid();
}
count =20;
for(uint8_t x=0; x< 10;x++){
ClearNumer();
GridNumber(count);
Number_13SegmentsDigit_1L(x);
Number_13SegmentsDigit_2R(x +1);
delay(1000);
count--;
if(count < 17 )count =20;
ClearGrid();
}



 
}