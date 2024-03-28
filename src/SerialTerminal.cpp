#include "SerialTerminal.h"

terminal::terminaд(){
  
}

int terminal::verCommand(const char *cmd, int len, int count){
  int blen = len * count;
  char *buf = new char[len];
  Serial.readBytes(buf, len);
  cleanBuf();
  
  int j = 0;
  for(j = 0; j < count; j++){
    int i = 0; 
    int ic = j * len;
    while (cmd[ic] == buf[i] && i < len) {
      i++;
      ic++;
      if (i == len) {
        delete[] buf;
        return j;
      } 
    }
  }
  return -1;

}

bool terminal::verCommand(const char *cmd, int len) {
  char *buf = new char[len];
  Serial.readBytes(buf, len);
  cleanBuf();
  int i = 0;
  while (cmd[i] == buf[i] && i < len) {
    i++;
  }
  delete[] buf;

  if (i == len) {
    return true;
  } else {
    return false;
  }
}

void terminal::cleanBuf() {
  while (Serial.available() > 0) char bin = Serial.read();
}

bool terminal::waitBuf(uint32_t timeout) {
  uint32_t tmr = millis();
  bool res = true;
  while (!Serial.available() && res){
    if(millis() > tmr + timeout) res = false; 
  }
  return res;
}