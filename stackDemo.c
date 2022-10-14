#include <stdio.h>
#include <string.h>
#include "stackLinkedList.h"

int main( int argc, char *argv[])
{
  int i = 0;
  Stack *ps = createStack();
  char *buffer;

  while( i<=99 )
  {
    buffer = (char *)malloc( 3 );
    sprintf( buffer, "%d", i );
    push( ps, buffer );
    printf("push %d\n", i);
    i++;
  }
  printf("\n");
  while( i>=0 )
  {
    if(top(ps) != NULL)
    {
      printf("pop %s\n", top( ps ));
      free( pop( ps ) );
      i--;
    }
    else
		{
		 		break;
		}
  }
  freeStackElements( ps );
  freeStack( ps );
  return 0;
}