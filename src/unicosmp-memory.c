/*
* File:    unicos-memory.c
* Author:  Kevin London
*          london@cs.utk.edu
*
* Mods:    <your name here>
*          <your email address>
*/

#include "papi.h"
#include "papi_internal.h"

int get_memory_info(PAPI_hw_info_t * mem_info)
{
   inventory_t *curr;
   PAPI_mh_level_t *L = mem_info->mem_hierarchy.level;

   return PAPI_OK;
}

int _papi_hwd_get_dmem_info(PAPI_dmem_info_t *d)
{
	/* This function has been reimplemented 
		to conform to current interface.
		It has not been tested.
		Nor has it been confirmed for completeness.
		An identical copy exists inside irix-memory.c
		If you change this one, check that one too.
		dkt 05-10-06
	*/

   pid_t pid = getpid();
   prpsinfo_t info;
   char pfile[256];
   int fd;

   sprintf(pfile, "/proc/%05d", (int) pid);
   if ((fd = open(pfile, O_RDONLY)) < 0) {
      SUBDBG("PAPI_get_dmem_info can't open /proc/%d\n", (int) pid);
      return (PAPI_ESYS);
   }
   if (ioctl(fd, PIOCPSINFO, &info) < 0) {
      return (PAPI_ESYS);
   }
   close(fd);

   d->size = info.pr_size;
   d->resident = info.pr_rssize;
   d->high_water_mark = PAPI_EINVAL;
   d->shared = PAPI_EINVAL;
   d->text = PAPI_EINVAL;
   d->library = PAPI_EINVAL;
   d->heap = PAPI_EINVAL;
   d->locked = PAPI_EINVAL;
   d->stack = PAPI_EINVAL;
   d->pagesize = getpagesize();

   return (PAPI_OK);
}

/* old PAPI 2 implementation...
long _papi_hwd_get_dmem_info(int option)
{
   pid_t pid = getpid();
   prpsinfo_t info;
   char pfile[256];
   int fd;

   sprintf(pfile, "/proc/%05d", (int) pid);
   if ((fd = open(pfile, O_RDONLY)) < 0) {
      SUBDBG("open(/proc/%d) errno %d", (int) pid, errno);
      return (PAPI_ESYS);
   }
   if (ioctl(fd, PIOCPSINFO, &info) < 0) {
      return (PAPI_ESYS);
   }
   close(fd);

    switch(option) {
	case PAPI_GET_RESSIZE:
  	  return (info.pr_rssize);
	case PAPI_GET_SIZE:
          return (info.pr_size);
	case PAPI_GET_PAGESIZE:
	  return(getpagesize());
	default:
	  return(PAPI_EINVAL);
    }
}
*/
