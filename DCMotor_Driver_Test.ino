const int REAR_BA = 3;
const int REAR_BB = 4; //후륜 우측
const int REAR_AA = 6;
const int REAR_AB = 7; //후륜 좌측

const int FRONT_BA = 8;
const int FRONT_BB = 9; //전륜 우측 
const int FRONT_AA = 11;
const int FRONT_AB = 12; //전륜 좌측

const int STICK_X = 0;
const int STICK_Y = 1;
const int STICK_Z = 2;

int val_X = 0;
int val_Y = 0;
int val_Z = 0;

int velocity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(FRONT_BA, OUTPUT);
  pinMode(FRONT_BB, OUTPUT); //후륜 우측
  
  pinMode(FRONT_AA, OUTPUT);
  pinMode(FRONT_AB, OUTPUT); //후륜 좌측
  
  pinMode(REAR_BA, OUTPUT);
  pinMode(REAR_BB, OUTPUT); //전륜 우측
  
  pinMode(REAR_AA, OUTPUT);
  pinMode(REAR_AB, OUTPUT); //전륜 좌측

}

void loop() {
  val_X = analogRead(STICK_X); 
  val_Y = analogRead(STICK_Y); 
  val_Z = analogRead(STICK_Z); //조이스틱에서 값을 받아오는 함수
  
  if(val_Y>635){ //조이스틱이 Y좌표로 값이 커졌을 때 전진
    velocity = map(val_Y, 636, 1023, 0, 255);
    go_forward(velocity);
    Serial.println("GO");
  }
  else if(val_Y<528){ //조이스틱이 Y좌표로 값이 작아졌을 때 후진
    velocity=map(val_Y,527,0,0,255);
    go_back(velocity);
    Serial.println("BACK");
  }
  else{
    brake();
  }

  Serial.println(val_Y);
  
}

void go_forward(int rate){ //전진 명령 함수
  analogWrite(FRONT_BA, 0);
  analogWrite(FRONT_BB, rate);
  
  analogWrite(FRONT_AA, rate);
  analogWrite(FRONT_AB, 0);
  
  analogWrite(REAR_BA, 0);
  analogWrite(REAR_BB, rate);
  
  analogWrite(REAR_AA, rate);
  analogWrite(REAR_AB, 0);
}

void go_back(int rate){ //후진 명령 함수
  analogWrite(FRONT_BA, rate);
  analogWrite(FRONT_BB, LOW);
  
  analogWrite(FRONT_AA, LOW);
  analogWrite(FRONT_AB, rate);
  
  analogWrite(REAR_BA, rate);
  analogWrite(REAR_BB, LOW);
  
  analogWrite(REAR_AA, LOW);
  analogWrite(REAR_AB, rate);
}

void brake(){ //정지 함수
  digitalWrite(FRONT_BA, HIGH);
  digitalWrite(FRONT_BB, HIGH);
  
  digitalWrite(FRONT_AA, HIGH);
  digitalWrite(FRONT_AB, HIGH);
  
  digitalWrite(REAR_BA, HIGH);
  digitalWrite(REAR_BB, HIGH);
  
  digitalWrite(REAR_AA, HIGH);
  digitalWrite(REAR_AB, HIGH);
}
