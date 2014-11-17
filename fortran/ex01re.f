	Program ex01
	IMPLICIT NONE
	real	a, b, c, d
	integer i
	REAL	PI
	PI = 3.141592653589793238462643383279502884197169399375
 
	print*, 'input tree number : '
	read(*,*) a, b, c
 
	if (a < b) then
		d = a
		a = b
		b = d
	end if
	if (a .lt. c) then
		d = a
		a = c
		c = d
	end if
	if (b.lt.c) then
		d = b
		b = c
		c = d
	end if
	write(*,*) a, b, c
 
 20	FORMAT('ang=',F4.1,', radian=',F5.3,', value=',F7.5)
 
	do i=0, 9
		a=i*10.0!makedegree
		b = a * PI / 180.0		! make radian
		c = sin(b) + cos(b)
		write(*,20) a, b, c
	end do
 
	End Program ex01
