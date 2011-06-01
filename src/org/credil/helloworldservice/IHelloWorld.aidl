package org.credil.helloworldservice;

/**
 *  AIDL file create to match the interface defined in IHelloWorld.h
 *  THe order ot the methods defines the "method id" of the method
 *  and the package name + interface name defines the interface descriptor
 **/
interface IHelloWorld {
        int hellothere(String msg);
}
