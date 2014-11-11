/*  An electric Dice.
 // (c) 2014/10/22 Akio Fujimoto.
 // Dice lighting assignment.
 ##  2  3  4
 ##     5   
 ##  6  7  8 
 
 DiceNumber   ->   LED to be turned on
 0            ->    none
 1            ->    5
 2            ->    2, 8  ||  4, 6
 3            ->    4, 5, 6  ||  2, 5, 8
 4            ->    2, 4, 6, 8
 5            ->    2, 4, 6, 8, 5
 6            ->    2, 3, 4, 6, 7, 8
 
 */

int debug = 13;
// input pin is 12.
/*  pinDef[int x] value :=
 // 0 := use this pin as INPUT. (w/o input pull-up.)
 // 1 := use this pin as OUTPUT.
 // 2 := use this pin as INPUT. (w/ internal input pull-up registor enabled.)
 // 3 := don't care for this pin. (pinMode() will be not called.)
 // otherwise := not impremented.
 */
int pinDef[14] = {
  //  3, 3, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 1, 0};
  3, 3, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 0, 1};
const int startPin = 0;
int buttonState = 0;
int oldState = 0;
int inPin = 12;
int transTime = 200;  // dice transition duration time in ms.
int finalTime = 5000;  // final dice display duration time in ms. 

void setup() {
  // put your setup code here, to run once:
  for(int i=startPin; i<=13; i++){
    if(pinDef[i] == 0){
      pinMode(i, INPUT);

    }
    else if(pinDef[i] == 1){
      pinMode(i, OUTPUT);
    }
    else if(pinDef[i] == 2){
      pinMode(i, INPUT);
      digitalWrite(i, HIGH);  // input pullup.
    }
    else{
      // do nothing for this pin [i]. 
    } 
  }  // pinMode declaration ends.
  Serial.begin(9600);
  randomSeed(analogRead(A0));  // set random seed with analog port's noise.
}  // setup ends.

void loop() {
  // put your main code here, to run repeatedly: 
  for (int j=startPin; j<=13; j++){
    Serial.print(pinDef[j]);
    Serial.print(" ");
  }
  Serial.println();

  for(int i=2;i<=8;i++){
    digitalWrite(i, LOW);
  }
  buttonState = digitalRead(inPin);
  Serial.println(digitalRead(inPin));
  delay(20);

  if(buttonState == HIGH && oldState == LOW) {
    delay(20);
    oldState = buttonState;
    dicePick();
  }
  oldState = buttonState;
  //  cnt++;
  //  digitalWrite(cnt%7 + 1);
  //  delay(transTime); // key input prompt.
  diceErase();

}

void dicePick(){
  // when trigger button has been pushed...
  for (int i=0; i<=10; i++){
    dice((int)(random(6)+1));
    delay(transTime + i*20);
    allLow();
  }
  delay(transTime * 3);
  for(int i=2;i<=8;i++){
    digitalWrite(i, LOW);
    Serial.println((random(6)+1));
  }
  static int x;
  x = (int)(random(6)+1);
  if (x==0)x++;
  dice(x);
  delay(finalTime);
  allLow();
}

void diceErase(){
  for(int i=2;i<=8;i++){
    digitalWrite(i, LOW);
    //    Serial.println((random(6)+1));
  }
}
void allLow(){
  for(int i=0;i<=13;i++){
    digitalWrite(i, LOW);
  }
}
void dice(int x){
  switch(x){
  case 0:
    dice((int)(random(6)+1));
    break;
  case 1:
    digitalWrite(5, HIGH);
    break;
  case 2:
    digitalWrite(2, HIGH);
    digitalWrite(8, HIGH);
    break;
  case 3:
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    break;
  case 4:
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    break;
  case 5:
    digitalWrite(5, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    break;
  case 6:
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    break;
  default:
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    break;
  }
}

