//Transistions
void inVarOutVarFullLong(unsigned long ms, int num_of_times, bool turn_right){
  for(int i=0;i<num_of_times;i++){
    inFullOutVar(ms,8,turn_right, 4);
    inVarOutFull(ms,8,turn_right, 4); 
  }
}

void inVarOutVarLong(unsigned long ms, int num_of_times, bool turn_right){
  for(int i=0;i<num_of_times;i++){
    inVar(ms,8,turn_right, 0);
    outVar(ms,8,turn_right, 0); 
  }
}

void singleInOutToFull(unsigned long ms, int num_of_times, bool turn_right){
  inOutSingleSync(ms, num_of_times, turn_right);
  inOutDoubleSync(ms, num_of_times, turn_right);
  inOutTripleSync(ms, num_of_times, turn_right);
  allOn(ms);
}

void fullToSingleInOut(unsigned long ms, int num_of_times, bool turn_right){
  allOn(ms);
  inOutTripleSync(ms, num_of_times, turn_right);
  inOutDoubleSync(ms, num_of_times, turn_right);
  inOutSingleSync(ms, num_of_times, turn_right);
}

void fullSingleToFullSingle(unsigned long ms, int num_of_times, bool turn_right){
    inFullOutSingle(ms, num_of_times,turn_right);
    inFullOutVar(ms,3,turn_right,1);
    inVarOutFull(ms,3,turn_right,4);
    inSingleOutFull(ms,num_of_times,turn_right);
    inVarOutFull(ms,3,turn_right,1);
    inFullOutVar(ms,3,turn_right,4);
}


// --------------------PROGRAMS-------------------------------

void program1(int ms, int num_of_times, bool turn_right){
  for(int i=0; i<num_of_times; i++){
    inVarOutVarSync(ms, 3, turn_right, 0);
    singleInOutToFull(ms, 30, turn_right);
    inVarOutVarFullLong(ms, 10, turn_right);
    fullToSingleInOut(ms,30,turn_right);
  }
}



void program2(int ms, int num_of_times, bool turn_right){
  num_of_times = 1;
  for(int i=0; i<num_of_times; i++){
    inVar(ms, 4, turn_right, 0);
    for(int j=0; j<3;j++){
      fullSingleToFullSingle(ms,10,turn_right);
    }
    inFullOutSingle(ms,5,turn_right);
    inFullOutVar(ms,3,turn_right,1);
    inVarOutVarFullLong(ms, 10, turn_right);
    inVarOutFull(ms,3,turn_right,4);
    inSingleOutFull(ms,5,turn_right);
    outVar(ms,4,turn_right,4);
    inVarOutVarLong(ms,5,turn_right);
    inVar(ms, 4, turn_right, 0);
    for(int j=0; j<3;j++){
      fullSingleToFullSingle(ms,10,turn_right);
    }
    inFullOutSingle(ms,5,turn_right);
    inFullOutVar(ms,3,turn_right,1);
    inVarOutVarFullLong(ms, 5, turn_right);
    inVarOutFull(ms,3,turn_right,4);
    inSingleOutFull(ms,5,turn_right);
    outVar(ms,4,turn_right,4);  
  }
}

void program3(int ms, int num_of_times, bool turn_right){
  int end_ms = ms - (ms/2);
  int deacc = ms/20;
  for(int i = 0; i<num_of_times;i++){
    inVarOutVarSync(ms, 3, turn_right, 0);
    accelerateFunction(ms, deacc, end_ms, turn_right, inOutSingleSync );
    inOutSingleOpposite(end_ms, num_of_times*8, turn_right);
    inOutDoubleOpposite(end_ms, num_of_times*4, turn_right);
    turn_right = !turn_right;
    inOutDoubleOpposite(end_ms, num_of_times*4, turn_right);
    inOutSingleOpposite(end_ms, num_of_times*8, turn_right);
    decelerateFunction(end_ms, deacc, ms, turn_right, inOutSingleSync );
    inVarOutVarSync(ms, 3, turn_right, 5);
    allOn(3000);
  }
}

void program4(int ms, int num_of_times, bool turn_right){
  int end_ms = ms + (ms/2);
  int deacc = ms/20;
  for(int i = 0; i<num_of_times;i++){
    inVarOutVarSync(ms, 3, turn_right, 0);
    decelerateFunction(ms, deacc, end_ms, turn_right, inOutSingleSplit );
    inOutSingleSync(end_ms, num_of_times*2, turn_right);
    inOutDoubleSync(end_ms, num_of_times*4, turn_right);
    inOutDoubleOpposite2(end_ms, num_of_times*2, turn_right);
    turn_right = !turn_right;
    inOutDoubleOpposite2(end_ms, num_of_times*2, turn_right);
    inOutDoubleSync(end_ms, num_of_times*4, turn_right);
    inOutSingleSync(end_ms, num_of_times*2, turn_right);
    accelerateFunction(end_ms, deacc, ms, turn_right, inOutSingleSplit );
    inVarOutVarSync(ms, 3, turn_right, 5);
    allOn(3000);
  }
}

void program5(int ms, int num_of_times, bool turn_right){
  for(int i=0; i<num_of_times; i++){
    inVarOutVarSync(ms, 3, turn_right, 0);
    singleInOutToFull(ms, 20, turn_right);
    inOutTripleOpposite(ms, 20, turn_right);
    turn_right = !turn_right;
    fullToSingleInOut(ms,20,turn_right);
  }
}
