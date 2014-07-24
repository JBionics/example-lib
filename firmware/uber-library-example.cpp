// NOTE/NUANCE: When including WITHIN a library, no sub-dir prefix is needed.
#include "uber-library-example.h"

// Constructor
JBPin::JBPin(int _number)
{
  number = _number;
  state = LOW;
}

// Initializers that should be called in the `setup()` function
void JBPin::beginInPinMode(PinMode _pinMode)
{
  pinMode(number, _pinMode); 
}

// Main API functions that the library provides
// typically called in `loop()` or `setup()` functions
void JBPin::modulateAtFrequency(int _ms)
{
  setHigh();
  delay(_ms);
  setLow();
  delay(_ms);
}

// Getters
int JBPin::getNumber()
{
  return number;
}
bool JBPin::getState()
{
  return state;
}
bool JBPin::getMode()
{
  return mode;
}
bool JBPin::isHigh()
{
  return state == HIGH ? true : false;
}

// Setters
void JBPin::setHigh()
{
  state = HIGH;
  setActualPinState();
}
void JBPin::setLow()
{
  state = LOW;
  setActualPinState();
}
void JBPin::setActualPinState()
{
  digitalWrite(number, state);
}
