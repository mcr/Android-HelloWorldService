#define LOG_TAG "HelloWorldService"

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

#include "helloworldservice.h"
#include "utils/Log.h"

#include <unistd.h>

const android::String16 IHelloWorldService::descriptor(HELLOWORLD_NAME);

android::String16 IHelloWorldService::getInterfaceDescriptor() {
        return IHelloWorldService::descriptor;
}


void HelloWorldService::instantiate() {
	android::defaultServiceManager()->addService(
                IHelloWorldService::descriptor, new HelloWorldService());
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
        
        return android::NO_ERROR;
}

