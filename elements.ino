


void initElements()
{
  for(byte i=0;i<NB_ELEMENT_INGAME;i++){
    elements[i].vx = 0;
    elements[i].posX = random(88,250)*(i+1); 
    elements[i].type = ((int)elements[i].posX)%2;
  }
  
  bottes.vx = 0;
  bottes.posX = 50; 
}

void updateElements()
{
  for(byte i=0;i<NB_ELEMENT_INGAME;i++){
    elements[i].vx = player1.vx;
    elements[i].posX -= elements[i].vx; 
  }
  bottes.vx = (player1.vx/1.5);
  bottes.posX -= bottes.vx;
  if(bottes.posX<-16){
    bottes.posX += random(88,150);
  } 
}

void drawElements()
{
   for(byte i=0;i<NB_ELEMENT_INGAME;i++){
    if(elements[i].posX>-16.0 && elements[i].posX<84.0){
      gb.display.drawBitmap(elements[i].posX,(elements[i].type==0)?33 : 44,(elements[i].type==0)?tramplin : bosse);
    } 
  }
  gb.display.setColor(GRAY);
  gb.display.drawBitmap(bottes.posX,40,bottesFoins);
  gb.display.setColor(BLACK);
}
