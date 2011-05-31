#define LOG_TAG "HelloWorldService-JNI"

#include <utils/Log.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#include <string.h>
#include <cutils/atomic.h>
#include <utils/Errors.h>
#include <binder/IServiceManager.h>
#include <utils/String16.h>
#include <binder/Parcel.h>

#include "helloworld.h"
//#include "helloworldservice.h"
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
                data.writeInterfaceToken(getInterfaceDescriptor());
                data.writeString16(android::String16(str));
                remote()->transact(HW_HELLOTHERE, data, &reply, android::IBinder::FLAG_ONEWAY);
        }

};

android_IMPLEMENT_META_INTERFACE(HelloWorldClient, HELLOWORLD_NAME)
