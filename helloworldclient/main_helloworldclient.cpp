/*
 * HelloWorld Service driver.
 * Copyright (C) 2009 Michael Richardson <mcr@credil.org>
 *
 * Released under the terms of the file ../NOTICE
 */
#define LOG_TAG "HelloWorld/Service"

#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "helloworld.h"

int main(int argc, char *argv[])
{
	LOGI("Hello client is now starting");

        android::sp<android::IServiceManager> sm = android::defaultServiceManager();
        android::sp<android::IBinder> binder;
        android::sp<android::IHelloWorldInterface> shw;

        do {
                binder = sm->getService(android::String16(HELLOWORLD_NAME));
                if (binder != 0)
                        break;
                LOGW("HelloWorld not published, waiting...");
                usleep(500000); // 0.5 s
        } while(true);

        //LOGI("sm: %u binder: %u", sm, binder);

        //if (sDeathNotifier == NULL) {
        //    sDeathNotifier = new DeathNotifier();
        //}
        //binder->linkToDeath(sDeathNotifier);
        //sMediaPlayerService = interface_cast<IMediaPlayerService>(binder);

	LOGI("Hello client is now trying");

        shw = android::interface_cast<android::IHelloWorldInterface>(binder);
        shw->hellothere("fun");
	
	LOGI("Hello client is now exiting");

	return(0);
}
