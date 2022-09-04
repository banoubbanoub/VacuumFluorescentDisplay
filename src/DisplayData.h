#include<Arduino.h>
#include<ShiftRegisterBus.h>
//first byte
#define d1_0 0
#define d1_1 1
#define d1_2 2
#define d1_3 3
#define d1_4 4
#define d1_5 5
#define d1_6 6
#define d1_7 7
//second byte
#define d2_0 0
#define d2_1 1
#define d2_2 2
#define d2_3 3
#define d2_4 4
#define d2_5 5
#define d2_6 6
#define d2_7 7
//third byte
#define d3_0 0
#define d3_1 1
#define d3_2 2
#define d3_3 3
#define d3_4 4
#define d3_5 5
#define d3_6 6
#define d3_7 7
//fourth byte
#define d4_0 0
#define d4_1 1
#define d4_2 2
#define d4_3 3
#define d4_4 4
#define d4_5 5
#define d4_6 6
#define d4_7 7
#define seg_latch 6
#define seg_strob 7
ShiftRegisterBus DisplayBus(A0,A1);// Pins: DO CL 
byte shiftRegisterBytes[4];
void ClearNumer(){
  digitalWrite(seg_strob,HIGH);
  digitalWrite(seg_latch,LOW);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_latch,LOW);
 for(uint8_t x=0;x < 4;x++){
  shiftRegisterBytes[x]=0;
 }
  DisplayBus.write(shiftRegisterBytes,4);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_strob,LOW);
}
void NumberDisplayOn(){
  digitalWrite(seg_strob,HIGH);
  digitalWrite(seg_latch,LOW);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_latch,LOW);
  for(uint8_t x=0;x < 4;x++){
  shiftRegisterBytes[x] = 255;
 }
 DisplayBus.write(shiftRegisterBytes,4);
 digitalWrite(seg_latch,HIGH);
 digitalWrite(seg_strob,LOW);
}
void Number_30segment(int number){
  digitalWrite(seg_strob,HIGH);
  digitalWrite(seg_latch,LOW);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_latch,LOW);
  
  switch (number)
  {
   case 0:
   //first byte
   shiftRegisterBytes[0] = 116;
   //second byte
   shiftRegisterBytes[1] = 103; 
   //third byte
   shiftRegisterBytes[2] = 92;
   //fourth byte
   shiftRegisterBytes[3] = 184;
   break;
   case 1:
   //first byte
    shiftRegisterBytes[0] = 35;
    //second byte
    shiftRegisterBytes[1] =8;
    //third byte
    shiftRegisterBytes[2]= 66;
    //fourth byte
    shiftRegisterBytes[3] = 124;
    break;
    case 2:
     //first byte
    shiftRegisterBytes[0] = 116;
    //second byte
    shiftRegisterBytes[1] = 66;
    //third byte
    shiftRegisterBytes[2] = 38;
    //fourth byte
    shiftRegisterBytes[3] = 124;
    break;
    case 3:
     //first byte
    shiftRegisterBytes[0] = 248;
    //second byte
    shiftRegisterBytes[1] = 136;
    //third byte
    shiftRegisterBytes[2] = 40;
    //fourth byte
    shiftRegisterBytes[3] = 184;
    break;
    case 4:
    //fist byte
    shiftRegisterBytes[0]= 17;
    //second byte
    shiftRegisterBytes[1] = 149;
    //third byte
    shiftRegisterBytes[2] = 47;
    //fourth byte
    shiftRegisterBytes[3] = 136;
    break;
    case 5:
    //first byte
    shiftRegisterBytes[0] = 252;
    // second byte
    shiftRegisterBytes[1] = 60;
    //third byte
    shiftRegisterBytes[2] = 24;
    //fourth byte
    shiftRegisterBytes[3] = 184; 
    break;
    case 6:
    //first byte
    shiftRegisterBytes[0] =50; 
    //second byte
    shiftRegisterBytes[1] = 33;
    //third byte
    shiftRegisterBytes[2] = 232;
   //fourth byte
   shiftRegisterBytes[3] = 184;
   break;
   case 7:
   //first byte
   shiftRegisterBytes[0] = 248;
   //second byte
   shiftRegisterBytes[1] = 68;
   //third byte
   shiftRegisterBytes[2] = 68;
   //fourth byte
   shiftRegisterBytes[3] = 32;
   break;
   case 8:
   //first byte
   shiftRegisterBytes[0] = 116;
   //second byte
   shiftRegisterBytes[1] = 98; 
   //third byte
   shiftRegisterBytes[2] = 232;
   //fourth byte
   shiftRegisterBytes[3] = 184;
   break;
   case 9:
   //first byte
   shiftRegisterBytes[0] = 116;
   //second byte
   shiftRegisterBytes[1] = 98;
   //third byte
   shiftRegisterBytes[2] = 240;
   //fourth byte
   shiftRegisterBytes[3] =248;
   break;
  }
  DisplayBus.write(shiftRegisterBytes,4);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_strob,LOW);
  
}
void Characters_30Segments(char c){
  digitalWrite(seg_strob,HIGH);
  digitalWrite(seg_latch,LOW);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_latch,LOW);
 switch(c){
  case 'A':
  //first byte
  shiftRegisterBytes[0] = 116;
  //second byte
  shiftRegisterBytes[1] = 99;
 //third byte
 shiftRegisterBytes[2] = 248;
 //fourth byte
 shiftRegisterBytes[3] = 196;
 break;
 case 'B':
 //first byte
  shiftRegisterBytes[0] = 244;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 232;
  //fourth byte
  shiftRegisterBytes[3] = 248;
  break;
  case 'C':
   //first byte
  shiftRegisterBytes[0] = 116;
  //second byte
  shiftRegisterBytes[1] = 97;
  //third byte
  shiftRegisterBytes[2] = 8;
  //fourth byt
  shiftRegisterBytes[3] = 184;
  break;
  case 'D':
     //first byte
  shiftRegisterBytes[0] = 228;
  //second byte
  shiftRegisterBytes[1] = 163;
  //third byte
  shiftRegisterBytes[2] = 25;
  //fourth byt
  shiftRegisterBytes[3] = 112;
  break;
  case 'E':
     //first byte
  shiftRegisterBytes[0] = 252;
  //second byte
  shiftRegisterBytes[1] = 33;
  //third byte
  shiftRegisterBytes[2] = 232;
  //fourth byt
  shiftRegisterBytes[3] = 124;
  break;
  case 'F':
     //first byte
  shiftRegisterBytes[0] = 252;
  //second byte
  shiftRegisterBytes[1] = 33;
  //third byte
  shiftRegisterBytes[2] = 232;
  //fourth byt
  shiftRegisterBytes[3] = 66;
  break;
  case 'G':
     //first byte
  shiftRegisterBytes[0] = 116;
  //second byte
  shiftRegisterBytes[1] = 97;
  //third byte
  shiftRegisterBytes[2] = 120;
  //fourth byt
  shiftRegisterBytes[3] = 188;
  break;
  case 'H':
     //first byte
  shiftRegisterBytes[0] = 140;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 248;
  //fourth byt
  shiftRegisterBytes[3] = 196;
  break;
  case 'I':
     //first byte
  shiftRegisterBytes[0] = 113;
  //second byte
  shiftRegisterBytes[1] = 8;
  //third byte
  shiftRegisterBytes[2] = 66;
  //fourth byt
  shiftRegisterBytes[3] = 56;
  break;
  case 'J':
     //first byte
  shiftRegisterBytes[0] = 56;
  //second byte
  shiftRegisterBytes[1] = 132;
  //third byte
  shiftRegisterBytes[2] = 41;
  //fourth byt
  shiftRegisterBytes[3] = 48;
  break;
  case 'K':
     //first byte
  shiftRegisterBytes[0] = 140;
  //second byte
  shiftRegisterBytes[1] = 169;
  //third byte
  shiftRegisterBytes[2] = 138;
  //fourth byt
  shiftRegisterBytes[3] = 74;
  break;
  case 'L':
     //first byte
  shiftRegisterBytes[0] = 132;
  //second byte
  shiftRegisterBytes[1] = 33;
  //third byte
  shiftRegisterBytes[2] = 8;
  //fourth byt
  shiftRegisterBytes[3] = 124;
  break;
  case 'M':
     //first byte
  shiftRegisterBytes[0] = 142;
  //second byte
  shiftRegisterBytes[1] = 235;
  //third byte
  shiftRegisterBytes[2] = 88;
  //fourth byt
  shiftRegisterBytes[3] = 196;
  break;
  case 'N':
     //first byte
  shiftRegisterBytes[0] = 140;
  //second byte
  shiftRegisterBytes[1] = 115;
  //third byte
  shiftRegisterBytes[2] = 89;
  //fourth byt
  shiftRegisterBytes[3] = 196;
  break;
  case 'O':
     //first byte
  shiftRegisterBytes[0] = 116;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 24;
  //fourth byt
  shiftRegisterBytes[3] = 184;
  break;
  case 'P':
     //first byte
  shiftRegisterBytes[0] = 244;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 232;
  //fourth byt
  shiftRegisterBytes[3] = 66;
  break;
  case 'Q':
     //first byte
  shiftRegisterBytes[0] = 116;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 89;
  //fourth byt
  shiftRegisterBytes[3] = 52;
  break;
  case 'R':
     //first byte
  shiftRegisterBytes[0] = 244;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 234;
  //fourth byt
  shiftRegisterBytes[3] = 74;
  break;
  case 'S':
     //first byte
  shiftRegisterBytes[0] = 124;
  //second byte
  shiftRegisterBytes[1] = 32;
  //third byte
  shiftRegisterBytes[2] = 224;
  //fourth byt
  shiftRegisterBytes[3] = 248;
  break;
  case 'T':
     //first byte
  shiftRegisterBytes[0] = 249;
  //second byte
  shiftRegisterBytes[1] = 8;
  //third byte
  shiftRegisterBytes[2] = 66;
  //fourth byt
  shiftRegisterBytes[3] = 16;
  break;
  case 'U':
  //first byte
  shiftRegisterBytes[0] = 140;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 24;
  //fourth byt
  shiftRegisterBytes[3] = 184;
  break;
  case 'V':
  //first byte
  shiftRegisterBytes[0] = 140;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 21;
  //fourth byt
  shiftRegisterBytes[3] = 16;
  break;
  case 'W':
  //first byte
  shiftRegisterBytes[0] = 140;
  //second byte
  shiftRegisterBytes[1] = 99;
  //third byte
  shiftRegisterBytes[2] = 90;
  //fourth byt
  shiftRegisterBytes[3] = 168;
  break;
  case 'X':
  //first byte
  shiftRegisterBytes[0] = 140;
  //second byte
  shiftRegisterBytes[1] = 84;
  //third byte
  shiftRegisterBytes[2] = 69;
  //fourth byt
  shiftRegisterBytes[3] = 68;
  break;
  case 'Y':
  //first byte
  shiftRegisterBytes[0] = 140;
  //second byte
  shiftRegisterBytes[1] = 98;
  //third byte
  shiftRegisterBytes[2] = 162;
  //fourth byt
  shiftRegisterBytes[3] = 16;
  break;
  case 'Z':
  //first byte
  shiftRegisterBytes[0] = 248;
  //second byte
  shiftRegisterBytes[1] = 68;
  //third byte
  shiftRegisterBytes[2] = 68;
  //fourth byt
  shiftRegisterBytes[3] = 124;
  break;
  case '>':
   //first byte
  shiftRegisterBytes[0] = 17;
  //second byte
  shiftRegisterBytes[1] = 17;
  //third byte
  shiftRegisterBytes[2] = 4;
  //fourth byt
  shiftRegisterBytes[3] = 16;
  break;
  case '<':
  //first byte
  shiftRegisterBytes[0] = 65;
  //second byte
  shiftRegisterBytes[1] = 4;
  //third byte
  shiftRegisterBytes[2] = 17;
  //fourth byt
  shiftRegisterBytes[3] = 17;
  break;
}
 DisplayBus.write(shiftRegisterBytes,4);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_strob,LOW);
}
void Number_13SegmentsDigit_1L(int number){
 digitalWrite(seg_strob,HIGH);
  digitalWrite(seg_latch,LOW);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_latch,LOW);
  switch (number)
  {
  case 0:
    shiftRegisterBytes[0] = 160;
    shiftRegisterBytes[1] = 32;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 40;
    break;
  case 1:
    shiftRegisterBytes[0] = 32;
    shiftRegisterBytes[1] = 0;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 0;
    break;
    case 2:
    shiftRegisterBytes[0] = 160;
    shiftRegisterBytes[1] = 5;
    shiftRegisterBytes[2] = 0;
    shiftRegisterBytes[3] = 40;
    break;
    case 3:
    shiftRegisterBytes[0] = 128;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 0;
    shiftRegisterBytes[3] = 40;
    break;
    case 4:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 32;
    break;
    case 5:
    shiftRegisterBytes[0] = 128;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 8;
    break;
    case 6:
    shiftRegisterBytes[0] = 160;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 8;
    break;
    case 7:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 32;
    shiftRegisterBytes[2] = 0;
    shiftRegisterBytes[3] = 40;
    break;
    case 8:
    shiftRegisterBytes[0] = 160;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 40;
    break;
    case 9:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 40;
    break;

  }
  DisplayBus.write(shiftRegisterBytes,4);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_strob,LOW);
}
void Number_13SegmentsDigit_2R(int number){
 digitalWrite(seg_strob,HIGH);
  digitalWrite(seg_latch,LOW);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_latch,LOW);
  switch (number)
  {
  case 0:
    shiftRegisterBytes[0] = 80;
    shiftRegisterBytes[1] = 16;
    shiftRegisterBytes[2] = 16;
    shiftRegisterBytes[3] = 20;
    break;
  case 1:
    shiftRegisterBytes[0] = 16;
    shiftRegisterBytes[1] = 0;
    shiftRegisterBytes[2] = 16;
    shiftRegisterBytes[3] = 0;
    break;
    case 2:
    shiftRegisterBytes[0] = 80;
    shiftRegisterBytes[1] = 2;
    shiftRegisterBytes[2] = 128;
    shiftRegisterBytes[3] = 20;
    break;
    case 3:
    shiftRegisterBytes[0] = 64;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 128;
    shiftRegisterBytes[3] = 20;
    break;
    case 4:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 16;
    break;
    case 5:
    shiftRegisterBytes[0] = 64;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 4;
    break;
    case 6:
    shiftRegisterBytes[0] = 80;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 4;
    break;
    case 7:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 16;
    shiftRegisterBytes[2] = 128;
    shiftRegisterBytes[3] = 20;
    break;
    case 8:
    shiftRegisterBytes[0] = 80;
    shiftRegisterBytes[1] = 20;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 20;
    break;
    case 9:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 20;
    break;

  }
  DisplayBus.write(shiftRegisterBytes,4);
  digitalWrite(seg_latch,HIGH);
  digitalWrite(seg_strob,LOW);
}
