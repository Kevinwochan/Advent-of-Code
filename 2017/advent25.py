#!/usr/bin/python
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

