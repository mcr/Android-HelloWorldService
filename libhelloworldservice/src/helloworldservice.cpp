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

void HelloWorldService::instantiate() {
	android::defaultServiceManager()->addService(
                IHelloWorldClient::descriptor, new HelloWorldService());
}
void HelloWorldService::hellothere(const char *str){

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

#define android_CHECK_INTERFACE(interface, data, reply) \
        do { if (!data.enforceInterface(interface::getInterfaceDescriptor())) { \
            LOGW("Call incorrectly routed to " #interface); \
            return android::PERMISSION_DENIED;              \
        } } while (0)

android::status_t HelloWorldService::onTransact(uint32_t code,
                                                const android::Parcel &data,
                                                android::Parcel *reply,
                                                uint32_t flags)
{
        LOGE("OnTransact(%u,%u)", code, flags);
        
        switch(code) {
        case HW_HELLOTHERE: {
                android_CHECK_INTERFACE(IHelloWorldClient, data, reply);
                android::String16 str = data.readString16();
                /* hellothere(str); */
                LOGE("hello: %s\n", android::String8(str).string());
                printf("hello: %s\n", android::String8(str).string());
                return android::NO_ERROR;
        } break;
        default:
                return BBinder::onTransact(code, data, reply, flags);
        }

        return android::NO_ERROR;
}

