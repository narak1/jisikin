      integer k
      real x, y, r, z11, z2

 90	FORMAT('          ',I3,'  ',F10.3,'  ',F10.3,'  ',G10.3)

      print*, 'Input ����, ������, ����: '
      read(5,*)x,y,r

      write(6,*)'         ���   ������Ȳ     ������'
      k=0
      z1=x
 10   k=k+1
      z11=z1*(1+r/100)
      z2=(z11-y)
      write(6,90)k, z11 , z2 , z11
      if(k.ge.30) then
          go to 20
      else if(z2.le.y) then
          go to 20
      else if(z2.gt.y) then
          z1=z2
          go to 10
      end if
  20  stop
      end
