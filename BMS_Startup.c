#include "BMS_Common_Include.h"
#include "BMS_System_Check.h"
#include "BMS_Scheduler.h"

int main()
{
  /*System init*/
  void Fc_start_timer(void);
  Fc_System_init();
  /********/
  Fc_Cyclic_task();  
  return 0;
}/*end of main*/
