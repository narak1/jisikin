	dimension a(3,3), b(3,3), c(3,3)
	data a/4,1,0,3,1,2,2,1,8/,b/6,1,2,3,5,9,1,2,4/
	do 10 i=1,3
	do 20 j=1,3
	c(i,j) = 0
	do 30 k=1,3
	c(i,j)=c(i,j)+a(i,k)*b(k,j)
	print*, i, j, k, c(i,j)
  30  continue
  20  continue
  10  continue
	write(*,"( 'a=')")
	do 40 i=1,3
	write(*,110) a(i,1),a(i,2),a(i,3)
  40  continue
	write(*,"( 'b=')")
	do 50 i=1,3
	write(*,110) b(i,1),b(i,2),b(i,3)
  50  continue
	write(*,"( 'c=')")
	do 60 i=1,3
	write(*,110) c(i,1),c(i,2),c(i,3)
  60  continue
  110 format(3f15.3)
	stop
	end
