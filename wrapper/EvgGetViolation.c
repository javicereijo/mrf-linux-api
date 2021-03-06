/**
@file
EvgGetViolation [ <evg-device> ] [ <clear> ] - Get/clear EVG Upstream RX violation flag.

@param <evg-device> Device name of EVG (defaults to /dev/ega3) if left blank.
@param <clear> 0/blank - do not clear, 1 - clear flag
*/

#include <stdint.h>
#include <endian.h>
#include <byteswap.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <signal.h>
#include "../api/egapi.h"

/** @private */
int main(int argc, char *argv[])
{
  struct MrfEgRegs *pEg;
  int              fdEg;
  int              i;

  if (argc < 1)
    {
      printf("Usage: %s /dev/ega3\n", argv[0]);
      printf("Assuming: /dev/ega3\n");
      argv[1] = "/dev/ega3";
    }

  fdEg = EvgOpen(&pEg, argv[1]);
  if (fdEg == -1)
    return errno;

  if (argc > 2)
    {
      i = atoi(argv[2]);
      EvgGetViolation(pEg, i);
    }
  
  i = EvgGetViolation(pEg, 0);
  printf("%d\n", (i ? 1 : 0));
  
  EvgClose(fdEg);

  return 0;
}
