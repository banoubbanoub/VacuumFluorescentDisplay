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
#define grid_latch 8
#define grid_strob 9
ShiftRegisterBus GridBus(A2,A3);// Pins: DO CL
byte GshiftRegisterBytes[4];

void ClearGrid(){
 for(uint8_t x=0; x < 4;x++){
    GshiftRegisterBytes[x]=0;
  }
}

void GridNumbeOn(){
  digitalWrite(grid_strob,HIGH);
  digitalWrite(grid_latch,LOW);
  digitalWrite(grid_latch,HIGH);
  digitalWrite(grid_latch,LOW);
  for(uint8_t x=0; x < 4;x++){
    GshiftRegisterBytes[x] = 255;
  }
   GridBus.write(GshiftRegisterBytes,4);
  digitalWrite(grid_latch,HIGH);
  digitalWrite(grid_strob,LOW);
}

void GridNumber(int number){
  digitalWrite(grid_strob,HIGH);
  digitalWrite(grid_latch,LOW);
  digitalWrite(grid_latch,HIGH);
  digitalWrite(grid_latch,LOW);
// ClearGrid();
  switch (number)
  {
  case 1:
    bitWrite(GshiftRegisterBytes[0],d1_7,1);
    break;
    case 2:
    bitWrite(GshiftRegisterBytes[0],d1_6,1);
    break;
    case 3:
    bitWrite(GshiftRegisterBytes[0],d1_5,1);
    break;
    case 4:
    bitWrite(GshiftRegisterBytes[0],d1_4,1);
    break;
    case 5:
    bitWrite(GshiftRegisterBytes[0],d1_3,1);
    break;
    case 6:
    bitWrite(GshiftRegisterBytes[0],d1_2,1);
    break;
    case 7:
    bitWrite(GshiftRegisterBytes[0],d1_1,1);
    break;
    case 8:
    bitWrite(GshiftRegisterBytes[0],d1_0,1);
    break;
    case 9:
    bitWrite(GshiftRegisterBytes[1],d2_7,1);
    break;
    case 10:
    bitWrite(GshiftRegisterBytes[1],d2_6,1);
    break;
    case 11:
    bitWrite(GshiftRegisterBytes[1],d2_5,1);
    break;
    case 12:
    bitWrite(GshiftRegisterBytes[1],d2_4,1);
    break;
    case 13:
    bitWrite(GshiftRegisterBytes[1],d2_3,1);
    break;
    case 14:
    bitWrite(GshiftRegisterBytes[1],d2_2,1);
    break;
    case 15:
    bitWrite(GshiftRegisterBytes[1],d2_1,1);
    break;
   case 16:
   bitWrite(GshiftRegisterBytes[1],d2_0,1);
   break;
   case 17:
   bitWrite(GshiftRegisterBytes[2],d3_7,1);
   break;
   case 18:
   bitWrite(GshiftRegisterBytes[2],d3_6,1);
   break;
   case 19:
   bitWrite(GshiftRegisterBytes[2],d3_5,1);
   break;
   case 20:
   bitWrite(GshiftRegisterBytes[2],d3_4,1);
   break;
  }
 // bitWrite(GshiftRegisterBytes[3],d4_0,1);// dot 33
 // bitWrite(GshiftRegisterBytes[3],d4_1,1); // dot 34
 // bitWrite(GshiftRegisterBytes[3],d4_2,1); // dot 35
  bitWrite(GshiftRegisterBytes[3],d4_3,1); // red line
 GridBus.write(GshiftRegisterBytes,4);
  digitalWrite(grid_latch,HIGH);
  digitalWrite(grid_strob,LOW);
  
}