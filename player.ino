


void initPlayer()
{
  player1.state = MOTO_STATE_NORMAL;
  player1.y = SOL_Y;
}

void updatePlayer()
{
  if(gb.buttons.repeat(BTN_A, 1)){
    player1.vx += MOTO_ACC;
  } else {
    player1.vx -= MOTO_ENGINE_BREAK;
  }
  
  if(gb.buttons.repeat(BTN_B, 1)){
    player1.vx -= MOTO_BREAK;
  }
  
  
  if(gb.buttons.repeat(BTN_RIGHT, 1)){
    if(player1.vy<0){
      float temp = player1.vy - (player1.vy * TRANSFER_FORCE);
      player1.vx += temp;
      player1.vy -= temp;
      if(player1.state == MOTO_STATE_ROUE_AR){
        player1.state = MOTO_STATE_NORMAL;
      } else if(player1.state == MOTO_STATE_ROUE_AR){
        player1.state = MOTO_STATE_ROUE_AV;
      }
    }
  }
  
    
  if(gb.buttons.repeat(BTN_LEFT, 1)){
    if(gb.frameCount%10 == 0){
      if(player1.state == MOTO_STATE_ROUE_AV){
        player1.state = MOTO_STATE_NORMAL;
      } else if(player1.state == MOTO_STATE_NORMAL){
        player1.state = MOTO_STATE_ROUE_AR;
      } else if(MOTO_STATE_ROUE_AR){
          player1.state = MOTO_STATE_KO;
      }
    }
  }
  
  if(player1.vx>MOTO_MAX_VITT) {
    player1.vx=MOTO_MAX_VITT;
  } else if(player1.vx < 0.0){
    player1.vx=0;
  }
  
  for(byte i=0;i<NB_ELEMENT_INGAME;i++){
  if(gb.collideBitmapBitmap(elements[i].posX, ((elements[i].type==0)?33 : 44), ((elements[i].type==0)?tramplin : bosse), player1.x, player1.y, player1.sprites[player1.state])){
      
    while(gb.collideBitmapBitmap(elements[i].posX, ((elements[i].type==0)?33 : 44), ((elements[i].type==0)?tramplin : bosse), player1.x, player1.y, player1.sprites[player1.state])){
      player1.y-= 1;//on ne rentre pas dans le sol
    }
      player1.vx *= FROTTEMENT_OBSTACLE;
      player1.vy = 0;
      player1.vy -= (TREMPLIN_VY* player1.vx);
      player1.state = MOTO_STATE_ROUE_AR;
      break;
    } 
  }
  player1.y += player1.vy;
  
  if(player1.y<SOL_Y){
    player1.vy += GRAVITY;
  } else if(player1.y > SOL_Y) {
    player1.y = SOL_Y;
    player1.vy = 0;
    player1.state = MOTO_STATE_NORMAL;
  } 
  
}

void drawPlayer()
{
  gb.display.print(player1.vx);
  gb.display.drawBitmap(player1.x,player1.y,player1.sprites[player1.state]);
}
