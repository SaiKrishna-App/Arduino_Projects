int RED = 13;
int YELLOW = 12;
int GREEN = 8;
int RED1 = 6;
int YELLOW1 = 5;
int GREEN1 = 4;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(RED1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(GREEN1, OUTPUT);
}

void loop()
{
  digitalWrite(RED, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(GREEN, LOW);
  
  digitalWrite(RED1, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(RED1, LOW);
  digitalWrite(YELLOW1, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(YELLOW1, LOW);
  digitalWrite(GREEN1, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(GREEN1, LOW);
 

}
