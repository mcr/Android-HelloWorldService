#define LOG_TAG "HelloWorldService-JNI"

#include <utils/Log.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#include <string.h>
#include <cutils/atomic.h>
#include <utils/Errors.h>
#include <utils/IServiceManager.h>
#include <utils/String16.h>
#include <utils/Parcel.h>

#include "helloworld.h"
#include "helloworldservice.h"
#include "utils/Log.h"

#include <unistd.h>



class BpHelloWorldClient: public android::BpInterface<IHelloWorldClient>
{
public:
        BpHelloWorldClient(const android::sp<android::IBinder>& impl)
                : android::BpInterface<IHelloWorldClient>(impl)
        {
        }
                
        void hellothere(const char *str)
        {
                android::Parcel data, reply;
                data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor());
                data.writeCString(str);
                remote()->transact(HW_HELLOTHERE, data, &reply, android::IBinder::FLAG_ONEWAY);
        }
};


/* From MACRO IMPLEMENT_META_INTERFACE() */
/*
 * INTERFACE = HelloWorldClient
 * NAME = "org.credil.helloworldservice.HelloWorldServiceInterface"
 *
 */
android_IMPLEMENT_META_INTERFACE(HelloWorldClient, HELLOWORLD_NAME)
