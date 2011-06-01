#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#include <binder/IInterface.h>

/**
 * The name also called descriptor of the binder interface. This is the
 * unique name that will be used to register the service and that can be
 * used to get the services.
 **/
#define HELLOWORLD_NAME "org.credil.helloworldservice.HelloWorldServiceInterface"

namespace android {

/**
 *  Define the interface we want to be remotable. This interface
 *  can be used to create booth local and remote implementations.
 *
 * The convention is to start such interface with I
 *
 *  Extending from IInterface means we will have an asBinder method
 *  That can be used to perform remote calls
 **/
class IHelloWorldInterface: public IInterface {
protected:
    /**
     * Interface are regsitered using a name see "HELLOWORLD_NAME"
     * this is how binders find eachoter. Once this connection is setup dispatching
     * is done using the enum bellow. to booth parties (client/server) will use
     * HW_HELLOTHERE (1) as intentifier for the hellothere call.
     **/
    enum {
            HW_HELLOTHERE =  IBinder::FIRST_CALL_TRANSACTION
    };

public:
        /**
         * macro Defined in binder/IInterface.h
         *
         * It defines two methods
         * getInterfaceDescriptor (this is meta data)
         * and
         * asInterface(IBinder) to convert a binder object back to the interface.
         *
         * This last method can either return a local(native) or remote(p) implementatation
         * of the interface. It does this by calling the queryLocalInterface on the Binder
         * object and if this object does not exist create a new instance of a class called
         * Bp"interfacename" so in our case BpHelloWorldInterface. Note that the macro takes
         * the interface name without the starting I
         *
         * If you are only implementing the native side of things this macro might be overhead because
         * it requires you to have a Bp (remote) implementation
         **/
        DECLARE_META_INTERFACE(HelloWorldInterface)

        /**
         * The methods we want to expose using the interface.
         * There is nothing really magic here you will need to wire the
         * binder calls to the methods using the enum.
         **/
        virtual void hellothere(const char *str) = 0;
};

}
#endif
