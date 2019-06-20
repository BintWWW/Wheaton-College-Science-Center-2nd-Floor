/* Programer:  Bintao Wang
   Name:       WangG1.cpp
   Purpose:    Using openGL printing a graph of science center second floor
               Allowing user to make changes by pressing certain keyboard
   Input:      Certain keyboard that will be given when you run the file
   Output:     A instuction of changes you can make in this program
               A cool graph of science center second floor
               Some changes such as highlight and toggle in the graph
*/
using namespace std;
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
float Maker = 0.95, Office = 0.95, Three = 0.8, Six = 0.95;
/* Here's a very basic class */
class myClass {
   float wall;
   float Stair;
   int   Path;
   bool  Lbl;
public:
   myClass () {wall=15;Stair = 1.0;Path = 0;Lbl = false;}
   void init ();
   void myDisplay (); 
   void mykeyboard (unsigned char, int, int);
};
myClass drawstuff;
void instruction () {
   cout << "Welcome to Science Center Second Floor" << endl;
   cout << "Here are some instructions you might want to use" << endl;
   cout << "-------------------------------------------------------------------------------------------" << endl;
   cout << "Press '3' to highlight Room 243" << endl;
   cout << "Press '6' to highlight Room 246" << endl;
   cout << "Press 'm' to highlight the Makerspace" << endl;
   cout << "Press 'f' to highlight all the offices" << endl;
   cout << "Press 's' to highlight the stairways, press again to turn it back" << endl;
   cout << "Press 'p' to show a path from the main door to a stairway, you want to press multiple times" << endl;
   cout << "Press 'L' to show the label of each rooms (not all of them), press again to close it" << endl;
   cout << "Press 'l' to get a hint because assignment didn't mention about 'l'" << endl;
   cout << "Press 'q' to receive a nice goodbye and quit the program" << endl;
   cout << "Now start doing stuff" << endl;
}
/* Most stuff will be handled within the class method(s): */
void myClass :: myDisplay () {
   int num;
   int num_;
   int i;
   float x_room = 2000/7;
   float x = 120;
   string Make_ = "Makerspace\0";
   // string Stair_ = "Stairway\0";          // Stairways is not a room!
   string Room_ = "Unrelated\nRoom\0";
   string rm_3 = "243\0";
   string rm_6 = "246\0";
   string rm_down = "208\n 207\n 205\n 204\n 203\n 202\n 201\n";
   string rm_down_left = "209\0";
   string rm_2_1 = "227\0";
   string rm_2_2 = "228(Non-office)\0";
   string rm_2_3 = "229\0";
   string rm_2_4 = "230\0";
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (0.0, 0.0, 0.0);						// Color of wall
   glBegin (GL_POLYGON);
      glVertex3f (100, 100, 0.0);
      glVertex3f (100, 4350, 0.0);
      glVertex3f (2100, 4350, 0.0);
      glVertex3f (2100, 100, 0.0);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (2100, 100, 0.0);
      glVertex3f (2100, 1900, 0.0);
      glVertex3f (3600, 1900, 0.0);
      glVertex3f (3600 , 100, 0.0);
   glEnd();
   glColor3f (0.95, 0.95, 0.8);						// Color of rooms
   glBegin (GL_POLYGON);							// There are classrooms
      glVertex3f (100+wall, 2175+wall/2, 0.0);
      glVertex3f (100+wall, 3950-wall/2, 0.0);
      glVertex3f (650-wall/2, 3950-wall/2, 0.0);
      glVertex3f (650-wall/2, 2175+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);							// This is a room
      glVertex3f (100+wall, 3750+wall/2, 0.0);
      glVertex3f (100+wall, 4350-wall, 0.0);
      glVertex3f (350-wall/2, 4350-wall, 0.0);
      glVertex3f (350-wall/2, 3750+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);							// This is a room
      glVertex3f (1850+wall/2, 3750+wall/2, 0.0);
      glVertex3f (1850+wall/2, 4350-wall, 0.0);
      glVertex3f (2100-wall, 4350-wall, 0.0);
      glVertex3f (2100-wall, 3750+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);							// There are classrooms
      glVertex3f (1550+wall/2, 1775+wall/2, 0.0);
      glVertex3f (1550+wall/2, 3950-wall/2, 0.0);
      glVertex3f (2100-wall, 3950-wall/2, 0.0);
      glVertex3f (2100-wall, 1775+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);							// There are rooms
      glVertex3f (800+wall/2, 700+wall/2, 0.0);
      glVertex3f (800+wall/2, 2150-wall/2, 0.0);
      glVertex3f (1400-wall/2, 2150-wall/2, 0.0);
      glVertex3f (1400-wall/2, 700+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);							// There are rooms
      glVertex3f (800+wall/2, 2250+wall/2, 0.0);
      glVertex3f (800+wall/2, 3750-wall/2, 0.0);
      glVertex3f (1400-wall/2, 3750-wall/2, 0.0);
      glVertex3f (1400-wall/2, 2250+wall/2, 0.0);
   glEnd();				
   glBegin (GL_POLYGON);							// There are rooms
      glVertex3f (2100+wall/2, 500+wall/2, 0.0);
      glVertex3f (2100+wall/2, 1900-wall, 0.0);
      glVertex3f (3600-wall, 1900-wall, 0.0);
      glVertex3f (3600-wall, 500+wall/2, 0.0);
   glEnd();		
   glBegin (GL_POLYGON);							// This is a room
      glVertex3f (100+wall, 500+wall/2, 0.0);
      glVertex3f (100+wall, 1175-wall/2, 0.0);
      glVertex3f (650-wall/2, 1175-wall/2, 0.0);
      glVertex3f (650-wall/2, 500+wall/2, 0.0);
   glEnd();			
   glBegin (GL_POLYGON);                     // A sneaky room between two offices (gocha@@@)
      glVertex3f (350+wall/2+1500*1/5, 4100+wall/2, 0.0);
      glVertex3f (350+wall/2+1500*1/5, 4350-wall, 0.0);
      glVertex3f (350-wall/2+1500*3/5, 4350-wall, 0.0);
      glVertex3f (350-wall/2+1500*3/5, 4100+wall/2, 0.0);
   glEnd();
   glColor3f (Office, 0.95, 0.8);	         // Start offices
   for(num = 0; num < 7; num++){
      glBegin (GL_POLYGON);                     
      glVertex3f (107.5+wall/2+2000*num/7, 100+wall, 0.0);
      glVertex3f (107.5+wall/2+2000*num/7, 350-wall/2, 0.0);
      glVertex3f (107.5-wall/2+2000*(1+num)/7, 350-wall/2, 0.0);
      glVertex3f (107.5-wall/2+2000*(1+num)/7, 100+wall, 0.0);
   glEnd();
   }					
      glBegin (GL_POLYGON);
      glVertex3f (100+wall, 350+wall/2, 0.0);
      glVertex3f (100+wall, 500-wall/2, 0.0);
      glVertex3f (350-wall/2, 500-wall/2, 0.0);
      glVertex3f (350-wall/2, 350+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (350+wall/2, 4100+wall/2, 0.0);
      glVertex3f (350+wall/2, 4350-wall, 0.0);
      glVertex3f (350-wall/2+1500*1/5, 4350-wall, 0.0);
      glVertex3f (350-wall/2+1500*1/5, 4100+wall/2, 0.0);
   glEnd();
   for(num = 0; num < 2; num++){
      glBegin (GL_POLYGON);
      glVertex3f (350+wall/2+1500*(3+num)/5, 4100+wall/2, 0.0);
      glVertex3f (350+wall/2+1500*(3+num)/5, 4350-wall, 0.0);
      glVertex3f (350-wall/2+1500*(4+num)/5, 4350-wall, 0.0);
      glVertex3f (350-wall/2+1500*(4+num)/5, 4100+wall/2, 0.0);
   glEnd();
   }                                         // That's done for the offices
   glColor3f (0.95, Maker, 0.8);
   glBegin (GL_POLYGON);							// This is Makerspace
      glVertex3f (100+wall, 1175+wall/2, 0.0);
      glVertex3f (100+wall, 2175-wall/2, 0.0);
      glVertex3f (650-wall/2, 2175-wall/2, 0.0);
      glVertex3f (650-wall/2, 1175+wall/2, 0.0);
   glEnd();
   glColor3f (0.95, Six, 0.8);
   glBegin (GL_POLYGON);							// Classroom 246
      glVertex3f (1550+wall/2, 1137.5+wall/2, 0.0);
      glVertex3f (1550+wall/2, 1775-wall/2, 0.0);
      glVertex3f (2100-wall, 1775-wall/2, 0.0);
      glVertex3f (2100-wall, 1137.5+wall/2, 0.0);
   glEnd();
   glColor3f (0.95, 0.95, Three);
   glBegin (GL_POLYGON);							// Classroom 243
      glVertex3f (1550+wall/2, 500+wall/2, 0.0);
      glVertex3f (1550+wall/2, 1137.5-wall/2, 0.0);
      glVertex3f (2100-wall, 1137.5-wall/2, 0.0);
      glVertex3f (2100-wall, 500+wall/2, 0.0);
   glEnd();											// That's all for the rooms in Science Center
   glColor3f (1.0, 1.0, 1.0);						// Color of walkway and stairway
   glBegin (GL_POLYGON);							// Start of hallways
      glVertex3f (350+wall/2, 350+wall/2, 0.0);
      glVertex3f (350+wall/2, 500-wall/2, 0.0);
      glVertex3f (2100+wall/2, 500-wall/2, 0.0);
      glVertex3f (2100+wall/2, 350+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);							
      glVertex3f (650+wall/2, 350+wall/2, 0.0);
      glVertex3f (650+wall/2, 4100-wall/2, 0.0);
      glVertex3f (800-wall/2, 4100-wall/2, 0.0);
      glVertex3f (800-wall/2, 350+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);							
      glVertex3f (1400+wall/2, 350+wall/2, 0.0);
      glVertex3f (1400+wall/2, 4100-wall/2, 0.0);
      glVertex3f (1550-wall/2, 4100-wall/2, 0.0);
      glVertex3f (1550-wall/2, 350+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (350+wall/2, 3950+wall/2, 0.0);
      glVertex3f (350+wall/2, 4100-wall/2, 0.0);
      glVertex3f (1850-wall/2, 4100-wall/2, 0.0);
      glVertex3f (1850-wall/2, 3950+wall/2, 0.0);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (650+wall/2, 2150+wall/2, 0.0);
      glVertex3f (650+wall/2, 2250-wall/2, 0.0);
      glVertex3f (1550-wall/2, 2250-wall/2, 0.0);
      glVertex3f (1550-wall/2, 2150+wall/2, 0.0);
   glEnd();	
   glBegin (GL_POLYGON);	
      glVertex3f (2100+wall/2, 100+wall, 0.0);
      glVertex3f (2100+wall/2, 500-wall/2, 0.0);
      glVertex3f (3600-wall, 500-wall/2, 0.0);
      glVertex3f (3600-wall, 100+wall, 0.0);
   glEnd();                                     // Done for the hallways
   glBegin (GL_POLYGON);   
      glVertex3f (2400+wall/2, 90, 0.0);
      glVertex3f (2400+wall/2, 120, 0.0);
      glVertex3f (2700-wall, 120, 0.0);
      glVertex3f (2700-wall, 90, 0.0);
   glEnd();										            // IMPORTANT DOOOOOOOR
   glColor3f (Stair,1.0,Stair);
   glBegin (GL_POLYGON);
      glVertex3f (800+wall/2, 500+wall/2, 0.0);
      glVertex3f (800+wall/2, 700-wall/2, 0.0);
      glVertex3f (1400-wall/2, 700-wall/2, 0.0);
      glVertex3f (1400-wall/2, 500+wall/2, 0.0);
   glEnd();											// Stairway #1
   glBegin (GL_POLYGON);
      glVertex3f (800+wall/2, 3750+wall/2, 0.0);
      glVertex3f (800+wall/2, 3950-wall/2, 0.0);
      glVertex3f (1400-wall/2, 3950-wall/2, 0.0);
      glVertex3f (1400-wall/2, 3750+wall/2, 0.0);
   glEnd();											// Stairway #2
   glColor3f (1.0, 0.0, 0.0);             // Time for the Path to the Stairways  
   if(Path == 0){
      glBegin (GL_LINE_STRIP);
         glVertex3f(2550,100,0.0);
      glEnd();
   }
   else if(Path == 1){
      glBegin (GL_LINE_STRIP);
         glLineWidth(10);
         glLineStipple(1,0x00FF);
         glVertex3f(2550,100,0.0);
         glVertex3f(2550,425,0.0);
      glEnd();
   }
   else if(Path == 2){
      glBegin (GL_LINE_STRIP);
         glLineWidth(10);
         glLineStipple(1,0x00FF);
         glVertex3f(2550,100,0.0);
         glVertex3f(2550,425,0.0);
         glVertex3f(1475,425,0.0);
      glEnd();
   }
   else if(Path == 3){
      glBegin (GL_LINE_STRIP);
         glLineWidth(10);
         glLineStipple(1,0x00FF);
         glVertex3f(2550,100,0.0);
         glVertex3f(2550,425,0.0);
         glVertex3f(1475,425,0.0);
         glVertex3f(1475,600,0.0);
      glEnd();
   }
   else if(Path == 4){
      glBegin (GL_LINE_STRIP);
         glLineWidth(10);
         glLineStipple(1,0x00FF);
         glVertex3f(2550,100,0.0);
         glVertex3f(2550,425,0.0);
         glVertex3f(1475,425,0.0);
         glVertex3f(1475,600,0.0);
         glVertex3f(1300,600,0.0);
      glEnd();
      glBegin (GL_LINE_STRIP);
         glVertex3f(1350,650,0.0);
         glVertex3f(1300,600,0.0);
         glVertex3f(1350,550,0.0);
      glEnd();
   }
   if(Lbl == true){
      glColor3f(0.0,0.0,0.0);
      glRasterPos2i(250, 3150);
      i = 0;
      while (Room_ [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, Room_ [i]);
         i++;
      }
      glRasterPos2i(250, 1675);
      i = 0;
      while (Make_ [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, Make_ [i]);
         i++;
      }
      glRasterPos2i(250, 800);
      i = 0;
      while (Room_ [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, Room_ [i]);
         i++;
      }
      glRasterPos2i(975, 3150);
      i = 0;
      while (Room_ [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, Room_ [i]);
         i++;
      }
      glRasterPos2i(975, 1500);
      i = 0;
      while (Room_ [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, Room_ [i]);
         i++;
      }
      glRasterPos2i(1700, 2700);
      i = 0;
      while (Room_ [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, Room_ [i]);
         i++;
      }
      glRasterPos2i(2650, 1200);
      i = 0;
      while (Room_ [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, Room_ [i]);
         i++;
      }
      glRasterPos2i(1750, 1450);
      i = 0;
      while (rm_6 [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, rm_6 [i]);
         i++;
      }
      glRasterPos2i(1750, 800);
      i = 0;
      while (rm_3 [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, rm_3 [i]);
         i++;
      }
      glRasterPos2i(160, 400);
      i = 0;
      while (rm_down_left [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, rm_down_left [i]);
         i++;
      }
      glRasterPos2i(430, 4225);
      i = 0;
      while (rm_2_1 [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, rm_2_1 [i]);
         i++;
      }
      glRasterPos2i(700, 4225);
      i = 0;
      while (rm_2_2 [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, rm_2_2 [i]);
         i++;
      }
      glRasterPos2i(1330, 4225);
      i = 0;
      while (rm_2_3 [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, rm_2_3 [i]);
         i++;
      }
      glRasterPos2i(1630, 4225);
      i = 0;
      while (rm_2_4 [i] != '\0') {
         glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, rm_2_4 [i]);
         i++;
      }
      for(num_ = 0; num_ < 7; num_++){
         glRasterPos2i(160+2000*num_/7, 215);
         i = 0 + num_*5;
         while (rm_down [i] != '\n') {
            glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, rm_down [i]);
            i++;
         }
      }
   }
}
void myClass :: init ()
{
   /* i.e., black */
   glClearColor (1.0, 1.0, 1.0, 0.0);
   /* type of projection */
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   /* set up viewport 0 to 1 (x and y) and orthographic projection -1 to 1 */
   glOrtho (0.0, 5000.0, 0.0, 5000.0, -1.0, 1.0);
}
/*
 * The OpenGL functions are NOT part of the class directly, but can
 * call methods of your class because the instance was declared globally.
 */
void display ()
{
   /* here's where OOP comes into play */
   drawstuff.myDisplay();
   /* flush the buffer (i.e., draw the thing!) */
   glFlush ();
}
void keyboard (unsigned char key, int x, int y)
{
   /* here's where OOP comes into play */
   drawstuff.mykeyboard(key, x, y);
   /* flush the buffer (i.e., draw the thing!) */
   //glFlush ();
}
void myClass::mykeyboard (unsigned char key, int x, int y)
{
   switch (key){
   		case '3':	Three = 0.2;
   			break;
   		case '6':	Six = 0.5;
   			break;
   		case 'm':	Maker = 0.3;
   			break;
   		case 'f':	Office = 0.0;
   			break;
   		case 's':	if(Stair == 1.0)	
   		 				Stair = 0.5;
   		 				else 
   		 					Stair = 1.0;
   		 	break;
   		case 'p':	if(Path < 4)
                     Path++;
                     else
                     Path = 0;
   		 	break;
   		case 'L':	if(Lbl == false)
                     Lbl = true;
                     else
                     Lbl= false;
   		 	break;
   		case 27  :
   		case 'q' : cout << "Good Bye~~";
         exit (1);
      }
   if(key != '3'&& key != '6'&& key != 'm'&& key != 'f'&& key != 's'&& key != 'p'&& key != 'L'&&key != 'q')
      cout << "Not a valid input read the instruction again!" << endl;
   if(key == 'l')
      cout << "Dude, you should type capitalized L " << endl;
   glutPostRedisplay();
}
int main (int argc, char** argv)
{
   instruction();
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   /* set up the window size, in pixels */
   glutInitWindowSize (5000, 5000); 
   /* put the window at 100, 100 on user's screen */
   glutInitWindowPosition (100, 100);
   /* make a title for window */
   glutCreateWindow ("Science Center 2F");
   /* set up some GL stuff; use class method */
   drawstuff.init ();
   /* call display function, which in turn will call class method */
   glutDisplayFunc(display); 
   //GlutPostRedisplay();
   /* can do the same trick with the keyboard function as above */
   glutKeyboardFunc (keyboard);
   //glClearColor(0.0;0.0;0.0;0.0);
   /* repeat these things indefinitely */
   glutMainLoop();
   /* we're done! */
   return 0; 
}