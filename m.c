/*
  Slightly inpired by:
  https://stackoverflow.com/questions/3585871/how-can-i-get-the-current-mouse-pointer-position-co-ordinates-in-x
*/

#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void getMousePosition( int* x, int* y );
void printMousePosition();
void setMousePosition( int x, int y );
void moveMouse( int deltaX, int deltaY );
void printHelp();


int main(int argc, char *argv[]) {
  
  if ( argc == 1 ) {
    printHelp();
    return 0;
  }
  
  if( !strcmp( argv[1], "setmouse") ){
    if( argc != 4 ){
      printHelp();
      return 0;
    }
    
    int x = atoi( argv[2]);
    int y = atoi( argv[3]);
    setMousePosition( x, y );
      
  }else if(!strcmp( argv[1], "movemouse")){
    if( argc != 4 ){
      printHelp();
      return 0;
    }
    
    int dx = atoi( argv[2]);
    int dy = atoi( argv[3]);
    moveMouse( dx, dy );
    
  }else if(!strcmp( argv[1], "print")){
    printMousePosition();
    
    
  }else if(!strcmp( argv[1], "help") || !strcmp( argv[1], "--help") || !strcmp( argv[1], "-h")){
    printHelp();
    return 0;
  }else{
    printHelp();
    return 0;
  }
  
  //printMousePosition();
  //setMousePosition( 50, 100 );
  //moveMouse(5, 10);
  return 0;
}


void printHelp(){
  printf("use one of the following options:\n");
  printf("setmouse: jump the mouse pointer to a given position\n");
  printf("\tm setmouse x y (where x and y are positive integers)\n");
  printf("movemouse: displace the mouse pointer with given deltas\n");
  printf("\tm movemouse deltaX deltaY (where deltaX and deltaY are integers)\n");
  printf("print: display the mouse pointer position as \"x,y\"\n");
  printf("\tm print\n");
}


void setMousePosition( int x, int y ){
  Display *display = XOpenDisplay(NULL);
  Window defaultWindow = XRootWindow(display, 0);
  XWarpPointer(display, None, defaultWindow, 0, 0, 0, 0, x, y);
  XCloseDisplay(display);
}


void moveMouse( int deltaX, int deltaY ){
  int x = 0;
  int y = 0;
  
  getMousePosition( &x, &y );
  setMousePosition( x + deltaX, y + deltaY );
}


void getMousePosition( int* x, int* y ){
  Display *display = XOpenDisplay(NULL);
  Window defaultWindow = XRootWindow(display, 0); 
  Window windowReturned;
  int root_x, root_y;
  int win_x, win_y;
  unsigned int maskReturn;
  
  Bool result = XQueryPointer(display, defaultWindow, &windowReturned,
          &windowReturned, &root_x, &root_y, &win_x, &win_y,
          &maskReturn);
          
  if( result ){
    (*x) = root_x;
    (*y) = root_y;
  }else{
    (*x) = -1;
    (*y) = -1;
  }
          
  XCloseDisplay(display);
}


void printMousePosition(){
  int x = 0;
  int y = 0;
  
  getMousePosition( &x, &y );
  printf("%d,%d\n", x, y);
}
