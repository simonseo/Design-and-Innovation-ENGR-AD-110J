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
String songs[] = {"a1.mp3", "a2.mp3", "a3.mp3"};
int playtimes[] = {60000, 60000, 60000};
int songlist_loop_counter = 0;
int has_come_counter =0;



public String previous_song_name;
public String new_song_name;

int songlist_loop_counter_zero;
boolean booleanList_zero[] = {false, false, false};
String songs_zero[] = {"1.mp3", "2.mp3", "3.mp3"};
public String previous_song_name_zero;
public String new_song_name_zero;

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
  println(">"+val+"<");
  if (val != null)
  { 
    if (val.contains("0")) {
      counter = 0;
    } 
    if (val.contains("1")) {
      counter = 1;
    } 
    if (val.contains("2")) {
      counter = 2;
    }
    if (val.contains("3")) {
      counter = 3;
    }
    if (val.contains("4")) {
      counter = 4;
    }
  }
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
      //has_come_counter++;
      if (songlist_loop_counter_zero == 3) {
        for (int j =0; j<3; j++) {
          booleanList_zero[j] = false;
        }
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






 //<>//
  // Sad
  if (counter==1) {

    ////////////////////////////////////////////if the previous counter was NOT 1..i.e song was being played from different genre/////////then/////////////
    if (previous_counter !=1) {
      //has_come_counter++;
      if (songlist_loop_counter == 3) {
        for (int j =0; j<3; j++) {
          booleanList[j] = false;
        }
      }
      for (int i =0; i<3; i++) {
        if (!booleanList[i]) {
          songlist_loop_counter++;
          // not sure about hte below statement
          player.pause();
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
        //meta = player.getMetaData();
        //previous_song_name = meta.fileName();
        //for (int i =0; i<3; i++) {
        //  if (songs[i] == previous_song_name) {
        //    String new_song_name = songs[(i+1)%3];

        //        print();
        //        print("NEW SONG NAME");
        //println(new_song_name);
        //println(new_song_name);
        //println(new_song_name);
        //println(new_song_name);
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
  if (counter==2 && previous_counter !=2) {
    player.pause();
    player = minim.loadFile("c1.mp3", 1024);
    player.play();
    previous_counter = 2;
  }

  // Happy 
  if (counter==3 && previous_counter !=3) {
    player.pause();
    player = minim.loadFile("d1.mp3", 1024);
    player.play();
    previous_counter = 3;
  }

  // In Love
  if (counter==4 && previous_counter !=4) {
    player.pause();
    player = minim.loadFile("e1.mp3", 1024);
    player.play();
    previous_counter = 4;
  }
}