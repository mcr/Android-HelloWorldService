#define LOG_TAG "HelloWorldService"

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
#include <utils/String8.h>
#include "helloworldservice.h"
#include "utils/Log.h"

#include <unistd.h>

namespace android {


void HelloWorldService::instantiate() {
	defaultServiceManager()->addService(
                IHelloWorldInterface::descriptor, new HelloWorldService());
}

void HelloWorldService::hellothere(const char *str){
                /* hellothere(str); */
                LOGE("hello: %s\n", str);
                printf("hello: %s\n", str);
}

HelloWorldService::HelloWorldService()
{
    LOGE("HelloWorldService created");
    mNextConnId = 1;
}

HelloWorldService::~HelloWorldService()
{
    LOGE("HelloWorldService destroyed");
}

android::status_t HelloWorldService::onTransact(uint32_t code,
                                                const android::Parcel &data,
                                                android::Parcel *reply,
                                                uint32_t flags)
{
        LOGE("OnTransact(%u,%u)", code, flags);
        
        switch(code) {
        case HW_HELLOTHERE: {
                CHECK_INTERFACE(IHelloWorldInterface, data, reply);
                String16 str = data.readString16();
                hellothere(String8(str).string());
                return NO_ERROR;
        } break;
        default:
                return BBinder::onTransact(code, data, reply, flags);
        }

        return NO_ERROR;
}

}