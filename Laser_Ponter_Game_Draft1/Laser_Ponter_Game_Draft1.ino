
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
const int led5 = 12;
const int led6 = 13;
const int sensorPin = 0;

void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  Serial.begin(9600);
}

int count=0;
int incrementMultiplier=25; //sets number of cycles of lazer light exposure needed for LED response (sensitivity)

void loop(){
  int sensorvalue = analogRead(sensorPin); //read voltage resulting from photosensor light exposure
  Serial.println(sensorvalue);
  
  if(sensorvalue > 300) //if lazer on photoresistor
    count++;            //increase counter
    
  if(count == incrementMultiplier)
    digitalWrite(led1, HIGH);
  if(count == 2*incrementMultiplier)
    digitalWrite(led2, HIGH);
  if(count == 3*incrementMultiplier)
    digitalWrite(led3, HIGH);    
  if(count == 4*incrementMultiplier)
    digitalWrite(led4, HIGH);
  if(count == 5*incrementMultiplier)
    digitalWrite(led5, HIGH);
  if(count == 6*incrementMultiplier)
    digitalWrite(led6, HIGH);
  if(count > 7*incrementMultiplier){
    while(1){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
      digitalWrite(led6, HIGH);
      
      delay (100); // this delay is doesn't matter because 100 is an mili second of 1 second .
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, LOW);
      
       delay (100);
      
      // i little bit change in code in comment if you like than change 
//       digitalWrite(led1, LOW);
//       digitalWrite(led2, HIGH);
//       digitalWrite(led3, LOW);
//       digitalWrite(led4, HIGH);
//       digitalWrite(led5, LOW);
//       digitalWrite(led6, HIGH);
      
//       delay (1000); 
      
//       digitalWrite(led1, HIGH);
//       digitalWrite(led2, LOW);
//       digitalWrite(led3, HIGH);
//       digitalWrite(led4, LOW);
//       digitalWrite(led5, HIGH);
//       digitalWrite(led6, LOW);
      
//        delay (1000);
    }
    
  }
  
}
