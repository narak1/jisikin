	Program NewtonRaphson
	IMPLICIT NONE
	real*8	x, y
	real*8	eps;
	real*8	func, fp
	integer i

	eps = 1.0e-6
	x = -2.0
	y = func(x)
	write(*,20) x, y
	print*, '----------------'
 20   format('func(',f4.2,')=',f9.6)

	do i=0, 100
		x = x - y / fp(x)
		y = func(x)
		write(*,20) x, y
		if( abs(y) < eps ) exit
	end do

	write(*,*) 'Solution = ', x

 10	stop
	End Program NewtonRaphson

      real*8 function func(x)
c--------------------------------------------
      implicit none
      real*8 x
      func = x * x - sin(x) - 1.0
      return
      end

      real*8 function fp(x)
c--------------------------------------------
      implicit none
      real*8 x
      fp = 2.0 * x - cos(x)
      return
      end
