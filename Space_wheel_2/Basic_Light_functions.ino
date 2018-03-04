//Basic Light Program Functions

//All wires on
void allOn(int ms){
  int set_inBits[8] = {1,1,1,1,1,1,1,1};
  inByte = set_byte(set_inBits);
  lightWires(inByte);
  delay(ms);
}

//All wires off
void allOff(int ms){
  int set_inBits[8] = {0,0,0,0,0,0,0,0};
  inByte = set_byte(set_inBits);
  lightWires(inByte);
  delay(ms);
}

void inOutSingleSync(int ms, int num_of_times, bool turn_right){
  int set_inBits[8]={1,0,0,0,1,0,0,0};
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    lightWires(inByte);
    delay(ms);
    if(turn_right){
      inByte = rightRotate(inByte, 1);
    }
    else{
      inByte = leftRotate(inByte, 1);
    }
  }
}

void inOutSingleSplit(int ms, int num_of_times, bool turn_right){
  int set_outBits[8]={1,0,0,0,1,0,0,0};
  int set_inBits[8]={0,0,1,0,0,0,1,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte, 1);
      inByte = rightRotate(inByte,1);
    }
    else{
      outByte = leftRotate(outByte, 1);
      inByte = leftRotate(inByte,1);
    }
  }
}


void inOutSingleOpposite(int ms, int num_of_times, bool turn_right){
  ms = ms/2;
  int set_outBits[8]={1,0,0,0,1,0,0,0};
  int set_inBits[8]={1,0,0,0,1,0,0,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(8*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      if(i%2){outByte = rightRotate(outByte, 1);}
      else{inByte = leftRotate(inByte,1);}
    }
    else{
      if(i%2){outByte = leftRotate(outByte, 1);}
      else{inByte = rightRotate(inByte,1);}
    }
  }
}


void inOutDoubleSync(int ms, int num_of_times, bool turn_right){
  int set_outBits[8]={1,1,0,0,1,1,0,0};
  int set_inBits[8]={1,1,0,0,1,1,0,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte, 1);
      inByte = rightRotate(inByte,1);
    }
    else{
      outByte = leftRotate(outByte, 1);
      inByte = leftRotate(inByte,1);
    }
  }
}


void inOutDoubleOpposite(int ms, int num_of_times, bool turn_right){
  ms = ms/2;
  int set_outBits[8]={1,0,0,1,1,0,0,1};
  int set_inBits[8]={1,0,0,1,1,0,0,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(8*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      if(i%2){outByte = rightRotate(outByte, 1);}
      else{inByte = leftRotate(inByte,1);}
    }
    else{
      if(i%2){outByte = leftRotate(outByte, 1);}
      else{inByte = rightRotate(inByte,1);}
    }
  }     
}

void inOutDoubleOpposite2(int ms, int num_of_times, bool turn_right){
  int set_outBits[8]={1,0,0,1,1,0,0,1};
  int set_inBits[8]={1,0,0,1,1,0,0,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte, 1);
      inByte = leftRotate(inByte,1);
    }
    else{
      outByte = leftRotate(outByte, 1);
      inByte = rightRotate(inByte,1);
    }
  }     
}
void inOutDoubleSplit(int ms, int num_of_times, bool turn_right){
  int set_outBits[8]={1,0,0,1,1,0,0,1};
  int set_inBits[8]={0,1,1,0,0,1,1,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte, 1);
      inByte = rightRotate(inByte,1);
    }
    else{
      outByte = leftRotate(outByte, 1);
      inByte = leftRotate(inByte,1);
    }
  }  
}


void inOutTripleSync(int ms, int num_of_times, bool turn_right){
  int set_outBits[8]={0,1,1,1,0,1,1,1};
  int set_inBits[8]={0,1,1,1,0,1,1,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte, 1);
      inByte = rightRotate(inByte,1);
    }
    else{
      outByte = leftRotate(outByte, 1);
      inByte = leftRotate(inByte,1);
    }
  }
}


void inOutTripleOpposite(int ms, int num_of_times, bool turn_right){
  ms = ms/2;
  int set_outBits[8]={0,1,1,1,0,1,1,1};
  int set_inBits[8]={0,1,1,1,0,1,1,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(8*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      if(i%2){outByte = rightRotate(outByte, 1);}
      else{inByte = leftRotate(inByte,1);}
    }
    else{
      if(i%2){outByte = leftRotate(outByte, 1);}
      else{inByte = rightRotate(inByte,1);}
    }
  }     
}


void inSingleOutFull(int ms, int num_of_times, bool turn_right){
  int set_outBits[8]={1,1,1,1,1,1,1,1};
  int set_inBits[8]={1,0,0,0,1,0,0,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      inByte = rightRotate(inByte,1);
    }
    else{
      inByte = leftRotate(inByte,1);
    }
  }
}


void inDoubleOutFull(int ms, int num_of_times, bool turn_right){
  int set_outBits[8]={1,1,1,1,1,1,1,1};
  int set_inBits[8]={1,0,0,1,1,0,0,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      inByte = rightRotate(inByte,1);
    }
    else{
      inByte = leftRotate(inByte,1);
    }
  }
}


void inDoubleSplitOutFull(int ms, int num_of_times, bool turn_right){
  int set_outBits[8]={1,1,1,1,1,1,1,1};
  int set_inBits[8]={1,0,1,0,1,0,1,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      inByte = rightRotate(inByte,1);
    }
    else{
      inByte = leftRotate(inByte,1);
    }
  }
}


void inFullOutSingle(int ms, int num_of_times, bool turn_right){
  int set_inBits[8]={1,1,1,1,1,1,1,1};
  int set_outBits[8]={1,0,0,0,1,0,0,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte,1);
    }
    else{
      outByte = leftRotate(outByte,1);
    }
  }
}


void inFullOutDouble(int ms, int num_of_times, bool turn_right){
  int set_inBits[8]={1,1,1,1,1,1,1,1};
  int set_outBits[8]={1,0,0,1,1,0,0,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte,1);
    }
    else{
      outByte = leftRotate(outByte,1);
    }
  }
}


void inFullOutDoubleSplit(int ms, int num_of_times, bool turn_right){
  int set_inBits[8]={1,1,1,1,1,1,1,1};
  int set_outBits[8]={1,0,1,0,1,0,1,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(4*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte,1);
    }
    else{
      outByte = leftRotate(outByte,1);
    }
  }
}


void inVarOutVarSync(int ms, int num_of_times, bool turn_right, int start_offset){
  int set_inBits[8]={1,1,1,1,0,0,0,0};
  int set_outBits[8]={0,0,0,0,1,1,1,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  inByte = rightRotate(inByte,start_offset);
  outByte = rightRotate(outByte,start_offset);
  for(int i=0;i<(num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte,1);
      inByte = rightRotate(inByte,1);
    }
    else{
      outByte = leftRotate(outByte,1);
      inByte = leftRotate(inByte,1);
    }
  }
}


void inVarOutVarSplit(int ms, int num_of_times, bool turn_right){
  int set_inBits[8]={0,0,0,0,1,1,1,1};
  int set_outBits[8]={0,0,0,0,1,1,1,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(8*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte,1);
      inByte = rightRotate(inByte,1);
    }
    else{
      outByte = leftRotate(outByte,1);
      inByte = leftRotate(inByte,1);
    }
  }
}


void inVarOutVarOpposite(int ms, int num_of_times, bool turn_right){
  ms = ms/2;
  int set_inBits[8]={0,0,0,0,1,1,1,1};
  int set_outBits[8]={0,0,0,0,1,1,1,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(16*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      if(i%2){outByte = rightRotate(outByte,1);}
      else{inByte = leftRotate(inByte,1);}
    }
    else{
      if(i%2){outByte = leftRotate(outByte,1);}
      else{inByte = rightRotate(inByte,1);}
    }
  }
}


void inVarOutVarOpposite2(int ms, int num_of_times, bool turn_right){
  ms = ms/2;
  int set_inBits[8]={1,1,1,1,0,0,0,0};
  int set_outBits[8]={0,0,0,0,1,1,1,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  for(int i=0;i<(16*num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      if(i%2){outByte = rightRotate(outByte,1);}
      else{inByte = leftRotate(inByte,1);}
    }
    else{
      if(i%2){outByte = leftRotate(outByte,1);}
      else{inByte = rightRotate(inByte,1);}
    }
  }
}


void inFullOutVar(int ms, int num_of_times, bool turn_right, int start_offset){
  int set_inBits[8]={1,1,1,1,1,1,1,1};
  int set_outBits[8]={1,1,1,1,0,0,0,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  outByte = rightRotate(outByte,start_offset);  
  for(int i=0;i<(num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte,1);
    }
    else{
      outByte = leftRotate(outByte,1);
    }
  }
}


void inVarOutFull(int ms, int num_of_times, bool turn_right, int start_offset){
  int set_inBits[8]={0,0,0,0,1,1,1,1};
  int set_outBits[8]={1,1,1,1,1,1,1,1};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  inByte = rightRotate(inByte,start_offset);
  for(int i=0;i<(num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      inByte = rightRotate(inByte,1);
    }
    else{
      inByte = leftRotate(inByte,1);
    }
  }
}


void outVar(int ms, int num_of_times, bool turn_right, int start_offset){
  int set_inBits[8]={0,0,0,0,0,0,0,0};
  int set_outBits[8]={1,1,1,1,0,0,0,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits); 
  outByte = rightRotate(outByte,start_offset);
  for(int i=0;i<(num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      outByte = rightRotate(outByte,1);
    }
    else{
      outByte = leftRotate(outByte,1);
    }
  }
}


void inVar(int ms, int num_of_times, bool turn_right, int start_offset){
  int set_inBits[8]={0,0,0,0,1,1,1,1};
  int set_outBits[8]={0,0,0,0,0,0,0,0};
  outByte = set_byte(set_outBits);
  inByte = set_byte(set_inBits);
  inByte = rightRotate(inByte,start_offset);
  for(int i=0;i<(num_of_times);i++){
    combinedByte = combineBytes(inByte,outByte);
    lightWires(combinedByte);
    delay(ms);
    if(turn_right){
      inByte = rightRotate(inByte,1);
    }
    else{
      inByte = leftRotate(inByte,1);
    }
  }
}

