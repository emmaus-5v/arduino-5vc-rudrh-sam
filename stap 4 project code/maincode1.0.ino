#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int knopGeel = 13;
int knopBlauw = 12;
int knopGroen = 11;
int knopRood = 10;
int knopWit = 9;

int ledGeel = 8;
int ledGroen = 6;
int ledRood = 7;
int ledBlauw = 5;

int knopStatusGeel = LOW;
int knopStatusBlauw = LOW;
int knopStatusGroen = LOW;
int knopStatusRood = LOW;
int knopStatusWit = LOW;

int ledStatusGeel = LOW;
int ledStatusBlauw = LOW;
int ledStatusGroen = LOW;
int ledStatusRood = LOW;

int positieSpelerX = 0;
int positieSpelerY = 0;

int positieSpelerBovenY = 0;
int positieSpelerOnderY = 1;

int positieRechthoekX = 16;
int positieRechthoekY = random(2);

int positieVierkantX = 22;
int positieVierkantBovenY = 0;
int positieVierkantOnderY = 1;

int positieGroteRechthoekX = 28;
int positieGroteRechthoekBovenY = 0;
int positieGroteRechthoekOnderY = 1;

int positieDriehoekX = 34;
int positieDriehoekBovenY = 0;
int positieDriehoekOnderY = 1;

int positieVijandX = 40;
int positieVijandBovenY = 0;
int positieVijandOnderY = 1;

int positieRandom[6] = {16, 20, 24, 28, 32, 36};

unsigned long tijd = 0;
unsigned long tijdNu = 0;
unsigned long tijdAftelling = 0;
unsigned long tijdPagina = 0;
unsigned long tijdGameMode = 0;


const int STARTSCHERM = 0;
const int REGELPAGINA1 = 1;
const int REGELPAGINA2 = 2;
const int REGELPAGINA3 = 3;
const int REGELPAGINA4 = 4;
const int REGELPAGINA5 = 5;
const int HERHALING = 6;
const int GAMEMODE = 7;
const int SPELLADING = 8;
const int SPELEN = 9;
const int OBSTAKEL = 10;
const int GAMEOVER = 11;
int gameStatus = STARTSCHERM;

const int EASY = 0;
const int NORMAL = 1;
const int HARD = 2;
int gameModeStatus = EASY;

float score = 0;

int aftelling = 11;

int regelPagina = 0;

int gameMode = 0;

const int uitKnopLos = 0;
const int uitKnopIn = 1;
const int aanKnopIn = 2;
const int aanKnopLos = 3;
int knopStatus = 0;

byte rechthoek[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte speler[] = {
  B01110,
  B01111,
  B11101,
  B11111,
  B11110,
  B11110,
  B01010,
  B01010
};

byte vierkantBoven[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte vierkantOnder[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte driehoekBoven[] = {
  B00000,
  B00000,
  B00000,
  B00001,
  B00011,
  B00111,
  B01111,
  B11111
};

byte driehoekOnder[] = {
  B11111,
  B01111,
  B00111,
  B00011,
  B00001,
  B00000,
  B00000,
  B00000
};

byte vijandLichaamBoven[] = {
  B11111,
  B10111,
  B10111,
  B11111,
  B01110,
  B01110,
  B01110,
  B01110
};

byte vijandLichaamOnder[] = {
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B11111,
  B11011,
  B11011
};

byte spelerBoven[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01110,
  B01111,
  B11101,
  B11111
};

byte spelerOnder[] = {
  B11110,
  B11110,
  B01010,
  B01010,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  pinMode(knopGeel, INPUT);
  pinMode(knopBlauw, INPUT);
  pinMode(knopGroen, INPUT);
  pinMode(knopRood, INPUT);
  pinMode(knopWit, INPUT);
  pinMode(ledGeel, OUTPUT);
  pinMode(ledGroen, OUTPUT);
  pinMode(ledRood, OUTPUT);
  pinMode(ledBlauw, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  knopStatusGeel = digitalRead(knopGeel);
  knopStatusBlauw = digitalRead(knopBlauw);
  knopStatusGroen = digitalRead(knopGroen);
  knopStatusRood = digitalRead(knopRood);
  knopStatusWit = digitalRead(knopWit);
 
  tijd = millis();

Serial.println(gameModeStatus);

  if (gameStatus == STARTSCHERM) {
      lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Press White");
    lcd.setCursor(0, 1);
    lcd.print("Button To Start");
    if(tijd > tijdPagina + 500) {
        regelPagina = 0;
      }
    if (knopStatusWit == HIGH & regelPagina == 0) {
      gameStatus = REGELPAGINA1;
      tijdPagina = tijd;
    }
 
  }

  if (gameStatus == REGELPAGINA1) {
      lcd.begin(16, 2);
      lcd.createChar(1, rechthoek);
    lcd.setCursor(14, 1);
    lcd.write(1);
    lcd.setCursor(0, 0);
    lcd.print("Press White");
    lcd.setCursor(0, 1);
    lcd.print("Button For");
    if(tijd > tijdPagina + 500) {
        regelPagina = 1;
      }
   
    if (knopStatusWit == HIGH & regelPagina == 1) {
      gameStatus = REGELPAGINA2;
      tijdPagina = tijd;
   
    }
  }

   if (gameStatus == REGELPAGINA2) {
    lcd.begin(16, 2);
    lcd.createChar(1, vierkantBoven);
    lcd.setCursor(14, 0);
    lcd.write(1);
    lcd.createChar(2, vierkantOnder);
    lcd.setCursor(14, 1);
    lcd.write(2);
    lcd.setCursor(0, 0);
    lcd.print("Press Yellow");
    lcd.setCursor(0, 1);
    lcd.print("Button For");
    if(tijd > tijdPagina + 500) {
       regelPagina = 2;
      }
      
    if (knopStatusWit == HIGH & regelPagina == 2) {
      gameStatus = REGELPAGINA3;
      tijdPagina = tijd;
      
    }
  }

   if (gameStatus == REGELPAGINA3) {
      lcd.begin(16, 2);
      lcd.createChar(1, rechthoek);
    lcd.setCursor(14, 1);
    lcd.write(1);
    lcd.createChar(1, rechthoek);
    lcd.setCursor(14, 0);
    lcd.write(1);
    lcd.setCursor(0, 0);
    lcd.print("Press Blue");
    lcd.setCursor(0, 1);
    lcd.print("Button For");
     if(tijd > tijdPagina + 500) {
      regelPagina = 3;
      }
      
    if (knopStatusWit == HIGH & regelPagina == 3) {
      gameStatus = REGELPAGINA4;
      tijdPagina = tijd;
      
    }
  }

   if (gameStatus == REGELPAGINA4) {
      lcd.begin(16, 2);
      lcd.createChar(1, driehoekBoven);
    lcd.setCursor(14, 0);
    lcd.write(1);
    lcd.createChar(2, driehoekOnder);
    lcd.setCursor(14, 1);
    lcd.write(2);
    lcd.setCursor(0, 0);
    lcd.print("Press Green");
    lcd.setCursor(0, 1);
    lcd.print("Button For");
     if(tijd > tijdPagina + 500) {
         regelPagina = 4;
      }
      
    if (knopStatusWit == HIGH & regelPagina == 4) {
      gameStatus = REGELPAGINA5;
      tijdPagina = tijd;
     
    }
  }

  if (gameStatus == REGELPAGINA5) {
      lcd.begin(16, 2);
      lcd.createChar(1, vijandLichaamBoven);
    lcd.setCursor(14, 0);
    lcd.write(1);
    lcd.createChar(2, vijandLichaamOnder);
    lcd.setCursor(14, 1);
    lcd.write(2);
    lcd.setCursor(0, 0);
    lcd.print("Press Red");
    lcd.setCursor(0, 1);
    lcd.print("Button For");
     if(tijd > tijdPagina + 500) {
        regelPagina = 5;
      }
   
    if (knopStatusWit == HIGH & regelPagina == 5) {
      gameStatus = HERHALING;
      tijdPagina = tijd;
    }
  }

  if (gameStatus == HERHALING) {
      lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Press Yellow");
    lcd.setCursor(0, 1);
    lcd.print("Button To Repeat");
    if(knopStatusGeel == HIGH){
      gameStatus = REGELPAGINA1;
    }
     if(tijd > tijdPagina + 500) {
        regelPagina = 6;
      }
   
    if (knopStatusWit == HIGH & regelPagina == 6) {
      gameStatus = GAMEMODE;
      tijdGameMode = tijd;
    }
  }

  if(gameStatus == GAMEMODE) {
    if(gameMode == 0) {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Press Green For");
    lcd.setCursor(0, 1);
    lcd.print("Easy Mode");
    if(tijd > tijdGameMode + 3000) {
        gameMode = 1;
        tijdGameMode = tijd;
      }
    } 
    if(gameMode == 1) {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Press Yellow For");
    lcd.setCursor(0, 1);
    lcd.print("Normal Mode");
    if(tijd > tijdGameMode + 3000) {
        gameMode = 2;
        tijdGameMode = tijd;
      }
    } 
     if(gameMode == 2) {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Press Red For");
    lcd.setCursor(0, 1);
    lcd.print("Hard Mode");
    if(tijd > tijdGameMode + 3000) {
        gameMode = 0;
        tijdGameMode = tijd;
      }
   } if(knopStatusGroen == HIGH) {
    gameStatus = SPELLADING;
    gameModeStatus = EASY;
   }
   if(knopStatusGeel == HIGH) {
    gameStatus = SPELLADING;
    gameModeStatus = NORMAL;
   }
   if(knopStatusRood == HIGH) {
    gameStatus = SPELLADING;
    gameModeStatus = HARD;
    positieRechthoekX = positieRandom[random(6)];
    positieVierkantX = positieRandom[random(6)];
    positieGroteRechthoekX = positieRandom[random(6)];
    positieDriehoekX = positieRandom[random(6)];
    positieVijandX = positieRandom[random(6)];
  }
  }
   

  if (gameStatus == SPELLADING) {
      lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("GAME STARTING");
    lcd.setCursor(0, 1);
    lcd.print("IN    SECONDS");
    lcd.setCursor(3, 1);
    lcd.print(aftelling);
     
    if(tijd > tijdAftelling + 1000) {
    aftelling = aftelling - 1;
    tijdAftelling = tijd;
    }
    if(aftelling < 1) {
      gameStatus = SPELEN;
    }
  }

  if (gameStatus == SPELEN) {
    lcd.begin(16, 2);
    lcd.createChar(1, speler);
    lcd.setCursor(positieSpelerX, positieSpelerY);
    lcd.write(1);

    if (knopStatusWit == HIGH & positieSpelerY == 1) {
      positieSpelerY = positieSpelerY - 1;
      delay(200);
    } else if (knopStatusWit == HIGH & positieSpelerY == 0) {
      positieSpelerY = positieSpelerY + 1;
      delay(200);
    }

    if(knopStatusGeel == HIGH || knopStatusBlauw == HIGH || knopStatusGroen == HIGH || knopStatusRood == HIGH) {
      gameStatus = OBSTAKEL;
    }  

    if (positieRechthoekX == positieSpelerX & positieRechthoekY == positieSpelerY || positieVierkantX == positieSpelerX || positieGroteRechthoekX == positieSpelerX || positieDriehoekX == positieSpelerX || positieVijandX == positieSpelerX) {
    gameStatus = GAMEOVER;
  }
  }
  if(gameStatus == SPELEN || gameStatus == OBSTAKEL) {
    lcd.begin(16, 2);
    lcd.setCursor(12, 0);
    lcd.print(round(score));
    score = score + 0.2;
    
    lcd.createChar(1, rechthoek);
    lcd.setCursor(positieRechthoekX, positieRechthoekY);
    lcd.write(1);

    lcd.createChar(2, vierkantBoven);
    lcd.setCursor(positieVierkantX, positieVierkantBovenY);
    lcd.write(2);

    lcd.createChar(3, vierkantOnder);
    lcd.setCursor(positieVierkantX, positieVierkantOnderY);
    lcd.write(3); 

    lcd.setCursor(positieGroteRechthoekX, positieGroteRechthoekBovenY);
    lcd.write(1);
    
    lcd.setCursor(positieGroteRechthoekX, positieGroteRechthoekOnderY);
    lcd.write(1);

     lcd.createChar(4, driehoekBoven);
    lcd.setCursor(positieDriehoekX, positieDriehoekBovenY);
    lcd.write(4); 
    
    lcd.createChar(5, driehoekOnder);
    lcd.setCursor(positieDriehoekX, positieDriehoekOnderY);
    lcd.write(5);

     lcd.createChar(6, vijandLichaamBoven);
    lcd.setCursor(positieVijandX, positieVijandBovenY);
    lcd.write(6);
    
    lcd.createChar(7, vijandLichaamOnder);
    lcd.setCursor(positieVijandX, positieVijandOnderY);
    lcd.write(7);
    

    if (tijd > tijdNu + 500 & (positieRechthoekX < 17 || positieVierkantX < 23 || positieGroteRechthoekX < 29 || positieDriehoekX < 35  || positieVijandX < 41) & (gameModeStatus == EASY || gameModeStatus == NORMAL)) {
    positieRechthoekX  = positieRechthoekX - 1;
    positieVierkantX = positieVierkantX - 1;
    positieGroteRechthoekX = positieGroteRechthoekX - 1;
    positieDriehoekX = positieDriehoekX - 1;
    positieVijandX = positieVijandX - 1;
    tijdNu = millis();

    }

    if (tijd > tijdNu + 200 & (positieRechthoekX < positieRechthoekX + 1 || positieVierkantX < positieVierkantX + 1 || positieGroteRechthoekX < positieGroteRechthoekX + 1 || positieDriehoekX < positieDriehoekX + 1 || positieVijandX < positieVijandX + 1) & gameModeStatus == HARD) {
    positieRechthoekX  = positieRechthoekX - 1;
    positieVierkantX = positieVierkantX - 1;
    positieGroteRechthoekX = positieGroteRechthoekX - 1;
    positieDriehoekX = positieDriehoekX - 1;
    positieVijandX = positieVijandX - 1;
    tijdNu = millis();

    }

if(gameModeStatus == EASY || gameModeStatus == NORMAL) {
  if (positieVierkantX < 0) {
    positieVierkantX = 39;
  }
  
  if (positieGroteRechthoekX < 0) {
    positieGroteRechthoekX = 39;
  }
  
  if (positieDriehoekX < 0) {
    positieDriehoekX = 39;
  }

  if (positieRechthoekX < 0) {
    positieRechthoekX = 39;
    positieRechthoekY = random(2);
    
  } 
  if (positieVijandX < 0) {
    positieRechthoekX = 16;
    positieVierkantX = 22;
    positieGroteRechthoekX = 28;
    positieDriehoekX = 34;
    positieVijandX = 40;
  }
}

if(gameModeStatus == HARD) {
  if (positieVierkantX < 0 & (positieGroteRechthoekX > 0 || positieDriehoekX > 0 || positieRechthoekX > 0 || positieVijandX > 0)) {
    positieVierkantX = 35;
  } else if(positieVierkantX < 0){
    positieRechthoekX = positieRandom[random(6)];
    positieVierkantX = positieRandom[random(6)];
    positieGroteRechthoekX = positieRandom[random(6)];
    positieDriehoekX = positieRandom[random(6)];
    positieVijandX = positieRandom[random(6)];
  }
  
  
  if (positieGroteRechthoekX < 0 & (positieVierkantX > 0 || positieDriehoekX > 0 || positieRechthoekX > 0 || positieVijandX > 0)) {
    positieGroteRechthoekX = 35;
  } else if(positieGroteRechthoekX < 0){
    positieRechthoekX = positieRandom[random(6)];
    positieVierkantX = positieRandom[random(6)];
    positieGroteRechthoekX = positieRandom[random(6)];
    positieDriehoekX = positieRandom[random(6)];
    positieVijandX = positieRandom[random(6)];
  }
  
  if (positieDriehoekX < 0 & (positieGroteRechthoekX > 0 || positieVierkantX > 0 || positieRechthoekX > 0 || positieVijandX > 0)) {
    positieDriehoekX = 35;
  } else if(positieDriehoekX < 0){
    positieRechthoekX = positieRandom[random(6)];
    positieVierkantX = positieRandom[random(6)];
    positieGroteRechthoekX = positieRandom[random(6)];
    positieDriehoekX = positieRandom[random(6)];
    positieVijandX = positieRandom[random(6)];
  }

  if (positieRechthoekX < 0 & (positieGroteRechthoekX > 0 || positieDriehoekX > 0 || positieVierkantX > 0 || positieVijandX > 0)) {
    positieRechthoekX = 35;
    positieRechthoekY = random(2);
  } else if(positieRechthoekX < 0){
    positieRechthoekX = positieRandom[random(6)];
    positieVierkantX = positieRandom[random(6)];
    positieGroteRechthoekX = positieRandom[random(6)];
    positieDriehoekX = positieRandom[random(6)];
    positieVijandX = positieRandom[random(6)];
    positieRechthoekY = random(2);
  }

  if (positieVijandX < 0 & (positieGroteRechthoekX > 0 || positieDriehoekX > 0 || positieRechthoekX > 0 || positieVierkantX > 0)) {
    positieVijandX = 35;
  } else if (positieVijandX < 0) {
    positieRechthoekX = positieRandom[random(6)];
    positieVierkantX = positieRandom[random(6)];
    positieGroteRechthoekX = positieRandom[random(6)];
    positieDriehoekX = positieRandom[random(6)];
    positieVijandX = positieRandom[random(6)];
  }
}
  
  if (knopStatus == uitKnopLos) {
  if(digitalRead(knopGeel) == HIGH & ledStatusGeel == LOW) {
   knopStatus = aanKnopIn;
   digitalWrite(ledGeel, HIGH);
   ledStatusGeel = HIGH;
    } if(digitalRead(knopBlauw) == HIGH & ledStatusBlauw == LOW) {
   knopStatus = aanKnopIn;
   digitalWrite(ledBlauw, HIGH);
   ledStatusBlauw = HIGH;
    } if(digitalRead(knopGroen) == HIGH & ledStatusGroen == LOW) {
   knopStatus = aanKnopIn;
   digitalWrite(ledGroen, HIGH);
   ledStatusGroen = HIGH;
    } if(digitalRead(knopRood) == HIGH & ledStatusRood == LOW) {
   knopStatus = aanKnopIn;
   digitalWrite(ledRood, HIGH);
   ledStatusRood = HIGH;
    }
 
  }

  if (knopStatus == aanKnopIn) {
  if(digitalRead(knopGeel) == LOW & ledStatusGeel == HIGH) {
   knopStatus = aanKnopLos;
   digitalWrite(ledGeel, HIGH);
    } if(digitalRead(knopBlauw) == LOW & ledStatusBlauw == HIGH) {
   knopStatus = aanKnopLos;
   digitalWrite(ledBlauw, HIGH);
    } if(digitalRead(knopGroen) == LOW & ledStatusGroen == HIGH) {
   knopStatus = aanKnopLos;
   digitalWrite(ledGroen, HIGH);
    } if(digitalRead(knopRood) == LOW & ledStatusRood == HIGH) {
   knopStatus = aanKnopLos;
   digitalWrite(ledRood, HIGH);
    }
  }
  if (knopStatus == aanKnopLos) {
  if(digitalRead(knopGeel) == HIGH & ledStatusGeel == HIGH) {
   knopStatus = uitKnopIn;
   digitalWrite(ledGeel, LOW);
    } if(digitalRead(knopBlauw) == HIGH & ledStatusBlauw == HIGH) {
   knopStatus = uitKnopIn;
   digitalWrite(ledBlauw, LOW);
    } if(digitalRead(knopGroen) == HIGH & ledStatusGroen == HIGH) {
   knopStatus = uitKnopIn;
   digitalWrite(ledGroen, LOW);
    } if(digitalRead(knopRood) == HIGH & ledStatusRood == HIGH) {
   knopStatus = uitKnopIn;
   digitalWrite(ledRood, LOW);
    }

  }

  if (knopStatus == uitKnopIn) {
  if(digitalRead(knopGeel) == LOW & ledStatusGeel == HIGH) {
   knopStatus = uitKnopLos;
   digitalWrite(ledGeel, LOW);
   ledStatusGeel = LOW;
    } if(digitalRead(knopBlauw) == LOW & ledStatusBlauw == HIGH) {
   knopStatus = uitKnopLos;
   digitalWrite(ledBlauw, LOW);
   ledStatusBlauw = LOW;
    } if(digitalRead(knopGroen) == LOW & ledStatusGroen == HIGH) {
   knopStatus = uitKnopLos;
   digitalWrite(ledGroen, LOW);
   ledStatusGroen = LOW;
    } if(digitalRead(knopRood) == LOW & ledStatusRood == HIGH) {
   knopStatus = uitKnopLos;
   digitalWrite(ledRood, LOW);
   ledStatusRood = LOW;
    }
  }

  }
    
  if (gameStatus == OBSTAKEL) {
    lcd.begin(16, 2);
    lcd.createChar(1, spelerBoven);
    lcd.setCursor(positieSpelerX, positieSpelerBovenY);
    lcd.write(1);

    lcd.createChar(2, spelerOnder);
    lcd.setCursor(positieSpelerX, positieSpelerOnderY);
    lcd.write(2);

    if(ledStatusGeel == LOW & ledStatusBlauw == LOW & ledStatusGroen == LOW & ledStatusRood == LOW) {
      gameStatus = SPELEN; 
    }
    if (positieRechthoekX == positieSpelerX || positieVierkantX == positieSpelerX & ledStatusGeel == LOW || positieGroteRechthoekX == positieSpelerX & ledStatusBlauw == LOW || positieDriehoekX == positieSpelerX & ledStatusGroen == LOW || positieVijandX == positieSpelerX & ledStatusRood == LOW) {
    gameStatus = GAMEOVER;
  }
 }

    


  if (gameStatus == GAMEOVER) {
      lcd.begin(16, 2);
    lcd.setCursor(12, 0);
    lcd.print(round(score));
    lcd.setCursor(0, 0);
    lcd.print("Game Over");
      
      digitalWrite(ledGeel, LOW);
      digitalWrite(ledBlauw, LOW);
       digitalWrite(ledGroen, LOW);
        digitalWrite(ledRood, LOW);

    if (knopStatusWit == HIGH) {
      gameStatus = STARTSCHERM;
      score = 0;
      regelPagina = -1;
      tijdPagina = tijd;
      aftelling = 11;
      positieRechthoekX = 16;
      positieVierkantX = 22;
      positieGroteRechthoekX = 28;
      positieDriehoekX = 34;
      positieVijandX = 40;
      gameModeStatus = EASY;
    }
  }

}






  
