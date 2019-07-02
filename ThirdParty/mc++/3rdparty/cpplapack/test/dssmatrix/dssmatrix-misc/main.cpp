/*****************************************************************************/
/*                                 noname                                    */
/*****************************************************************************/

//=============================================================================
#include <ctime>
#include "cpplapack.h"

//=============================================================================
/*! main */
int main(int argc, char** argv)
{
  srand(time(NULL));
  int N(5);
  
  //////// A ////////
  CPPL::dssmatrix A(N);
  A.put(0,0, 1.);
  A.put(3,2, 2.);
  A.put(1,3, 3.);
  A.put(3,4, 4.);
  A.put(1,2, 5.);
  A.put(2,2, 6.);
  A.put(4,1, 7.);
  A.put(1,1, 8.);
  std::cout << "A =\n" << A << std::endl;
  
  //////// B ////////
  CPPL::dssmatrix B(A);
  for(long i=0; i<B.n; i++){
    B.del(i,i);
  }
  std::cout << "B =\n" << B << std::endl;
  
  //////// reorder A ////////
  //A.checkup();
  std::cout << "==============================================" << std::endl;
  A.reorder(0);
  A.checkup();

  std::cout << "##############################################" << std::endl;

  //////// reorder B ////////
  //B.checkup();
  std::cout << "==============================================" << std::endl;
  B.reorder(1);
  B.checkup();
  
  return 0;
}

/*****************************************************************************/
