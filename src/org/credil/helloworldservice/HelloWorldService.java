package org.credil.helloworldservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.ServiceManager;    //Android internal API
import android.util.Log;

/**
 *   HelloWorldService is a normal Android service declared in a normal
 *   AndroidManifest.xml. It therefore will be instantiated when the correct
 *   Intent is launched. Upon that happening in the onBind methods we use
 *   ServiceManager.getService.
 */
public class HelloWorldService extends Service {
    private final static String LOG_TAG = HelloWorldService.class.getSimpleName();
    private IBinder mIBinder;

    public IBinder onBind(Intent intent) {
        /**
         * Assume the service is already as in this setup we are running a native service for
         * some good reason: We are running the service from init.rc
         *
         * The following code works but it most probably is conceptualy wrong.
         *
         * The mBinder returned "lives" in a different process.
         **/
        mIBinder = ServiceManager.getService("org.credil.helloworldservice.IHelloWorld");
        if (mIBinder == null) {
            Log.e(LOG_TAG, "Hello service not found is/system/bin/helloworldservice running?");
            return null;
        }
        return mIBinder;
    }
}
