	Program Bisection
	IMPLICIT NONE
	real*8	xl, xr, x
	real*8	yl, yr, y;
	real*8	eps;
	real*8	func
	integer i

	eps = 1.0e-6
	xl = -2.0
	xr = 0.0
	yl = func(xl)
	yr = func(xr)
	write(*,20) xl, yl
	write(*,20) xr, yr
	print*, '----------------'
 20   format('func(',f4.2,')=',f9.6)

	if (yl * yr > 0) then
		write(*,*) 'cannot'
		go to 10
	end if

	do i=0, 100
		x = (xl + xr) / 2.0
		y = func(x)
		write(*,20) x, y
		if( abs(y) < eps ) exit
		if( yl * y > 0 ) then
			xl = x
		else
			xr = x
		end if
	end do

	write(*,*) 'Solution = ', x

 10	stop
	End Program Bisection

      real*8 function func(x)
c--------------------------------------------
      implicit none
      real*8 x
      func = x * x - sin(x) - 1.0
      return
      end

