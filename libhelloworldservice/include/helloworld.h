#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#define HELLOWORLD_NAME "org.credil.helloworldservice.HelloWorldServiceInterface"

enum {
        HW_HELLOTHERE=1,
};


class HelloWorldService;

class IHelloWorldClient: public android::IInterface {
public:
// expand macro DECLARE_META_INTERFACE
	static const android::String16 descriptor;
	static android::sp<IHelloWorldClient> asInterface(const android::sp<android::IBinder>& obj);   
	virtual android::String16 getInterfaceDescriptor() const;

        virtual void hellothere(const char *str) = 0;
};

class BnHelloWorldClient : public android::BnInterface<IHelloWorldClient> 
{
public:
        virtual android::status_t    onTransact( uint32_t code,
                                    const android::Parcel& data,
                                    android::Parcel* reply,
                                    uint32_t flags = 0);

        /* void hellothere(const char *str); */
};


#endif
