# Arduino RFID Servo Ultrasonic LED


## Komponen:

- Arduino Uno
- BreadBoard
- Motor Servo
- RFID RC522
- Kabel Jumper Male & Female
- Sensor Ultrasonic
- LED
- USB Kabel Uno

## Wiring
- RFID RC522: 
	- 3.3 RFID RC522 -> 3.3V Arduino Uno
	- GND RFID RC522 -> GND Arduino Uno
	- RST RFID RC522 -> PIN 9 Arduino Uno
	- SDA RFID RC522 -> PIN 10 Arduino Uno
	- MOSI RFID RC522 -> PIN 11 Arduino Uno
	- MISO RFID RC522 -> PIN 12 Arduino Uno
	- SCK RFID RC522 -> PIN 13 Arduino Uno
- Servo:
	- GND Servo -> GND Arduino Uno
	- POWER Servo -> 5V Arduino Uno
	- SIGNAL Servo -> PIN 6 Arduino Uno
- Ultrasonic:
	- GND Ultrasonic -> GND Arduino Uno
	- VCC Ultrasonic -> 5V Arduino Uno
	- TRIG Ultrasonic -> PIN 3 Arduino Uno
	- ECHO Ultrasonic -> PIN 5 Arduino Uno
- LED:
	- GND LED -> GND Arduino Uno
	- PIN LED -> PIN 2 Arduino Uno with Resistor 220 Ohm

## Algoritma:
	- Kartu dapat dicek terdaftar atau tidak
	- Jika kartu terdaftar, maka akan memutar servo
	- Jika kartu tidak terdaftar tidak akan memutar servo
	- Jika kartu berhasil discan, maka statusnya akan membuka pintu lalu memutar servo serta menyalakan LED
	- Jika objek terdeteksi sensor ultrasonic dan sudah scan kartu / pintu terbuka, maka pintu akan tertutup lalu memutar servo dan mematikan LED

## Usable Pin:
	- Pin Servo PIN_SERVO: 6
	- Pin Slave Select RFID SS_PIN: 10
	- Pin Reset RFID RST_PIN: 9
	- Pin Ultrasonic TRIG_PIN: 3
	- Pin Ultrasonic ECHO_PIN: 5
	- Pin LED LED_PIN: 2