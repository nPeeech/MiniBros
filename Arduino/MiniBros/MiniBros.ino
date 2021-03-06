#define PWMA 9
#define A2 8
#define A1 7
#define B1 14
#define B2 16
#define PWMB 10
//#define Serial1 Serial

//right motor: B
//left motor: A

void setup() {
  Serial1.begin(9600);
  pinMode(PWMA, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}

void loop() {
  char c;
  if(Serial1.available()){
    c = Serial1.read();
    switch(c){
      case 'a':
        //前進
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
        digitalWrite(B1, HIGH);
        digitalWrite(B2, LOW);
        Serial1.println("go_straight");
        break;
      case 'b':
        //後退
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
        digitalWrite(B1, LOW);
        digitalWrite(B2, HIGH);
        Serial1.println("go_back");
        break;
      case 'c':
        //右旋回
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
        digitalWrite(B1, LOW);
        digitalWrite(B2, HIGH);
        Serial1.println("turn_right");
        break;
      case 'd':
        //左旋回
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
        digitalWrite(B1, HIGH);
        digitalWrite(B2, LOW);
        Serial1.println("turn_left");
        break;
      case 'e':
        //移動停止（ショートブレーキ）
        digitalWrite(A1, HIGH);
        digitalWrite(A2, HIGH);
        digitalWrite(B1, HIGH);
        digitalWrite(B2, HIGH);
        Serial1.println("stop");
        break;
      default:
        Serial1.println(c);
    }
  }
}
