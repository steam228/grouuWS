
// portas
#define ledPin 13
#define moistSens A0

//variaveis
int valor = 0;
int Max = 0;
int Min = 1023;

const int nTeste = 30;


void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.println ("Vai Calibrar");
  delay(5000);
  calib();
  delay(5000);
  Serial.println ("Já Calibrou");


}


void loop() {

  valor = analogRead(moistSens);
  valor = map(valor, Min, Max, 0, 100);
  if (valor < 20) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);
  Serial.println(valor);
  delay(1);        // delay in between reads for stability
}

void calib() {
  Serial.println ("calibraMIN");
  delay(1000);
  for (int i = 0; i < nTeste; i++) {

    valor = analogRead(moistSens);
    if (valor < Min) {
      Min = valor;
    }

    Serial.print (Min);
    Serial.print (" | " );
    Serial.println (valor);
    delay(10);
  }
  delay(1000);
  Serial.println ("calibraMAX");
  delay(1000);

  for (int j = 0; j < nTeste; j++) {

    valor = analogRead(moistSens);

    if (valor > Max) {
      Max = valor;
    }

    Serial.print(Max);
    Serial.print (" | " );
    Serial.println (valor);
    delay(10);
  }

}
