#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Cursor 
{
	char state;
	int position;
};

struct List 
{
	int position;
	void* next;
};

struct Tape 
{
	int size;
	int numberOfOnes;
	struct List listOfOnes;
};

bool valueAtTapePosition( void* tapePtr, int position)
{
	
}

void writeOnTape(bool newVal, int position, void* tapePtr)
{
	struct Tape* tape = tapePtr;
	if (valueAtTapePosition(void* tapePtr, int position) == 0 && newVal == 1) {
		tape->numberOfOnes++;
	}else if (valueAtTapePosition(void* tapePtr, int position) == 1 && newVal == 0)
		tape->numberOfOnes--;
	}
	tape->values[position] = newVal;
}

void moveOnTape(void* direction, void* cursorPtr)
{
	struct Cursor* cur = cursorPtr;
	if (direction == "left")
{
		cur->position =- 1;
	}else if (direction == "right")
{
		cur->position += 1;
	}
}

void action (void* cursorPtr, void* tapePtr)
{
	struct Cursor* cur = cursorPtr;
	char state = cur->state;
	int position = cur->position;
	struct Tape* tape = tapePtr;
	bool value = tape->values[position];
	switch(cur->state)
{
		case 'A':
		   if (value == 0)
{
			 writeOnTape(1, position, tape);
			 moveOnTape("right", cursorPtr);
			 cur->state = 'D';
		 }else if (value == 1)
{
			 writeOnTape(0,position, tape);
			 moveOnTape("left", cursorPtr);
			 cur->state = 'D';
			}
		case 'B':
		   if (value == 0)
{
			 writeOnTape(1, position, tape);
			 moveOnTape("right", cursorPtr);
			 cur->state = 'D';
		   }else if (value == 1)
{
			 writeOnTape(0,position, tape);
			 moveOnTape("right", cursorPtr);
			 cur->state = 'D';
			}
		case 'C':
		   if (value == 0)
{
			 writeOnTape(1, position, tape);
			 moveOnTape("left", cursorPtr);
			 cur->state = 'D';
		   }else if (value == 1)
{
			 writeOnTape(1, position, tape);
			 moveOnTape("left", cursorPtr);
			 cur->state = 'D';
			}
		case 'D':
		   if (value == 0)
{
			 writeOnTape(0,position, tape);
			 moveOnTape("left", cursorPtr);
			 cur->state = 'D';
		   }else if (value == 1)
{
			 writeOnTape(1, position, tape);
			 moveOnTape("right", cursorPtr);
			 cur->state = 'D';
			}
		case 'E':
		   if (value == 0)
{
			 writeOnTape(1, position, tape);
			 moveOnTape("left", cursorPtr);
			 cur->state = 'D';
		   }else if (value == 1)
{
			 writeOnTape(0,position, tape);
			 moveOnTape("right", cursorPtr);
			 cur->state = 'D';
			}
		case 'F':
		   if (value == 0)
{
			 writeOnTape(0,position, tape);
			 moveOnTape("right", cursorPtr);
			 cur->state = 'D';
		   }else if (value == 1)
{
			 writeOnTape(0,position, tape);
			 moveOnTape("right", cursorPtr);
			 cur->state = 'D';
			}
	}
}

void* initTape(int size)
{
	struct Tape* tape = malloc(sizeof(struct Tape));
	bool* values = malloc(size);
	tape->size = size*8;
	tape->numberOfOnes = 0;
	return tape;
}

void* initCursor()
{
	struct Cursor* cur = malloc(sizeof(struct Cursor));
	cur->position = 0;
	cur->state = 'A';
	return cur;
}

int main ()
{
	struct Tape* tape = initTape(100);
	struct Cursor* cursor = initCursor();
	for (int i = 1; i <= 12317297; i++)
{
		action(tape, cursor);
	}
	return EXIT_SUCCESS;
}
