https://msyksphinz.hatenablog.com/entry/2030/01/01/000000

Cache 

Reading
1. Immediate Understand : https://www.youtube.com/watch?v=ISaYWm8T8n4
2. Tilelink : 
    a. https://msyksphinz.hatenablog.com/entry/2017/07/13/020620
3. https://prod.tinker.cc.gatech.edu/pdfs/MICRO44_Jesse_Beu.pdf

Basic MESI Concept
- Modified: The cache line is present only in the current cache, and is dirty; it has been modified from the value in main memory. The cache is required to write the data back to main memory at some
time in the future, before permitting any other read of the (no longer valid) main memory state.
- Exclusive: The cache line is present only in the current cache, but is clean; it matches main memory. It may be changed to the Shared state at any time, in response to a bus read request.
Alternatively, it may be changed to the Modified state when writing to it.
- Shared: Indicates that this cache line may be stored in other caches of the machine and is clean; it matches the main memory.  The line may be discarded (changed to the Invalid state) at any
time. Writes to SHARED cache lines get special handling ...
- Invalid: Indicates that this cache line is invalid (unused).
