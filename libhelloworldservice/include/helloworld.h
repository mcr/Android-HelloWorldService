#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#include <binder/IInterface.h>

#define HELLOWORLD_NAME "org.credil.helloworldservice.HelloWorldServiceInterface"

namespace android {

class IHelloWorldInterface: public android::IInterface {
protected:
    enum {
            HW_HELLOTHERE=  android::IBinder::FIRST_CALL_TRANSACTION
    };

public:
        DECLARE_META_INTERFACE(HelloWorldInterface)   // no trailing ;
        virtual void hellothere(const char *str) = 0;
};

}
#endif
