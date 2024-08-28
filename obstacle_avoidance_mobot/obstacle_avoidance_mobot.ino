const int motor_A_forward  = 5;  
const int motor_A_reverse  = 6;  

const int motor_B_forward  = 9; 
const int motor_B_reverse  = 10;  

const int right_sensor_trig = A0;
const int right_sensor_echo = A1;

const int left_sensor_trig = A4;
const int left_sensor_echo = A5;

const int middle_sensor_trig = A2;
const int middle_sensor_echo = A3;

const int r_led = 8;
const int m_led = 11;
const int l_led = 12;

//change these values for calibration, also change the delays 

const int obs = 7;
const int max_speed = 150;
const int min_speed = 120;

//motor_A is left
//motor_B is right

void setup(){
    Serial.begin(9600);

    pinMode(right_sensor_trig, OUTPUT);
	  pinMode(left_sensor_trig, OUTPUT);
    pinMode(middle_sensor_trig, OUTPUT);
  
    pinMode(right_sensor_echo, INPUT);
	  pinMode(left_sensor_echo, INPUT);
    pinMode(middle_sensor_echo, INPUT);

  	pinMode(motor_A_forward, OUTPUT);
    pinMode(motor_A_reverse, OUTPUT);
    pinMode(motor_B_forward, OUTPUT);
    pinMode(motor_B_reverse, OUTPUT);
  
  	analogWrite(motor_A_forward, 0);
  	analogWrite(motor_A_reverse, 0);
    analogWrite(motor_B_forward, 0);
  	analogWrite(motor_B_reverse, 0);

    pinMode(m_led, OUTPUT);
    pinMode(r_led, OUTPUT);
    pinMode(l_led, OUTPUT);
}

void loop(){

	  Serial.print("r_rdg: ");
    Serial.println(rdist());
  	Serial.print("l_rdg: ");
    Serial.println(ldist());
	  Serial.print("m_rdg: ");
	  Serial.println(mdist());
  	Serial.write(10);
      
    if (mdist()>obs && rdist()>obs && ldist()>obs) {
      // no obs
      forward();
    }
    else if (mdist()< obs && rdist()<obs && ldist()<obs) {
      // obs on all sides
      reverse();
    }
    else if (mdist()<obs && rdist()<obs && ldist()>obs) {
      // obs on right & mid
      left(); // turn left 
    }
    else if (mdist()<obs && rdist()>obs && ldist()<obs) {
      // obs on left & mid 
      right(); // turn right 
    }
    else  if (mdist()<obs && rdist()>obs && ldist()>obs) {
      // obs on mid 
      left(); // turn left but can change to right depending on maze
      delay(500);
      stop();
    }
    else if (mdist()>obs && rdist()>obs  && ldist()<obs) {
      // obs on left 
      right(); // turn right then stop to check for obs
      delay(500);
      stop();
    }
    else if (mdist()>obs && rdist()<obs && ldist()>obs) {
      // obs on right 
      left(); // turn left 
      delay(500);
      stop();
    }
    else {
      forward();
    }
}

void left() {
    analogWrite(motor_A_forward, min_speed);
    analogWrite(motor_A_reverse, 0);
    analogWrite(motor_B_forward, 0);
    analogWrite(motor_B_reverse, max_speed);
    Serial.println("go left");
    digitalWrite(r_led, HIGH);
    digitalWrite(m_led, LOW);
    digitalWrite(l_led, LOW);
}

void right() {
    analogWrite(motor_A_forward, 0);
    analogWrite(motor_A_reverse, max_speed);
    analogWrite(motor_B_forward, min_speed);
    analogWrite(motor_B_reverse, 0);
    Serial.println("go right");
    digitalWrite(l_led, HIGH);
    digitalWrite(m_led, LOW);
    digitalWrite(r_led, LOW);
}

void stop() {
    analogWrite(motor_A_forward, 0);
    analogWrite(motor_A_reverse, 0);
    analogWrite(motor_B_forward, 0);
    analogWrite(motor_B_reverse, 0);
    Serial.println("stop");
    digitalWrite(m_led, LOW);
    digitalWrite(l_led, LOW);
    digitalWrite(r_led, LOW);
}
void forward() {
    analogWrite(motor_A_forward, min_speed);
    analogWrite(motor_A_reverse, 0);
    analogWrite(motor_B_forward, min_speed);
    analogWrite(motor_B_reverse, 0);
    Serial.println("go forward");
    digitalWrite(m_led, HIGH);
    digitalWrite(l_led, LOW);
    digitalWrite(r_led, LOW);
}

void reverse() {
    analogWrite(motor_A_forward, 0);
    analogWrite(motor_A_reverse, max_speed);
    analogWrite(motor_B_forward, 0);
    analogWrite(motor_B_reverse, max_speed);
    Serial.println("go back");
    digitalWrite(m_led, HIGH);
    digitalWrite(l_led, HIGH);
    digitalWrite(r_led, HIGH);
}

long mdist () {
    digitalWrite(middle_sensor_trig, LOW);
    delayMicroseconds(2);	
    digitalWrite(middle_sensor_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(middle_sensor_trig, LOW);
    
    float middle_duration = pulseIn(middle_sensor_echo, HIGH);
    float middle_distance = middle_duration / 58;
    return (middle_distance);
}

long rdist () {
    digitalWrite(right_sensor_trig, LOW);
    delayMicroseconds(2);	
    digitalWrite(right_sensor_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(right_sensor_trig, LOW);

    float right_duration = pulseIn(right_sensor_echo, HIGH);
    float right_distance = right_duration / 58;
    return(right_distance);
}

long ldist () {
    digitalWrite(left_sensor_trig, LOW);
    delayMicroseconds(2);	
    digitalWrite(left_sensor_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(left_sensor_trig, LOW);
      
    float left_duration = pulseIn(left_sensor_echo, HIGH);
    float left_distance = left_duration / 58;  
    return (left_distance);
}