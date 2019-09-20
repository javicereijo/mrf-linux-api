/**
@file
EvgSeqRamStatus <evg-device> <ram> - Display EVG Sequence RAM status.

@param <evg-device> Device name of EVG (defaults to /dev/ega3) if left blank.
@param <ram> Sequence RAM number 0, 1
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
      printf("Usage: %s /dev/ega3 <trig>\n", argv[0]);
      printf("Assuming: /dev/ega3\n");
      argv[1] = "/dev/ega3";
    }

  fdEg = EvgOpen(&pEg, argv[1]);
  if (fdEg == -1)
    return errno;

  if (argc > 2)
    {
      i = atoi(argv[2]);
      EvgSeqRamStatus(pEg, i);
    }
 
  EvgClose(fdEg);

  return 0;
}
