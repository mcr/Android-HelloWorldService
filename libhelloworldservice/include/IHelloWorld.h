#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#include <binder/IInterface.h>

/**
 * The name also called descriptor of the binder interface. This is the
 * unique name that will be used to register the service and that can be
 * used to get the services.
 *
 * The aidl tool used by android by default uses the interface name as descriptor
 * if you use an aidl this must match the aidl package and name
 **/
#define HELLOWORLD_NAME "org.credil.helloworldservice.IHelloWorld"

namespace android {

/**
 *  Define the interface we want to be remotable. This interface
 *  can be used to create booth local and remote implementations.
 *
 * The convention is to start such interface with I. In this case we simply call
 * the interface IHelloWorld as the interface does not offer real functionality.
 * In Android code you will find that many interfaces name contain information about
 * what they do:Manager,Service, Callback,Session, Listener etc.
 *
 *  Extending from IInterface means we will have an asBinder method
 *  That can be used to perform remote calls
 *
 * class IInterface extends RefBase
 *   + asBinder()
 *   + onAsBinder();
 **/
class IHelloWorld: public IInterface {
protected:
    /**
     * Interface are regsitered using a name see "HELLOWORLD_NAME"
     * this is how binders find eachoter. Once this connection is setup dispatching
     * is done using the enum bellow. to booth parties (client/server) will use
     * HW_HELLOTHERE (1) as intentifier for the hellothere call and addutional payloads
     * are delivered using parcels.
     **/
    enum {
            HW_HELLOTHERE =  IBinder::FIRST_CALL_TRANSACTION
    };

public:
        /**
         * DECLARE_META_INTERFACE is a macro Defined in binder/IInterface.h that
         * implements the BnInterface (native interface)
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
        DECLARE_META_INTERFACE(HelloWorld)

        /**
         * The methods we want to expose using the interface.
         * There is nothing really magic here you will need to wire the
         * binder calls to the methods using the enum.
         **/
        virtual void hellothere(const char *str) = 0;
};

}
#endif
