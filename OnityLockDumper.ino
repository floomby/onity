//#define USE_SERIAL

int ioPin = 3;
#define BUFSIZE 200
unsigned char buf[BUFSIZE];

#define pullLow() pinMode(ioPin, OUTPUT)
#define pullHigh() pinMode(ioPin, INPUT)

unsigned char dbits[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1};
unsigned char bits[][144] = {
  {
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    1, 0, 1, 0, 0, 0, 1, 0, 
    0, 1, 

    1, 0, 0, 0, 1, 0, 0, 0, 1, 
    1, 0, 1, 0, 0, 1, 0, 1, 1, 
    1, 1, 0, 0, 0, 0, 1, 1, 1, 
    0, 0, 0, 1, 1, 1, 0, 1, 1,

    1, 1, 1, 1, 1, 1, 1, 1, 
    0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0
  }, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0}
};

int A, B, C;
unsigned char Ac[8], Bc[8], Cc[8];

unsigned char bval;

void bitConv(int n, unsigned char *out)
{
  for(int i = sizeof(n)*8-1; i >= 0; i --)
    *(out+i) = (n&(1<<i))>>i;
}

void wentLow()
{
  bval = 1;
}

void setup()
{
  A = B = C = 0;
#ifdef USE_SERIAL
  Serial.begin(9600);
#endif

  pinMode(ioPin, OUTPUT);
  digitalWrite(ioPin, LOW);
  pinMode(ioPin, INPUT);
  digitalWrite(ioPin, LOW);
}

int temp;

void open()
{  
  bitConv(A, Ac);
  bitConv(B, Bc);
  bitConv(C, Cc);
  for(int i = 0; i < 76; i++) {
    if(i <= 50){
      temp = dbits[i];
    }
    else if(i > 50 && i <= 58){
      temp = Ac[i-51];
    }
    else if(i > 59 && i <= 67){
      temp = Bc[i-60];
    }
    else if(i > 68 && i <= 76){
      temp = Cc[i-69];
    }
    else{
     temp = 1; 
    }
      if(temp == 0) {
        pullLow();
        delayMicroseconds(16);
        pullHigh();
        delayMicroseconds(190);
      } else {
        pullLow();
        delayMicroseconds(16);
        pullHigh();
        delayMicroseconds(56);
        pullLow();
        delayMicroseconds(16);
        pullHigh();
        delayMicroseconds(112);
      }
    
  }

  pullLow();
  delayMicroseconds(16);
  pullHigh();

  bval = 0;
  attachInterrupt(1, wentLow, FALLING);

  unsigned int i = 0;
  while(digitalRead(ioPin) == HIGH && i++ < 32767) {}
  if(i == 32767)
    return;

  delayMicroseconds(20);
  for(int i = 0; i < 164; ++i) {
    buf[i] = 0;
    pullLow();
    delayMicroseconds(8);
    pullHigh();
    bval = 0;
    delayMicroseconds(184);
    buf[i] = bval;
  }
  for(int i = 0; i < 32+3; ++i)
    bits[0][50+i] = buf[22+i];

  for(int i = 0; i < 8; ++i)
    bits[0][86+i] = bits[0][50+i] ^ bits[0][50+9+i] ^ bits[0][50+18+i] ^ bits[0][50+27+i];
  bits[0][86] ^= 1;
  bits[0][87] ^= 0;
  bits[0][88] ^= 1;
  bits[0][89] ^= 1;
  bits[0][90] ^= 1;
  bits[0][91] ^= 0;
  bits[0][92] ^= 1;
  bits[0][93] ^= 1;


  delay(100);

#ifdef USE_SERIAL
  for(int j = 0; j < 11; ++j) {
    for(int i = 0; i < sizeof(bits[j]); ++i) {
      Serial.print(bits[j][i]);
    }
    Serial.println();
  }
#endif //USE_SERIAL
}

void loop(){
    open();
    if(A < 255){
      A++;
    }
    else{
      A = 0;
      B++;
    }
    C = A ^ B ^ 0x1D;
}
