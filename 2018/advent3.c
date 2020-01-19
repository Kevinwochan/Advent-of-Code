set i 31 i = 31
set a 1  a = 1
mul p 17 p = 0
jgz p p  if ( p > 0) jump to p(0)
mul a 2  a = 2; a = 4 ; a = 8; .. a = 2^30 OR 31  
add i -1 i = 30; i = 29; i = 28 ... i = 0
jgz i -2 if ( i > 0 ) jump up 2 lines  
add a -1 2^30 - 1 
set i 127 i = 127
set p 735 p = 735
mul p 8505  p = 735 * 8505
mod p a   p = 735 * 8505 * (2^30 - 1)
mul p 129749 p = 735 * 8505 * (2^30 - 1) * 129749
add p 12345 p = 12345 + 735 * 8505 * (2^30 - 1) * 129749
mod p a   p = 12345 + 735 * 8505 * (2^30 - 1) * 129749% (2^30 - 1)
set b p   b = 12345 + 735 * 8505 * (2^30 - 1) * 129749% (2^30 - 1)  
mod b 10000 b = 
snd b rcv = b 
add i -1   i = 126
jgz i -9   
jgz a 3
rcv b
jgz b -1
set f 0
set i 126
rcv a
rcv b
set p a
mul p -1
add p b
jgz p 4
snd a
set a b
jgz 1 3
snd b
set f 1
add i -1
jgz i -11
snd a
jgz f -16
jgz a -19
