const int buzzer = 10;
int photocellPin = A0;

const float songSpeed = 1.0;

#define C5 523
#define Db5 554
#define D5 587
#define Eb5 622
#define E5 659
#define F5 698
#define Gb5 740
#define G5 784
#define Ab5 831
#define Bb5 932

int notes[] = {
  Eb5, F5, Eb5, 0, Eb5, F5, G5, F5, Eb5, 0, Eb5, //vivir asi es morir de amor
  0,
  Eb5, F5, Gb5, Gb5, F5, Gb5, F5, Ab5, Eb5, // por amor tengo el alma herida
  0,
  Eb5, F5, Gb5, //por amoooor
  0,
  E5, Eb5, Db5, Eb5, E5, Eb5, E5, Ab5, Ab5, Eb5, // no quiero mas vida que su vida
  0,
  Eb5, Ab5, Bb5, Ab5, G5 //melancolia
    };

int durations[] = {
  300, 1000, 250, 100, 500, 300, 300, 1000, 100, 250, 1000,
  1000,
  250, 300, 300, 300, 300, 200, 350, 1000, 
  1000,
  300, 250, 500,
  1000,
  300, 250, 300, 300, 250, 300, 350, 350, 500, 700,
  500,
  300, 350, 300, 600, 500
    };

void setup()
{pinMode(photocellPin, INPUT);
}

void loop()
{ const int totalNotes = sizeof(notes) / sizeof(int);
 int photocellValue = analogRead(photocellPin);
 Serial.println(photocellValue);
 
 if (photocellValue > 50){
    for (int i = 0; i < totalNotes; i++)
  {
    const int currentNote = notes[i];
    float wait = durations[i] / songSpeed;
    // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
    if (currentNote != 0)
    {
      tone(buzzer, notes[i], wait); // tone(pin, frequency, duration)
    }
    else
    {
      noTone(buzzer);
    }
    // delay is used to wait for tone to finish playing before moving to next loop
    delay(wait);
  }
  }
}