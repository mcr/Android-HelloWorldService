package org.credil.helloworldservice;

/**
 *  AIDL file created to match the interface defined in IHelloWorld.h
 *
 *  The order ot the methods defines the "method id" of the method
 *  and the package name + interface name defines the interface descriptor
 *  If you want to better understand what is going on here is will be very usefull
 *  to look at the code generated from this file.
 **/
interface IHelloWorld {
        int hellothere(String msg);
}
