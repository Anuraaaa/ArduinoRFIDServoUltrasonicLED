#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

const int SS_PIN = 10; 
const int RST_PIN = 9; 
const int PIN_SERVO = 6;
const int TRIG_PIN = 3;
const int ECHO_PIN = 5;
const int LED_PIN = 2;

long waktu;
long jarak;

bool pintuKebuka = false;
int pos;

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myServo; 

String kartuTerdaftar[] = {
  "c36500a8"
};

void setup() {
  Serial.begin(9600);
  Serial.println("STATUS: Initalizing system ...");
  Serial.println("STATUS: Silahkan scan kartu...");
  SPI.begin();
  mfrc522.PCD_Init();
  myServo.attach(PIN_SERVO);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  waktu = pulseIn(ECHO_PIN, HIGH);
  jarak = (waktu*0.034)/2;
  checkCard(jarak);
  checkTutupPintu(jarak);
}

void checkTutupPintu(long jarak) {
 
  if (pintuKebuka && jarak > 0 && jarak <= 5) {
    digitalWrite(LED_PIN, LOW);
    Serial.println("STATUS: Menutup pintu...");
    if (pos >= 120) {
      for (pos = 120; pos >= 0; pos--) {
        myServo.write(pos);
        delay(10);
      }            
    }      
    Serial.println("STATUS: Berhasil menutup pintu.");
  }
}

void bukaPintu(long jarak) {

  if (pintuKebuka){
    digitalWrite(LED_PIN, HIGH);
    Serial.println("STATUS: Membuka pintu...");
      for (pos = 0; pos <= 120; pos++) {
      myServo.write(pos);
      delay(10);
    }  
    Serial.println("STATUS: Berhasil membuka pintu.");  
  }
}

void checkCard(long jarak) {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("STATUS: Kartu terdeteksi!");

    String cardUID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardUID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      cardUID += String(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.print("STATUS: CardUID is ");
    Serial.println(cardUID);

    for (int i = 0; i < sizeof(kartuTerdaftar) / sizeof(kartuTerdaftar[0]); i++) {
      if (cardUID == kartuTerdaftar[i]) {
        Serial.println("STATUS: Kartu terdaftar.");
        pintuKebuka = true;
        bukaPintu(jarak);
      }
      else {
        Serial.println("STATUS: Kartu tidak terdaftar pada sistem.");        
      }      
    }
  }  
}
