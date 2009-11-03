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
const android::String16 IHelloWorldClient::descriptor(HELLOWORLD_NAME);

android::String16 IHelloWorldClient::getInterfaceDescriptor() const {
        return IHelloWorldClient::descriptor;
}

android::sp<IHelloWorldClient> IHelloWorldClient::asInterface(const android::sp<android::IBinder>& obj)
{                                                                   
	android::sp<IHelloWorldClient> intr;                                          
        if (obj != NULL) {
     		intr = static_cast<IHelloWorldClient*>(
			obj->queryLocalInterface(
				IHelloWorldClient::descriptor).get());
		
		if (intr == NULL) {                                         
			intr = new BpHelloWorldClient(obj);
		}                                                           
        }                                                               
        return intr;                                                    
}                                                                   

#define CHECK_INTERFACE(interface, data, reply) \
        do { if (!data.enforceInterface(interface::getInterfaceDescriptor())) { \
            LOGW("Call incorrectly routed to " #interface); \
            return android::PERMISSION_DENIED;              \
        } } while (0)

android::status_t BnHelloWorldClient::onTransact(
        uint32_t code,
        const android::Parcel& data,
        android::Parcel* reply,
        uint32_t flags)
{
        switch(code) {
        case HW_HELLOTHERE: {
                CHECK_INTERFACE(IHelloWorldClient, data, reply);
                const char *str;
                str = data.readCString();
                /* hellothere(str); */
                printf("hello: %s\n", str);
                return android::NO_ERROR;
        } break;
        default:
                return BBinder::onTransact(code, data, reply, flags);
        }
}

