#include "stdio.h"
#include <dlfcn.h>

void main()
{
  void* handler = dlopen("./libtest1_lib.so",RTLD_NOW | RTLD_DEEPBIND);

  if(dlerror() != NULL)
  {
        printf("%s",dlerror());
    }

  void(*test1_fun)()=dlsym(handler,"test1_fun");
    if(dlerror()!=NULL)
  {
    printf("%s",dlerror());
    }

  test1_fun();

  dlclose(handler);
}
