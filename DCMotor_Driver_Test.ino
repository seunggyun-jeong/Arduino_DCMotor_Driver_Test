const int REAR_BA = 3;
const int REAR_BB = 4; //후륜 우측
const int REAR_AA = 6;
const int REAR_AB = 7; //후륜 좌측

const int FRONT_BA = 8;
const int FRONT_BB = 9; //전륜 우측 
const int FRONT_AA = 11;
const int FRONT_AB = 12; //전륜 좌측


void setup() {
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
  digitalWrite(FRONT_BA, LOW);
  digitalWrite(FRONT_BB, HIGH);
  
  digitalWrite(FRONT_AA, HIGH);
  digitalWrite(FRONT_AB, LOW);
  
  digitalWrite(REAR_BA, LOW);
  digitalWrite(REAR_BB, HIGH);
  
  digitalWrite(REAR_AA, HIGH);
  digitalWrite(REAR_AB, LOW);
}
