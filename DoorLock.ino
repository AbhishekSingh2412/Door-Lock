void loop()
{

  // Identify fingerprint test
  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    if (id <200)
    {
      Serial.print("Verified ID:");
      Serial.println(id);
    }
    else
    {
      Serial.println("Finger not found");
    }
  }
  else
  {
    Serial.println("Please press finger");
    if(Serial.available())
{
  while(Serial.available())
    {
      // reading the input
      String inputChar = Serial.readString();
      // Appending Char to Form String of Characters.
      inputString += inputChar;       
    }

    Serial.println(inputString);

    if(inputString == pwd)
    {
      // Setting LED To OFF.
      digitalWrite(relay, LOW);
      delay(800);  
      digitalWrite(relay,HIGH);
    }
    else {}
    while (Serial.available() > 0) 
    {
      // clearing serial buffer if any.
      removeChar = Serial.readString() ;
    }     

    inputString = "";
}
  }
  delay(5);
}
