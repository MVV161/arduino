#ifndef SHIFTREGISTER595_H
#define SHIFTREGISTER595_H

class ShiftRegister595
{
	public:
		ShiftRegister595( byte userLatchPin, byte userClockPin, byte userDataPin );	
		
		void buffer(byte out);
		 void write();
		void write(byte out);
			
	private:
		void shiftOut(byte out);
		byte latchPin;
		byte clockPin;
		byte dataPin;
		byte bufferByte;
};
ShiftRegister595::ShiftRegister595( byte userLatchPin, byte userClockPin, byte userDataPin ){
  latchPin  = userLatchPin;
  clockPin  = userClockPin;
  dataPin = userDataPin;
  bufferByte = 0;
}

void ShiftRegister595::buffer(byte out){
  bufferByte = out;
}

void ShiftRegister595::write(){
  digitalWrite(latchPin, LOW);
  shiftOut(bufferByte);   
  digitalWrite(latchPin, HIGH);
}

void ShiftRegister595::write(byte out){
  digitalWrite(latchPin, LOW);
  shiftOut(out);   
  digitalWrite(latchPin, HIGH);
}

void ShiftRegister595::shiftOut(byte out){
  bool pinState = false;
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  for (byte i=7; i>=0; i--)  {
    digitalWrite(clockPin, LOW);
    if ( out & (1<<i) ) {
      pinState= true;
    }
    else {  
      pinState= false;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
    digitalWrite(dataPin, LOW);
  }
  digitalWrite(clockPin, LOW);
}
#endif

