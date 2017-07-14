#ifndef __IHEXOUT_H
#define __IHEXOUT_H

#include <stdint.h>

class ihexout
{
 public:
  int write(uint16_t count,uint16_t base=0);
 protected:
  virtual int putch(int c)=0;
  virtual int crlf(void)  { if (putch('\r')==-1) return -1; return putch('\n');  }
  virtual uint8_t getnxtbyte(uint16_t add)=0;
  virtual int start(void)  {  return 0;  }
  virtual int eof(void)  { return 0;  }
  uint8_t digit(uint8_t d);

   
};


#endif
