# m
Like in "**m**ouse". This tiny C program, depending on the option you give, can:  
- make your mouse pointer move to a given screen position
- move your mouse pointer move of a given delta from its current position
- print in terminal the mouse position

**Use one of the following options**  
setmouse: jump the mouse pointer to a given position  
`m setmouse x y` (where x and y are positive integers)    

movemouse: displace the mouse pointer with given deltas  
`m movemouse deltaX deltaY` (where deltaX and deltaY are integers)  

print: display the mouse pointer position as "x,y"  
`m print`  

# TODO
- simulates cliks (right, left, middle)
- simulate scrolls
