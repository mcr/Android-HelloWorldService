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

class HelloWorldService;

class IHelloWorldService: public android::IInterface {
public:
// expand macro DECLARE_META_INTERFACE
	static const android::String16 descriptor;
	static android::sp<IHelloWorldService> asInterface(const android::sp<android::IBinder>& obj);   
	virtual android::String16 getInterfaceDescriptor() const;
};


class BnHelloWorldService : public android::BnInterface<IHelloWorldService>
{
	// not sure.
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

    mutable     android::Mutex                       mLock;
    android::SortedVector< android::wp<Client> >     mClients;
    int32_t                     mNextConnId;
};


#endif
