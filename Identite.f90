program identite_main
  implicit none
  integer, parameter :: T = 2, N = 10
  real(8) :: A(T, T), S(T, T)

  ! Exemple de matrice
  A = reshape((/ 0.0d0, 1.0d0, &
                 0.125d0, 0.25d0/), shape(A))

  call Identite(A, N, T, S)

  print *, 'Resultat de la somme :'
  call print_matrix(S)

contains

  function factorial(n) result(fact)
    integer, intent(in) :: n
    real(8) :: fact
    integer :: i
    fact = 1.0d0
    if (n == 0) return
    do i = 1, n
      fact = fact * dble(i)
    end do
  end function factorial

  subroutine mat_mult(A, B, result, T)
    integer, intent(in) :: T
    real(8), intent(in) :: A(T,T), B(T,T)
    real(8), intent(out) :: result(T,T)
    integer :: i, j, k
    result = 0.0d0
    do i = 1, T
      do j = 1, T
        do k = 1, T
          result(i,j) = result(i,j) + A(i,k) * B(k,j)
        end do
      end do
    end do
  end subroutine mat_mult

  subroutine mat_power(A, power, T, result)
    integer, intent(in) :: power, T
    real(8), intent(in) :: A(T,T)
    real(8), intent(out) :: result(T,T)
    real(8) :: temp(T,T), inter(T,T)
    integer :: i, j

    ! Initialise à l'identité
    result = 0.0d0
    do i = 1, T
      result(i,i) = 1.0d0
    end do

    do i = 1, power
      call mat_mult(result, A, inter, T)
      result = inter
    end do
  end subroutine mat_power

  subroutine Identite(A, N, T, Somme)
    integer, intent(in) :: N, T
    real(8), intent(in) :: A(T,T)
    real(8), intent(out) :: Somme(T,T)
    real(8) :: pi, pj, coeff, temp(T,T)
    integer :: i, j

    Somme = 0.0d0

    do i = 0, N - 1
      pi = factorial(i)
      do j = 0, N - 1
        pj = factorial(j)
        coeff = (-1.0d0)**j / (pi * pj)
        call mat_power(A, i + j, T, temp)
        Somme = Somme + coeff * temp
      end do
    end do
  end subroutine Identite

  subroutine print_matrix(M)
    real(8), intent(in) :: M(:,:)
    integer :: i, j, T
    T = size(M,1)
    do i = 1, T
      do j = 1, T
        write(*,'(F10.4)', advance='no') M(i,j)
      end do
      print *
    end do
  end subroutine print_matrix

end program identite_main
