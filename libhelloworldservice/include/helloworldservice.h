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


class HelloWorldService : public BnInterface<IHelloWorld>
{
	class Client;

public:
    static  void                instantiate();
    void hellothere(const char *str);

                            HelloWorldService();
    virtual                 ~HelloWorldService();

    android::status_t onTransact(uint32_t code,
                                 const android::Parcel &data,
                                 android::Parcel *reply,
                                 uint32_t flags);

    mutable     android::Mutex                       mLock;
    android::SortedVector<wp<Client> >     mClients;
    int32_t                     mNextConnId;
};

}

#endif
