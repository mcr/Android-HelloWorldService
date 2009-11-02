#define LOG_TAG "HelloWorldService-JNI"

#include <utils/Log.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#include <string.h>
#include <cutils/atomic.h>
#include <utils/IServiceManager.h>
#include <utils/String16.h>

#include "helloworldservice.h"
#include "utils/Log.h"

#include <unistd.h>


const android::String16 IHelloWorldService::descriptor("org.credil.helloworldservice.HelloWorldServiceInterface");

class BpHelloWorldService: public android::BpInterface<IHelloWorldService>
{
public:
	BpHelloWorldService(const android::sp<android::IBinder> &impl)
		: android::BpInterface<IHelloWorldService>(impl)
	{
	}
};

void HelloWorldService::instantiate() {
	android::defaultServiceManager()->addService(
                IHelloWorldService::descriptor, new HelloWorldService());
}

HelloWorldService::HelloWorldService()
{
    LOGV("HelloWorldService created");
    mNextConnId = 1;
}

HelloWorldService::~HelloWorldService()
{
    LOGV("HelloWorldService destroyed");
}

/* From MACRO IMPLEMENT_META_INTERAFACE() */
/*
 * INTERFACE = HelloWorldService
 * NAME = helloworld.codec
 *
 */
android::String16 IHelloWorldService::getInterfaceDescriptor() const {             
        return IHelloWorldService::descriptor;                                
}

android::sp<IHelloWorldService> IHelloWorldService::asInterface(const android::sp<android::IBinder>& obj)
{                                                                   
	android::sp<IHelloWorldService> intr;                                          
        if (obj != NULL) {
     		intr = static_cast<IHelloWorldService*>(
			obj->queryLocalInterface(
				IHelloWorldService::descriptor).get());
		
		if (intr == NULL) {                                         
			intr = new BpHelloWorldService(obj);
		}                                                           
        }                                                               
        return intr;                                                    
}                                                                   

