#ifndef _HELLOWORLDSERVICE_H_
#define _HELLOWORLDSERVICE_H_

#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/String16.h>
#include <utils/threads.h>
#include <string.h>

#include <utils/Log.h>

#include "IHelloWorld.h"

namespace android {


/*
 * The native class implementation extends BnInterface
 * this is the instance that will be given to the service
 * manager
 *
 * class BnInterface<INTERFACE> extends BBinder
 *   + queryLocalInterface(descriptor)
 * BnInterface is the base implementation for a native (local) IInterface
 * B  stands for Base and "n" for native.
 *
 * The BBinder class is the standard implementation of IBinder for a IInterface object
 * class BBinder extends IBinder
 *   + getInterfaceDescriptor()
 *   + attachObject(id ...) // housekeeping of clients
 *   + findObject(id ...)
 *   + detachObject(id ...);
 *
 * This implementation is kept as simple as possible. if you need more control
 * over the objects attached to the service you can implement the attachObject/detachObject
 **/
class HelloWorldService : public BnInterface<IHelloWorld>
{
public:
    virtual                 ~HelloWorldService(){};

    static  void                instantiate();

    void hellothere(const char *str);

    status_t onTransact(uint32_t code,
                                 const android::Parcel &data,
                                Parcel *reply,
                                 uint32_t flags);
private:
    /* Private constructor to force the usage the  instantiate method */
    HelloWorldService(){};
};

}

#endif
