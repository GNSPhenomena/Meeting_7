const int echoPin = 7;
const int trigPin = 8;

void setup()
{ 
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long findDistance()
{
	long duration,distance;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = (duration/2) / 29.1;
	return distance;
}

void loop()
{
  //ultrasonic
  long dis = findDistance();
  Serial.print("Distance: ");
  Serial.println(dis);
}
