int po_w(int base,int power){
  int output = 1;
  for(int i=0;i<power;i++){
    output *= base;
  }
  return output;
}