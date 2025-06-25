#define PIR_SENSOR A0    // Pino do sensor PIR
#define BUZZER_PIN 7     // Pino do buzzer
#define LED_PIN 6        // Pino do LED
#define ALARM_DURATION 1000  // Duração do alarme em ms
#define TONE_FREQUENCY 1900  // Frequência do buzzer em Hz
#define BLINK_INTERVAL 500   // Intervalo de piscada do LED em ms

unsigned long alarmStartTime = 0;
bool alarmActive = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pirValue = analogRead(PIR_SENSOR);
  
  // Se detectar movimento e o alarme não estiver ativo
  if (pirValue > 0 && !alarmActive) {
    alarmActive = true;
    alarmStartTime = millis();
  }

  // Se o alarme estiver ativo
  if (alarmActive) {
    // Piscar LED e tocar buzzer
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - alarmStartTime;
    
    if (elapsedTime < ALARM_DURATION) {
      // Piscar o LED e tocar o buzzer
      if ((elapsedTime / BLINK_INTERVAL) % 2 == 0) {
        digitalWrite(LED_PIN, HIGH);
        tone(BUZZER_PIN, TONE_FREQUENCY);
      } else {
        digitalWrite(LED_PIN, LOW);
        noTone(BUZZER_PIN);
      }
    } else {
      // Desligar alarme após a duração definida
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);
      alarmActive = false;
    }
  }

  Serial.println(pirValue);
  delay(100); // Pequeno delay para estabilidade
}