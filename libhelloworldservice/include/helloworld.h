#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#include <binder/IBinder.h>

#define HELLOWORLD_NAME "org.credil.helloworldservice.HelloWorldServiceInterface"


#include "android-IInterface.h"



class IHelloWorldClient: public android::IInterface {
protected:
    enum {
            HW_HELLOTHERE=  android::IBinder::FIRST_CALL_TRANSACTION
    };

public:
        android_DECLARE_META_INTERFACE(HelloWorldClient)   // no trailing ;

        virtual void hellothere(const char *str) = 0;
};


#endif
