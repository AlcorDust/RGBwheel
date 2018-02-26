// AlcorDust code
// Pilotare un LED rgb modificando l'angolo
// della ruota dei colori (vedi immagine allegata)

int redPin=11;      
int greenPin=10;
int bluePin=9;

int angle;
int startAngle=0;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  delay(500);
}

void loop(){
          
  //Va dall'angolo di partenza a 359
  for(angle=startAngle;angle<360;angle++){
    color(redPin, greenPin, bluePin, angle);   
    delay(20);
  }
  
  //Va da 359 all'angolo di partenza
  for(angle=0;angle<startAngle;angle++){
    color(redPin, greenPin, bluePin, angle); 
    delay(20);
  }
  
  //Spegni tutto per un secondo
  noColor(redPin, greenPin, bluePin); 
  delay(1000);
}


//Funzioni utilizzate 

int R(int angle){
  
  if((angle>=0&&angle<60) || (angle>=300&&angle<360)){
    return 255;
  }
  if(angle>=60&&angle<120){
    return -(255./60.)*angle+255*2;
  }
  if(angle>=120&&angle<240){
    return 0;
  }
  if(angle>=240&&angle<300){
    return (255./60.)*angle-255*4;
  }
}

int G(int angle){
  if(angle>=0&&angle<60){
    return (255./60.)*angle;
  }
  if(angle>=60&&angle<180){
    return 255;
  }
  if(angle>=180&&angle<240){
    return -(255./60.)*angle+255*4;
  }
  if(angle>=240&&angle<=360){
    return 0;
  }
}

int B(int angle){
  if(angle>=0&&angle<120){
    return 0;
  }
  if(angle>=120&&angle<180){
    return (255./60.)*angle-255*2;
  }
  if(angle>=180&&angle<300){
    return 255;
  }
  if(angle>=300&&angle<=360){
    return -(255./60.)*angle+255*6;
  }
}     

void color(int redPin, int greenPin, int bluePin, int angle){
    analogWrite(redPin, R(angle));
    analogWrite(greenPin, G(angle));
    analogWrite(bluePin, B(angle));
}

void noColor(int redPin, int greenPin, int bluePin){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}
