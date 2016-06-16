import processing.serial.*; //<>//

import ddf.minim.*;

Minim minim;
AudioPlayer player;
AudioMetaData meta;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
int counter=1;
int previous_counter = 900;

// lists of songs
boolean booleanList[] = {false, false, false};
String songs[] = {"sad1.mp3", "sad2.mp3", "sad3.mp3"};
int playtimes[] = {60000, 60000, 60000};
int songlist_loop_counter = 0;
int has_come_counter =0;



public String previous_song_name;
public String new_song_name;

int songlist_loop_counter_zero;
boolean booleanList_zero[] = {false, false, false};
String songs_zero[] = {"angry1.mp3", "angry2.mp3", "angry3.mp3"};
public String previous_song_name_zero;
public String new_song_name_zero;

int songlist_loop_counter_two;
boolean booleanList_two[] = {false, false, false};
String songs_two[] = {"calm1.mp3", "calm2.mp3", "calm3.mp3"};
public String previous_song_name_two;
public String new_song_name_two;

int songlist_loop_counter_three;
boolean booleanList_three[] = {false, false, false};
String songs_three[] = {"happy1.mp3", "happy2.mp3", "happy3.mp3"};
public String previous_song_name_three;
public String new_song_name_three;

int songlist_loop_counter_four;
boolean booleanList_four[] = {false, false, false};
String songs_four[] = {"love1.mp3", "love2.mp3", "love3.mp3"};
public String previous_song_name_four;
public String new_song_name_four;

// I know that the first port in the serial list on my mac
// is Serial.list()[0].
// On Windows machines, this generally opens COM1.
// Open whatever port is the one you're using.
void setup() {
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  size(100, 100); 
  minim = new Minim(this);
}
void draw()
{
  if ( myPort.available() > 0) 
  {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
  } 
    try {
  counter = int(val.trim());
  //Integer.parseInt(val);
  } catch (Exception e) {
    println("val is null");
    counter = -1;
  }
  //println(">"+val+"<");
  //if (val != null)
  //{ 
  //  if (val.contains("0")) {
  //    counter = 0;
  //  } 
  //  if (val.contains("1")) {
  //    counter = 1;
  //  } 
  //  if (val.contains("2")) {
  //    counter = 2;
  //  }
  //  if (val.contains("3")) {
  //    counter = 3;
  //  }
  //  if (val.contains("4")) {
  //    counter = 4;
  //  }
  //}
   //<>//
if (previous_counter == 900) {
    player = minim.loadFile("neutral.mp3");
    previous_counter = 990;
  }
  print("Counter:");
  print(counter);
  println("\n");
  print("previous_counter:");
  print(previous_counter);
  // Angry
  if (counter==0) {

    ////////////////////////////////////////////if the previous counter was NOT 0..i.e song was being played from different genre/////////then/////////////
    if (previous_counter !=0) {
      
      if (songlist_loop_counter_zero == 3) {
        for (int j =0; j<3; j++) {
          booleanList_zero[j] = false;
        }
        songlist_loop_counter_zero=0;
      }
      for (int i =0; i<3; i++) {
        if (!booleanList_zero[i]) {
          songlist_loop_counter_zero++;
          // not sure about hte below statement
          player.pause();
          player = minim.loadFile(songs_zero[i]);
          player.play();
          previous_song_name_zero = songs_zero[i];

          booleanList_zero[i] = true;
          print("I WAS HEREEEEEEEEEEEEEEEEe");
          break;
        }
      }
    }
    /////////////////////////////////////////////////////ELSE//i.e if previous counter is equal to 0./////////////////////////////////////////////////////////////////////////////
    else if (previous_counter==0){
      if (player.isPlaying()) {
        
      }
    
   else if(!player.isPlaying()){
    player.pause();
    meta = player.getMetaData();
    previous_song_name_zero = meta.fileName();
    for (int i =0; i<3; i++) {
      if (songs_zero[i] == previous_song_name_zero) {
        String new_song_name_zero = songs_zero[(i+1)%3];
        println(new_song_name_zero);
        player = minim.loadFile((String)new_song_name_zero);
       
        player.play();}}
      }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
    previous_counter = 0;
  }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



  // Sad
  if (counter==1) {

    ////////////////////////////////////////////if the previous counter was NOT 1..i.e song was being played from different genre/////////then/////////////
    if (previous_counter !=1) {
      player.pause();
      //has_come_counter++;
      if (songlist_loop_counter == 3) {
        for (int j =0; j<3; j++) {
          booleanList[j] = false;
        }
        songlist_loop_counter=0;
        
      }
      for (int i =0; i<3; i++) {
        if (!booleanList[i]) {
          songlist_loop_counter++;
          // not sure about hte below statement
          
          player = minim.loadFile(songs[i]);
          player.play();
          previous_song_name = songs[i];

          booleanList[i] = true;
          print("I WAS HEREEEEEEEEEEEEEEEEe");
          break;
        }
      }
    }
    /////////////////////////////////////////////////////ELSE//i.e if previous counter is equal to one./////////////////////////////////////////////////////////////////////////////
    else if (previous_counter==1){
      if (player.isPlaying()) {
        meta = player.getMetaData();
        String s = meta.fileName();
        print(s);
        print(s);

      }
    
   else if(!player.isPlaying()){
    player.pause();
    meta = player.getMetaData();
    previous_song_name = meta.fileName();
    for (int i =0; i<3; i++) {
      if (songs[i] == previous_song_name) {
        String new_song_name = songs[(i+1)%3];
        println(new_song_name);
        player = minim.loadFile((String)new_song_name);
        //meta = player.getMetaData();

        //print(meta.fileName());
        //print(meta.fileName());
        player.play();}}
      }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
    previous_counter = 1;
  }
          
          
          
          
          
 
          

  // Calm
  if (counter==2) {

    ////////////////////////////////////////////if the previous counter was NOT 2..i.e song was being played from different genre/////////then/////////////
    if (previous_counter !=2) {
      
      if (songlist_loop_counter_two == 3) {
        for (int j =0; j<3; j++) {
          booleanList_two[j] = false;
        }
        songlist_loop_counter_two=0;
      }
      for (int i =0; i<3; i++) {
        if (!booleanList_two[i]) {
          songlist_loop_counter_two++;
          // not sure about hte below statement
          player.pause();
          player = minim.loadFile(songs_two[i]);
          player.play();
          previous_song_name_two = songs_two[i];

          booleanList_two[i] = true;
          print("I WAS HEREEEEEEEEEEEEEEEEe");
          break;
        }
      }
    }
    /////////////////////////////////////////////////////ELSE//i.e if previous counter is equal to 2./////////////////////////////////////////////////////////////////////////////
    else if (previous_counter==2){
      if (player.isPlaying()) {
        
      }
    
   else if(!player.isPlaying()){
    player.pause();
    meta = player.getMetaData();
    previous_song_name_two = meta.fileName();
    for (int i =0; i<3; i++) {
      if (songs_two[i] == previous_song_name_two) {
        String new_song_name_two = songs_two[(i+1)%3];
        println(new_song_name_two);
        player = minim.loadFile((String)new_song_name_two);
       
        player.play();}}
      }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
    previous_counter = 2;
  }















  // Happy 
if (counter==3) {

    ////////////////////////////////////////////if the previous counter was NOT 3..i.e song was being played from different genre/////////then/////////////
    if (previous_counter !=3) {
      
      if (songlist_loop_counter_three == 3) {
        for (int j =0; j<3; j++) {
          booleanList_three[j] = false;
        }
        songlist_loop_counter_three =0;
      }
      for (int i =0; i<3; i++) {
        if (!booleanList_three[i]) {
          songlist_loop_counter_three++;
          // not sure about hte below statement
          player.pause();
          player = minim.loadFile(songs_three[i]);
          player.play();
          previous_song_name_three = songs_three[i];

          booleanList_three[i] = true;
          print("I WAS HEREEEEEEEEEEEEEEEEe");
          break;
        }
      }
    }
    /////////////////////////////////////////////////////ELSE//i.e if previous counter is equal to 3./////////////////////////////////////////////////////////////////////////////
    else if (previous_counter==3){
      if (player.isPlaying()) {
        
      }
    
   else if(!player.isPlaying()){
    player.pause();
    meta = player.getMetaData();
    previous_song_name_three = meta.fileName();
    for (int i =0; i<3; i++) {
      if (songs_three[i] == previous_song_name_three) {
        String new_song_name_three = songs_three[(i+1)%3];
        println(new_song_name_three);
        player = minim.loadFile((String)new_song_name_three);
       
        player.play();}}
      }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
    previous_counter = 3;
  }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








  // In Love
    if (counter==4) {

    ////////////////////////////////////////////if the previous counter was NOT 4..i.e song was being played from different genre/////////then/////////////
    if (previous_counter !=4) {
      
      if (songlist_loop_counter_four == 3) {
        for (int j =0; j<3; j++) {
          booleanList_four[j] = false;
        }
        songlist_loop_counter_four=0;
      }
      for (int i =0; i<3; i++) {
        if (!booleanList_four[i]) {
          songlist_loop_counter_four++;
          // not sure about hte below statement
          player.pause();
          player = minim.loadFile(songs_four[i]);
          player.play();
          previous_song_name_four = songs_four[i];

          booleanList_four[i] = true;
          print("I WAS HEREEEEEEEEEEEEEEEEe");
          break;
        }
      }
    }
    /////////////////////////////////////////////////////ELSE//i.e if previous counter is equal to 4./////////////////////////////////////////////////////////////////////////////
    else if (previous_counter==4){
      if (player.isPlaying()) {
        
      }
    
   else if(!player.isPlaying()){
    player.pause();
    meta = player.getMetaData();
    previous_song_name_four = meta.fileName();
    for (int i =0; i<3; i++) {
      if (songs_four[i] == previous_song_name_four) {
        String new_song_name_four = songs_four[(i+1)%3];
        println(new_song_name_four);
        player = minim.loadFile((String)new_song_name_four);
       
        player.play();}}
      }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
    previous_counter = 4;
  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}