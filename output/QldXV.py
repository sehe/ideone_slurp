// error:	OK
// langId:	4
// langName:	Python
// langVersion:	python 2.7.3
// time:	-1
// date:	2011-11-14 14:03:14
// status:	0
// result:	13
// memory:	6692
// signal:	24
// public:	true
// ------------------------------------------------
#!/usr/bin/env python
from array import *;

positions = set()

def is_gameover(board):
  rows = [ board[i:i+3]                 for i in range(len(board)) if i%3==0 ];
  cols = [ [ board[i], board[i+3], board[i+6] ] for i in range(3) ];
  diag = [ board[0:9:4], board[2:8:2] ];
  for triplet in rows + cols + diag:
    if triplet[0]!='.' and (triplet[0] == triplet[1] == triplet[2]):
      return True
  return False

def generate(board, asX = True):
  positions.add(array('c', board).tostring())

  if not is_gameover(board):
    for i,c in enumerate(board):
      if '.'==c:
        generate(board[:i] + [ "XO"[asX] ] + board [i+1:], not asX)

generate(['.' for x in range(9)])

for p in positions:
  print p

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
