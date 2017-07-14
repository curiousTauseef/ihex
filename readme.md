Intel Hex File I/O Classes
===
Quick and dirty hack so I can stop writing this code over and over. The classes are
virtual--you must derive from them to use them. However, you only have to provide
very simple helper objects. Each file has a demo section. Compile with -DDEMO=1 to generate
a test executable.

Reading
===
Use ihexread as a base class. You must provide two functions:
* int getch(void) - Return a character to process.
* void setmem(uint16_t add, uint8_t data) - Set memory at add to data

You may also provide any of the following if you like:
* int start(void) - Called before anything is processed, return 0 to proceed
* int error(void) - Called when there is an error, return whatever you want the error code to be
* void eof(void) - Called at successful end of input

To start the process, call read. A zero return value indicates success.

Writing
===
Use class ihexout as your base. You must implement:
* int putch(int c) - Write character and return 0. Return -1 for an error.
* uint8_t getnxtbyte(uint16_t add) - Get the byte at add of course, you can ignore add and just provide the "next" byte if you wish as this will be called in sequence and each address will be called exactly one time.

You may also provide any of the following:
* int crlf(void) - Print a line ending (default \r\n). Return non-zero to abort
* int start(void) - Called before processing. Return 0 to continue.
* int eof(void) - Called after processing. Return 0 to continue.

To start the process, call write(uint16_t count, uint16_t base). The base defaults to 0. Return value is a zero on success.