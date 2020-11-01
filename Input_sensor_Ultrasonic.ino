const int pingPin = 7; //Pin Trigger Sensor Ultrasonic
const int echoPin = 6; //Pin Echo Sensor Ultrasonic
const int ledPin = 13; //LED

void setup ()
{
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(ledPin, OUTPUT) ;
}

void loop ()
{
  long duration;//variable duration untuk menyimpan lama waktu saat
  //sensor memancarkan gelombang ultrasonik sampai memantul pada benda
  //dan diterima kembali oleh echoPin (pin 6)dalam satuan microsecond
  long cm;//variabel untuk menyimpan hasil konversi dari Us ke cm
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  pinMode (echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  //pemanggilan fungsi microsecondsToCentimeters
  if (cm <= 200)
  {
    digitalWrite(ledPin, HIGH);
  }
  else if (cm >= 200)
  {
    digitalWrite(ledPin, LOW);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}
  //fungsi untuk mengubah dari mikrosecond ke cm
  long microsecondsToCentimeters (long microseconds)
{
  return microseconds*0.034/2;//konversi dari microseconds ke cm
}
