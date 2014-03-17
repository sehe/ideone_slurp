// error:	OK
// langId:	4
// langName:	Python
// langVersion:	python 2.7.3
// time:	0.01
// date:	2011-09-14 16:47:46
// status:	0
// result:	15
// memory:	6660
// signal:	0
// public:	true
// ------------------------------------------------
#!/usr/bin/python
ROWS = 2
COLS = 3

## different cell representations
def cell(r,c): 
    ## exercise for the reader: _gues_ which of the following is the fastest
    ## ...
    ## then profile it :)
    index = COLS*(r) + c
    # return [ r,c ]
    # return ( r,c )
    # return index
    # return "(%i,%i)" % (r,c)

    def baseN(num,b,numerals="abcdefghijklmnopqrstuvwxyz"):
        return ((num == 0) and numerals[0]) or (baseN(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b])

    return baseN(index, 26)

ORIGIN = cell(0,0)

def debug(t): pass; #print t
def dump(grid): print("\n".join(map(str, grid)))

def print_path(path):
    ## Note: to 'normalize' to start at (1,1) node:
    # while ORIGIN != path[0]: path = path[1:] + path[:1] 
    print " -> ".join(map(str, path))

def bruteforce_hamiltonians(grid, whenfound):
    def inner(grid, whenfound, partial):

        cols = len(grid[-1]) # number of columns remaining in last rank
        if cols<1:
            # assert 1 == len(set([ len(r) for r in grid ])) # for debug only
            whenfound(partial)                             # disable when benchmarking
            pass
        else:
            #debug(" ------ cols: %i ------- " % cols)

            for i,rank in enumerate(grid):
                if len(rank)<cols: continue
                #debug("debug: %i, %s (partial: %s%s)" % (i,rank, "... " if len(partial)>3 else "", partial[-3:]))
                for ci,cell in enumerate(rank):
                    partial.append(cell)
                    grid[i] = rank[:ci]+rank[ci+1:] # modify grid in-place, keeps rank

                    inner(grid, whenfound, partial)

                    grid[i] = rank # restore in-place
                    partial.pop()
                break
        pass
    # start of recursion
    inner(grid, whenfound, [])

grid = [ [ cell(c,r) for r in range(COLS) ] for c in range(ROWS) ]

dump(grid)

bruteforce_hamiltonians(grid, print_path)

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
['a', 'b', 'c']
['d', 'e', 'f']
a -> d -> b -> e -> c -> f
a -> d -> b -> f -> c -> e
a -> d -> c -> e -> b -> f
a -> d -> c -> f -> b -> e
a -> e -> b -> d -> c -> f
a -> e -> b -> f -> c -> d
a -> e -> c -> d -> b -> f
a -> e -> c -> f -> b -> d
a -> f -> b -> d -> c -> e
a -> f -> b -> e -> c -> d
a -> f -> c -> d -> b -> e
a -> f -> c -> e -> b -> d
b -> d -> a -> e -> c -> f
b -> d -> a -> f -> c -> e
b -> d -> c -> e -> a -> f
b -> d -> c -> f -> a -> e
b -> e -> a -> d -> c -> f
b -> e -> a -> f -> c -> d
b -> e -> c -> d -> a -> f
b -> e -> c -> f -> a -> d
b -> f -> a -> d -> c -> e
b -> f -> a -> e -> c -> d
b -> f -> c -> d -> a -> e
b -> f -> c -> e -> a -> d
c -> d -> a -> e -> b -> f
c -> d -> a -> f -> b -> e
c -> d -> b -> e -> a -> f
c -> d -> b -> f -> a -> e
c -> e -> a -> d -> b -> f
c -> e -> a -> f -> b -> d
c -> e -> b -> d -> a -> f
c -> e -> b -> f -> a -> d
c -> f -> a -> d -> b -> e
c -> f -> a -> e -> b -> d
c -> f -> b -> d -> a -> e
c -> f -> b -> e -> a -> d

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
