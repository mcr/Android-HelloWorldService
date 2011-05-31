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

namespace android {

class BpHelloWorldInterface: public BpInterface<IHelloWorldInterface>
{
public:
        BpHelloWorldInterface(const sp<IBinder>& impl)
                : BpInterface<IHelloWorldInterface>(impl)
        {
        }

                
        void hellothere(const char *str)
        {
                android::Parcel data, reply;
                data.writeInterfaceToken(getInterfaceDescriptor());
                data.writeString16(String16(str));
                remote()->transact(HW_HELLOTHERE, data, &reply, android::IBinder::FLAG_ONEWAY);
        }

};

/* TODO move this code to the generifc header */
IMPLEMENT_META_INTERFACE(HelloWorldInterface, HELLOWORLD_NAME);


};