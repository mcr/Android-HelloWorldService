#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#define HELLOWORLD_NAME "org.credil.helloworldservice.HelloWorldServiceInterface"

#include "android-IInterface.h"

enum {
        HW_HELLOTHERE=1,
};


class IHelloWorldClient: public android::IInterface {
public:
        android_DECLARE_META_INTERFACE(HelloWorldClient)   // no trailing ;

        virtual void hellothere(const char *str) = 0;
};

#endif
