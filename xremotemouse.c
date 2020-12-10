/* fakeMouse.c */
// gcc fakeMouse.c -o fakeMouse -lX11 -lXtst -lXext
// Mouse Button Mappings: The 2nd argument in XTestFakeButtonEvent() represent the specific mouse button. You can map 8 mouse buttons (1 – Left, 2 – Middle, 3 – Right, 5 – Scroll,..).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>

int main (int argc, char* argv[]){
  Display *dpy = NULL;
  XEvent event;
  char param[64];
  int sw=0;

  setenv("DISPLAY",":0",1);
                
  if(argc < 2){
      printf("Syntax: %s [l|m|r|d]\n", argv[0]);
      exit(1);
  }
  memset(param,0,sizeof(param));
  strcpy(param,argv[1]);
  if(!strcmp(param, "l")) sw=1;
  if(!strcmp(param, "m")) sw=2;
  if(!strcmp(param, "r")) sw=3;
  if(!strcmp(param, "d")) sw=1;

  dpy = XOpenDisplay (NULL);
  /* Get the current pointer position */
  XQueryPointer (dpy, RootWindow (dpy, 0), &event.xbutton.root,
   &event.xbutton.window, &event.xbutton.x_root,
   &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y,
   &event.xbutton.state);
 
  /* Fake the pointer movement to new relative position *
  XTestFakeMotionEvent (dpy, 0, event.xbutton.x + 100,
  event.xbutton.y + 50, CurrentTime);
  XSync(dpy, 0);
  sleep(3);
 
  /* Fake the pointer movement to new absolate position 
  XTestFakeMotionEvent (dpy, 0, 250, 250, CurrentTime);
  sleep(3);
 */
  /* Fake the mouse button Press and Release events */
  XTestFakeButtonEvent (dpy, sw, True,  CurrentTime);
  XTestFakeButtonEvent (dpy, sw, False, CurrentTime);
  if(!strcmp(param, "d")){
    usleep(3000);
    XTestFakeButtonEvent (dpy, sw, True,  CurrentTime);
    XTestFakeButtonEvent (dpy, sw, False, CurrentTime);
  }
  XCloseDisplay (dpy);
  return 0;
}
