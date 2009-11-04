#ifndef _HELLOWORLDSERVICE_H_
#define _HELLOWORLDSERVICE_H_

#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/IInterface.h>
#include <utils/Parcel.h>
#include <utils/String16.h>
#include <utils/threads.h>
#include <string.h>

#include <utils/Log.h>

#include "helloworld.h"

class IHelloWorldService: public android::IInterface {
public:

        android_DECLARE_META_INTERFACE(HelloWorldService)

        void hellothere(const char *str);
};

class BnHelloWorldService : public android::BnInterface<IHelloWorldService>
{
	// not sure.
        // actual dispatch.
};

class HelloWorldService : public BnHelloWorldService
{
	class Client;

public:
    static  void                instantiate();

//    class Client : public BnMediaPlayer {
//
//        // IHelloWorld interface
//    }

                            HelloWorldService();
    virtual                 ~HelloWorldService();

    android::status_t onTransact(uint32_t code,
                                 const android::Parcel &data,
                                 android::Parcel *reply,
                                 uint32_t flags);

    mutable     android::Mutex                       mLock;
    android::SortedVector< android::wp<Client> >     mClients;
    int32_t                     mNextConnId;
};


#endif
