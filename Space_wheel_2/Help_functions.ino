//input array with 8 binary elements, return a byte in same order
byte set_byte(int bits[8]){
  byte OnOffByte = 0;
  for(int i=0; i<8;i++){
    if(bits[7-i]==1){
      OnOffByte = OnOffByte|(1<<i);
    }
  }
  return OnOffByte;
}

//bitwise OR operation of two bytes, masking in/out part (repeat pattern in four first and last bits of each byte for consistent rotation)
byte combineBytes(byte inner, byte outer){
  byte inner_mask = 240;
  byte outer_mask = 15;
  inner = inner & inner_mask;
  outer = outer & outer_mask;
  byte combined = inner | outer;
  return combined;
}

//Rotate all bits left by integer d
byte leftRotate(byte n, unsigned int d)
{
   return (n << d)|(n >> (8 - d));
}

//Rotate all bits right by integer d
byte rightRotate(byte n, unsigned int d)
{
   return (n >> d)|(n << (8 - d));
}

//write to outputs depending on 1/0 in byte
void lightWires(byte setByte){
  for(int i=0;i<8;i++){
    if(bitRead(setByte,i)==1){
      digitalWrite(pin_array[i],HIGH);
    }
    else{
      digitalWrite(pin_array[i],LOW);
    }
  }
}


//Function accelerating Basic Light Program Functions, taking start delay, acceleration, final delay, turn_boolean and a function as inputs
void accelerateFunction(int start_delay, int acc, int end_delay, bool right_turn, void (*programFunc)(int, int, bool) ){
  long start_t = start_delay*4;
  int repeats;
  if(start_delay>=end_delay && start_delay > 0 && end_delay > 0 && acc !=0){    
    for(start_delay; start_delay>=end_delay;start_delay=(start_delay-acc)){
      repeats = floor(start_t/(start_delay));
      (*programFunc)(start_delay,repeats,right_turn);
    }
  }
}

//Function decelerating Basic Light Program Functions, taking start delay, deceleration, final delay, turn_boolean and a function as inputs
void decelerateFunction(int start_delay, int dec, int end_delay, bool right_turn, void (*programFunc)(int, int, bool) ){
  long start_t = end_delay*4;
  int repeats;
  if(start_delay<=end_delay && start_delay > 0 && end_delay > 0 && dec !=0){    
    for(start_delay; start_delay<=end_delay;start_delay=(start_delay+dec)){
      repeats = floor(start_t/(start_delay));
      (*programFunc)(start_delay,repeats,right_turn);
    }
  }
}
